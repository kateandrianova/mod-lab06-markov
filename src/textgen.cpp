#include <iostream>
#include <cstdlib>
#include "textgen.h"
#include <random>

TextGen::TextGen() {}

void TextGen::makeTab(std::string text, int count) {
    std::vector<std::string> words;
    char sep = ' ';
    int start = 0;
    int end = 0;
    std::string t;

    for (int i = 0; i <= text.size(); i++) {
        if (text[i] == sep || i == text.size())
        {
            end = i;
            t.append(text, start, end - start);
            words.push_back(t);
            start = end + 1;
        }
    }

    first.push_back(words[0]);
    first.push_back(words[1]);

    for (int i = 0; i < words.size() - count; i++) {
        prefix pref;
        for (int j = 0; j < count; j++) {
            pref.push_back(words[i + j]);
        }
        statetab[pref].push_back(words[i + count]);
    }
}

std::string TextGen::generateText(int count) {
    prefix pref;
    std::string text;
    pref = first;

    for (const std::string& elem : pref) {
        text += elem + ' ';
    }
    std::default_random_engine gen();
    while (text.size() < count) {
        if (statetab.find(pref) != statetab.end()) {
            const std::vector<std::string>& suffixes = statetab[pref];

            if (!suffixes.empty()) {
                std::uniform_int_distribution<> dist(0, suffixes.size() - 1);
                int index = dist(gen);
                text += suffixes[index] + ' ';
                pref.pop_front();
                pref.push_back(suffixes[index]);
            }
            else {
                break;
            }
        }
        else
        {
            break;
        }
    }

    if (!text.empty() && text.back() == ' ') {
        text.pop_back();
    }

    if (text.size() > count) {
        text = text.substr(0, count);
    }

    return text;
}
