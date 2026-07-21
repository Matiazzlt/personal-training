/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfritz <mfritz@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:18:58 by mfritz            #+#    #+#             */
/*   Updated: 2026/07/12 15:26:05 by gtourill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	count_visible_right(char **board, int row_i)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 3;
	while (i >= 0)
	{
		if (board[row_i][i] > max)
		{
			count++;
			max = board[row_i][i];
		}
		i--;
	}
	return (count);
}

int	count_visible_left(char **board, int row_i)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (board[row_i][i] > max)
		{
			count++;
			max = board[row_i][i];
		}
		i++;
	}
	return (count);
}

int	count_visible_down(char **board, int col_i)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 3;
	while (i >= 0)
	{
		if (board[i][col_i] > max)
		{
			count++;
			max = board[i][col_i];
		}
		i--;
	}
	return (count);
}

int	count_visible_up(char **board, int col_i)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (board[i][col_i] > max)
		{
			count++;
			max = board[i][col_i];
		}
		i++;
	}
	return (count);
}

void	print_board(char **board)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = board[row][col] + '0';
			write(1, &c, 1);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
