cmake_minimum_required(VERSION 3.17)
project(GameEng)

#if(NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE Release)
#endif()

#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_NAME "GameEng")

set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(${EXECUTABLE_NAME} main.cpp Game.cpp Game.h States/State.cpp States/State.h States/GameState.cpp States/GameState.h Entities/Entity.cpp Entities/Entity.h States/MainMenuState.cpp States/MainMenuState.h Resources/Button.cpp Resources/Button.h Entities/Player.cpp Entities/Player.h)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-audio)