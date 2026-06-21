//#include <gtest/gtest.h>
//#include "OpenCVRenderer.hpp"
//#include <opencv2/core.hpp>
//
//TEST(OpenCVRendererTest, Constructor) {
//    OpenCVRenderer renderer("Test Window");
//    EXPECT_FALSE(renderer.is_window_closed());
//    renderer.release();
//}
//
//TEST(OpenCVRendererTest, RenderEmptyFrame) {
//    OpenCVRenderer renderer("Test Window");
//    cv::Mat empty_frame;
//    PlayerContext context;
//
//    // Должно корректно обработать пустой кадр
//    renderer.render(empty_frame, "Test subtitle", context);
//    EXPECT_FALSE(renderer.is_window_closed());
//
//    renderer.release();
//}
//
//TEST(OpenCVRendererTest, RenderFrameWithSubtitle) {
//    OpenCVRenderer renderer("Test Window");
//
//    // Создаём тестовый кадр
//    cv::Mat frame(100, 200, CV_8UC3, cv::Scalar(128, 128, 128));
//    PlayerContext context;
//
//    renderer.render(frame, "Hello, World!", context);
//    EXPECT_FALSE(renderer.is_window_closed());
//
//    renderer.release();
//}
//
//TEST(OpenCVRendererTest, RenderFrameWithoutSubtitle) {
//    OpenCVRenderer renderer("Test Window");
//
//    cv::Mat frame(100, 200, CV_8UC3, cv::Scalar(128, 128, 128));
//    PlayerContext context;
//    context.toggle_subtitles(); // Отключаем субтитры
//
//    renderer.render(frame, "Should not appear", context);
//    EXPECT_FALSE(renderer.is_window_closed());
//
//    renderer.release();
//}
//
//TEST(OpenCVRendererTest, RenderMultilineSubtitle) {
//    OpenCVRenderer renderer("Test Window");
//
//    cv::Mat frame(200, 400, CV_8UC3, cv::Scalar(128, 128, 128));
//    PlayerContext context;
//
//    std::string multiline = "Line 1\nLine 2\nLine 3";
//    renderer.render(frame, multiline, context);
//    EXPECT_FALSE(renderer.is_window_closed());
//
//    renderer.release();
//}
//
//TEST(OpenCVRendererTest, Release) {
//    OpenCVRenderer renderer("Test Window");
//    EXPECT_FALSE(renderer.is_window_closed());
//
//    renderer.release();
//    EXPECT_TRUE(renderer.is_window_closed());
//
//    // Повторный вызов release не должен вызывать ошибок
//    renderer.release();
//    EXPECT_TRUE(renderer.is_window_closed());
//}
//
//TEST(OpenCVRendererTest, DestructorCallsRelease) {
//    {
//        OpenCVRenderer renderer("Test Window");
//        EXPECT_FALSE(renderer.is_window_closed());
//    } // Здесь вызывается деструктор
//
//    // После выхода из scope окно должно быть закрыто
//    // (проверяем косвенно - программа не упала)
//    SUCCEED();
//}
