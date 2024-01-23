#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
  // Seed the random number generator with the current time
  srand(time(0));

  // Generate the secret number between 1 and 1000 (inclusive)
  int secretNumber = rand() % 1000 + 1;

  // Create an array to store the user's guesses
  int guesses[1000];

  // Initialize the guess count to 0
  int guessCount = 0;

  // Prompt the user to guess the number
  cout << "Guess the number (between 1 and 1000): ";

  // Keep track of the user's guesses until they guess the secret number or reach the maximum number of guesses
  while (guessCount < 1000) {
    // Read the user's guess as an integer
    int guess;
    bool isValidInput = false;

    // Keep prompting the user for a valid input until they enter an integer
    while (!isValidInput) {
      if (cin >> guess) {
        isValidInput = true;
      } else {
        // Clear the error flags
        cin.clear();

        // Ignore the invalid input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Prompt the user to enter an integer again
        cout << "Invalid input. Please enter an integer: ";
      }
    }

    // Store the user's guess in the guesses array
    guesses[guessCount] = guess;

    // Increment the guess count
    guessCount++;

    // Check if the user's guess is lower, higher, or equal to the secret number
    if (guess < secretNumber) {
      // Print "Too low. Try again: "
      cout << "Too low. Try again: ";
    } else if (guess > secretNumber) {
      // Print "Too high. Try again: "
      cout << "Too high. Try again: ";
    } else {
      // Print "Correct! You guessed the number in " followed by the number of guesses
      cout << "Correct! You guessed the number in " << guessCount << " tries.\n";

      // Break out of the loop
      break;
    }
  }

  // If the user has made 1000 guesses and hasn't guessed the secret number correctly, print "You didn't guess the number. The number was " followed by the secret number
  if (guessCount == 1000) {
    cout << "You didn't guess the number. The number was " << secretNumber << ".\n";
  }

  // Print "Your guesses were: " followed by the user's guesses separated by spaces
  cout << "Your guesses were: ";
  for (int i = 0; i < guessCount; i++) {
    cout << guesses[i] << " ";
  }
  cout << endl;

  // Return 0 to indicate that the program has executed successfully
  return 0;
}