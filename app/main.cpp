#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // Тест 1: Вывод версии OpenCV
    std::cout << "=== OpenCV Test ===" << std::endl;
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    // Тест 2: Создание и работа с изображением
    cv::Mat testImage(400, 400, CV_8UC3, cv::Scalar(255, 255, 255));

    // Рисуем красный круг
    cv::circle(testImage, cv::Point(200, 200), 100, cv::Scalar(0, 0, 255), -1);

    // Пишем текст
    cv::putText(testImage, "OpenCV Works!", cv::Point(120, 350),
        cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 0, 0), 2);

    // Показываем окно
    cv::imshow("OpenCV Test Window", testImage);

    std::cout << "Window opened. Press any key in the window to exit..." << std::endl;
    cv::waitKey(0);  // Ждем нажатия клавиши

    std::cout << "Success!" << std::endl;
    return 0;
}