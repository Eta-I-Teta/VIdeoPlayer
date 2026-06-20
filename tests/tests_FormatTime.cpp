#include <gtest/gtest.h>
#include "FormatTime.hpp"

TEST(FormatTimeTest, ZeroSeconds) {
	EXPECT_EQ(format_time(0.0), "00:00");
}

TEST(FormatTimeTest, SecondsOnly) {
	EXPECT_EQ(format_time(45.0), "00:45");
}

TEST(FormatTimeTest, MinutesAndSeconds) {
	EXPECT_EQ(format_time(125.0), "02:05");
}

TEST(FormatTimeTest, HoursMinutesSeconds) {
	EXPECT_EQ(format_time(3665.0), "01:01:05");
}

TEST(FormatTimeTest, LargeHours) {
	EXPECT_EQ(format_time(7200.0), "02:00:00");
}

TEST(FormatTimeTest, FractionalSecondsIgnored) {
	EXPECT_EQ(format_time(125.7), "02:05");
}

TEST(FormatTimeTest, OneHour) {
	EXPECT_EQ(format_time(3600.0), "01:00:00");
}

TEST(FormatTimeTest, AlmostTwoHours) {
	EXPECT_EQ(format_time(7199.0), "01:59:59");
}
