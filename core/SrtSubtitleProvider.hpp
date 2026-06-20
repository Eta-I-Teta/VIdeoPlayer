//#pragma once
//
//#include "SubtitleProvider.hpp"
//#include "SubtitleCue.hpp"
//
//#include <vector>
//#include <memory>
//
//
//class SrtSubtitleProvider : public SubtitleProvider {
//private:
//	std::vector<SubtitleCue> m_cues;
//	bool m_isLoaded;
//
//	static bool parse_timecodes(const std::string& line, double& startTime, double& endTime);
//
//public:
//	bool load(std::unique_ptr<std::istream> stream) override;
//	std::string get_line(double timeSec) const override;
//};
