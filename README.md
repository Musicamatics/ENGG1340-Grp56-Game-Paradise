# Game Paradise

Welcome to Game Paradise!

This is a simple implementation of two classic games: Wordle and Snake, programmed in C++. You can choose which game you want to play from the game menu.

## Description

### Wordle:
A replica of the "Wordle" game, originally published by the New York Times. In this game, you have 6 chances to guess a 5-letter word. Guess wisely and good luck! Detailed instructions are provided within the program.

### Snake Game:
An implementation of the classic Snake Game, which originated as Blockade, an arcade video game by Gremlin Industries. You control a snake moving around the board, eating fruits that appear at random locations. Each fruit eaten earns you 1 point. The game ends when the snake collides with the board boundary or its own body. Use 'w', 'a', 's', or 'd' followed by Enter to move the snake. Note: only one key press is considered per input.

#### Input Validity:
We ensure the validity of inputs in two ways:
1. Only the first character of input is considered for movement. For example, 'wa' or 'was' will result in only 'w' (forward movement) being considered. Inputs lacking 'w', 'a', 's', or 'd' as the first character are regarded as invalid.
2. Inputs with opposite directions (e.g., 'w' followed by 's') are considered invalid but do not immediately end the game. The game ends only if the snake collides with the board boundary or itself.

## Installation
To compile the game, you need a C++ compiler that supports C++11. Here's the compilation command:

```bash
g++ -std=c++11 main.cpp wordle_main.cpp wordle.cpp snake_game.cpp Snake.cpp userinput.cpp -o game_paradise
```

To start the game, execute the following command:
```bash
./game_paradise
```

**Note:** This game is recommended for Linux environments.

## Contributions:
### Wordle:
@yburnachs
@youarethexie

### Snake Game:
@Musicamatics
@FungCT
@LeungLongHey

## Enjoy playing!
