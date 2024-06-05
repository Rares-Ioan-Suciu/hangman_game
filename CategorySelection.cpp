#include "CategorySelection.h"

sf::Color CategorySelection::hexToColor(std::string hex) {
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}

CategorySelection::CategorySelection(GameApp& app) : app(app) {

    backgroundTexture.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/ppwildwest.jpg");

    backgroundSprite.setTexture(backgroundTexture);

    foregroundTexture.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/oldpaper.png");


    foregroundSprite.setTexture(foregroundTexture);
    foregroundSprite.setScale(2.0f, 2.0f);
    foregroundSprite.setPosition(1000, 100);

    font.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/WesternBangBang-Regular.ttf");

    titleFont.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/RioGrande.ttf");

    title.setFont(titleFont);
    title.setString("Select Category");
    title.setCharacterSize(70);
    title.setFillColor(hexToColor("#30221a"));

    titleUnderline.setSize(sf::Vector2f(title.getGlobalBounds().width, 4)); // 2 is the thickness of the underline
    titleUnderline.setPosition(title.getPosition().x - title.getGlobalBounds().width / 2, title.getPosition().y + title.getGlobalBounds().height - 30);
    titleUnderline.setFillColor(title.getFillColor());

    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    title.setPosition(sf::Vector2f(1500, 350));

    moviesButton.setFont(font);
    moviesButton.setString("Movies");
    moviesButton.setCharacterSize(65);
    moviesButton.setFillColor(sf::Color::Black);

    sf::FloatRect moviesButtonBounds = moviesButton.getLocalBounds();
    moviesButton.setOrigin(moviesButtonBounds.left + moviesButtonBounds.width / 2.0f, moviesButtonBounds.top + moviesButtonBounds.height / 2.0f);
    moviesButton.setPosition(sf::Vector2f(1500, 520));

    literatureButton.setFont(font);
    literatureButton.setString("Literature");
    literatureButton.setCharacterSize(65);
    literatureButton.setFillColor(sf::Color::Black);

    sf::FloatRect literatureButtonBounds = literatureButton.getLocalBounds();
    literatureButton.setOrigin(literatureButtonBounds.left + literatureButtonBounds.width / 2.0f, literatureButtonBounds.top + literatureButtonBounds.height / 2.0f);
    literatureButton.setPosition(sf::Vector2f(1500, 600));

    musicButton.setFont(font);
    musicButton.setString("Music");
    musicButton.setCharacterSize(65);
    musicButton.setFillColor(sf::Color::Black);

    sf::FloatRect musicButtonBounds = musicButton.getLocalBounds();
    musicButton.setOrigin(musicButtonBounds.left + musicButtonBounds.width / 2.0f, musicButtonBounds.top + musicButtonBounds.height / 2.0f);
    musicButton.setPosition(sf::Vector2f(1500, 700));

    pop_cultureButton.setFont(font);
    pop_cultureButton.setString("Pop Culture");
    pop_cultureButton.setCharacterSize(65);
    pop_cultureButton.setFillColor(sf::Color::Black);

    sf::FloatRect pop_cultureButtonBounds = pop_cultureButton.getLocalBounds();
    pop_cultureButton.setOrigin(pop_cultureButtonBounds.left + pop_cultureButtonBounds.width / 2.0f, pop_cultureButtonBounds.top + pop_cultureButtonBounds.height / 2.0f);
    pop_cultureButton.setPosition(sf::Vector2f(1500, 800));

    video_gamesButton.setFont(font);
    video_gamesButton.setString("Video Games");
    video_gamesButton.setCharacterSize(65);
    video_gamesButton.setFillColor(sf::Color::Black);

    sf::FloatRect video_gamesButtonBounds = video_gamesButton.getLocalBounds();
    video_gamesButton.setOrigin(video_gamesButtonBounds.left + video_gamesButtonBounds.width / 2.0f, video_gamesButtonBounds.top + video_gamesButtonBounds.height / 2.0f);
    video_gamesButton.setPosition(sf::Vector2f(1500, 900));
}

void CategorySelection::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (moviesButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Movies");
            gameState = GameState::Game;
            gameStateChanged = true;
        }
        else if (literatureButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Literature");
            gameState = GameState::Game;
            gameStateChanged = true;
        }
        else if (musicButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Music");
            gameState = GameState::Game;
            gameStateChanged = true;
        }
        else if (pop_cultureButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Pop_culture");
            gameState = GameState::Game;
            gameStateChanged = true;
        }
        else if (video_gamesButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Video_games");
            gameState = GameState::Game;
            gameStateChanged = true;
        }
    }
}

