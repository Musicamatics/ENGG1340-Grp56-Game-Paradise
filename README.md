# Game_Paradise
Welcome to Game Paradise!
This is a simple implementation of the Wordle Game and the classic Snake Game  in C++.
You may choose what you want to play from the game menu.

## Description
Wordle:
A replica of the “Wordle” game, which is a video game purchased by the New York Times. The player has a total of 6 chances to guess a 5 letter word. Make your guess wisely and good luck in finding the word in 6 tries!
You may find detailed instructions in the program when you launch it.

Snake Game:
An implementation of the classical Snake Game, which started out as Blockade, an arcade video game published by game manufacturer Gremlin Industries. The player controls a snake that moves around the board, trying to eat fruits that appear at random locations. Eating each fruit would award the player 1 point. The game ends when the snake collides with the board boundary or with its own body. Press 'w', 'a', 's', or 'd' followed by Enter to move. Please press one key at a time.

## Installation
To compile the game, you need a C++ compiler that supports C++11. You can compile the game with the following command:

```bash
g++ -std=c++11 main.cpp wordle_main.cpp wordle.cpp snake_game.cpp Snake.cpp userinput.cpp -o game_paradise
```

You can start the game with the following command:
```
./game_paradise
```

