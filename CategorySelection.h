
#ifndef HANGMAN_PP_CATEGORYSELECTION_H
#define HANGMAN_PP_CATEGORYSELECTION_H

#pragma once
#include "IScreen.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "GameApp.h"


class GameApp;  // Forward declaration of GameApp

class CategorySelection : public IScreen {
public:
    explicit CategorySelection(GameApp& app);

    void handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    GameApp& app;
    sf::Font font;
    sf::Text title;
    sf::Text moviesButton;
    sf::Text literatureButton;
    sf::Text musicButton;
    sf::Text pop_cultureButton;
    sf::Text video_gamesButton;
};



#endif //HANGMAN_PP_CATEGORYSELECTION_H
