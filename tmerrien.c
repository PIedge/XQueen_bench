/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:38:51 by tmerrien          #+#    #+#             */
/*   Updated: 2020/09/07 10:35:18 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include  <time.h>

void	ft_putstr(char *s)
{
	write(1, s, 11);
}

void	display(char *number_queen)
{
	int i;

	i = 0;
	ft_putstr(number_queen);
}

int		set_nb_queen(int bit)
{
	int i;

	i = 0;
	while (!(bit & (1 << i)))
		++i;
	return (i);
}

void	backtracking(int *tab, int *count, char *number_queen)
{
	int	bitmap;
	int	bit;
	int	tab2[4];

	if (tab[0] == 10)
	{
		++*count;
		display(number_queen);
	}
	else
	{
		bitmap = ((1 << 10) - 1) & ~(tab[1] | tab[2] | tab[3]);
		while (bitmap)
		{
			bit = -bitmap & bitmap;
			bitmap ^= bit;
			number_queen[set_nb_queen(bit)] = tab[0] + 48;
			tab2[0] = tab[0] + 1;
			tab2[1] = (tab[1] | bit) << 1;
			tab2[2] = tab[2] | bit;
			tab2[3] = (tab[3] | bit) >> 1;
			backtracking(tab2, count, number_queen);
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		tab[4];
	int		count;
	char	number_queen[11];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	count = 0;
	number_queen[10] = '\n';
	backtracking(tab, &count, number_queen);
	return (count);
}
