#include <ncurses.h>
#include "mapBuilder.h"

void MapBuilder::drawMap(int &y, int &x, chtype symbol) {
	
	mvvline((y / 2) - 3, (x / 2) - 10, symbol, 2);
	mvvline((y / 2) - 3, (x / 2) + 10, symbol, 2);
	mvvline((y / 2) + 4, (x / 2) - 10, symbol, 1);
	mvvline((y / 2) + 4, (x / 2) + 10, symbol, 1);

	mvaddch((y / 2) + 3, (x / 2) + 10, '&');
	mvaddch((y / 2) + 3, (x / 2) - 10, '&');

	mvhline((y / 2) + 5, (x / 2) - 10, symbol, 21);
	mvhline((y / 2) - 4, (x / 2) - 10, symbol, 21);

	mvprintw((y / 2) - 3, (x / 2) - 1, "[=]");

}

