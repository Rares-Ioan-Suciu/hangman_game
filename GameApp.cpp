#include "GameApp.h"
#include "MainMenu.h"
#include "DifficultySelection.h"
#include "CategorySelection.h"
#include "GameScreen.h"
#include "WinScreen.h"
#include "LoseScreen.h"
#include <iostream>

GameApp::GameApp()
        : window(sf::VideoMode::getDesktopMode(), "Hangman Game"), gameState(GameState::MainMenu), gameStateChanged(false) {
    currentScreen = std::make_unique<class MainMenu>();
}

void GameApp::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameApp::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        currentScreen->handleEvent(event, window, gameState, gameStateChanged);

        if (gameStateChanged) {
            std::cout << "Processing gameState change" << std::endl; // Debug output
            switch (gameState) {
                case GameState::MainMenu:
                    currentScreen = std::make_unique<class MainMenu>();
                    break;
                case GameState::DifficultySelection:
                    currentScreen = std::make_unique<class DifficultySelection>(*this);
                    break;
                case GameState::CategorySelection:
                    currentScreen = std::make_unique<class CategorySelection>(*this);
                    break;
                case GameState::Game:
                    currentScreen = std::make_unique<GameScreen>(*this , selectedCategory, selectedDifficulty);
                    break;
                case GameState::GameWon:
                    currentScreen = std::make_unique<WinScreen>();
                    break;
                case GameState::GameLost: {
                    auto loseScreen = std::make_unique<LoseScreen>();
                    loseScreen->setMessage(correct);
                    currentScreen = std::move(loseScreen);
                    break;
                }
                default:
                    break;
            }
            gameStateChanged = false;  // Reset the flag
            std::cout << "Screen changed successfully" << std::endl; // Debug output
        }
    }
}

void GameApp::update() {
    currentScreen->update(window);
}

void GameApp::render() {
    window.clear(sf::Color::White);
    currentScreen->render(window);
    window.display();
}

void GameApp::setSelectedCategory(const std::string& category) {
    selectedCategory = category;
}

void GameApp::setSelectedDifficulty(const std::string& difficulty) {
    selectedDifficulty = difficulty;
}

void GameApp::set_correct(const std::string& correct_word) {

    correct = correct_word;
}