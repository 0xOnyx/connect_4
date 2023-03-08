#include "includes.h"

int update_counter(int counter, enum e_player token, t_size size, enum e_player tab[size.row][size.col], int y, int x)
{
	if (y < 0 || y > size.row - 1 || x < 0 || x > size.col -1)
		return (counter);
	if (tab[y][x] == token)
		return (counter + 1);
	else
		return (0);
}

int has_won(t_size size, enum e_player tab[size.row][size.col], t_pos pos)
{
	int i;
	int count_hor = 0;
	int count_ver = 0;
	int count_diag_up = 0;
	int count_diag_down = 0;
	enum  e_player token = tab[pos.y][pos.x];

	i = -3;
	while (i <= 3)
	{
		count_hor = update_counter(count_hor, token, size, tab, pos.y, pos.x + i);
		count_ver = update_counter(count_ver, token, size, tab, pos.y + i, pos.x);
		count_diag_up = update_counter(count_diag_up, token, size, tab, pos.y - i, pos.x + i);
		count_diag_down = update_counter(count_diag_down, token, size, tab, pos.y + i, pos.x + i);
		if (count_hor >= 4 || count_ver >= 4 || count_diag_up >= 4 || count_diag_down >= 4)
			return (1);
		i++;
	}
	return (0);
}
