#include <ncurses.h>
#include "camera.h"
#include "mapBuilder.h"


bool Camera::camOpen = false;

void Camera::openCamera() {

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

	refresh();

}

void Camera::closeCamera() {

	int y, x;
	getmaxyx(stdscr, y, x);

	erase();
	MapBuilder map;
	map.drawMap(y, x, '#');

}
