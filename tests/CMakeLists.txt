add_executable(core_tests "tests_StringTrim.cpp" "tests_FormatTime.cpp" "tests_ParseTimestamp.cpp" "tests_SubtitleCue.cpp" "tests_VideoInfo.cpp" "tests_PlayerContext.cpp" "tests_SrtSubtitleProvider.cpp" "tests_OpenCVVideoSource.cpp")
target_link_libraries(core_tests PRIVATE core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(core_tests)
