# So Long

A 2D game implementation in C using the MinilibX graphics library, where the player must collect all items and reach the exit to win.

## Description

So Long is a 2D top-down game where you control a ninja character who must collect all shurikens (collectibles) scattered throughout the map before reaching the exit. The game features smooth movement, collision detection, and a graphical interface.

## Installation

Clone the repository and compile with make:

```bash
git clone <repository-url>
cd so_long
make
```

## Usage

Run the program with a map file as argument:

```bash
# Basic usage with a valid map file
./so_long map.ber

# Run with a custom map
./so_long maps/test1.ber
```

### Controls

- **W** - Move up
- **A** - Move left  
- **S** - Move down
- **D** - Move right
- **ESC** - Exit the game

### Map File Format (.ber)

The map file must follow this format:

```
# Map layout (required)
# 1 = wall, 0 = empty space, P = player spawn, E = exit, C = collectible
# Must be surrounded by walls and rectangular
1111111111111
100PC10000C01
1C00010000001
1000010100001
100000C10E001
1111111111111
```

### Map Requirements

- **One player spawn**: Exactly one 'P' character
- **One exit**: Exactly one 'E' character  
- **At least one collectible**: At least one 'C' character
- **Closed map**: All walls must be connected and form a rectangle
- **Valid path**: Player must be able to reach all collectibles and the exit
- **.ber extension**: Map files must have .ber extension

## Features

- **2D Graphics**: Real-time rendering using MinilibX
- **Collision Detection**: Walls prevent player movement
- **Collectible System**: Player must collect all items to unlock exit
- **Smooth Movement**: WASD controls with immediate response
- **Map Validation**: Comprehensive map format checking
- **Memory Management**: Proper cleanup and resource management
- **Cross-platform**: Works on Linux and macOS

## Project Structure

```
so_long/
├── main.c                 # Main program entry point
├── so_long.h             # Main header file with structures
├── Makefile              # Build configuration
├── libft/                # Custom C library functions
├── minilibx_linux/       # Graphics library (Linux)
├── map.c                 # Map loading and parsing
├── check_map.c           # Map validation functions
├── check_map_utils.c     # Map validation utilities
├── set_tiles.c           # Graphics and tile management
├── key_binds.c           # Input handling
├── key_binds_utils.c     # Input utilities
├── cleanup.c             # Memory cleanup functions
├── img/                  # Game sprites and images
├── maps/                 # Example map files
└── map.ber              # Default map file
```

## Dependencies

- **MinilibX**: Graphics library for window management and rendering
- **libft**: Custom C library with utility functions
- **X11** (Linux): X Window System libraries
- **OpenGL/AppKit** (macOS): Graphics frameworks

## Building

The project uses a custom Makefile with animated compilation:

```bash
# Standard build
make

# Clean build artifacts
make clean

# Remove all build files
make fclean

# Rebuild everything
make re
```

## Game Rules

1. **Objective**: Collect all collectibles (C) and reach the exit (E)
2. **Movement**: Use WASD keys to move the player
3. **Collision**: Cannot walk through walls (1)
4. **Exit Access**: Exit is only accessible after collecting all items
5. **Win Condition**: Reaching the exit after collecting all items

## Error Handling

The program validates:
- Map file format and syntax
- Map connectivity and closure
- Player spawn position (exactly one)
- Exit position (exactly one)
- Collectible presence (at least one)
- Valid path to all collectibles and exit

## Example Maps

The project includes several example maps in the `maps/` directory:
- `test1.ber` - Simple test map
- `test2.ber` - Medium complexity map
- `test3.ber` - Complex map with multiple collectibles

## License

This project is part of the 42 curriculum and follows the 42 coding standards. 
