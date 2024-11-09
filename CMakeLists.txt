cmake_minimum_required(VERSION 3.29)
project(cpp_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(3rdparty)
include_directories(3rdparty/include)
include_directories(3rdparty/include/sgg)

add_executable(cpp_game
    3rdparty/include/sgg/graphics.h
    3rdparty/include/sgg/scancodes.h
    cpp_game/main.cpp
        cpp_game/define.h
        cpp_game/game.cpp
        cpp_game/player.cpp
        cpp_game/event.cpp
        cpp_game/button.cpp
        cpp_game/screen.cpp
        cpp_game/screen_manager.cpp
        cpp_game/main_menu_screen.cpp
        cpp_game/robot.cpp
        cpp_game/ground.cpp
        cpp_game/help_screen.cpp
        cpp_game/select_screen.cpp
        cpp_game/game_screen.cpp)
