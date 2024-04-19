#pragma once
#include <string>
#include <sstream>
#include <deque>
#include <map>
#include <vector>

class TextGen {
public:
	typedef std::deque<std::string> prefix;
	std::map<prefix, std::vector<std::string> > statetab;
	prefix first;

public:
	TextGen();
	void makeTab(std::string text, int count);
	std::string generateText(int count);
};
