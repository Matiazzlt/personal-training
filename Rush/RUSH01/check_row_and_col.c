/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_and_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfritz <mfritz@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:23:32 by mfritz            #+#    #+#             */
/*   Updated: 2026/07/12 15:25:33 by gtourill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sky_scrapers.h"

int	check_row(char **board, char *row_l, char *row_r, int row_i)
{
	if (count_visible_left(board, row_i) != (row_l[row_i] - '0'))
	{
		return (1);
	}
	if (count_visible_right(board, row_i) != (row_r[row_i] - '0'))
	{
		return (1);
	}
	return (0);
}

int	check_col_duplicates(char **board, int col_i)
{
	int	count;
	int	val;
	int	i;

	count = 0;
	val = 1;
	i = 0;
	while (val < 4)
	{
		count = 0;
		i = 0;
		while (i < 4)
		{
			if (board[i][col_i] == val)
				count++;
			i++;
		}
		if (count > 1)
		{
			return (1);
		}
		val++;
	}
	return (0);
}

int	check_col(char **board, char *col_u, char *col_d)
{
	int	col_i;

	col_i = 0;
	while (col_i < 4)
	{
		if (count_visible_up(board, col_i) != (col_u[col_i] - '0'))
		{
			return (1);
		}
		if (count_visible_down(board, col_i) != (col_d[col_i] - '0'))
		{
			return (1);
		}
		if (check_col_duplicates(board, col_i))
		{
			return (1);
		}
		col_i++;
	}
	return (0);
}
