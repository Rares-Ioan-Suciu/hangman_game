//
// Created by rares655 on 5/17/24.
//

#ifndef HANGMAN_PP_LOSESCREEN_H
#define HANGMAN_PP_LOSESCREEN_H

#pragma once
#include <SFML/Graphics.hpp>
#include "IScreen.h"
#include "GameState.h"

class LoseScreen : public IScreen {
public:
    LoseScreen();
    void handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void setMessage(const std::string& correctWord);

private:
    sf::Font font;
    sf::Text message;
};


#endif //HANGMAN_PP_LOSESCREEN_H