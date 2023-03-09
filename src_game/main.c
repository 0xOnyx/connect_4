#include "includes.h"
# define GRAY 8

WINDOW  *game = NULL;
WINDOW 	*column_selector = NULL;
WINDOW 	*scoreboard = NULL;
WINDOW  *progress_bar = NULL;
bool gui = false;

static void	init_ncurses(t_size size)
{
	initscr();
	cbreak();
	noecho();
	start_color();
	use_default_colors();
	init_pair(2, GRAY, -1);
	init_pair(3, COLOR_RED, -1);
	init_pair(4, COLOR_YELLOW, -1);
	keypad(stdscr, true);
	game = newwin(size.row * 2 + 1, size.col * 4 + 1, LINES/2 - (size.row*2/2), COLS/2 - (size.col*4/2));
	column_selector = newwin(2, size.col * 4 + 1, (LINES/2 - (size.row*2/2)) - 2, COLS/2 - (size.col*4/2));

	progress_bar = newwin(2, size.col * 4 + 1, (LINES/2 +(size.row*2/2)) + 2, COLS/2 - (size.col*4/2));
	refresh();
	wrefresh(progress_bar);


	scoreboard = newwin(size.row * 2 + 1, 15, LINES/2 - (size.row*2/2), (COLS/2 - (size.col*4/2)) - 20);
	refresh();
	wrefresh(scoreboard);



	int x_off = COLS/2 - (size.col*4/2);
	attron(A_UNDERLINE | A_BOLD);
	mvprintw((LINES/2 - (size.row*2/2)) - 4, x_off + (size.col*4/2) - 4, "Connect 4");
	attroff(A_UNDERLINE | A_BOLD);

	refresh();

	wrefresh(game);
	wrefresh(column_selector);
	move(0, 0);
}

int	main(int argc, char **argv)
{
	t_size	size;
	time_t	time_value;

	if (argc != 3 && argc != 4)
	{
		ft_putstr(1, "[failed]\tusage => ./connect4 [row] [col]\n");
		return (1);
	}
	if (argc == 4)
	{
		if (ft_strncmp(argv[3], "gui", 3) == 0)
			gui = true;
	}
	if ((size.row = ft_atoi(argv[1])) < 6
	|| (size.col = ft_atoi(argv[2])) < 7)
	{
		ft_putstr(1, "[error]\tto small row or col\n");
		return (2);
	}
    //	                 Y         X
	enum e_player	tab[size.row][size.col];
	int 		 	current_pos[size.col];

	if (time(&time_value) < 0)
	{
		ft_putstr(1, "[failed]\tto get time\n");
		return (3);
	}
	if (gui)
		init_ncurses(size);
	srand((unsigned int)time_value);
	ft_memset((void *)tab, 0, sizeof(enum e_player) * size.row * size.col);
	ft_memset((void *)current_pos, 0, sizeof(int) * size.col);
	play_game(size, tab, current_pos, (rand() % 2) ?  AI : HUMAN);
	if (gui)
		endwin();
	return (0);
}

