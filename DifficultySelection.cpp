#include "DifficultySelection.h"

DifficultySelection::DifficultySelection(GameApp& app) : app(app) {
    font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf");

    title.setFont(font);
    title.setString("Select Difficulty");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    title.setPosition(400, 150);

    easyButton.setFont(font);
    easyButton.setString("Easy");
    easyButton.setCharacterSize(30);
    easyButton.setFillColor(sf::Color::Black);
    easyButton.setPosition(400, 300);

    mediumButton.setFont(font);
    mediumButton.setString("Medium");
    mediumButton.setCharacterSize(30);
    mediumButton.setFillColor(sf::Color::Black);
    mediumButton.setPosition(400, 350);

    hardButton.setFont(font);
    hardButton.setString("Hard");
    hardButton.setCharacterSize(30);
    hardButton.setFillColor(sf::Color::Black);
    hardButton.setPosition(400, 400);
}

void DifficultySelection::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (easyButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedDifficulty("easy");
            gameState = GameState::CategorySelection;
            gameStateChanged = true;
        } else if (mediumButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedDifficulty("medium");
            gameState = GameState::CategorySelection;
            gameStateChanged = true;
        } else if (hardButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedDifficulty("hard");
            gameState = GameState::CategorySelection;
            gameStateChanged = true;
        }
    }
}

void DifficultySelection::update(sf::RenderWindow& window) {
    // Update logic if needed
}

void DifficultySelection::render(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(easyButton);
    window.draw(mediumButton);
    window.draw(hardButton);
}
