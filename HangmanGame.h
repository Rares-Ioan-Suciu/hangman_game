#ifndef HANGMAN_PP_HANGMANGAME_H
#define HANGMAN_PP_HANGMANGAME_H


#include <vector>
#include <string>

#include <string>
#include <vector>

class HangmanGame {
public:
    HangmanGame(const std::vector<std::string>& wordList, int maxAttempts);

    bool isGameOver() const;
    void displayGameStatus() const;
    void guessLetter(char letter);

private:
    std::string secretWord;
    std::string guessedWord;
    std::vector<char> guessedLetters;
    int maxAttempts;
    int attemptsLeft;

    void updateGuessedWord(char letter);
};


#endif //HANGMAN_PP_HANGMANGAME_H