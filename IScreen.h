//
// Created by rares655 on 5/17/24.
//

#ifndef HANGMAN_PP_ISCREEN_H
#define HANGMAN_PP_ISCREEN_H


#include <SFML/Graphics.hpp>
#include "GameState.h"
#pragma once

class IScreen {
public:
    virtual ~IScreen() = default;
    virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) = 0;
    virtual void update(sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif //HANGMAN_PP_ISCREEN_H