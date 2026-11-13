# Simple Calculator

A simple command-line calculator written in C.

## Features
- Displays a menu and loops until the user quits with option 0
- 1) Add, 2) Subtract, 3) Multiply, 4) Divide
- Prints `Invalid choice` for options not in the menu
- Prints `Error: division by zero` when dividing by 0

## Number type
The calculator uses decimals (`double`) for all operations, so
results are consistent: `10 / 4` gives `2.5`, and whole results
such as `10 + 25` are printed without decimals (`35`).

## Compilation
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 calculator.c -o calculator

## Usage
./calculator
