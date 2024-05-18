//
// Created by rares655 on 5/15/24.
//

#ifndef HANGMAN_PP_RENDERER_H
#define HANGMAN_PP_RENDERER_H

#include <SFML/Graphics.hpp>
#include <string>

class HangmanRenderer {
public:
    HangmanRenderer();
    void drawHangman(sf::RenderWindow& window, int incorrectGuessCount) const;
    void renderWord(sf::RenderWindow& window, const std::string& guessedWord) const;
    void renderMessage(sf::RenderWindow& window, const std::string& message) const;
    void renderInstructions(sf::RenderWindow& window, const std::string& instructions);


private:
    sf::Font font;
};

#endif //HANGMAN_PP_RENDERER_H
