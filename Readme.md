# Sandpiles

This project is an implementation of the **Abelian sandpile model** in C.  
The goal is to simulate how sand grains behave when piles become unstable and start redistributing grains to neighboring cells.

## Project Overview

In this project, I implemented a function that computes the **sum of two sandpiles** represented as 3x3 grids.

Each cell of the grid represents a number of sand grains.  
A sandpile is considered **stable** when no cell contains more than 3 grains.

When a cell contains **more than 3 grains**, it becomes unstable and **topples**:
- 1 grain moves to the cell above
- 1 grain moves to the cell below
- 1 grain moves to the cell on the left
- 1 grain moves to the cell on the right

This redistribution continues until the sandpile becomes stable.

## Function Implemented

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
