#pragma once

#include <string>
#include <stdexcept>


class SubtitleCue {
private:
	int m_id;
	double m_startTimeSec;
	double m_endTimeSec;
	std::string m_text;

public:
	SubtitleCue(int id, double startTimeSec, double endTimeSec, std::string text)
		: m_id(id),
		m_startTimeSec(startTimeSec),
		m_endTimeSec(endTimeSec),
		m_text(std::move(text))
	{
		if (m_startTimeSec < 0.0 || m_endTimeSec < m_startTimeSec) {
			throw std::invalid_argument("SubtitleCue: некорректный диапазон времени");
		}
	}

	[[nodiscard]] int getId() const						{ return m_id; }
	[[nodiscard]] double getStartTimeSec() const		{ return m_startTimeSec; }
	[[nodiscard]] double getEndTimeSec() const			{ return m_endTimeSec; }
	[[nodiscard]] const std::string& getText() const	{ return m_text; }

	[[nodiscard]] bool isActiveAt(double timeSec) const 
	{
		return timeSec >= m_startTimeSec && timeSec <= m_endTimeSec;
	}
};