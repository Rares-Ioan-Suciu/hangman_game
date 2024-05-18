#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu() {
    if (!font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    title.setFont(font);
    title.setString("Hangman Game");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Green);
    title.setPosition(400, 150);

    startButton.setFont(font);
    startButton.setString("Start Game");
    startButton.setCharacterSize(30);
    startButton.setFillColor(sf::Color::Black);
    startButton.setPosition(400, 300);
}

void MainMenu::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged){
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            std::cout << "Start button clicked" << std::endl; // Debug output
            gameState = GameState::DifficultySelection;
            gameStateChanged = true; // Ensure the flag is set
            std::cout << "GameState changed to DifficultySelection" << std::endl; // Debug output
        }
    }
}

void MainMenu::update(sf::RenderWindow& window) {
    // Update logic if needed
}

void MainMenu::render(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(startButton);
}
