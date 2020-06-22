#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_safe(int n, int *solution, int solindex, int index)
{
	int i;
	int j;

	i = 0;
	while (i < solindex)
	{
		if (solution[i] % n == index % n)
			return (0);
		if (solution[i] / n == index / n)
			return (0);
		i++;
	}
	i = 0;
	while (i < solindex)
	{
//		j = 1;
//		while((index + j * n + j) % n > index % n && (index + j * n + j) < n * n)
//		{
//			if (solution[i] == index + j * n + j)
//				return (0);
//			j++;
//		}
		j = 1;
		while((index - j * n + j) % n > index % n && (index - j * n + j) >= 0) // Did you notice '>' on the left and '>=' on the right ?
		{
			if (solution[i] == index - j * n + j)
				return (0);
			j++;
		}
//		j = 1;
//		while((index + j * n - j) % n < index % n && (index + j * n - j) < n * n)
//		{
//			if (solution[i] == index + j * n - j)
//				return (0);
//			j++;
//		}
		j = 1;
		while((index - j * n - j) % n < index % n && (index - j * n - j) >= 0)
		{
			if (solution[i] == index - j * n - j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_solution(int n, int *solution)
{
	int i;
	char c;

	i = 0;
	while (i < n)
	{
		c = '0' + (solution[i] % n);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
}

void	backtrack(int n, int *solution, int solindex, int index)
{
	if(solindex == n) // Exit case the solution array is full
	{
		print_solution(n, solution);
		solution[n] += 1;
		return ;
	}
	if(index > (n * n) - 1)
		return ;
	if (is_safe(n, solution, solindex, index))
	{
		solution[solindex] = index; //Place a queen in the solution array
		backtrack(n, solution, solindex + 1, index + 1);
	}
	backtrack(n, solution, solindex, index + 1);
}

int	ft_ten_queens_puzzle(int n)
{
	int i;

	int solution[n + 1]; //Solution[n] will contain the number of solutions.

	solution[n] = 0;
	i = 0;
	while (solution[i] < n)
	{
		solution[i] = -1;
		i++;
	}	
	solution[n] = 0;

	i = 0;
	backtrack(n, solution, 0, i);
	return (solution[n]);
}