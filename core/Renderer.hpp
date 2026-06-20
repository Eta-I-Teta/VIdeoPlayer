#pragma once
#include <string>
#include <opencv2/core.hpp>
#include "PlayerContext.hpp"

class Renderer {
public:
	virtual ~Renderer() = default;

	virtual void render(const cv::Mat& frame, const std::string& subtitle, const PlayerContext& context) = 0;
	virtual bool is_window_closed() const = 0;
	virtual void release() = 0;
};
