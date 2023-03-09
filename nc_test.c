#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum e_player
{
	NONE,
	HUMAN,
	AI,
};

enum e_minmax
{
	MAXIMIZER,
	MINIMIZER,
};

typedef struct s_size
{
	int col;
	int row;
} t_size;

typedef struct s_pos
{
	int x;
	int y;
} t_pos;

void initCurses() {

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

/* Draw game grid */
void drawBoard(t_size size) {

	int y, x;
	int x_off = COLS/2 - (size.col*4/2);
	int y_off = LINES/2 - (size.row*2/2);

	attron(A_UNDERLINE | A_BOLD);
	mvprintw(y_off/2, x_off + (size.col*4/2) - 4, "Connect 4");
	attroff(A_UNDERLINE | A_BOLD);

	for(y=0;y<size.row;y++) {
		for(x=0;x<size.col;x++) {
			mvaddch(2*y + y_off, 4*x + x_off, '-');
			mvaddch(2*y + y_off, 4*x+1 + x_off, '-');
			mvaddch(2*y + y_off, 4*x+2 + x_off, '-');
			mvaddch(2*y + y_off, 4*x+3 + x_off, '-');
			mvaddch(2*y + y_off, 4*x+4 + x_off, '-');
		}
		for (x = 0; x<= size.col; x++)
		{
			mvaddch(2*y+1+ y_off, 4*x + x_off, '|');
		}
	}
	for(x=0;x<size.col;x++) {
		mvaddch(2*size.row+ y_off, 4*x + x_off, '-');
		mvaddch(2*size.row+ y_off, 4*x+1 + x_off, '-');
		mvaddch(2*size.row+ y_off, 4*x+2 + x_off, '-');
		mvaddch(2*size.row+ y_off, 4*x+3 + x_off, '-');
		mvaddch(2*size.row+ y_off, 4*x+4 + x_off, '-');
	}
	move(1,2);
	refresh();
}

/*void place_token(t_pos pos, enum e_player token) {

	char c;

	c = token == HUMAN ? 'H' : 'A';

	mvaddch(pos.y * 2, 4*x+4, '-');
	move(1,2);
	refresh();
}*/

int main(void)
{
 t_size  size;

 size.col = 8;
 size.row = 9;


	initCurses();
	drawBoard(size);
	sleep(20);
	endwin();
	return(0);
}

