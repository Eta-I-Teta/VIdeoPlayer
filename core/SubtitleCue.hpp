#pragma once

#include <string>
#include <stdexcept>


class SubtitleCue {
private:
	int m_id;
	double m_start_time_sec;
	double m_end_time_sec;
	std::string m_text;

public:
	SubtitleCue(int id, double start_time_sec, double end_time_sec, std::string text)
		: m_id(id),
		m_start_time_sec(start_time_sec),
		m_end_time_sec(end_time_sec),
		m_text(std::move(text))
	{
		if (m_start_time_sec < 0.0 || m_end_time_sec < m_start_time_sec) {
			throw std::invalid_argument("SubtitleCue: некорректный диапазон времени");
		}
	}

	[[nodiscard]] int get_id() const						{ return m_id; }
	[[nodiscard]] double get_start_time_sec() const			{ return m_start_time_sec; }
	[[nodiscard]] double get_end_time_sec() const			{ return m_end_time_sec; }
	[[nodiscard]] const std::string& get_text() const		{ return m_text; }

	[[nodiscard]] bool is_active_at(double time_sec) const 
	{
		return time_sec >= m_start_time_sec && time_sec <= m_end_time_sec;
	}
};