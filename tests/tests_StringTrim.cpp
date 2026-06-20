#include <gtest/gtest.h>
#include "StringTrim.hpp"

TEST(StringTrimTest, TrimsSpaces) {
    std::string str = "  hello  ";
    trim(str);
    EXPECT_EQ(str, "hello");
}

TEST(StringTrimTest, TrimsTabs) {
    std::string str = "\thello\t";
    trim(str);
    EXPECT_EQ(str, "hello");
}

TEST(StringTrimTest, TrimsNewlines) {
    std::string str = "\nhello\n";
    trim(str);
    EXPECT_EQ(str, "hello");
}

TEST(StringTrimTest, TrimsCarriageReturn) {
    std::string str = "\rhello\r";
    trim(str);
    EXPECT_EQ(str, "hello");
}

TEST(StringTrimTest, TrimsMixedWhitespace) {
    std::string str = " \t\n\rhello\r\n\t ";
    trim(str);
    EXPECT_EQ(str, "hello");
}

TEST(StringTrimTest, EmptyString) {
    std::string str = "";
    trim(str);
    EXPECT_EQ(str, "");
}

TEST(StringTrimTest, OnlyWhitespace) {
    std::string str = "   \t\n\r  ";
    trim(str);
    EXPECT_EQ(str, "");
}

TEST(StringTrimTest, NoWhitespace) {
    std::string str = "hello";
    trim(str);
    EXPECT_EQ(str, "hello");
}

TEST(StringTrimTest, SingleCharacter) {
    std::string str = " x ";
    trim(str);
    EXPECT_EQ(str, "x");
}
