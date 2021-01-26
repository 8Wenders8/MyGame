cmake_minimum_required(VERSION 3.17)
project(GameEng)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_NAME "GameEng")

set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(${EXECUTABLE_NAME} main.cpp Game.cpp Game.h States/State.cpp States/State.h States/GameState.cpp States/GameState.h Entities/Entity.cpp Entities/Entity.h States/MainMenuState.cpp States/MainMenuState.h Resources/Button.cpp Resources/Button.h)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-audio)