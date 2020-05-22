#include <ncurses.h>
#include "camera.h"
#include "mapBuilder.h"

bool camOpen = false;

void Camera::openCamera() {

    camOpen = true;
	int y, x;
	getmaxyx(stdscr, y, x);

	erase();
	
	mvvline((y / 2) - 4, (x / 2) - 5, '#', 5);
	mvvline((y / 2) - 4, (x / 2) + 5, '#', 5);
	mvhline((y / 2), (x / 2) - 4, '#', 10);
	mvhline((y / 2) - 4, (x / 2) - 4, '#', 10);
	mvaddch((y / 2) - 2, (x / 2) + 5, ' ');
	mvaddch((y / 2) - 2, (x / 2) - 5, ' ');
	mvhline((y / 2) - 1, (x / 2) - 9, '#', 4);
	mvhline((y / 2) - 1, (x / 2) + 6, '#', 4);
	mvhline((y / 2) - 3, (x / 2) - 7, '#', 3);
	mvhline((y / 2) - 3, (x / 2) + 6, '#', 2);
	mvvline((y / 2) - 6, (x / 2) + 9, '#', 6);
	mvvline((y / 2) - 6, (x / 2) - 9, '#', 6);
	mvvline((y / 2) - 6, (x / 2) - 7, '#', 3);
	mvvline((y / 2) - 6, (x / 2) + 7, '#', 3);
	mvvline((y / 2) - 14, (x / 2) + 10, '#', 9);
	mvvline((y / 2) - 14, (x / 2) - 10, '#', 9);
	mvhline((y / 2) - 14, (x / 2) - 9, '#', 20);

	refresh();

}

void Camera::closeCamera() {

    camOpen = false;
	int y, x;
	getmaxyx(stdscr, y, x);

	erase();
	MapBuilder map;
	map.drawMap(y, x, '#');

}
