#include "OpenCVRenderer.hpp"
#include "PlayerContext.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <locale>

int main() {

	std::locale::global(std::locale(".UTF8"));
	std::cout.imbue(std::locale(".UTF8"));


	OpenCVRenderer renderer("testij");

	if (renderer.is_window_closed()) {
		return 1;
	}
	std::cout << "Окно открыто" << std::endl;

	// тестовый кадр (синий прямоугольник)
	cv::Mat frame(500, 700, CV_8UC3, cv::Scalar(255, 0, 0));
	PlayerContext context;

	std::cout << "Тест 1: Отображение кадра без субтитров..." << std::endl;
	renderer.render(frame, "", context);
	cv::waitKey(0);

	std::cout << "Тест 2: Отображение кадра с субтитрами..." << std::endl;
	renderer.render(frame, "Hello world!", context);
	cv::waitKey(0);

	std::cout << "Тест 3: Многострочные субтитры..." << std::endl;
	renderer.render(frame, "line 1\nline 2\nline 3", context);
	cv::waitKey(0);

	std::cout << "Тест 4: Отключение субтитров..." << std::endl;
	context.toggle_subtitles();
	renderer.render(frame, "subs", context);
	cv::waitKey(0);

	std::cout << "Тест 5: Пустой кадр..." << std::endl;
	cv::Mat empty_frame;
	renderer.render(empty_frame, "test", context);
	cv::waitKey(0);

	std::cout << "Тест 6: Освобождение ресурсов..." << std::endl;
	renderer.release();
	if (!renderer.is_window_closed()) {
		std::cerr << "Окно не закрылось" << std::endl;
		return 1;
	}
	std::cout << "Окно закрыто" << std::endl;

	renderer.release();  // Не должно упасть

	return 0;
}