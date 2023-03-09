#include "includes.h"

extern WINDOW  *column_selector;
extern bool	gui;

static int    get_col(t_size size, enum e_player tab[size.row][size.col])
{
	int		current_pos;
	char    str[200];
	int     column;
	int 	input;

	if (!gui)
	{
		while (1)
		{
			ft_putstr(1, "select >");
			if (read(STDIN_FILENO, str, 200) <= 1)
			{
				ft_putstr(1, "Not a valid column\n");
				continue;
			}
			column = ft_atoi(str);
			if (column >= 0 && column < size.col)
			{
				if (tab[size.row - 1][column] != 0)
					ft_putstr(1, "Column is already full\n");
				else
					return (column);
			} else
				ft_putstr(1, "Not a valid column\n");
		}
	}
	else
	{
		current_pos = 0;
		mvwprintw(column_selector, 1, 4 * current_pos + 1, "___");
		wrefresh(column_selector);
		refresh();
		while (1)
		{
			input = getch();
			if (input == KEY_LEFT || input == KEY_RIGHT)
			{
				wclear(column_selector);
				if (input == KEY_LEFT && current_pos > 0)
					current_pos--;
				else if (input == KEY_RIGHT && current_pos < size.col - 1)
					current_pos++;
				mvwprintw(column_selector, 1, 4 * current_pos + 1, "___");
				wrefresh(column_selector);
				move(0, 0);
			}
			else if (input == ' ')
			{
				wclear(column_selector);
				wrefresh(column_selector);
				return (current_pos);
			}
		}
		return (0);
	}
}

t_pos play_human(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col])
{
	t_pos	pos;

	pos.x = get_col(size, tab);
	pos.y = current_pos[pos.x];
	current_pos[pos.x]++;
	return (pos);
}