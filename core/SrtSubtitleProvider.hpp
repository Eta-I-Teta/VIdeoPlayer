#pragma once

#include "SubtitleProvider.hpp"
#include "SubtitleCue.hpp"

#include <vector>
#include <memory>


class SrtSubtitleProvider : public SubtitleProvider {
private:
	std::vector<SubtitleCue> m_cues;
	bool m_is_loaded;

	static bool parse_timecodes(const std::string& line, double& start_time, double& end_time);

public:
	SrtSubtitleProvider();

	bool load(std::unique_ptr<std::istream> stream) override;
	std::string get_line(double time_sec) const override;
};
