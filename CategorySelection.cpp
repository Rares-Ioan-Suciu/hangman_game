#include "CategorySelection.h"

CategorySelection::CategorySelection(GameApp& app) : app(app) {
    font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf");
    title.setFont(font);
    title.setString("Select Category");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    title.setPosition(400, 150);

    moviesButton.setFont(font);
    moviesButton.setString("Movies");
    moviesButton.setCharacterSize(30);
    moviesButton.setFillColor(sf::Color::Black);
    moviesButton.setPosition(400, 300);

    literatureButton.setFont(font);
    literatureButton.setString("Literature");
    literatureButton.setCharacterSize(30);
    literatureButton.setFillColor(sf::Color::Black);
    literatureButton.setPosition(400, 350);

    musicButton.setFont(font);
    musicButton.setString("Music");
    musicButton.setCharacterSize(30);
    musicButton.setFillColor(sf::Color::Black);
    musicButton.setPosition(400, 400);

    pop_cultureButton.setFont(font);
    pop_cultureButton.setString("Pop Culture");
    pop_cultureButton.setCharacterSize(30);
    pop_cultureButton.setFillColor(sf::Color::Black);
    pop_cultureButton.setPosition(400, 450);

    video_gamesButton.setFont(font);
    video_gamesButton.setString("Video Games");
    video_gamesButton.setCharacterSize(30);
    video_gamesButton.setFillColor(sf::Color::Black);
    video_gamesButton.setPosition(400, 500);
}

void CategorySelection::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (moviesButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Movies");
            gameState = GameState::Game;
            gameStateChanged = true;
        } else if (literatureButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Literature");
            gameState = GameState::Game;
            gameStateChanged = true;
        } else if (musicButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Music");
            gameState = GameState::Game;
            gameStateChanged = true;
        } else if (pop_cultureButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Pop_culture");
            gameState = GameState::Game;
            gameStateChanged = true;
        } else if (video_gamesButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            app.setSelectedCategory("Video_games");
            gameState = GameState::Game;
            gameStateChanged = true;
        }
    }
}

void CategorySelection::update(sf::RenderWindow& window) {
    // Update logic if needed
}

void CategorySelection::render(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(moviesButton);
    window.draw(literatureButton);
    window.draw(musicButton);
    window.draw(pop_cultureButton);
    window.draw(video_gamesButton);
}
