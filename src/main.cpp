#include <iostream>
#include "textgen.h"
#include <fstream>


std::string readText(const std::string& filename) {
    std::string text;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            text += line + " ";
        }
        text.pop_back();
        file.close();
    }

    return text;
}
int main()
{
    const int NREF = 2;
    const int MAXGEN = 1000;

    std::string intext = readText("text.txt");

    TextGen gen;
    gen.makeTab(intext, NREF);

    std::string text = gen.generateText(MAXGEN);
    std::cout << text;
}
