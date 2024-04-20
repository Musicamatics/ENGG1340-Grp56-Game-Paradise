#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <cstdlib>
#include <ctime>

struct Point {
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Snake {
    Point head;
    std::vector<Point> body;
    Direction direction;
    bool ateFruit;
    Snake();

    void ChangeDirection(Direction newDirection);
    void EatFruit();
    bool CheckCollision(const Game& game);
    void Move();
};

struct Game {
    Snake snake;
    Point fruit;
    int width;
    int height;
    bool over;

    Game();
};


void InitializeGame(Game& game);
void UpdateGame(Game& game);
void RenderGame(const Game& game);
void HandleUserInput(Game& game);

int SetDifficulty();
void UserInput(Game& game);

#endif