#include "LoseScreen.h"

LoseScreen::LoseScreen() {
    if (!font.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/LiberationSans-Regular.ttf")) {
       //Handle it..
    }
    message.setFont(font);
    message.setCharacterSize(50);
    message.setFillColor(sf::Color::Red);
    message.setPosition(100, 100); // Adjust position as needed
}

void LoseScreen::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            gameState = GameState::MainMenu;
            gameStateChanged = true;
        }
    }
}

void LoseScreen::update(sf::RenderWindow& window) {
    // Update logic if needed
}

void LoseScreen::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);
    window.draw(message);
    window.display();
}

void LoseScreen::setMessage(const std::string& correctWord) {
    message.setString("You lost! The correct word was: " + correctWord);
}