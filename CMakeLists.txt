cmake_minimum_required(VERSION 3.25)
project(my_first_game_sfml)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_first_game_sfml src/main.cpp src/game.cpp src/game.hpp)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(my_first_game_sfml PRIVATE sfml-system sfml-network sfml-graphics sfml-window)