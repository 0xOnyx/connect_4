#include "includes.h"

char *print_element[3] = {"\033[90m_\033[0m", "\033[33mH\033[0m", "\033[31mA\033[0m"};
char *print_element_gui[3] = {" ", "H", "A"};
extern bool 	gui;
extern WINDOW  *game;

static void	put_token(t_size size, t_pos pos, enum e_player token)
{
	if (token == HUMAN)
		wattron(game, COLOR_PAIR(3));
	else if (token == AI)
		wattron(game, COLOR_PAIR(4));
	mvwprintw(game, size.row * 2 - (2 * pos.y + 1), 4 * pos.x + 2 , print_element_gui[token]);
	if (token == HUMAN)
		wattroff(game, COLOR_PAIR(3));
	else if (token == AI)
		wattroff(game, COLOR_PAIR(4));
}


void	print_board(t_size size, enum e_player tab[size.row][size.col])
{
	if (!gui)
	{
		int x;
		int y;
		char *tmp;

		if (size.row > 10)
			ft_putchar_fd('\t', 1);
		else
			ft_putstr(1, "  ");
		y = 0;
		while (y < size.col)
		{
			tmp = ft_itoa(y);
			ft_putstr(1, tmp);
			ft_putchar_fd(' ', 1);
			free(tmp);
			y++;
		}
		ft_putchar_fd('\n', 1);
		y = size.row - 1;
		while (y >= 0)
		{
			x = 0;
			tmp = ft_itoa(y);
			ft_putstr(1, tmp);

			if (size.row > 10)
				ft_putchar_fd('\t', 1);
			else
				ft_putchar_fd(' ', 1);

			while (x < size.col)
			{
				ft_putstr(1, print_element[tab[y][x]]);
				ft_putchar_fd(' ', 1);
				x++;
			}
			if (size.row > 10)
				ft_putchar_fd('\t', 1);
			else
				ft_putchar_fd(' ', 1);
			ft_putstr(1, tmp);
			free(tmp);
			ft_putchar_fd('\n', 1);
			y--;
		}
		if (size.row > 10)
			ft_putchar_fd('\t', 1);
		else
			ft_putstr(1, "  ");
		y = 0;
		while (y < size.col)
		{
			tmp = ft_itoa(y);
			ft_putstr(1, tmp);
			ft_putchar_fd(' ', 1);
			free(tmp);
			y++;
		}
		ft_putstr(1, "\n<------------------->\n");
	}
	else
	{
		int x;
		int y;

		if (!has_colors())
			mvprintw(0, 0 , "NO COLOR");
		wattron(game, COLOR_PAIR(2));
		for(y=0;y<size.row;y++) {
			for(x=0;x<size.col;x++) {
				mvwprintw(game, 2*y, 4*x+0 , "+---+");
			}
			for (x = 0; x<= size.col; x++)
			{
				mvwprintw(game, 2*y+1, 4*x+0, "|");
			}
		}
		for(x=0;x<size.col;x++) {
			mvwprintw(game, 2*size.row, 4*x+0 , "+---+");
		}
		wattroff(game, COLOR_PAIR(2));
		y = size.row - 1;
		while (y >= 0)
		{
			x = 0;
			while (x < size.col)
			{
				put_token(size, (t_pos){x, y}, tab[y][x]);
				x++;
			}
			y--;
		}
		wrefresh(game);
		refresh();
	}
}