# Connect Four Game

## Overview  
A simple **Connect Four** game implemented in **C++**, where two players take turns dropping tokens into a 4x4 grid, aiming to connect four in a row, column, or diagonal to win.

## Features  
- **Two-player mode** with turn-based gameplay.
- **Randomized coin toss** for deciding who starts.
- **Input validation** to prevent invalid moves.
- **Win detection** for all possible connections.
- **Draw detection** when the board is full.

## Setup & Installation  
### Prerequisites  
- **C++ compiler** (GCC, MSVC, Clang, etc.) installed.

### Steps  
1. Clone the repository:
   ```sh
   git clone https://github.com/Ehsan-Tanvir/connect-four-game.git
   ```
2. Compile the code:
   ```sh
   g++ connect_four.cpp -o connect_four
   ```
3. Run the game:
   ```sh
   ./connect_four
   ```

## How to Play  
1. Start the game and choose an option from the menu.
2. Players **take turns** entering a column number (0-3).
3. The game detects a **win condition** or **draw**.
4. The first player to connect four pieces **wins**!
5. If the board is full, the game ends in a **draw**.
