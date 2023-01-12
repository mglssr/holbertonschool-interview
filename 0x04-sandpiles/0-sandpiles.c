#include "sandpiles.h"

/**
 * add_grids - adds two grids.
  * @grid1: First 3x3 grid.
 * @grid2: Second 3x3 grid.
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * is_stable - computes the sum of two sandpiles
 * @grid: sandpiles stable
 * Return: 0 if it's inestable, 1 otherwise.
 */
int is_stable(int grid[3][3])
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
 * print_grid - computes the sum of two sandpiles
 * @grid: sandpiles stable
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
 * sandpiles_sum - function that computes the sum of two sandpiles.
 * @grid1: First 3x3 grid.
 * @grid2: Second 3x3 grid.
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int new_grid[3][3];
	/*add grid2 to grid1*/
	add_grids(grid1, grid2);

	/* while grid1 is not stable, perform toppling*/
	while (!is_stable(grid1))
	{
		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				new_grid[i][j] = 0;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if ((i - 1 >= 0) && (i - 1 < 3))
						new_grid[i - 1][j] += 1;
					if ((j - 1 >= 0) && (j - 1 < 3))
						new_grid[i][j - 1] += 1;
					if ((i + 1 >= 0) && (i + 1 < 3))
						new_grid[i + 1][j] += 1;
					if ((j + 1 >= 0) && (j + 1 < 3))
						new_grid[i][j + 1] += 1;
				}
			}
		}

		add_grids(grid1, new_grid);
	}
}