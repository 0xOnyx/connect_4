#include "includes.h"

#define DEPTH 6

t_pos play_ai(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col])
{
	int 	col_max;
	int 	value_max;
	t_pos	pos;

	pos.x = 0;
	value_max = INT_MIN;
	col_max = pos.x;
	while (pos.x < size.col)
	{
		int tmp_value;
		if ((pos.y = current_pos[pos.x]) >= size.row)
		{
			pos.x++;
			continue;
		}
		current_pos[pos.x]++;
		tab[pos.y][pos.x] = AI;
		if ((tmp_value = max(value_max, minmax(size, tab, DEPTH, current_pos, MINIMIZER))) != value_max)
		{
			value_max = tmp_value;
			col_max = pos.x;
		}
		printf(" pos => %d minmax => %d\n", pos.x, tmp_value);
		tab[pos.y][pos.x] = NONE;
		current_pos[pos.x]--;
		pos.x++;
	}
	pos.x = col_max;
	pos.y = current_pos[col_max];
	current_pos[col_max]++;
	return (pos);
}