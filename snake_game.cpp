//#include <ncurses.h>
#include "snake.h"
#include <iostream>
using namespace std;

void playSnakeGame() {
    srand(time(NULL));

    //initscr();  // Initialize ncurses
    //cbreak();   // Disable line buffering
    //noecho();   // Turn off echo
    //keypad(stdscr, TRUE);  // Enable function and arrow keys

    Game game;
    InitializeGame(game);

    while (!game.over) {
        RenderGame(game);
        UserInput(game);
        UpdateGame(game);
    }

    //endwin();  // End ncurses mode

    std::cout << "Game Over! Press any key to exit." << std::endl;
    std::cin.get();
}
