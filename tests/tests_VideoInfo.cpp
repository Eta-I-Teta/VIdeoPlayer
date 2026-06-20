#include <gtest/gtest.h>
#include "VideoInfo.hpp"

TEST(VideoInfoTest, ConstructorAndGetters) {
    VideoInfo info(30.0, 1920, 1080, 9000, 300.0);
    EXPECT_DOUBLE_EQ(info.get_fps(), 30.0);
    EXPECT_EQ(info.get_width(), 1920);
    EXPECT_EQ(info.get_height(), 1080);
    EXPECT_EQ(info.get_total_frames(), 9000);
    EXPECT_DOUBLE_EQ(info.get_duration_sec(), 300.0);
}

TEST(VideoInfoTest, ZeroValues) {
    VideoInfo info(0.0, 0, 0, 0, 0.0);
    EXPECT_DOUBLE_EQ(info.get_fps(), 0.0);
    EXPECT_EQ(info.get_width(), 0);
    EXPECT_EQ(info.get_height(), 0);
    EXPECT_EQ(info.get_total_frames(), 0);
    EXPECT_DOUBLE_EQ(info.get_duration_sec(), 0.0);
}

TEST(VideoInfoTest, HighResolution) {
    VideoInfo info(60.0, 3840, 2160, 18000, 300.0);
    EXPECT_DOUBLE_EQ(info.get_fps(), 60.0);
    EXPECT_EQ(info.get_width(), 3840);
    EXPECT_EQ(info.get_height(), 2160);
}
