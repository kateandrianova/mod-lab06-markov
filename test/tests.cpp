// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(test1, prefix) {
  TextGen textgen;
  std::string words = "I am student"};
  std::deque<std::string> prefix;
  prefix.push_back("I");
  prefix.push_back("am");
  textgen.makeTab(words, 2);
  EXPECT_EQ(prefix, textgen.first);
}

TEST(test2, prefix_suffix) {
    std::vector<std::string>words{ "I", "am", "good", "and", "kind", "student"};
    TextGen textgen;
    std::deque<std::string> prefix{ "I", "am" };
    textgen.makeTab(words, 2);
    std::vector<std::string> suffix{ "student" };
    EXPECT_EQ(mark.statetab.begin()->second, suffix);
}

TEST(test3, suffix) {
    std::vector<std::string>words{ "I", "am", "good", "and", 
      "kind", "student" };
    TextGen textgen;
    textgen.makeTab(words, 1);
    EXPECT_EQ(textgen.generateText(10, 10), "I am good and kind student");
}

TEST(test4, chooseSuffix) {
    std::vector<std::string>words{ "a",
    "b", "c", "d", "e",
    "b", "c", "a", "b", "d", "e", "a"};
    TextGen textgen;
    textgen.makeTab(words, 1);
    EXPECT_EQ(textgen.generateText(10, 10), "a b d e b d e a b c ");
}

TEST(test5, text) {
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string> > state = {
        { { "a" }, { "A", "a" } },
        { { "b" }, { "B", "b" } },
        { {"c"}, {"C"} }
    };
    TextGen textgen;
    typedef std::deque<std::string> prefix;
    prefix pref{ "a" };
    textgen.statetab = state;
    textgen.first = pref;
    EXPECT_EQ(textgen.generateText(10, 10), "b B ");
}
