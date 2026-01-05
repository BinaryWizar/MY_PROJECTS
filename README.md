================================================================================
                        NUMBER SHIFTING GAME
================================================================================

PROJECT OVERVIEW
--------------------------------------------------------------------------------
A console-based sliding puzzle game implemented in C++ that demonstrates strong
logical programming skills, object-oriented design principles, and efficient
algorithm implementation. This classic puzzle game challenges players to arrange
numbers in sequential order by sliding tiles into an empty space.

GAME DESCRIPTION
--------------------------------------------------------------------------------
The Number Shifting Game is a digital implementation of the classic 15-puzzle
(also known as the sliding puzzle). Players must arrange numbered tiles in
ascending order by strategically moving tiles into the empty space. The game
offers multiple difficulty levels with different board sizes.

FEATURES
--------------------------------------------------------------------------------
✓ Multiple Difficulty Levels:
  - 2x2 Board (Easy)    : 4 tiles
  - 3x3 Board (Medium)  : 9 tiles
  - 4x4 Board (Hard)    : 16 tiles (Classic 15-puzzle)

✓ Intuitive Controls:
  - Arrow Keys for movement (Up, Down, Left, Right)
  - 'Q' key to quit game
  - Real-time move counter

✓ Smart Game Mechanics:
  - Random board generation with unique tile positions
  - Invalid move detection and prevention
  - Win condition verification
  - Move limit tracking

✓ User-Friendly Interface:
  - Clear visual board representation
  - Game rules display before starting
  - Move counter display
  - Win/Loss notifications

TECHNICAL HIGHLIGHTS
--------------------------------------------------------------------------------
This project demonstrates proficiency in:

1. OBJECT-ORIENTED PROGRAMMING (OOP)
   - Abstract base class (gboard) with pure virtual functions
   - Inheritance hierarchy (board2, board3, board4 classes)
   - Encapsulation of game logic and data
   - Polymorphism through virtual functions

2. DATA STRUCTURES & ALGORITHMS
   - Dynamic 2D array implementation using pointers
   - Efficient position tracking algorithms
   - Random number generation with uniqueness validation
   - Optimal search algorithms for empty tile location

3. MEMORY MANAGEMENT
   - Dynamic memory allocation using new/malloc
   - Proper pointer handling and dereferencing
   - Array manipulation and indexing

4. SYSTEM PROGRAMMING
   - Terminal I/O control using termios.h
   - Non-buffered character input (getch implementation)
   - Screen clearing for smooth gameplay
   - Cross-platform considerations (Unix/Linux)

5. GAME LOGIC IMPLEMENTATION
   - Boundary condition checking
   - Win state verification
   - Move validation logic
   - State management

WINNING CONDITION
--------------------------------------------------------------------------------
For 4x4 Board (Default):

 -----------------
 | 1 | 2 | 3 | 4 |
 | 5 | 6 | 7 | 8 |
 | 9 |10 |11 |12 |
 |13 |14 |15 |   |
 -----------------

Numbers must be arranged in ascending order with the empty space in the
bottom-right corner.

HOW TO COMPILE & RUN
--------------------------------------------------------------------------------
REQUIREMENTS:
- C++ Compiler (g++, clang++)
- Unix/Linux/MacOS environment (uses termios.h)

COMPILATION:
g++ -o NumberShifting NumberShifting.cpp

EXECUTION:
./NumberShifting

GAME CONTROLS
--------------------------------------------------------------------------------
↑ (Up Arrow)    : Move tile below empty space upward
↓ (Down Arrow)  : Move tile above empty space downward
← (Left Arrow)  : Move tile right of empty space leftward
→ (Right Arrow) : Move tile left of empty space rightward
Q               : Quit game

CODE STRUCTURE
--------------------------------------------------------------------------------
1. BASE CLASS (gboard)
   - Abstract class defining common game interface
   - Shared utility functions (getch, game_rules)
   - Unique position validation
   - Protected members for inheritance

2. DERIVED CLASSES
   - board2: 2x2 puzzle implementation
   - board3: 3x3 puzzle implementation
   - board4: 4x4 puzzle implementation (Classic 15-puzzle)

3. KEY METHODS
   - create_board()     : Initialize game board with random positions
   - display_board()    : Render current game state
   - move_up/down/left/right() : Handle tile movements
   - win_condition()    : Check if puzzle is solved
   - run_game()         : Main game loop

ALGORITHMIC COMPLEXITY
--------------------------------------------------------------------------------
- Board Generation: O(n²) where n is board dimension
- Empty Tile Search: O(n²) worst case
- Move Validation: O(1) constant time
- Win Verification: O(n²) for complete board scan
- Space Complexity: O(n²) for board storage

LOGICAL CHALLENGES SOLVED
--------------------------------------------------------------------------------
1. Random Board Generation
   - Ensuring all numbers are unique
   - Preventing duplicate tile positions
   - Seeding randomness with system time

2. Movement Logic
   - Boundary detection to prevent invalid moves
   - Coordinate tracking for empty space
   - Bidirectional tile swapping

3. Input Handling
   - Capturing arrow key sequences (escape sequences)
   - Non-blocking character input
   - Terminal mode manipulation

4. Win Condition Detection
   - Sequential number verification
   - Efficient state comparison

FUTURE ENHANCEMENTS
--------------------------------------------------------------------------------
- Solvability check (not all random configurations are solvable)
- Optimal solution path finder using A* algorithm
- Difficulty-based time limits
- High score tracking system
- Hint system for stuck players
- Undo/Redo functionality
- Save/Load game state

LEARNING OUTCOMES
--------------------------------------------------------------------------------
This project showcases:
✓ Strong understanding of C++ fundamentals
✓ Proficiency in OOP concepts and design patterns
✓ Ability to implement complex game logic
✓ Problem-solving skills in algorithm design
✓ Memory management expertise
✓ System-level programming knowledge
✓ Code organization and modularity

AUTHOR
--------------------------------------------------------------------------------
Created to demonstrate logical programming capabilities and problem-solving
skills in C++. This project reflects a solid understanding of data structures,
algorithms, and object-oriented design principles.

LICENSE
--------------------------------------------------------------------------------
Free to use for educational purposes.

CONTACT & CONTRIBUTIONS
--------------------------------------------------------------------------------
Feel free to fork, modify, and enhance this project. Contributions and
suggestions are welcome!

================================================================================
                    Happy Gaming! Good Luck!
================================================================================
