cmake_minimum_required(VERSION 3.20)
project(VideoPlayer LANGUAGES CXX)

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui videoio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(ENABLE_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)

if(MSVC)
    add_compile_options(/W4)
    if(ENABLE_WARNINGS_AS_ERRORS)
        add_compile_options(/WX)
    endif()
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    if(ENABLE_WARNINGS_AS_ERRORS)
        add_compile_options(-Werror)
    endif()
endif()

if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy REQUIRED)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
endif()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set_directory_properties(PROPERTIES VS_STARTUP_PROJECT main)
FetchContent_MakeAvailable(googletest)

set_target_properties(gtest gtest_main gmock gmock_main
    PROPERTIES FOLDER "external/GoogleTest")

enable_testing()

add_subdirectory(core)
add_subdirectory(app)
add_subdirectory(tests)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/teacher_tests")
    add_subdirectory(teacher_tests)
endif()
