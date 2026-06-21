#include "SrtSubtitleProvider.hpp"
#include "ParseTimestamp.hpp"
#include "StringTrim.hpp"

#include <algorithm>


SrtSubtitleProvider::SrtSubtitleProvider(): m_is_loaded(false), m_cues() {}

bool SrtSubtitleProvider::parse_timecodes(
	const std::string& line,
	double& start_time,
	double& end_time
) 
{
	auto arrowPos = line.find("-->");
	if (arrowPos == std::string::npos) {
		return false;
	}

	std::string start_str = line.substr(0, arrowPos);
	std::string end_str = line.substr(arrowPos + 3);

	trim(start_str);
	trim(end_str);

	try {
		start_time = parse_timestamp(start_str);
		end_time = parse_timestamp(end_str);
		return true;
	}
	catch (...) {
		return false;
	}
}

bool SrtSubtitleProvider::load(std::unique_ptr<std::istream> stream) {
	if (!stream || !stream->good()) {
		return false;
	}

	m_cues.clear();
	m_is_loaded = false;

	int sub_id;
	std::string line;
	while (std::getline(*stream, line)) 
	{
		if (line.empty()) {
			continue;
		}

		// ID субтитра
		try {
			sub_id = std::stoi(line);
		}
		catch (...) {
			continue;
		}

		// таймкоды
		if (!std::getline(*stream, line)) break;

		double start_time = 0.0, end_time = 0.0;
		if (!parse_timecodes(line, start_time, end_time)) {
			continue;
		}

		// текст субтитра
		std::string text;
		while (std::getline(*stream, line)) {
			if (line.empty()) {
				break;
			}

			if (!text.empty()) {
				text += "\n";
			}
			text += line;
		}

		// Создаём SubtitleCue
		m_cues.emplace_back(
			sub_id,
			start_time,
			end_time,
			text
		);
	}

	m_is_loaded = !m_cues.empty();
	return m_is_loaded;
}

std::string SrtSubtitleProvider::get_line(double timeSec) const {
	if (!m_is_loaded) {
		return "";
	}

	auto it = std::upper_bound(
		m_cues.begin(), m_cues.end(), timeSec,
		[](double time, const SubtitleCue& cue) {
			return time < cue.get_start_time_sec();
		}
	);

	if (it != m_cues.begin()) {
		--it;
		if (it->is_active_at(timeSec)) {
			return it->get_text();
		}
	}

	return "";
}