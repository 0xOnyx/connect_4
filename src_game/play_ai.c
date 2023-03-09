#include "includes.h"

#define DEPTH 10

extern bool		gui;
extern WINDOW	*progress_bar;

t_pos play_ai(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col])
{
	int 	col_max;
	int 	value_max;
	t_pos	pos;
	unsigned long int nbr;

	nbr = 0;
	pos.x = 0;
	value_max = INT_MIN;
	col_max = pos.x;
	if (gui)
	{
		wclear(progress_bar);
		wrefresh(progress_bar);
		mvwprintw(progress_bar, 0, 0, "[");
		move(0, 0);
	}
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
		if ((tmp_value = max(value_max, minmax(size, tab, DEPTH, current_pos, MINIMIZER, INT_MIN, INT_MAX, &nbr))) != value_max)
		{
			value_max = tmp_value;
			col_max = pos.x;
		}
		if (!gui)
			printf(" pos => %d minmax => %d\n", pos.x, tmp_value);
		else
		{
			mvwprintw(progress_bar, 0, pos.x * 4, "====>");
			move(0, (pos.x * 4) - 1);
			wrefresh(progress_bar);
		}
		tab[pos.y][pos.x] = NONE;
		current_pos[pos.x]--;
		pos.x++;
	}
	if (!gui)
		printf("number iterationr => %lu\n", nbr);
	else
	{
		wclear(progress_bar);
		setlocale(LC_NUMERIC, "");
		mvwprintw(progress_bar, 0, 0, "nbr iteration => %'lu", nbr);
		wrefresh(progress_bar);
		move(0, 0);
	}
	pos.x = col_max;
	pos.y = current_pos[col_max];
	current_pos[col_max]++;
	return (pos);
}