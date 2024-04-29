# Game Paradise

Welcome to Game Paradise!

This is a simple implementation of two classic games: Wordle and Snake, programmed in C++. You can choose which game you want to play from the game menu.

## Contributions:
### Wordle:
@yburnachs
@youarethexie

### Snake Game:
@Musicamatics
@FungCT
@LeungLongHey

## Description

### Wordle:
A replica of the "Wordle" game, originally published by the New York Times. In this game, you have 6 chances to guess a 5-letter word. Guess wisely and good luck! Detailed instructions are provided within the program.

### Snake Game:
An implementation of the classic Snake Game, which originated as Blockade, an arcade video game by Gremlin Industries. You control a snake moving around the board, eating fruits that appear at random locations. Each fruit eaten earns you 1 point. The game ends when the snake collides with the board boundary or its own body. Use 'w', 'a', 's', or 'd' followed by Enter to move the snake. Note: only one key press is considered per input.


## List of Features
### Wordle:

### Snake Game:

#### Input Validity:
To handle the validity of user input in the Snake game, several coding elements are employed:

1. **UserInput Function in userinput.cpp**:
   ```cpp
   char ch; 
   std::cin >> ch;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   switch (ch) {
       // Cases for valid inputs: 'w', 's', 'a', 'd'
       // Other cases are considered invalid
   }
   ```
   - This function reads a single character from the user input and ignores the rest of the line.
   - The switch statement checks if the input is one of the valid directions ('w', 's', 'a', 'd'). Any other input is considered invalid.
   
2. **IsValidInput() Method in snake.h**:
   ```cpp
   bool IsValidInput() const {
       return validInput;
   }
   ```
   - This method returns whether the last user input was valid or not.

3. **Switch Statement in UserInput Function**:
   - Within the switch statement in the UserInput function, input that asks the snake to go in the opposite direction is explicitly considered invalid. This is achieved by not including cases for opposite directions.
   - For example, if the current direction is UP, input 's' (DOWN) and 'a' (LEFT) are valid, but 'w' (UP) and 'd' (RIGHT) are invalid as they are opposite directions.

4. **Boolean Flag in Snake Structure**:
   - The `validInput` boolean flag within the Snake structure is used to keep track of whether the last user input was valid. This flag is updated based on the user input handling logic.

By utilizing these coding elements, the program ensures that user input is validated according to the specified criteria:
- Valid inputs ('w', 's', 'a', 'd') are accepted.
- Inputs with more than one character are handled by only considering the first character, making them still valid if the first character is one of the valid directions ('w', 's', 'a', 'd').
- Inputs asking the snake to go in the opposite direction are explicitly considered invalid.

### Random Placement of Fruit:
For the feature of random placement of the fruit in the Snake game, the following coding elements are utilized:

1. **rand() Function**:
   ```cpp
   game.fruit.x = rand() % game.width;
   game.fruit.y = rand() % game.height;
   ```
   - This code generates random coordinates for the fruit within the boundaries of the game board.
   - `rand()` generates a pseudo-random integer, and `%` operator is used to limit the range within the width and height of the game board.

2. **UpdateGame(Game& game) Function in snake.cpp**:
   ```cpp
   if (game.snake.head.x == game.fruit.x && game.snake.head.y == game.fruit.y) {
       // Code to handle snake eating the fruit
       // Increment the score
       // Add a new segment to the snake's body
       // Generate new coordinates for the fruit
   }
   ```
   - Within the `UpdateGame` function, when the snake head reaches the position of the fruit, indicating that the snake has eaten the fruit, new coordinates for the fruit are generated randomly.
   - This ensures that the fruit is placed randomly on the game board each time it is consumed by the snake, adding unpredictability to the game.

The program effectively implements the feature of random placement of the fruit, contributing to the dynamic and engaging gameplay experience of the Snake game.

### Program Codes in Multiple Files:
We have separated the game logic into different modules for better organisation and modularity.

   - **Implementation**:
     - `snake.cpp` for snake-related logic
     - `userinput.cpp` for user input handling
     - `snake_game.cpp` for the main game loop and rendering
     - `snake.h` for header declarations and definitions

This can enhance the functionality and complexity of the game while maintaining a structured and manageable codebase.

### Dynamic Memory Management:

In the Snake game, dynamic memory management is crucial for handling the snake's body as it grows when it eats fruits. The `std::vector<Point> body` within the `Snake` struct efficiently manages memory allocation and deallocation for the snake's body segments.

**Feature Overview**:
- When the snake eats a fruit, a new segment is added to its body, extending its length.
- The `std::vector<Point>` automatically handles memory allocation and deallocation as the snake's body grows or shrinks.
- Memory reallocation occurs transparently to the programmer, ensuring efficient usage of memory resources without manual intervention.

**Corresponding Coding Element**:
- Utilizing the `std::vector` container from the C++ Standard Library for dynamic array management.
- The `std::vector` dynamically allocates memory as needed, resizing itself to accommodate new elements.

**Example Implementation**:
```cpp
struct Snake {
    Point head;
    std::vector<Point> body; // Represents the snake's body
    Direction direction;
    bool ateFruit;
    bool validInput = true; // Added to check if the input is valid

    Snake(); // Constructor
    
    // Other member functions...

    void EatFruit() {
        // Add a new segment to the snake's body
        // The vector automatically handles memory allocation
        body.push_back(Point()); // Example: adding a new segment
    }
};
```

By leveraging the `std::vector` container, the program efficiently manages memory for the snake's body, ensuring scalability and robustness in handling dynamic changes in the game state. This feature contributes to the smooth and seamless gameplay experience of the Snake game.

### File Input/Output:

In the Snake game, file input/output is utilized to manage the highest score. The `ReadHighestScore` function reads the highest score from a file, while the `WriteHighestScore` function writes the highest score to a file. Both functions utilize the `std::ifstream` and `std::ofstream` classes from the C++ standard library for file input/output operations.

**Code Overview**:
- `ReadHighestScore`: Reads the highest score from the file "highest_score.txt". If the file doesn't exist, it returns 0.
- `WriteHighestScore`: Writes the highest score to the file "highest_score.txt".

**Corresponding Coding Element**:
- Utilizing the `std::ifstream` and `std::ofstream` classes for file input/output operations.

**Example Implementation**:
```cpp
// Read the highest score from a file
int ReadHighestScore() {
    std::ifstream file("highest_score.txt");
    if (!file) {
        return 0;  // If the file doesn't exist, return 0
    }
    int highestScore;
    file >> highestScore;
    return highestScore;
}

// Write the highest score to a file
void WriteHighestScore(int highestScore) {
    std::ofstream file("highest_score.txt");
    file << highestScore;
    file.close();
}
```

These functions facilitate persistent storage of the highest score across game sessions, enhancing the gameplay experience by maintaining a record of the player's achievements.

### Data structures for storing game status: The Game structure stores the game status, including the snake's position and direction, the fruit's position, and the score. The Snake structure uses a std::vector (an STL container) to store the body of the snake.

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


## Enjoy playing!
