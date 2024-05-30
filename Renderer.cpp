#include "Renderer.h"
#include <iostream>

HangmanRenderer::HangmanRenderer() {
    if (!font.loadFromFile("C:/Users/daria/source/repos/HangmanGame/HangmanGame/LiberationSans-Regular.ttf")) {
        std::cerr << "Error loading font\n";
    }
}

void HangmanRenderer::drawHangman(sf::RenderWindow& window, int incorrectGuessCount) const {
    // Draw scaffold
    sf::RectangleShape scaffold(sf::Vector2f(200.f, 5.f));
    scaffold.setPosition(50.f, 400.f);
    scaffold.setFillColor(sf::Color::Black);
    window.draw(scaffold);

    // Draw horizontal beam
    sf::RectangleShape beam(sf::Vector2f(100.f, 5.f));
    beam.setPosition(100.f, 400.f);
    beam.setFillColor(sf::Color::Black);
    window.draw(beam);

    // Draw vertical beam
    sf::RectangleShape verticalBeam(sf::Vector2f(5.f, 100.f));
    verticalBeam.setPosition(150.f, 400.f);
    verticalBeam.setFillColor(sf::Color::Black);
    window.draw(verticalBeam);

    // Draw head (if incorrect guesses = 1)
    if (incorrectGuessCount >= 1) {
        sf::CircleShape head(20.f);
        head.setFillColor(sf::Color::Transparent);
        head.setOutlineThickness(2.f);
        head.setOutlineColor(sf::Color::Black);
        head.setPosition(130.f, 450.f);
        window.draw(head);
    }

    // Draw body (if incorrect guesses = 2)
    if (incorrectGuessCount >= 2) {
        sf::RectangleShape body(sf::Vector2f(5.f, 80.f));
        body.setPosition(147.5f, 470.f);
        body.setFillColor(sf::Color::Black);
        window.draw(body);
    }

    // Draw left arm (if incorrect guesses = 3)
    if (incorrectGuessCount >= 3) {
        sf::RectangleShape leftArm(sf::Vector2f(40.f, 5.f));
        leftArm.setPosition(120.f, 480.f);
        leftArm.setRotation(-45.f);
        leftArm.setFillColor(sf::Color::Black);
        window.draw(leftArm);
    }

    // Draw right arm (if incorrect guesses = 4)
    if (incorrectGuessCount >= 4) {
        sf::RectangleShape rightArm(sf::Vector2f(40.f, 5.f));
        rightArm.setPosition(165.f, 480.f);
        rightArm.setRotation(45.f);
        rightArm.setFillColor(sf::Color::Black);
        window.draw(rightArm);
    }

    // Draw left leg (if incorrect guesses = 5)
    if (incorrectGuessCount >= 5) {
        sf::RectangleShape leftLeg(sf::Vector2f(40.f, 5.f));
        leftLeg.setPosition(135.f, 450.f);
        leftLeg.setRotation(-45.f);
        leftLeg.setFillColor(sf::Color::Black);
        window.draw(leftLeg);
    }

    // Draw right leg (if incorrect guesses = 6)
    if (incorrectGuessCount >= 6) {
        sf::RectangleShape rightLeg(sf::Vector2f(40.f, 5.f));
        rightLeg.setPosition(165.f, 450.f);
        rightLeg.setRotation(45.f);
        rightLeg.setFillColor(sf::Color::Black);
        window.draw(rightLeg);
    }
}

void HangmanRenderer::renderWord(sf::RenderWindow& window, const std::string& guessedWord) const {
    sf::Text text;
    text.setFont(font);
    text.setString(guessedWord);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50.f, 50.f);
    window.draw(text);
}

void HangmanRenderer::renderMessage(sf::RenderWindow& window, const std::string& message) const {
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50.f, 100.f);
    window.draw(text);
}

void HangmanRenderer::renderInstructions(sf::RenderWindow& window, const std::string& instructions) {
    sf::Text instructionsText;
    instructionsText.setFont(font);
    instructionsText.setCharacterSize(28);
    instructionsText.setFillColor(sf::Color::Magenta);
    instructionsText.setString(instructions);
    instructionsText.setPosition(20, 500); // Adjust position as needed
    window.draw(instructionsText);
}