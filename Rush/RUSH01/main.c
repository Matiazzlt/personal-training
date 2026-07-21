/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourill <gtourill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:28:15 by gtourill          #+#    #+#             */
/*   Updated: 2026/07/12 15:19:28 by gtourill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sky_scrapers.h"

int	ft_run_tower(char *input)
{
	int				i;
	t_constraints	con;

	i = 0;
	while (i < 4)
	{
		con.col_u[i] = input[i * 2];
		con.col_d[i] = input[(i + 4) * 2];
		con.row_l[i] = input[(i + 8) * 2];
		con.row_r[i] = input[(i + 12) * 2];
		i++;
	}
	con.col_u[4] = '\0';
	con.col_d[4] = '\0';
	con.row_l[4] = '\0';
	con.row_r[4] = '\0';
	if (ft_solve_tower(con))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (ft_check_arg(argc, argv))
	{
		ft_print_error();
		return (0);
	}
	if (ft_run_tower(argv[1]))
		ft_print_error();
}
