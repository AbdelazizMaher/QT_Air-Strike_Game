cmake_minimum_required(VERSION 3.16)

project(AirStrike_Game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
)

qt_add_executable(AirStrike_Game
    ${PROJECT_SOURCES}
    Player.h Player.cpp
    Bullet.h Bullet.cpp
    Enemy.h Enemy.cpp
)

target_link_libraries(AirStrike_Game PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS AirStrike_Game
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AirStrike_Game)
endif()
