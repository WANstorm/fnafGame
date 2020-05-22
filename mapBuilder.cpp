#include <ncurses.h>
#include "mapBuilder.h"
#include "game.h"
#include "door.h"

void MapBuilder::drawMap(int y, int x, chtype symbol) {
	
    Door door;

	mvvline((y / 2) - 3, (x / 2) - 10, symbol, 2);
	mvvline((y / 2) - 3, (x / 2) + 10, symbol, 2);
	mvvline((y / 2) + 4, (x / 2) - 10, symbol, 1);
	mvvline((y / 2) + 4, (x / 2) + 10, symbol, 1);

	mvaddch((y / 2) + 3, (x / 2) + 10, '&');
	mvaddch((y / 2) + 3, (x / 2) - 10, '&');

	mvhline((y / 2) + 5, (x / 2) - 10, symbol, 21);
	mvhline((y / 2) - 4, (x / 2) - 10, symbol, 21);

	mvprintw((y / 2) - 3, (x / 2) - 1, "[=]");


    if (leftDoorClosed) {

        door.closeLeftDoor();

    }

    if (rightDoorClosed) {

        door.closeRightDoor();

    }

}
