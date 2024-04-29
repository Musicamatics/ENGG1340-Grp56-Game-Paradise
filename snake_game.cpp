#include "snake.h"
#include <iostream>
using namespace std;

void playSnakeGame() {
    srand(time(NULL));

    Game game;
    InitializeGame(game);

    while (!game.over) {
        RenderGame(game);
        UserInput(game);
        UpdateGame(game);
    }

    // Check if the current score exceeds the highest score
    if (game.score > game.highestScore) {
        std::cout << "Congratulations, you beat the previous highest score of " << game.highestScore << "!\n";
        game.highestScore = game.score;  // Update the highest score
        WriteHighestScore(game.highestScore);  // Save the new highest score
    } else {
        std::cout << "The highest score is " << game.highestScore << ".\n";
    }

    std::cout << "Game Over! Press any key to exit." << std::endl;
    std::cin.get();
}
