#include "PlayerContext.hpp"
#include <algorithm>

PlayerContext::PlayerContext()
	: m_isPaused(false),
	m_playbackSpeed(1.0),
	m_volume(100),
	m_subtitlesEnabled(true)
{
}

bool PlayerContext::isPaused() const {
	return m_isPaused;
}
void PlayerContext::togglePause() {
	m_isPaused = !m_isPaused;
}

double PlayerContext::getPlaybackSpeed() const {
	return m_playbackSpeed;
}
void PlayerContext::setPlaybackSpeed(double speed) {
	m_playbackSpeed = std::clamp(speed, 0.25, 2.5);
}
void PlayerContext::increaseSpeed() {
	setPlaybackSpeed(m_playbackSpeed + 0.25);
}
void PlayerContext::decreaseSpeed() {
	setPlaybackSpeed(m_playbackSpeed - 0.25);
}

int PlayerContext::getVolume() const {
	return m_volume;
}
void PlayerContext::setVolume(int volume) {
	m_volume = std::clamp(volume, 0, 100);
}
void PlayerContext::increaseVolume() {
	setVolume(m_volume + 10);
}
void PlayerContext::decreaseVolume() {
	setVolume(m_volume - 10);
}

bool PlayerContext::isSubtitlesEnabled() const {
	return m_subtitlesEnabled;
}
void PlayerContext::toggleSubtitles() {
	m_subtitlesEnabled = !m_subtitlesEnabled;
}
