
#ifndef HANGMAN_PP_DIFFICULTYSELECTION_H
#define HANGMAN_PP_DIFFICULTYSELECTION_H

#pragma once
#include <SFML/Graphics.hpp>
#include "IScreen.h"
#include "GameState.h"
#include "GameApp.h"


class GameApp;  // Forward declaration of GameApp

class DifficultySelection : public IScreen {
public:
    explicit DifficultySelection(GameApp& app);

    void handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    GameApp& app;
    sf::Font font;
    sf::Text title;
    sf::Text easyButton;
    sf::Text mediumButton;
    sf::Text hardButton;
};


#endif //HANGMAN_PP_DIFFICULTYSELECTION_H
