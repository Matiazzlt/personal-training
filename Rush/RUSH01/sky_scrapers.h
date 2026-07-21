/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_scrapers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfritz <mfritz@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 12:20:22 by mfritz            #+#    #+#             */
/*   Updated: 2026/07/12 17:05:47 by mfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKY_SCRAPERS_H
# define SKY_SCRAPERS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_constraints
{
	char	col_u[5];
	char	col_d[5];
	char	row_l[5];
	char	row_r[5];
}	t_constraints;

int		check_row(char **board, char *row_l, char *row_r, int row_i);
int		check_col(char **board, char *col_u, char *col_d);
int		fill_board(char **board, t_constraints con, int row, int col);
int		count_visible_right(char **board, int row_i);
int		count_visible_left(char **board, int row_i);
int		count_visible_down(char **board, int col_i);
int		count_visible_up(char **board, int col_i);
int		ft_check_arg(int size, char **str);
int		ft_solve_tower(t_constraints con);
void	free_board(char	**board);
void	ft_print_error(void);
void	print_board(char **board);
#endif
