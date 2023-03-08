#ifndef MINMAX_H
# define MINMAX_H
# include "includes.h"

int	minmax(t_size size, enum e_player tab[size.row][size.col], int depth, int current_pos[size.col], enum e_minmax current_minmax, int alpha, int beta, unsigned long int *nbr);
int	calc_board_value(t_size size, enum e_player tab[size.row][size.col]);

#endif
