#include <ncurses.h>
#include <iostream>
#include "setup.h"
#include "mapBuilder.h"
#include "player.h"
#include "game.h"
//Compile g++ main.cpp -lncurses

int main() {

	Setup setup;
	MapBuilder map;
	Player player;
	Game game;

	int y,x;
	getmaxyx(stdscr, y, x);

	map.drawMap(y, x, '#');
	game.getInput(y / 2, x / 2);

	setup.endCurses();

}
