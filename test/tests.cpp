// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

class TextGenTest : public testing::Test {
 protected:
    TextGen textgen;
};

TEST(test1, prefix) {
  TextGen textgen;
  std::string words = "I love my baby";
  prefix pref = {"I", "love"};
  textgen.makeTab(words, 2);
  EXPECT_NE(textgen.statetab.find(pref),
  textgen.statetab.end());
}

TEST(test3, suffix) {
    std::string words = "I love my baby";
    TextGen textgen;
    textgen.makeTab(words, 2);
    EXPECT_EQ(textgen.generateText(9, 123), "I love my");
}

TEST(test4, chooseSuffix) {
    std::string words = "I love my baby, I love my home, I love my eat";
    TextGen textgen;
    textgen.makeTab(words, 2);
    EXPECT_EQ(textgen.generateText(14, 302), "I love my eat");
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
