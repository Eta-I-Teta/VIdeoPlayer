#include <gtest/gtest.h>
#include "SubtitleCue.hpp"

TEST(SubtitleCueTest, ConstructorValid) {
    SubtitleCue cue(1, 1.0, 4.0, "Hello");
    EXPECT_EQ(cue.get_id(), 1);
    EXPECT_DOUBLE_EQ(cue.get_start_time_sec(), 1.0);
    EXPECT_DOUBLE_EQ(cue.get_end_time_sec(), 4.0);
    EXPECT_EQ(cue.get_text(), "Hello");
}

TEST(SubtitleCueTest, IsActiveAtStartTime) {
    SubtitleCue cue(1, 1.0, 4.0, "Hello");
    EXPECT_TRUE(cue.is_active_at(1.0));
}

TEST(SubtitleCueTest, IsActiveAtEndTime) {
    SubtitleCue cue(1, 1.0, 4.0, "Hello");
    EXPECT_TRUE(cue.is_active_at(4.0));
}

TEST(SubtitleCueTest, IsActiveAtMiddle) {
    SubtitleCue cue(1, 1.0, 4.0, "Hello");
    EXPECT_TRUE(cue.is_active_at(2.5));
}

TEST(SubtitleCueTest, IsNotActiveBefore) {
    SubtitleCue cue(1, 1.0, 4.0, "Hello");
    EXPECT_FALSE(cue.is_active_at(0.5));
}

TEST(SubtitleCueTest, IsNotActiveAfter) {
    SubtitleCue cue(1, 1.0, 4.0, "Hello");
    EXPECT_FALSE(cue.is_active_at(4.5));
}

TEST(SubtitleCueTest, InvalidTimeRangeThrows) {
    EXPECT_THROW(SubtitleCue(1, 5.0, 1.0, "Hello"), std::invalid_argument);
}

TEST(SubtitleCueTest, NegativeStartTimeThrows) {
    EXPECT_THROW(SubtitleCue(1, -1.0, 4.0, "Hello"), std::invalid_argument);
}

TEST(SubtitleCueTest, MultilineText) {
    SubtitleCue cue(1, 1.0, 4.0, "Line 1\nLine 2");
    EXPECT_EQ(cue.get_text(), "Line 1\nLine 2");
}
