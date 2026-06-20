#include <gtest/gtest.h>
#include "ParseTimestamp.hpp"

TEST(ParseTimestampTest, ZeroTime) {
    EXPECT_DOUBLE_EQ(parse_timestamp("00:00:00,000"), 0.0);
}

TEST(ParseTimestampTest, SecondsOnly) {
    EXPECT_DOUBLE_EQ(parse_timestamp("00:00:05,000"), 5.0);
}

TEST(ParseTimestampTest, MinutesAndSeconds) {
    EXPECT_DOUBLE_EQ(parse_timestamp("00:02:30,000"), 150.0);
}

TEST(ParseTimestampTest, FullTime) {
    EXPECT_DOUBLE_EQ(parse_timestamp("01:02:30,500"), 3750.5);
}

TEST(ParseTimestampTest, Milliseconds) {
    EXPECT_DOUBLE_EQ(parse_timestamp("00:00:01,999"), 1.999);
}

TEST(ParseTimestampTest, OneHour) {
    EXPECT_DOUBLE_EQ(parse_timestamp("01:00:00,000"), 3600.0);
}

TEST(ParseTimestampTest, InvalidFormatThrows) {
    EXPECT_THROW(parse_timestamp("invalid"), std::invalid_argument);
}

TEST(ParseTimestampTest, MissingMillisecondsThrows) {
    EXPECT_THROW(parse_timestamp("00:00:01"), std::invalid_argument);
}

TEST(ParseTimestampTest, MissingMinutesThrows) {
    EXPECT_THROW(parse_timestamp("00:01"), std::invalid_argument);
}
