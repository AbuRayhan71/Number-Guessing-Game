#include <iostream>
#include <cstdlib>
#include <ctime>

void printProximityHint(int guess, int secretNumber) {
    // Function to provide hints to the player
    int diff = abs(secretNumber - guess);
    if (diff >= 50) std::cout << "You are very cold.\n";
    else if (diff >= 20) std::cout << "You are cold.\n";
    else if (diff >= 10) std::cout << "You are warm.\n";
    else std::cout << "You are hot!\n";
}

int main() {
    srand(time(0));
    
    int difficulty, maxNumber, maxGuesses;
    char playAgain;

    do {
        std::cout << "Select Difficulty Level (1- Easy, 2- Medium, 3- Hard): ";
        std::cin >> difficulty;

        switch (difficulty) {
            case 1: maxNumber = 50; maxGuesses = 10; break;
            case 2: maxNumber = 100; maxGuesses = 7; break;
            case 3: maxNumber = 200; maxGuesses = 5; break;
            default: maxNumber = 100; maxGuesses = 7; // Default to Medium
        }

        int secretNumber = rand() % maxNumber + 1;
        int guessCount = 0;
        bool guessedCorrectly = false;

        std::cout << "Guess the number (between 1 and " << maxNumber << "): ";

        while (guessCount < maxGuesses) {
            int guess;
            std::cin >> guess;
            guessCount++;

            if (guess < secretNumber) {
                std::cout << "Too low. ";
                printProximityHint(guess, secretNumber);
            } else if (guess > secretNumber) {
                std::cout << "Too high. ";
                printProximityHint(guess, secretNumber);
            } else {
                std::cout << "Correct! You guessed the number in " << guessCount << " tries.\n";
                guessedCorrectly = true;
                break;
            }
        }

        if (!guessedCorrectly) {
            std::cout << "Sorry, you did not guess the number. It was " << secretNumber << ".\n";
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}
