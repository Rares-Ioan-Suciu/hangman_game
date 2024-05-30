#include "WinScreen.h"

WinScreen::WinScreen() {
    if (!font.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/LiberationSans-Regular.ttf")) {
        //Handle it..
    }
    message.setFont(font);
    message.setString("Congratulations! You won!");
    message.setCharacterSize(50);
    message.setFillColor(sf::Color::Green);
    message.setPosition(100, 100); // Adjust position as needed
}

void WinScreen::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {
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

void WinScreen::update(sf::RenderWindow& window) {
    // Update logic if needed
}

void WinScreen::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);
    window.draw(message);
    window.display();
}