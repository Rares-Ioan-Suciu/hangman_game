#ifndef HANGMAN_PP_GAMESCREEN_H
#define HANGMAN_PP_GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "IScreen.h"
#include "Renderer.h"
#include "GameApp.h"

class GameApp;

class GameScreen : public IScreen {
public:
    GameScreen(GameApp& app, const std::string& category, const std::string& difficulty);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void setNeedsClear(bool value) {
        needsClear = value;
    }

private:
    bool needsClear{};
    std::vector<char> guessedLetters;
    bool isGuessingWord;
    GameApp& app;
    HangmanRenderer renderer;
    std::string correctWord;
    std::string userInput;
    sf::Font font;              // Declare font variable
    sf::Text userInputText;     // Declare userInputText variable
    sf::Text scoreText;         // Declare scoreText variable
    int incorrectGuessCount;
    int maxIncorrectGuesses;
    std::string gameMessage;
    int score;                  // Declare score variable
};

#endif // HANGMAN_PP_GAMESCREEN_H
