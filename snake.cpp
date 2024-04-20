#include "snake.h"
#include <iostream>
using namespace std;

Snake::Snake() 
    : direction(Direction::UP), ateFruit(false) {
    // Initialize other members...
}

void Snake::EatFruit() {
    ateFruit = true;
}

void InitializeGame(Game& game) {
    game.width = 20;
    game.height = 10;
    game.snake = Snake(); // Create the Snake object using the default constructor
    game.fruit.x = rand() % game.width;
    game.fruit.y = rand() % game.height;
}

void Snake::ChangeDirection(Direction newDirection) {
    // Don't allow the snake to reverse direction
    if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT)) {
        direction = newDirection;
    }
}

void Snake::Move() {
    // Move the body
    for (int i = body.size() - 1; i > 0; --i) {
        body[i] = body[i - 1];
    }
    if (!body.empty()) {
        body[0] = head;
    }

    // Move the head
    switch (direction) {
        case Direction::UP:
            --head.y;
            break;
        case Direction::DOWN:
            ++head.y;
            break;
        case Direction::LEFT:
            --head.x;
            break;
        case Direction::RIGHT:
            ++head.x;
            break;
    }
}

void UpdateGame(Game& game) {
    game.snake.Move(); // Move the snake

    if (game.snake.CheckCollision(game)) {
        game.over = true;
        return;
    }

    if (game.snake.head.x == game.fruit.x && game.snake.head.y == game.fruit.y) {
        game.snake.EatFruit(); // Let the snake eat the fruit
        game.fruit.x = rand() % game.width;
        game.fruit.y = rand() % game.height;
    }
}

void RenderGame(const Game& game) {
    for (int y = 0; y < game.height; y++) {
        for (int x = 0; x < game.width; x++) {
            Point p = {x, y};
            if (p == game.snake.head) {
                std::cout << "O";
            } else if (p == game.fruit) {
                std::cout << "F";
            } else {
                bool printed = false;
                for (const Point& part : game.snake.body) {
                    if (part != game.snake.head && p == part) {
                        std::cout << "o";
                        printed = true;
                        break;
                    }
                }
                if (!printed) {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }
}


int SetDifficulty() {
    // implementation here
}