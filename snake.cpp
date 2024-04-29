#include "snake.h"
//#include <ncurses.h>
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

    // Initialize the snake
    game.snake.head = {game.width / 2, game.height / 2};  // Start at the center of the board
    game.snake.body.clear();  // Make sure the snake has no body parts to start with
    game.snake.direction = Direction::RIGHT;  // Start moving right
    game.snake.ateFruit = false;

    // Initialize the fruit
    game.fruit.x = rand() % game.width;
    game.fruit.y = rand() % game.height;
}

void Snake::ChangeDirection(Direction newDirection) {
    // Don't allow the snake to reverse direction
    /*
    if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT)) {
        direction = newDirection;
    }
    */
    if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT)) {
        direction = newDirection;
        validInput = true;  // Add this line
    } else {
        validInput = false;  // Add this line
    }
}

void Snake::Move() {
    // Move the body
    /* for (int i = body.size() - 1; i > 0; --i) {
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
    */
   if (validInput) {  // Add this line
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
}

bool Snake::CheckCollision(const Game& game) {
    // Check if the snake's head is out of bounds
    if (head.x < 0 || head.y < 0 || head.x >= game.width || head.y >= game.height) {
        return true;
    }

    // Check if the snake's head is colliding with its body
    for (const Point& part : body) {
        if (head == part) {
            return true;
        }
    }

    // No collision detected
    return false;
}

/*
void UpdateGame(Game& game) {
    game.snake.Move(); // Move the snake
    if (game.snake.CheckCollision(game)) {
        game.over = true;
        return;
    }

    if (game.snake.head.x == game.fruit.x && game.snake.head.y == game.fruit.y) {
        game.snake.EatFruit(); // Let the snake eat the fruit
        game.score++;  // Increment the score
        // Add a new segment to the snake's body (growing the snake)
        Point newSegment = game.snake.body.empty() ? game.snake.head : game.snake.body.back();
        game.snake.body.push_back(newSegment);

        // Generate new coordinates for the fruit
        game.fruit.x = rand() % game.width;
        game.fruit.y = rand() % game.height;
    }
}
*/

void UpdateGame(Game& game) {
    if (game.snake.validInput) {
        game.snake.Move(); // Move the snake
        if (game.snake.CheckCollision(game)) {
            game.over = true;
            return;
        }

        if (game.snake.head.x == game.fruit.x && game.snake.head.y == game.fruit.y) {
            game.snake.EatFruit(); // Let the snake eat the fruit
            game.score++;  // Increment the score
            // Add a new segment to the snake's body (growing the snake)
            Point newSegment = game.snake.body.empty() ? game.snake.head : game.snake.body.back();
            game.snake.body.push_back(newSegment);

            // Generate new coordinates for the fruit
            game.fruit.x = rand() % game.width;
            game.fruit.y = rand() % game.height;
        }
    } else {
        // Reset validInput to true for the next round of input
        game.snake.validInput = true;
    }
}

void RenderGame(const Game& game) {
    // Print blank lines to separate the old and new board
    for (int i = 0; i < 50; ++i) {
        std::cout << "\n";
    }

    // Print the instructions only the first time the game is rendered
    static bool firstTime = true;
    if (firstTime) {
        std::cout << "Instructions: Press 'w', 'a', 's', or 'd' followed by Enter to move. \n";
        std::cout << "Please press one key at a time. \n";
        firstTime = false;
    }

    // Print the score
    std::cout << "Score: " << game.score << "\n";

    // Print the upper border
    for (int i = 0; i < game.width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << "\n";

    for (int y = 0; y < game.height; ++y) {
        std::cout << "#";  // Print the left border
        for (int x = 0; x < game.width; ++x) {
            Point p = {x, y};
            if (p == game.snake.head) {
                std::cout << "O";  // Print the snake's head
            } else if (p == game.fruit) {
                std::cout << "F";  // Print the fruit
            } else {
                bool printed = false;
                for (const Point& part : game.snake.body) {
                    if (part != game.snake.head && p == part) {
                        std::cout << "o";  // Print the snake's body
                        printed = true;
                        break;
                    }
                }
                if (!printed) {
                    std::cout << " ";  // Print an empty space
                }
            }
        }
        std::cout << "#\n";  // Print the right border and move to the next line
    }

    // Print the bottom border
    for (int i = 0; i < game.width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << "\n";

    std::cout.flush();  // Flush the output buffer to show the changes
}
    
    /*clear();  // Clear the screen

    // Print the top border
    for (int i = 0; i < game.width + 2; ++i) {
        printw("#");
    }
    printw("\n");

        // Clear the screen
    for (int i = 0; i < 100; ++i) {
        std::cout << "\n";
    } */

    // Print the top border
    /* for (int i = 0; i < game.width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << "\n";

    // Print the game board
    for (int y = 0; y < game.height; ++y) {
        printw("#");  // Print the left border
        for (int x = 0; x < game.width; ++x) {
            Point p = {x, y};
            if (p == game.snake.head) {
                printw("O");  // Print the snake's head
            } else if (p == game.fruit) {
                printw("F");  // Print the fruit
            } else {
                bool printed = false;
                for (const Point& part : game.snake.body) {
                    if (part != game.snake.head && p == part) {
                        printw("o");  // Print the snake's body
                        printed = true;
                        break;
                    }
                }
                if (!printed) {
                    printw(" ");  // Print an empty space
                }
            }
        }
        printw("#\n");  // Print the right border and move to the next line
    }

    // Print the bottom border
    for (int i = 0; i < game.width + 2; ++i) {
        printw("#");
    }
    printw("\n");

    refresh();  // Refresh the screen to show the changes
} */



/*int SetDifficulty() {
   int difficulty;
    std::cout << "Enter difficulty level (1-3): ";
    std::cin >> difficulty;
    return difficulty;
}*/