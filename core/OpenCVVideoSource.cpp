#include "OpenCVVideoSource.hpp"

#include <opencv2/videoio.hpp>


OpenCVVideoSource::OpenCVVideoSource()
	: m_capture(nullptr),
	m_video_info(0.0, 0, 0, 0, 0.0),
	m_is_opened(false)
{
}

OpenCVVideoSource::~OpenCVVideoSource() {
	m_capture.reset();
}

bool OpenCVVideoSource::open(const std::string& filepath) {
	// Закрываем предыдущий файл
	m_capture.reset();
	m_is_opened = false;

	
	m_capture = std::make_unique<cv::VideoCapture>(filepath);

	if (!m_capture->isOpened()) {
		m_capture.reset();
		return false;
	}

	
	double fps = m_capture->get(cv::CAP_PROP_FPS);
	int width = static_cast<int>(m_capture->get(cv::CAP_PROP_FRAME_WIDTH));
	int height = static_cast<int>(m_capture->get(cv::CAP_PROP_FRAME_HEIGHT));
	int total_frames = static_cast<int>(m_capture->get(cv::CAP_PROP_FRAME_COUNT));
	double duration_sec = total_frames / fps;

	m_video_info = VideoInfo(fps, width, height, total_frames, duration_sec);
	m_is_opened = true;

	return true;
}

bool OpenCVVideoSource::is_opened() const {
	return m_is_opened && m_capture && m_capture->isOpened();
}

cv::Mat OpenCVVideoSource::read_frame() {
	if (!is_opened()) {
		return cv::Mat(); 
	}

	cv::Mat frame;
	if (!m_capture->read(frame)) {
		return cv::Mat(); 
	}

	return frame;
}

VideoInfo OpenCVVideoSource::get_video_info() const {
	return m_video_info;
}

double OpenCVVideoSource::get_current_time_sec() const {
	if (!is_opened()) {
		return 0;
	}

	double pos_msec = m_capture->get(cv::CAP_PROP_POS_MSEC);
	return pos_msec / 1000; 
}

bool OpenCVVideoSource::seek(double time_sec) {
	if (!is_opened()) {
		return false;
	}

	double clamped_time = std::clamp(
		time_sec,
		0.0,
		m_video_info.get_duration_sec()
	);

	double pos_msec = clamped_time * 1000.0;
	m_capture->set(cv::CAP_PROP_POS_MSEC, pos_msec);

	return true;  
}
