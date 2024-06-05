#include "DifficultySelection.h"

sf::Color DifficultySelection::hexToColor(std::string hex) {
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}

DifficultySelection::DifficultySelection(GameApp& app) : app(app) {

    backgroundTexture.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/ppwildwest.jpg");

    backgroundSprite.setTexture(backgroundTexture);

    foregroundTexture.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/oldpaper.png");
        

    foregroundSprite.setTexture(foregroundTexture);
    foregroundSprite.setScale(2.0f, 2.0f);
    foregroundSprite.setPosition(1000, 100);


    font.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/WesternBangBang-Regular.ttf");

    titleFont.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/RioGrande.ttf");


    title.setFont(titleFont);
    title.setString("Select Difficulty");
    title.setCharacterSize(70);
    title.setFillColor(hexToColor("#30221a"));


    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    title.setPosition(sf::Vector2f(1500, 350));


    titleUnderline.setSize(sf::Vector2f(title.getGlobalBounds().width, 4)); // 2 is the thickness of the underline
    titleUnderline.setPosition(title.getPosition().x - title.getGlobalBounds().width / 2, title.getPosition().y + title.getGlobalBounds().height - 30);
    titleUnderline.setFillColor(title.getFillColor());


    easyButton.setFont(font);
    easyButton.setString("Easy");
    easyButton.setCharacterSize(65);
    easyButton.setFillColor(hexToColor("#522309"));


    sf::FloatRect easyButtonBounds = easyButton.getLocalBounds();
    easyButton.setOrigin(easyButtonBounds.left + easyButtonBounds.width / 2.0f, easyButtonBounds.top + easyButtonBounds.height / 2.0f);
    easyButton.setPosition(sf::Vector2f(1500, 550));


    mediumButton.setFont(font);
    mediumButton.setString("Medium");
    mediumButton.setCharacterSize(65);
    mediumButton.setFillColor(hexToColor("#522309"));


    sf::FloatRect mediumButtonBounds = mediumButton.getLocalBounds();
    mediumButton.setOrigin(mediumButtonBounds.left + mediumButtonBounds.width / 2.0f, mediumButtonBounds.top + mediumButtonBounds.height / 2.0f);
    mediumButton.setPosition(sf::Vector2f(1500, 690));


    hardButton.setFont(font);
    hardButton.setString("Hard");
    hardButton.setCharacterSize(65);
    hardButton.setFillColor(hexToColor("#522309"));
    

    sf::FloatRect hardButtonBounds = hardButton.getLocalBounds();
    hardButton.setOrigin(hardButtonBounds.left + hardButtonBounds.width / 2.0f, hardButtonBounds.top + hardButtonBounds.height / 2.0f);
    hardButton.setPosition(sf::Vector2f(1500, 840));
}

void DifficultySelection::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (easyButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedDifficulty("easy");
            gameState = GameState::CategorySelection;
            gameStateChanged = true;
        }
        else if (mediumButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedDifficulty("medium");
            gameState = GameState::CategorySelection;
            gameStateChanged = true;
        }
        else if (hardButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedDifficulty("hard");
            gameState = GameState::CategorySelection;
            gameStateChanged = true;
        }
    }
}

void DifficultySelection::update(sf::RenderWindow& window) {
    

    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

    if (easyButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        easyButton.setFillColor(sf::Color::Green);
        easyButtonUnderline.setSize(sf::Vector2f(easyButton.getGlobalBounds().width, 3));
        easyButtonUnderline.setPosition(easyButton.getPosition().x - easyButton.getGlobalBounds().width / 2, easyButton.getPosition().y + easyButton.getGlobalBounds().height);
        easyButtonUnderline.setFillColor(sf::Color::Green);
    }
    else {
        // Mouse is not over the button, reset its color
        easyButton.setFillColor(hexToColor("#522309"));
        easyButtonUnderline.setSize(sf::Vector2f(0, 0));
    }


    if (mediumButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        mediumButton.setFillColor(hexToColor("#a16b06"));
        mediumButtonUnderline.setSize(sf::Vector2f(mediumButton.getGlobalBounds().width, 3));
        mediumButtonUnderline.setPosition(mediumButton.getPosition().x - mediumButton.getGlobalBounds().width / 2, mediumButton.getPosition().y + mediumButton.getGlobalBounds().height);
        mediumButtonUnderline.setFillColor(hexToColor("#a16b06"));
    }
    else {
        // Mouse is not over the button, reset its color
        mediumButton.setFillColor(hexToColor("#522309"));
        mediumButtonUnderline.setSize(sf::Vector2f(0, 0));
    }



    if (hardButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        hardButton.setFillColor(hexToColor("#ad1807"));
        buttonUnderline.setSize(sf::Vector2f(hardButton.getGlobalBounds().width, 3));
        buttonUnderline.setPosition(hardButton.getPosition().x - hardButton.getGlobalBounds().width / 2, hardButton.getPosition().y + hardButton.getGlobalBounds().height);
        buttonUnderline.setFillColor(hexToColor("#ad1807"));
    }
    else {
        // Mouse is not over the button, reset its color
        hardButton.setFillColor(hexToColor("#522309"));
        buttonUnderline.setSize(sf::Vector2f(0, 0));
    }


}

void DifficultySelection::render(sf::RenderWindow& window) {

    window.clear(sf::Color::Black);
    window.draw(backgroundSprite);

    window.draw(foregroundSprite);

    window.draw(title);
    window.draw(titleUnderline);

    window.draw(easyButton);
    window.draw(mediumButton);
    window.draw(hardButton);

    window.draw(easyButtonUnderline);
    window.draw(mediumButtonUnderline);
    window.draw(buttonUnderline);
}