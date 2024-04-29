//#include <ncurses.h>
#include "snake.h"
#include <iostream>
#include <limits>

void UserInput(Game& game) {
    char ch;
    std::cin >> ch;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (ch) {
        case 'w':
            game.snake.ChangeDirection(Direction::UP); 
            break;
        case 's':
            game.snake.ChangeDirection(Direction::DOWN);
            break;
        case 'a':
            game.snake.ChangeDirection(Direction::LEFT);
            break;
        case 'd':
            game.snake.ChangeDirection(Direction::RIGHT);
            break;
    }
}