#ifndef GAME_H
# define GAME_H
# include "includes.h"

void	print_board(t_size size, enum e_player tab[size.row][size.col]);
int		play_game(t_size size, enum e_player tab[size.row][size.col], enum e_player first_player);
int		has_won(t_size size, enum e_player tab[size.row][size.col], t_pos pos);
t_pos	play_human(t_size size, enum e_player tab[size.row][size.col]);

#endif