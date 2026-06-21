#include "OpenCVVideoSource.hpp"

#include <gtest/gtest.h>
#include <string>

#define TEST_VIDEO_PATH "C:/Users/User/Desktop/other/NSU/projects/cpp/VideoPlayer/tests/dummy_video.mp4"


TEST(OpenCVVideoSourceTest, Constructor) {
	OpenCVVideoSource source;
	EXPECT_FALSE(source.is_opened());
}

TEST(OpenCVVideoSourceTest, OpenInvalidFile) {
	OpenCVVideoSource source;
	EXPECT_FALSE(source.open("non_existent_file.mp4"));
	EXPECT_FALSE(source.is_opened());
}

TEST(OpenCVVideoSourceTest, OpenValidFile) {
	OpenCVVideoSource source;
	EXPECT_TRUE(source.open(TEST_VIDEO_PATH));
	EXPECT_TRUE(source.is_opened());
}

TEST(OpenCVVideoSourceTest, GetVideoInfo) {
	OpenCVVideoSource source;
	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));

	VideoInfo info = source.get_video_info();
	EXPECT_GT(info.get_width(), 0);
	EXPECT_GT(info.get_height(), 0);
	EXPECT_GT(info.get_total_frames(), 0);
	EXPECT_GT(info.get_fps(), 0.0);
}

TEST(OpenCVVideoSourceTest, ReadFrame) {
	OpenCVVideoSource source;
	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));

	cv::Mat frame = source.read_frame();
	EXPECT_FALSE(frame.empty());
	EXPECT_GT(frame.cols, 0);
	EXPECT_GT(frame.rows, 0);
}

TEST(OpenCVVideoSourceTest, ReadMultipleFrames) {
	OpenCVVideoSource source;
	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));

	cv::Mat frame1 = source.read_frame();
	cv::Mat frame2 = source.read_frame();
	cv::Mat frame3 = source.read_frame();

	EXPECT_FALSE(frame1.empty());
	EXPECT_FALSE(frame2.empty());
	EXPECT_FALSE(frame3.empty());
}

TEST(OpenCVVideoSourceTest, GetCurrentTimeSec) {
	OpenCVVideoSource source;
	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));

	double time = source.get_current_time_sec();
	EXPECT_DOUBLE_EQ(time, 0.0);

	source.read_frame();
	source.read_frame();
	source.read_frame();

	time = source.get_current_time_sec();
	EXPECT_GT(time, 0.0);
}

TEST(OpenCVVideoSourceTest, Seek) {
	OpenCVVideoSource source;
	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));

	EXPECT_TRUE(source.seek(1.0));

	double time = source.get_current_time_sec();
	EXPECT_NEAR(time, 1.0, 0.5); 

	cv::Mat frame = source.read_frame();
	EXPECT_FALSE(frame.empty());
}

TEST(OpenCVVideoSourceTest, SeekClampsToBoundaries) {
	OpenCVVideoSource source;
	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));

	VideoInfo info = source.get_video_info();
	double duration = info.get_duration_sec();

	EXPECT_TRUE(source.seek(-5));
	double time = source.get_current_time_sec();
	EXPECT_NEAR(time, 0.0, 0.1);

	EXPECT_TRUE(source.seek(duration + 10));
	time = source.get_current_time_sec();
	EXPECT_NEAR(time, duration, 0.5);
}

TEST(OpenCVVideoSourceTest, SeekToBeginning) {
	OpenCVVideoSource source;
	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));

	source.read_frame();
	source.read_frame();
	source.read_frame();

	EXPECT_TRUE(source.seek(0.0));

	double time = source.get_current_time_sec();
	EXPECT_NEAR(time, 0.0, 0.1);
}

TEST(OpenCVVideoSourceTest, MultipleOpen) {
	OpenCVVideoSource source;

	ASSERT_TRUE(source.open(TEST_VIDEO_PATH));
	EXPECT_TRUE(source.is_opened());

	EXPECT_TRUE(source.open(TEST_VIDEO_PATH));
	EXPECT_TRUE(source.is_opened());

	cv::Mat frame = source.read_frame();
	EXPECT_FALSE(frame.empty());
}