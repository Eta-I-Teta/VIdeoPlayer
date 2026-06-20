#include "PlayerContext.hpp"

PlayerContext::PlayerContext()
	: m_is_paused(false), m_subtitles_enabled(true) {}


bool PlayerContext::is_paused() const {
	return m_is_paused;
}
void PlayerContext::toggle_pause() {
	m_is_paused = !m_is_paused;
}

bool PlayerContext::is_subtitles_enabled() const {
	return m_subtitles_enabled;
}
void PlayerContext::toggle_subtitles() {
	m_subtitles_enabled = !m_subtitles_enabled;
}