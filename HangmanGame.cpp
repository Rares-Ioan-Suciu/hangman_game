#include "HangmanGame.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

HangmanGame::HangmanGame(const std::vector<std::string>& wordList, int maxAttempts)
        : maxAttempts(maxAttempts), attemptsLeft(maxAttempts) {
    srand(time(0));
    int randomIndex = rand() % wordList.size();
    secretWord = wordList[randomIndex];
    guessedWord = std::string(secretWord.length(), '_');
}

bool HangmanGame::isGameOver() const {
    return attemptsLeft <= 0 || guessedWord == secretWord;
}

void HangmanGame::displayGameStatus() const {
    std::cout << "Secret Word: " << guessedWord << std::endl;
    std::cout << "Attempts Left: " << attemptsLeft << std::endl;
    std::cout << "Guessed Letters: ";
    for (char letter : guessedLetters) {
        std::cout << letter << " ";
    }
    std::cout << std::endl;
}

void HangmanGame::guessLetter(char letter) {
    if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
        std::cout << "You already guessed that letter." << std::endl;
        return;
    }
    guessedLetters.push_back(letter);
    if (secretWord.find(letter) != std::string::npos) {
        updateGuessedWord(letter);
    } else {
        --attemptsLeft;
        std::cout << "Incorrect guess. Attempts left: " << attemptsLeft << std::endl;
    }
}

void HangmanGame::updateGuessedWord(char letter) {
    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] == letter) {
            guessedWord[i] = letter;
        }
    }
}
