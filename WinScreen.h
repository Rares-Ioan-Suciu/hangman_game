//
// Created by rares655 on 5/17/24.
//

#ifndef HANGMAN_PP_WINSCREEN_H
#define HANGMAN_PP_WINSCREEN_H


#include <SFML/Graphics.hpp>
#include "IScreen.h"
#pragma once
#include "GameState.h"

class WinScreen : public IScreen {
public:
    WinScreen();
    void handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font font;
    sf::Text message;
};


#endif //HANGMAN_PP_WINSCREEN_H