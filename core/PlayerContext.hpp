#pragma once

//  Пришлось вынести реализацию в заголовочный файл т.к. была ошибка линковки, которую я не смог решить иначе

class PlayerContext {
private:
	bool m_is_paused = false;
	bool m_subtitles_enabled = true;

public:
	PlayerContext() = default;

	[[nodiscard]] bool is_paused() const { return m_is_paused; }
	[[nodiscard]] bool is_subtitles_enabled() const { return m_subtitles_enabled; }

	void toggle_pause() { m_is_paused = !m_is_paused; }
	void toggle_subtitles() { m_subtitles_enabled = !m_subtitles_enabled; }

};