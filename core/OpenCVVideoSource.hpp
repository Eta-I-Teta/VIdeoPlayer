#pragma once

#include "VideoSource.hpp"
#include "VideoInfo.hpp"

#include <opencv2/videoio.hpp>

#include <memory>
#include <string>


class OpenCVVideoSource : public VideoSource {
private:
	std::unique_ptr<cv::VideoCapture> m_capture;
	VideoInfo m_video_info;
	bool m_is_opened = false;

public:
	OpenCVVideoSource();
	~OpenCVVideoSource() override;

	bool open(const std::string& filepath) override;
	bool is_opened() const override;
	cv::Mat read_frame() override;
	VideoInfo get_video_info() const override;
	double get_current_time_sec() const override;
	bool seek(double time_sec) override;
};