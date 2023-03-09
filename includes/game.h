#ifndef GAME_H
# define GAME_H
# include "includes.h"

void				update_score_board(enum e_player current_player);
void				print_board(t_size size, enum e_player tab[size.row][size.col]);
int					play_game(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col], enum e_player first_player);
enum e_player		has_won(t_size size, enum e_player tab[size.row][size.col], t_pos pos);
t_pos				play_human(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col]);
t_pos 				play_ai(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col]);

#endif