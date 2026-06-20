#pragma once


class PlayerContext {
private:
	bool m_is_paused;
	bool m_subtitles_enabled;

public:
	PlayerContext();

	[[nodiscard]] bool is_paused() const;
	[[nodiscard]] bool is_subtitles_enabled() const;

	void toggle_pause();
	void toggle_subtitles();

};