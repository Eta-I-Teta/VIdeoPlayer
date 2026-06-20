//#include "SrtSubtitleProvider.hpp"
// 
//#include <gtest/gtest.h>
//#include <sstream>
// 
//
//TEST(SrtSubtitleProviderTest, LoadValidSrt) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "Hello\n"
//        "\n"
//        "2\n"
//        "00:00:05,000 --> 00:00:08,000\n"
//        "World\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    EXPECT_TRUE(provider.load(std::move(stream)));
//}
//
//TEST(SrtSubtitleProviderTest, GetLineAtStartTime) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "Hello\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(1.0), "Hello");
//}
//
//TEST(SrtSubtitleProviderTest, GetLineAtEndTime) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "Hello\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(4.0), "Hello");
//}
//
//TEST(SrtSubtitleProviderTest, GetLineAtMiddle) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "Hello\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(2.5), "Hello");
//}
//
//TEST(SrtSubtitleProviderTest, GetLineBeforeStart) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "Hello\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(0.5), "");
//}
//
//TEST(SrtSubtitleProviderTest, GetLineAfterEnd) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "Hello\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(4.5), "");
//}
//
//TEST(SrtSubtitleProviderTest, MultipleSubtitles) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "First\n"
//        "\n"
//        "2\n"
//        "00:00:05,000 --> 00:00:08,000\n"
//        "Second\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(2.0), "First");
//    EXPECT_EQ(provider.get_line(6.0), "Second");
//    EXPECT_EQ(provider.get_line(4.5), ""); 
//}
//
//TEST(SrtSubtitleProviderTest, MultilineSubtitle) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "Line 1\n"
//        "Line 2\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(2.0), "Line 1\nLine 2");
//}
//
//TEST(SrtSubtitleProviderTest, EmptyStream) {
//    SrtSubtitleProvider provider;
//    auto stream = std::make_unique<std::istringstream>("");
//    EXPECT_FALSE(provider.load(std::move(stream)));
//}
//
//TEST(SrtSubtitleProviderTest, NullStream) {
//    SrtSubtitleProvider provider;
//    EXPECT_FALSE(provider.load(nullptr));
//}
//
//TEST(SrtSubtitleProviderTest, WindowsLineEndings) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\r\n"
//        "00:00:01,000 --> 00:00:04,000\r\n"
//        "Hello\r\n"
//        "\r\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    EXPECT_TRUE(provider.load(std::move(stream)));
//    EXPECT_EQ(provider.get_line(2.0), "Hello");
//}
//
//TEST(SrtSubtitleProviderTest, UnsortedSubtitles) {
//    SrtSubtitleProvider provider;
//    std::string srtContent =
//        "1\n"
//        "00:00:05,000 --> 00:00:08,000\n"
//        "Second\n"
//        "\n"
//        "2\n"
//        "00:00:01,000 --> 00:00:04,000\n"
//        "First\n";
//
//    auto stream = std::make_unique<std::istringstream>(srtContent);
//    provider.load(std::move(stream));
//
//    EXPECT_EQ(provider.get_line(2.0), "First");
//    EXPECT_EQ(provider.get_line(6.0), "Second");
//}
//
//TEST(SrtSubtitleProviderTest, GetLineBeforeLoad) {
//    SrtSubtitleProvider provider;
//    EXPECT_EQ(provider.get_line(1.0), "");
//}
