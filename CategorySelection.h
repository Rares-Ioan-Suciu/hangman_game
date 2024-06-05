
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
    sf::Font titleFont;
    sf::Text title;
    sf::Text moviesButton;
    sf::Text literatureButton;
    sf::Text musicButton;
    sf::Text pop_cultureButton;
    sf::Text video_gamesButton;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture foregroundTexture;
    sf::Sprite foregroundSprite;
    sf::Color hexToColor(std::string hex);
    sf::RectangleShape moviesUnderline;
    sf::RectangleShape literatureUnderline;
    sf::RectangleShape musicButtonUnderline;
    sf::RectangleShape pop_cultureButtonUnderline;
    sf::RectangleShape video_gameUnderline;
    sf::RectangleShape titleUnderline;
};



#endif //HANGMAN_PP_CATEGORYSELECTION_H