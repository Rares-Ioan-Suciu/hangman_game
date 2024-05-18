#ifndef HANGMAN_PP_GAMEAPP_H
#define HANGMAN_PP_GAMEAPP_H

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "IScreen.h"
#include "GameState.h"

class GameApp {
public:
    GameApp();
    void run();
    void setSelectedCategory(const std::string& category);
    void setSelectedDifficulty(const std::string& difficulty);
    void set_correct(const std::string& string);

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    GameState gameState;
    bool gameStateChanged;
    std::unique_ptr<IScreen> currentScreen;
    std::string correct;
    std::string selectedCategory;
    std::string selectedDifficulty;
};

#endif // HANGMAN_PP_GAMEAPP_H
