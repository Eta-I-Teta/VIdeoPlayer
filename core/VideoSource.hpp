#pragma once
#include <string>
#include <opencv2/core.hpp>
#include "VideoInfo.hpp"

class VideoSource {
public:
	virtual ~VideoSource() = default;

	virtual bool open(const std::string& file_path) = 0;
	virtual bool is_opened() const = 0;
	virtual cv::Mat read_frame() = 0;
	virtual VideoInfo get_video_info() const = 0;
	virtual double get_current_time_sec() const = 0;
	virtual bool seek(double time_sec) = 0;
};
