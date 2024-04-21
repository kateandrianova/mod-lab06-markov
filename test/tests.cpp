// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

class TextGenTest : public testing::Test {
 protected:
    TextGen textgen;
};

TEST(test1, prefix) {
  TextGen textgen;
  std::string words = "I am student";
  prefix pref = {"I", "am"};
  textgen.makeTab(words, 2);
  EXPECT_EQ(textgen.statetab.find(pref),
  textgen.statetab.end());
}

TEST(test2, prefix_suffix) {
    std::string words = "I am good and kind student";
    TextGen textgen;
    prefix pref = { "I", "am" };
    textgen.makeTab(words, 2);
    EXPECT_EQ(textgen.statetab[pref][0], "good");
}

TEST(test3, suffix) {
    std::string words = "I am good and kind student";
    TextGen textgen;
    textgen.makeTab(words, 2);
    EXPECT_EQ(textgen.generateText(9, 123), "I am good");
}

TEST(test4, chooseSuffix) {
    std::string words = "a b c d e b c a b d e a";
    TextGen textgen;
    textgen.makeTab(words, 2);
    EXPECT_EQ(textgen.generateText(14, 350), "d e a");
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
    EXPECT_EQ(textgen.generateText(10, 10), "a A ");
}
