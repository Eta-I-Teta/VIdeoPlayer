#include "VideoPlayer.hpp"

#include <opencv2/highgui.hpp>
#include <fstream>
#include <iostream>


VideoPlayer::VideoPlayer(
	std::unique_ptr<VideoSource> video_source,
	std::unique_ptr<SubtitleProvider> subtitle_provider,
	std::unique_ptr<Renderer> renderer
) :
	m_video_source(std::move(video_source)),
	m_subtitle_provider(std::move(subtitle_provider)),
	m_renderer(std::move(renderer))
{}

bool VideoPlayer::load_video(const std::string& filepath) {
	if (!m_video_source) {
		std::cerr << "Ошибка: источник видео не инициализирован" << std::endl;
		return false;
	}

	if (!m_video_source->open(filepath)) {
		std::cerr << "Ошибка: не удалось открыть видеофайл: " << filepath << std::endl;
		return false;
	}

	VideoInfo info = m_video_source->get_video_info();
	std::cout << "Видео загружено:" << std::endl;
	std::cout << "  Разрешение: " << info.get_width() << "x" << info.get_height() << std::endl;
	std::cout << "  FPS: " << info.get_fps() << std::endl;
	std::cout << "  Длительность: " << info.get_duration_sec() << " сек" << std::endl;

	return true;
}

bool VideoPlayer::load_subtitles(const std::string& filepath) {
	if (!m_subtitle_provider) {
		std::cerr << "Ошибка: провайдер субтитров не инициализирован" << std::endl;
		return false;
	}

	auto file_stream = std::make_unique<std::ifstream>(filepath);
	if (!file_stream->is_open()) {
		std::cerr << "Предупреждение: не удалось открыть файл субтитров: " << filepath << std::endl;
		std::cerr << "Воспроизведение продолжится без субтитров" << std::endl;
		return false;
	}

	if (!m_subtitle_provider->load(std::move(file_stream))) {
		std::cerr << "Предупреждение: не удалось загрузить субтитры" << std::endl;
		return false;
	}

	std::cout << "Субтитры загружены успешно" << std::endl;
	return true;
}

void VideoPlayer::run() {
	if (!m_video_source || !m_video_source->is_opened()) {
		std::cerr << "Ошибка: видео не загружено" << std::endl;
		return;
	}

	std::cout << "\n=== Управление ===" << std::endl;
	std::cout << "Пробел - Пауза/Воспроизведение" << std::endl;
	std::cout << "Стрелка вправо - Перемотка вперед на " << m_seek_interval_sec << " сек" << std::endl;
	std::cout << "Стрелка влево - Перемотка назад на " << m_seek_interval_sec << " сек" << std::endl;
	std::cout << "S - Вкл/выкл субтитры" << std::endl;
	std::cout << "Q или Esc - Выход" << std::endl;
	std::cout << "==================\n" << std::endl;

	while (should_continue()) {
		if (m_context.is_paused()) {
			cv::waitKey(100);
			continue;
		}

		process_frame();
	}

	std::cout << "\nВоспроизведение завершено" << std::endl;
}

void VideoPlayer::handle_command(PlayerCommand command) {
	switch (command) {
	case PlayerCommand::TogglePause:
		toggle_pause();
		break;

	case PlayerCommand::SeekForward:
		seek_forward();
		break;

	case PlayerCommand::SeekBackward:
		seek_backward();
		break;

	case PlayerCommand::ToggleSubtitles:
		toggle_subtitles();
		break;

	case PlayerCommand::None:
		break;
	}
}

void VideoPlayer::toggle_pause() {
	m_context.toggle_pause();

	if (m_context.is_paused()) {
		std::cout << "[ПАУЗА]" << std::endl;
	}
	else {
		std::cout << "[ВОСПРОИЗВЕДЕНИЕ]" << std::endl;
	}
}

void VideoPlayer::seek_forward() {
	double current_time = m_video_source->get_current_time_sec();
	double new_time = current_time + m_seek_interval_sec;
	m_video_source->seek(new_time);
	std::cout << "[ПЕРЕМОТКА ВПЕРЕД: " << new_time << " сек]" << std::endl;
}

void VideoPlayer::seek_backward() {
	double current_time = m_video_source->get_current_time_sec();
	double new_time = current_time - m_seek_interval_sec;
	m_video_source->seek(new_time);
	std::cout << "[ПЕРЕМОТКА НАЗАД: " << new_time << " сек]" << std::endl;
}

void VideoPlayer::toggle_subtitles() {
	m_context.toggle_subtitles();
	if (m_context.is_subtitles_enabled()) {
		std::cout << "[СУБТИТРЫ: ВКЛ]" << std::endl;
	}
	else {
		std::cout << "[СУБТИТРЫ: ВЫКЛ]" << std::endl;
	}
}

void VideoPlayer::process_frame() {
	cv::Mat frame = m_video_source->read_frame();

	if (frame.empty()) {
		return;
	}

	double current_time = m_video_source->get_current_time_sec();

	std::string subtitle;
	if (m_subtitle_provider && m_context.is_subtitles_enabled()) {
		subtitle = m_subtitle_provider->get_line(current_time);
	}

	if (m_renderer) {
		m_renderer->render(frame, subtitle, m_context);
	}


	VideoInfo info = m_video_source->get_video_info();
	if (info.get_fps() > 0) {
		int delay_ms = static_cast<int>(1000.0 / info.get_fps());
		cv::waitKey(delay_ms);
	}
}

bool VideoPlayer::should_continue() const {
	// Проверяем, закрыто ли окно рендерера
	if (m_renderer && m_renderer->is_window_closed()) {
		return false;
	}

	// Проверяем, открыто ли видео
	if (!m_video_source || !m_video_source->is_opened()) {
		return false;
	}

	return true;
}
