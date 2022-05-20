#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - Computes stable sum of sandpiles.
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	while (stabilize(grid1) != 1)
		continue;
}

/**
 * stabilize - stabilizes sandpile grid
 * @grid: 3x3 grid to stablize
 * Return: 1 if stable, else 0
 */

int stabilize(int grid[3][3])
{
	int stable = 1;
	int i, j;

	print_grid(grid);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] < 4)
				continue;

			stable = 0;

			grid[i][j] -= 4;

			if (i - 1 >= 0)
				grid[i - 1][j] += 1;
			if (i + 1 <= 2)
				grid[i + 1][j] += 1;
			if (j - 1 >= 0)
				grid[i][j - 1] += 1;
			if (j + 1 <= 2)
				grid[i][j + 1] += 1;
		}
	}

	return (stable);
}

/**
 * check_stability - checks if sandpile grid is stable
 * @grid: 3x3 grid
 * Return: 1 if stable, else 0
 */

int check_stability(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
				return (0);
		}
	}

	return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int i, j;
	int stable = check_stability(grid);

	if (stable == 0)
	{
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
}
