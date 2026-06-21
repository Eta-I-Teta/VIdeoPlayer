#include "OpenCVRenderer.hpp"

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <sstream>

#define COLOR_WHITE 255, 255, 255
#define COLOR_BLACK 0, 0, 0

//#define SUBTITLE_BOTTOM 30
//#define BG_PADDING 5

OpenCVRenderer::OpenCVRenderer(const std::string& window_name)
	: m_window_name(window_name),
	m_window_closed(false),
	m_font_face(cv::FONT_HERSHEY_SIMPLEX),
	m_font_scale(0.8),
	m_thickness(2),
	m_text_color(COLOR_WHITE),  
	m_bg_color(COLOR_BLACK)           
{
	cv::namedWindow(m_window_name, cv::WINDOW_AUTOSIZE);
}

OpenCVRenderer::~OpenCVRenderer() {
	release();
}

void OpenCVRenderer::render(const cv::Mat& frame, const std::string& subtitle, const PlayerContext& context) {
	if (frame.empty()) {
		return;
	}

	// Создаём копию кадра для отрисовки
	cv::Mat display_frame = frame.clone();

	// Если субтитры включены и есть текст, рисуем их
	if (context.is_subtitles_enabled() && !subtitle.empty()) {
		draw_subtitle(display_frame, subtitle);
	}

	// Отображаем кадр
	cv::imshow(m_window_name, display_frame);

	// Обрабатываем события окна (необходимо для отображения)
	cv::waitKey(1);
}

bool OpenCVRenderer::is_window_closed() const {
	return m_window_closed;
}

void OpenCVRenderer::release() {
	if (!m_window_closed) {
		cv::destroyWindow(m_window_name);
		m_window_closed = true;
	}
}

void OpenCVRenderer::draw_subtitle(cv::Mat& frame, const std::string& subtitle) {
	// Разбиваем многострочный субтитр на строки
	std::istringstream stream(subtitle);
	std::string line;

	// Вычисляем позицию для текста (внизу по центру)
	int line_height = 30;
	int num_lines = 0;

	// Сначала считаем количество строк
	std::string temp = subtitle;
	size_t pos = 0;
	while ((pos = temp.find('\n')) != std::string::npos) {
		num_lines++;
		temp.erase(0, pos + 1);
	}
	num_lines++; // Последняя строка

	// Начальная позиция Y (снизу)
	int y_start = frame.rows - 50 - (num_lines - 1) * line_height;

	// Рисуем каждую строку
	std::istringstream line_stream(subtitle);
	int current_line = 0;
	while (std::getline(line_stream, line)) {
		cv::Point position(50, y_start + current_line * line_height);
		draw_text_with_background(frame, line, position);
		current_line++;
	}
}

void OpenCVRenderer::draw_text_with_background(cv::Mat& frame, const std::string& text, cv::Point position) {
	// Получаем размер текста
	int baseline = 0;
	cv::Size text_size = cv::getTextSize(text, m_font_face, m_font_scale, m_thickness, &baseline);

	// Рисуем фон (прямоугольник за текстом)
	cv::Rect bg_rect(
		position.x - 5,
		position.y - text_size.height - 5,
		text_size.width + 10,
		text_size.height + baseline + 10
	);

	// Ограничиваем прямоугольник границами кадра
	bg_rect &= cv::Rect(0, 0, frame.cols, frame.rows);

	// Рисуем полупрозрачный фон
	cv::rectangle(frame, bg_rect, m_bg_color, cv::FILLED);

	// Рисуем текст
	cv::putText(frame, text, position, m_font_face, m_font_scale, m_text_color, m_thickness, cv::LINE_AA);
}
