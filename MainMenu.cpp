#include <iostream>
#include "MainMenu.h"

sf::Color MainMenu::hexToColor(std::string hex) {
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}

MainMenu::MainMenu() {

    if(!backgroundTexture.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/ppwildwest.jpg")) {
		std::cerr << "Error loading background image\n";
	}

    backgroundSprite.setTexture(backgroundTexture);

    if (!foregroundTexture.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/oldpaper.png")) {
        std::cerr << "Error loading foreground image\n";
    }

    foregroundSprite.setTexture(foregroundTexture);
    foregroundSprite.setScale(2.0f, 2.0f);
    foregroundSprite.setPosition(1000, 100);


    if (!font.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/LiberationSans-Regular.ttf")) {
        std::cerr << "Error loading font\n";
    }


    title.setFont(font);
    title.setString("Hangman Game");
    title.setCharacterSize(70);
    title.setFillColor(hexToColor("#30221a"));

    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    title.setPosition(sf::Vector2f(1500, 350));

    titleUnderline.setSize(sf::Vector2f(title.getGlobalBounds().width, 4)); // 2 is the thickness of the underline
    titleUnderline.setPosition(title.getPosition().x - title.getGlobalBounds().width / 2 , title.getPosition().y + title.getGlobalBounds().height - 30);
    titleUnderline.setFillColor(title.getFillColor());

    startButton.setFont(font);
    startButton.setString("Start Game");
    startButton.setCharacterSize(55);
    startButton.setFillColor(hexToColor("#522309"));
    
    sf::FloatRect startButtonBounds = startButton.getLocalBounds();
    startButton.setOrigin(startButtonBounds.left + startButtonBounds.width / 2.0f, startButtonBounds.top + startButtonBounds.height / 2.0f);
    startButton.setPosition(sf::Vector2f(1500, 600));
}

void MainMenu::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {

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
    
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

    if (startButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        startButton.setFillColor(sf::Color::Red);
        buttonUnderline.setSize(sf::Vector2f(startButton.getGlobalBounds().width, 3));
        buttonUnderline.setPosition(startButton.getPosition().x - startButton.getGlobalBounds().width / 2, startButton.getPosition().y + startButton.getGlobalBounds().height);
        buttonUnderline.setFillColor(sf::Color::Black);
    }
    else {
        // Mouse is not over the button, reset its color
        startButton.setFillColor(hexToColor("#522309"));
        buttonUnderline.setSize(sf::Vector2f(0, 0));
    }

}

void MainMenu::render(sf::RenderWindow& window) {

    window.clear(sf::Color::Black);
    window.draw(backgroundSprite);

    window.draw(foregroundSprite);

    window.draw(title);
    window.draw(titleUnderline);


    window.draw(startButton);
    window.draw(buttonUnderline);
}