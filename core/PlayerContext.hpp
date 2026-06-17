#pragma once

class PlayerContext {
private:
	bool m_isPaused;
	bool m_subtitlesEnabled;
	double m_playbackSpeed;
	int m_volume;

public:
	PlayerContext();

	[[nodiscard]] bool isPaused() const;
	void togglePause();

	[[nodiscard]] double getPlaybackSpeed() const;
	void setPlaybackSpeed(double speed);
	void increaseSpeed();
	void decreaseSpeed();

	[[nodiscard]] int getVolume() const;
	void setVolume(int volume);
	void increaseVolume();
	void decreaseVolume();

	[[nodiscard]] bool isSubtitlesEnabled() const;
	void toggleSubtitles();
};