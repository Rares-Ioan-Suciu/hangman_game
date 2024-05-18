#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "GameScreen.h"

std::string constructFilePath(const std::string& category, const std::string& difficulty) {
    std::cout << "words_" + category + "_" + difficulty + ".txt";
    return "words_" + category + "_" + difficulty + ".txt";
}

std::string loadRandomWordFromFile(const std::string& filePath) {
    std::vector<std::string> words;
    std::ifstream file(filePath);
    std::string word;

    if (file.is_open()) {
        while (std::getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cerr << "Error opening file: " << filePath << "\n";
    }

    if (words.empty()) {
        return ""; // Return an empty string if no words are found
    }

    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Return a random word
    return words[std::rand() % words.size()];
}

bool areAllLettersGuessed(const std::string& word, const std::vector<char>& guessedLetters) {
    // Skip the first and last letters as they are automatically revealed
    for (size_t i = 1; i < word.size() - 1; ++i) {
        char c = word[i];
        if (std::isalpha(c) && std::find(guessedLetters.begin(), guessedLetters.end(), std::tolower(c)) == guessedLetters.end()) {
            return false;
        }
    }
    return true;
}

GameScreen::GameScreen(GameApp& app, const std::string& category, const std::string& difficulty)
        : incorrectGuessCount(0), maxIncorrectGuesses(6), gameMessage("Enter your guess: "), isGuessingWord(false), app(app), score(0) {
    // Determine the file path based on category and difficulty
    std::string filePath = constructFilePath(category, difficulty);
    correctWord = loadRandomWordFromFile(filePath);

    // Check if the word was loaded successfully
    if (correctWord.empty()) {
        std::cerr << "Error loading word for category: " << category << ", difficulty: " << difficulty << "\n";
        correctWord = "HANGMAN"; // Fallback word
    }

    // Add first and last letters to guessed letters
    if (!correctWord.empty()) {
        guessedLetters.push_back(correctWord.front());
        if (correctWord.size() > 1) {
            guessedLetters.push_back(correctWord.back());
        }
    }

    // Initialize font and text for displaying input characters
    if (!font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf")) {
        std::cerr << "Error loading font\n";
    }
    userInputText.setFont(font);
    userInputText.setCharacterSize(24);
    userInputText.setFillColor(sf::Color::Black);
    userInputText.setPosition(20, 20);
    userInputText.setString("Input: "); // Ensure "Input: " is shown at the beginning

    // Initialize score text
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(1000, 100);
    scoreText.setString("Score: " + std::to_string(score));
}

void GameScreen::handleEvent(const sf::Event& event, sf::RenderWindow& window, GameState& gameState, bool& gameStateChanged) {
    if (event.type == sf::Event::Closed) {
        window.close();
    } else if (event.type == sf::Event::TextEntered) {
        if (static_cast<char>(event.text.unicode) == '1') {
            isGuessingWord = !isGuessingWord;
            gameMessage = isGuessingWord ? "Enter the word: " : "Enter your guess: ";
            userInput.clear();
        } else if (event.text.unicode < 128 && event.text.unicode != '\r' && event.text.unicode != '\b') {
            char enteredChar = static_cast<char>(event.text.unicode);
            if (isGuessingWord) {
                // Allow all characters for word input
                if (userInput.size() < correctWord.size()) {
                    userInput += enteredChar;
                }
            } else {
                // Allow only letters for single letter guess
                if (std::isalpha(enteredChar)) {
                    enteredChar = std::tolower(enteredChar); // Convert to lowercase for comparison
                    if (userInput.empty()) {
                        userInput += enteredChar;
                    }
                }
            }
        } else if (event.text.unicode == '\b' && !userInput.empty()) {
            userInput.pop_back();
        } else if (event.text.unicode == '\r') {
            if (isGuessingWord) {
                std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); // Convert to lowercase for comparison
                std::string lowerCorrectWord = correctWord;
                std::transform(lowerCorrectWord.begin(), lowerCorrectWord.end(), lowerCorrectWord.begin(), ::tolower);
                if (userInput == lowerCorrectWord) {
                    gameMessage = "Congratulations! You guessed the word correctly: " + correctWord;
                    gameState = GameState::GameWon;
                    gameStateChanged = true;
                    score += 100; // Add points for guessing the word
                    scoreText.setString("Score: " + std::to_string(score)); // Update score display
                    std::cout << "Game won: " << correctWord << std::endl; // Debug output
                } else {
                    gameMessage = "Incorrect! Enter your guess: ";
                    ++incorrectGuessCount;
                    if (incorrectGuessCount >= maxIncorrectGuesses) {
                        gameMessage = "You lose! The correct word was: " + correctWord;
                        gameState = GameState::GameLost;
                        app.set_correct(correctWord);
                        gameStateChanged = true;
                        std::cout << "Game lost: " << correctWord << std::endl; // Debug output
                    }
                }
            } else {
                if (!userInput.empty()) {
                    char guessedLetter = userInput.front();
                    guessedLetter = std::tolower(guessedLetter); // Convert to lowercase for comparison
                    if (std::find(guessedLetters.begin(), guessedLetters.end(), guessedLetter) == guessedLetters.end()) {
                        guessedLetters.push_back(guessedLetter);
                        bool letterGuessed = false;
                        for (char c : correctWord) {
                            if (std::tolower(c) == guessedLetter) {
                                letterGuessed = true;
                                break;
                            }
                        }
                        if (letterGuessed) {
                            gameMessage = "Letter guessed correctly!";
                            score += 10; // Add points for correct letter guess
                            scoreText.setString("Score: " + std::to_string(score)); // Update score display
                        } else {
                            gameMessage = "Incorrect letter!";
                            ++incorrectGuessCount;
                            if (incorrectGuessCount >= maxIncorrectGuesses) {
                                gameMessage = "You lose! The correct word was: " + correctWord;
                                gameState = GameState::GameLost;
                                app.set_correct(correctWord);
                                gameStateChanged = true;
                                std::cout << "Game lost: " << correctWord << std::endl; // Debug output
                            }
                        }

                        // Check if all letters are guessed
                        if (areAllLettersGuessed(correctWord, guessedLetters)) {
                            gameMessage = "Congratulations! You guessed all letters correctly!";
                            gameState = GameState::GameWon;
                            gameStateChanged = true;
                            score += 50; // Add bonus points for guessing all letters
                            scoreText.setString("Score: " + std::to_string(score)); // Update score display
                            std::cout << "Game won: " << correctWord << std::endl; // Debug output
                        }
                    } else {
                        gameMessage = "You already guessed that letter!";
                    }
                }
            }
            userInput.clear();
        }
    }
}

void GameScreen::update(sf::RenderWindow& window) {
    userInputText.setString("Input: " + userInput);
}

void GameScreen::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White); // Clear the window to a white background

    renderer.drawHangman(window, incorrectGuessCount);

    std::string displayWord;
    for (size_t i = 0; i < correctWord.size(); ++i) {
        char c = correctWord[i];
        // Always display the first and last letters and non-letter characters
        if (i == 0 || i == correctWord.size() - 1 || !std::isalpha(c)) {
            displayWord += c;
        } else if (std::find(guessedLetters.begin(), guessedLetters.end(), std::tolower(c)) != guessedLetters.end()) {
            displayWord += c;
        } else {
            displayWord += "_";
        }
        displayWord += " ";
    }
    renderer.renderWord(window, displayWord);

    renderer.renderMessage(window, gameMessage);
    renderer.renderInstructions(window, "Press '1' to switch between letter and word guessing");

    window.draw(userInputText);
    window.draw(scoreText); // Draw the score

    window.display(); // Display the updated content on the window
}
