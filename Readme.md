# Conway's game of life in c with [MinilibX](https://github.com/42Paris/minilibx-linux)

According to wikipedia:
>The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.[1] It is a zero-player game,[2][3] meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine.

This an implementation of Life in C with the X-Windows Graphic Library [MinilibX](https://github.com/42Paris/minilibx-linux).

## Configuration
configuration is done in conway.h
DEFAULT_X / DEFAULT_Y is the size in cell of the game
DEFAULT_CELL is the size in pixel of one cell
CELL_COLOR is the color of the cell to be drawn
MAX_FRAME the render is made only 1 / MAX_FRAME

## Compilation
```
git clone https://github.com/corecaps/conway.git
```
then you can either clone the [MinilibX](https://github.com/42Paris/minilibx-linux) directly into minilibx-linux dir or install the library and change the include and library path in the makefile.


```
make
```

## run
just type :
```
./conway
```
