#include <ncurses.h>
#include "door.h"

void Door::closeLeftDoor() {

	int y, x;
	getmaxyx(stdscr, y, x);
	attron(A_BOLD);
	mvvline((y / 2) - 1, (x / 2) - 10, 'H', 4);
	attroff(A_BOLD);

}

void Door::closeRightDoor() {

	int y, x;
	getmaxyx(stdscr, y, x);
	attron(A_BOLD);
	mvvline((y / 2) - 1, (x / 2) + 10, 'H', 4);
	attroff(A_BOLD);

}

void Door::openLeftDoor() {

	int y, x;
	getmaxyx(stdscr, y, x);
	mvvline((y / 2) - 1, (x / 2) - 10, ' ', 4);

}

void Door::openRightDoor() {

	int y, x;
	getmaxyx(stdscr, y, x);
	mvvline((y / 2) - 1, (x / 2) + 10, ' ', 4);

}
