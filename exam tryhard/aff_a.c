/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:47:02 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/23 14:07:46 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Ici un programme est demander donc on fait un main direct, on
// verifie qu'il n'y a bien que deux arguments (argc), puis on verrifie
// ce qu'il y a dans l'argument qui nous interesse (argv[1]), et on
// renvoi des trucs en fonction de ce qui est demander.

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		write(1, "a", 2);
	else
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == 'a')
			{
				write (1, "a", 2);
				break ;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
