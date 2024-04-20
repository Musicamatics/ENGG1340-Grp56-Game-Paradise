#include <ncurses.h>
#include "snake.h"

void UserInput(Game& game) {
    int ch = getch();
    if (ch != ERR) {
        switch (ch) {
            case 'w':
                game.snake.ChangeDirection(Direction::UP);  // Use Direction::UP instead of Snake::UP
                break;
            case 's':
                game.snake.ChangeDirection(Direction::DOWN);  // Use Direction::DOWN instead of Snake::DOWN
                break;
            case 'a':
                game.snake.ChangeDirection(Direction::LEFT);  // Use Direction::LEFT instead of Snake::LEFT
                break;
            case 'd':
                game.snake.ChangeDirection(Direction::RIGHT);  // Use Direction::RIGHT instead of Snake::RIGHT
                break;
        }
    }
}