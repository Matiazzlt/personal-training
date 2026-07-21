/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:19:08 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/12 17:05:11 by mfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sky_scrapers.h"

void	reset_row(char **board, int row_i)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		board[row_i][i] = 0;
		i++;
	}
}

int	check_valid(char **board, int val, int col, int row)
{
	int	valid;
	int	i;

	valid = 1;
	i = 0;
	while (i < col && valid)
	{
		if (board[row][i] == val)
			valid = 0;
		i++;
	}
	return (valid);
}

int	check_and_recurse(char **board, t_constraints con, int row, int col)
{
	if (col < 3)
	{
		if (fill_board(board, con, row, col + 1) == 0)
			return (0);
	}
	else
	{
		if (check_row(board, con.row_l, con.row_r, row) == 0)
		{
			if (row == 3)
			{
				if (check_col(board, con.col_u, con.col_d) == 0)
					return (0);
			}
			else
			{
				if (fill_board(board, con, row + 1, 0) == 0)
					return (0);
				reset_row(board, row + 1);
			}
		}
	}
	return (1);
}

int	fill_board(char **board, t_constraints con, int row, int col)
{
	int	valid;
	int	val;

	val = 1;
	while (val <= 4)
	{
		valid = check_valid(board, val, col, row);
		if (valid)
		{
			board[row][col] = val;
			if (check_and_recurse(board, con, row, col) == 0)
			{
				return (0);
			}
		}
		val++;
	}
	return (1);
}

int	ft_solve_tower(t_constraints con)
{
	char	**board;

	board = (char **)malloc(sizeof(char *) * 5);
	board[0] = malloc(sizeof(char) * 5);
	board[1] = malloc(sizeof(char) * 5);
	board[2] = malloc(sizeof(char) * 5);
	board[3] = malloc(sizeof(char) * 5);
	board[4] = NULL;
	if (fill_board(board, con, 0, 0))
	{
		free_board(board);
		return (1);
	}
	print_board(board);
	free_board(board);
	return (0);
}
