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

struct Game;

struct Snake {
    Point head;
    std::vector<Point> body;
    Direction direction;
    bool ateFruit;
    bool validInput = true; // Added to check if the input is valid
    Snake();
    
    void ChangeDirection(Direction newDirection);
    void EatFruit();
    bool CheckCollision(const Game& game); // Now the compiler knows that Game is a type
    void Move();

    bool IsValidInput() const {
        return validInput;
    }
};

struct Game {
    Snake snake;
    Point fruit;
    int width;
    int height;
    bool over;
    int score = 0;
    Game() : over(false) {}
};


void InitializeGame(Game& game);
void UpdateGame(Game& game);
void RenderGame(const Game& game);
void HandleUserInput(Game& game);
void playSnakeGame();
int SetDifficulty();
void UserInput(Game& game);

#endif