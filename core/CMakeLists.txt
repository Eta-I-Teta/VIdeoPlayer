add_library(core STATIC 
    # Оркестратор
    VideoPlayer.hpp 
    VideoPlayer.cpp
    
    # Модели и типы
    SubtitleCue.hpp
    VideoInfo.hpp
    PlayerCommand.hpp
    
    # Контекст
    PlayerContext.hpp
    PlayerContext.cpp
    
    # Утилиты
    FormatTime.hpp
    ParseTimestamp.hpp
    StringTrim.hpp
    
    # Интерфейсы
    VideoSource.hpp
    SubtitleProvider.hpp
    Renderer.hpp
    UserInterface.hpp
    
    # Реализации
    SrtSubtitleProvider.hpp
    SrtSubtitleProvider.cpp
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(core PUBLIC ${OpenCV_LIBS})