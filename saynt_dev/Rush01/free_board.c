#include "sky_scrapers.h"

void	free_board(char **board)
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
