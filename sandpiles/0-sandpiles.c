#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - checks if a grid is stable
 * @grid: grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int tmp[3][3];

	/* addition */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (!is_stable(grid1))
	{
		print_grid(grid1);

		/* copy grid */
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				tmp[i][j] = grid1[i][j];

		/* toppling */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (tmp[i][j] > 3)
				{
					grid1[i][j] -= 4;

					if (i > 0)
						grid1[i - 1][j] += 1;
					if (i < 2)
						grid1[i + 1][j] += 1;
					if (j > 0)
						grid1[i][j - 1] += 1;
					if (j < 2)
						grid1[i][j + 1] += 1;
				}
			}
		}
	}
}
