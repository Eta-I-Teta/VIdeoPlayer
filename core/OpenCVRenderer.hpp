#pragma once

#include "Renderer.hpp"

#include <string>


class OpenCVRenderer : public Renderer {
private:
	std::string m_window_name;
	bool m_window_closed;

	int m_font_face;
	double m_font_scale;
	int m_thickness;
	cv::Scalar m_text_color;
	cv::Scalar m_bg_color;

	void draw_subtitle(cv::Mat& frame, const std::string& subtitle);
	void draw_text_with_background(cv::Mat& frame, const std::string& text, cv::Point position);

public:
	explicit OpenCVRenderer(const std::string& window_name = "Video Player");
	~OpenCVRenderer() override;

	void render(const cv::Mat& frame, const std::string& subtitle, const PlayerContext& context) override;
	bool is_window_closed() const override;
	void release() override;
};
