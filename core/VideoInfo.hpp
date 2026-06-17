#pragma once


class VideoInfo {
private:
	double m_fps;
	int m_width;
	int m_height;
	int m_totalFrames;
	double m_durationSec;

public:
	VideoInfo(double fps, int width, int height, int totalFrames, double durationSec)
		: m_fps(fps),
		m_width(width),
		m_height(height),
		m_totalFrames(totalFrames),
		m_durationSec(durationSec)
	{
	}

	[[nodiscard]] double getFps() const         { return m_fps; }
	[[nodiscard]] int getWidth() const          { return m_width; }
	[[nodiscard]] int getHeight() const         { return m_height; }
	[[nodiscard]] int getTotalFrames() const    { return m_totalFrames; }
	[[nodiscard]] double getDurationSec() const { return m_durationSec; }
};