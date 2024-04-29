#include <iostream>
#include <string>
#include "wordle.h"
#include "snake.h"

using namespace std;

int main() {
    int choice;

    // Display the game menu
    cout << "Welcome to the Game Menu!" << endl;
    cout << "Choose a game to play:" << endl;
    cout << "1. Wordle" << endl;
    cout << "2. Snake Game" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Based on user choice, launch the corresponding game
    switch(choice) {
        case 1:
            // Launch Wordle
            cout << "Launching Wordle..." << endl;
            // Call the function to start Wordle game
            playWordle();
            break;
        case 2:
            // Launch Snake Game
            cout << "Launching Snake Game..." << endl;
            // Call the function to start Snake Game
            playSnakeGame();
            break;
        default:
            // Invalid choice
            cout << "Invalid choice! Exiting..." << endl;
            break;
    }

    return 0;
}
