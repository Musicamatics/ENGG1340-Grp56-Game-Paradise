#include "snake.h"
#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>

void GameLoop() {
    // Initialize the game
    Game game;
    InitializeGame(game);

    // Set up ncurses
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);

    // Game loop
    while (!game.over) {
        // Handle user input
        int key = getch();
        if (key == KEY_UP) {
            game.snake.ChangeDirection(Direction::UP);
        } else if (key == KEY_DOWN) {
            game.snake.ChangeDirection(Direction::DOWN);
        } else if (key == KEY_LEFT) {
            game.snake.ChangeDirection(Direction::LEFT);
        } else if (key == KEY_RIGHT) {
            game.snake.ChangeDirection(Direction::RIGHT);
        }

        // Update the game state
        UpdateGame(game);

        // Render the game board
        RenderGame(game);

        // Wait for a short duration to control the speed of the game
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Clean up ncurses
    endwin();
}

int main() {
    // Call the game loop
    GameLoop();

    return 0;
}
