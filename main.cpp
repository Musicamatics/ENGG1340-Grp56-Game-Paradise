#include <ncurses.h>
#include "snake.h"
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));

    initscr();  // Initialize ncurses
    cbreak();   // Disable line buffering
    noecho();   // Turn off echo
    keypad(stdscr, TRUE);  // Enable function and arrow keys

    Game game;
    InitializeGame(game);

    while (!game.over) {
        RenderGame(game);
        UserInput(game);  // Use UserInput instead of HandleUserInput
        UpdateGame(game);
    }

    endwin();  // End ncurses mode

    std::cout << "Game Over!" << std::endl;
    return 0;
}