cmake_minimum_required(VERSION 3.16)

project(AirStrike_Game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)

set(PROJECT_SOURCES
        main.cpp
)

include_directories(
    Game/
    Player/
    Enemy/
    Bullet/
    Health/
    Score/
)

qt_add_executable(AirStrike_Game
    ${PROJECT_SOURCES}
    Player/Player.h Player/Player.cpp
    Bullet/Bullet.h Bullet/Bullet.cpp
    Enemy/Enemy.h Enemy/Enemy.cpp
    Score/Score.h Score/Score.cpp
    Health/Health.h Health/Health.cpp
    Game/Game.h Game/Game.cpp
    resources.qrc
)

target_link_libraries(AirStrike_Game PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia)

install(TARGETS AirStrike_Game
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AirStrike_Game)
endif()
