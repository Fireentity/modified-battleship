# Advanced Battleship Game

A C++ implementation of an advanced version of the classic Battleship game, featuring different types of ships with special abilities and computer vs computer or player vs computer gameplay modes.

## Game Overview

This version of Battleship is played on a 12x12 grid where each player has:
- A defense grid for positioning their ships
- An attack grid for tracking shots and sonar detections

### Ships
Each player has 8 ships of three different types:
- 3 Battleships (5 cells long)
  - Action: Fire at target coordinates
- 3 Support Ships (3 cells long)
  - Action: Move and repair friendly ships in a 3x3 area
- 2 Explorer Submarines (1 cell long)
  - Action: Move and detect enemy ships in a 5x5 area

### Game Mechanics
- Ships can be placed horizontally or vertically
- Each turn, a player can perform one action with one ship
- Support ships can repair friendly ships to full health
- Submarines can detect enemy ships (marked as 'Y' on the attack grid)
- Ships are destroyed when all their cells are hit
- Ships move relative to their center cell

## Building the Project

### Prerequisites
- CMake
- C++ Compiler
- C++ Standard Library

### Build Instructions
```bash
mkdir build
cd build
cmake ..
make
```

This will generate two executables:
- `battaglia_navale` (main game)
- `replay` (game replay viewer)

## Running the Game

### Main Game
The game can be run in two modes:

1. Player vs Computer:
```bash
./battaglia_navale pc
```

2. Computer vs Computer:
```bash
./battaglia_navale cc
```

### Replay System
The replay system can be used in two ways:

1. View replay on screen:
```bash
./replay v [log_file_name]
```

2. Save replay to file:
```bash
./replay f [log_file_name] [output_file_name]
```

## Game Commands

### During Gameplay
- Move/Action Command Format: `XYOrigin XYTarget`
  - Example: `B8 G10` (Ship at B8 targets G10)
- Show Game Boards: `XX XX`
- Clear Sonar Detections: `AA AA`

### Ship Placement
At the start of the game, you'll be prompted to place your ships by providing bow and stern coordinates for each ship.
Example:
```
>> Quali sono le coordinate per la corazzata 1:
>> B6 B10
```

## Grid Display

### Defense Grid
- `C`: Battleship
- `S`: Support Ship
- `E`: Explorer Submarine
- Lowercase letters indicate damaged sections

### Attack Grid
- `X`: Hit
- `O`: Miss
- `Y`: Sonar Detection

## Additional Notes
- The game automatically logs all commands to a file
- Computer players make random moves
- Games between computers have a maximum turn limit
- Ships cannot overlap during placement
- Ships can only move within grid boundaries

