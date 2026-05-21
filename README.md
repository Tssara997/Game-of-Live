# Game-of-Live

A C++ screensaver implementation of Conway's Game of Life.

## Features

- multipule starting patterns
- drawing patterns
- speed control
- 2 window sizes

## Technologies

- C#
- Raylib
- Visual Studio

## Controls

| Key | Action |
|------|---------|
| 1 | Heart |
| 2 | Checkers |
| 3 | First Infinite pattern |
| 4 | Second Infinite pattern |
| 5 | Checkers |
| 6 | PingPong |
| 7 | Flower |
| 8 | Bee |
| 9 | Mosaic |
| 0 | Black screen |
| s | Speed control |
| c | Clear screen |
| Esc | Exit |
| F11 | Fullscreen |
| Left Mouse Button | Changing a color of a square |

## Video

https://github.com/user-attachments/assets/37084062-4267-4cc8-9993-f1eef984f63e

## Project Structure

```text
Game-of-Live/
├── Game of Live.sln
├── .gitignore
├── .gitattributes
└── Game of Live/
    ├── Game of Live.vcxproj
    ├── Game of Live.vcxproj.filters
    ├── main.cpp
    ├── Grid.cpp
    ├── Grid.h
    ├── Position.h
    ├── serce.csv
    └── wzor.txt
```

## Main Files

- `main.cpp` - starts the program and runs the simulation loop.
- `Grid.h` / `Grid.cpp` - contains the grid logic, drawing, updating cells and checking cell states.
- `Position.h` - represents positions on the grid.
- `serce.csv` - example pattern/data file.
- `wzor.txt` - example pattern/data file.
- `Game of Live.sln` - Visual Studio solution file.

## How to Run

### Using Visual Studio

1. Clone the repository:

```bash
git clone https://github.com/Tssara997/Game-of-Live.git
```

2. Open the project folder.

3. Open the solution file:

```text
Game of Live.sln
```

4. Build the project in Visual Studio.

5. Run the program.

### Using Developer Command Prompt

You can also build the project from the Visual Studio Developer Command Prompt:

```bash
git clone https://github.com/Tssara997/Game-of-Live.git
cd Game-of-Live
msbuild "Game of Live.sln"
```

Then run the generated executable from the build output directory.

## How It Works

The program creates a grid and repeatedly:

1. Draws the current state of the grid.
2. Checks which cells should change.
3. Updates the grid to the next generation.

The simulation loop is started in `main.cpp`.

## Author

Maja Budych

GitHub:
https://github.com/Tssara997
