cmake_minimum_required(VERSION 3.27)
project(hangman_pp)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)

add_executable(hangman_pp main.cpp
        HangmanGame.cpp
        HangmanGame.h
        Renderer.cpp
        Renderer.h
        MainMenu.cpp
        MainMenu.h
        DifficultySelection.cpp
        DifficultySelection.h
        CategorySelection.cpp
        CategorySelection.h
        GameScreen.cpp
        GameScreen.h
        IScreen.cpp
        IScreen.h
        GameState.cpp
        GameState.h
        GameApp.cpp
        GameApp.h
        WinScreen.cpp
        WinScreen.h
        LoseScreen.cpp
        LoseScreen.h)

target_link_libraries(hangman_pp sfml-graphics)
