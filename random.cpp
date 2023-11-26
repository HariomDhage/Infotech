#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "Try to guess the secret number between 1 and 100." << endl;

    while (true) {
        // Get user input for the guess
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        // Compare the user's guess with the secret number
        if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}