void CategorySelection::update(sf::RenderWindow& window) {
    
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

    if (moviesButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        moviesButton.setFillColor(sf::Color::Green);
        moviesUnderline.setSize(sf::Vector2f(moviesButton.getGlobalBounds().width, 3));
        moviesUnderline.setPosition(moviesButton.getPosition().x - moviesButton.getGlobalBounds().width / 2, moviesButton.getPosition().y + moviesButton.getGlobalBounds().height);
        moviesUnderline.setFillColor(sf::Color::Green);
    }
    else {
        // Mouse is not over the button, reset its color
        moviesButton.setFillColor(hexToColor("#522309"));
        moviesUnderline.setSize(sf::Vector2f(0, 0));
    }

    if (literatureButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        literatureButton.setFillColor(sf::Color::Green);
        literatureUnderline.setSize(sf::Vector2f(literatureButton.getGlobalBounds().width, 3));
        literatureUnderline.setPosition(literatureButton.getPosition().x - literatureButton.getGlobalBounds().width / 2, literatureButton.getPosition().y + literatureButton.getGlobalBounds().height);
        literatureUnderline.setFillColor(sf::Color::Green);
    }
    else {
        // Mouse is not over the button, reset its color
        literatureButton.setFillColor(hexToColor("#522309"));
        literatureUnderline.setSize(sf::Vector2f(0, 0));
    }

    if (musicButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        musicButton.setFillColor(sf::Color::Green);
        musicButtonUnderline.setSize(sf::Vector2f(musicButton.getGlobalBounds().width, 3));
        musicButtonUnderline.setPosition(musicButton.getPosition().x - musicButton.getGlobalBounds().width / 2, musicButton.getPosition().y + musicButton.getGlobalBounds().height);
        musicButtonUnderline.setFillColor(sf::Color::Green);
    }
    else {
        // Mouse is not over the button, reset its color
        musicButton.setFillColor(hexToColor("#522309"));
        musicButtonUnderline.setSize(sf::Vector2f(0, 0));
    }

    if (pop_cultureButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        pop_cultureButton.setFillColor(sf::Color::Green);
        pop_cultureButtonUnderline.setSize(sf::Vector2f(pop_cultureButton.getGlobalBounds().width, 3));
        pop_cultureButtonUnderline.setPosition(pop_cultureButton.getPosition().x - pop_cultureButton.getGlobalBounds().width / 2, pop_cultureButton.getPosition().y + pop_cultureButton.getGlobalBounds().height);
        pop_cultureButtonUnderline.setFillColor(sf::Color::Green);
    }
    else {
        // Mouse is not over the button, reset its color
        pop_cultureButton.setFillColor(hexToColor("#522309"));
        pop_cultureButtonUnderline.setSize(sf::Vector2f(0, 0));
    }

    if (video_gamesButton.getGlobalBounds().contains(mousePos)) {

        // Mouse is over the button, change its color
        video_gamesButton.setFillColor(sf::Color::Green);
        video_gameUnderline.setSize(sf::Vector2f(video_gamesButton.getGlobalBounds().width, 3));
        video_gameUnderline.setPosition(video_gamesButton.getPosition().x - video_gamesButton.getGlobalBounds().width / 2, video_gamesButton.getPosition().y + video_gamesButton.getGlobalBounds().height);
        video_gameUnderline.setFillColor(sf::Color::Green);
    }
    else {
        // Mouse is not over the button, reset its color
        video_gamesButton.setFillColor(hexToColor("#522309"));
        video_gameUnderline.setSize(sf::Vector2f(0, 0));
    }

}

void CategorySelection::render(sf::RenderWindow& window) {

    window.clear(sf::Color::Black);

    window.draw(backgroundSprite);

    window.draw(foregroundSprite);

    window.draw(title);

    window.draw(titleUnderline);

    window.draw(moviesButton);

    window.draw(moviesUnderline);

    window.draw(literatureButton);

    window.draw(literatureUnderline);

    window.draw(musicButton);

    window.draw(musicButtonUnderline);

    window.draw(pop_cultureButton);

    window.draw(pop_cultureButtonUnderline);

    window.draw(video_gamesButton);
    
    window.draw(video_gameUnderline);

}