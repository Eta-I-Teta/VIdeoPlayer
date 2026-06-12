add_library(core STATIC VideoPlayer.hpp VideoPlayer.cpp)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(core PUBLIC ${OpenCV_LIBS})
