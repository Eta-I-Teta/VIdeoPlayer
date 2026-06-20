#pragma once


class VideoInfo {
private:
	double m_fps;
	int m_width;
	int m_height;
	int m_total_frames;
	double m_duration_sec;

public:
	VideoInfo(double fps, int width, int height, int total_frames, double duration_sec)
		: m_fps(fps),
		m_width(width),
		m_height(height),
		m_total_frames(total_frames),
		m_duration_sec(duration_sec)
	{
	}

	[[nodiscard]] double get_fps() const			{ return m_fps; }
	[[nodiscard]] int get_width() const				{ return m_width; }
	[[nodiscard]] int get_height() const			{ return m_height; }
	[[nodiscard]] int get_total_frames() const		{ return m_total_frames; }
	[[nodiscard]] double get_duration_sec() const	{ return m_duration_sec; }
};
