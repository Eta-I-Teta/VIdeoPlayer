#pragma once

#include "VideoSource.hpp"
#include "SubtitleProvider.hpp"
#include "Renderer.hpp"
#include "PlayerContext.hpp"
#include "PlayerCommand.hpp"

#include <memory>
#include <string>


class VideoPlayer {
private:
	std::unique_ptr<VideoSource> m_video_source;
	std::unique_ptr<SubtitleProvider> m_subtitle_provider;
	std::unique_ptr<Renderer> m_renderer;
	PlayerContext m_context;

	double m_seek_interval_sec = 10;

	void toggle_pause();
	void seek_forward();
	void seek_backward();
	void toggle_subtitles();

	void process_frame();
	bool should_continue() const;

public:
	VideoPlayer(
		std::unique_ptr<VideoSource> video_source,
		std::unique_ptr<SubtitleProvider> subtitle_provider,
		std::unique_ptr<Renderer> renderer
	);

	bool load_video(const std::string& filepath);
	bool load_subtitles(const std::string& filepath);

	void run();
	void handle_command(PlayerCommand command);

};