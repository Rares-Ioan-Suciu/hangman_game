
#ifndef HANGMAN_PP_MAINMENU_H
#define HANGMAN_PP_MAINMENU_H



#include <SFML/Graphics.hpp>
#include "IScreen.h"

class MainMenu : public IScreen {
public:
    MainMenu();
    void handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
private:
    sf::Font font;
    sf::Text title;
    sf::Text startButton;
};

#endif //HANGMAN_PP_MAINMENU_H
