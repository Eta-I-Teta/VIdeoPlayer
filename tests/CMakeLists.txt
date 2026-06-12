add_executable(core_tests "test4test.cpp")
target_link_libraries(core_tests PRIVATE core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(core_tests)
