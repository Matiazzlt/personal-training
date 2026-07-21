/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfritz <mfritz@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 16:59:28 by mfritz            #+#    #+#             */
/*   Updated: 2026/07/12 17:06:11 by mfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sky_scrapers.h"

void	free_board(char	**board)
{
	int	i;

	i = 0;
	if (!board)
	{
		return ;
	}
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}
