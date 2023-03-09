#include "includes.h"

extern WINDOW  *scoreboard;
extern bool gui;

void update_score_board(enum e_player current_player)
{
	if (!gui)
		return ;
	(void)current_player;
	wclear(scoreboard);
	wattron(scoreboard, A_UNDERLINE);
	mvwprintw(scoreboard, 0, 0, "Current Player");
	wattroff(scoreboard, A_UNDERLINE);
	if (current_player == AI)
		mvwprintw(scoreboard, 2, 0, "AI");
	else
		mvwprintw(scoreboard, 2, 0, "HUMAN");
	refresh();
	wrefresh(scoreboard);
	move(0, 0);
}