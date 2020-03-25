#include <iostream>
#include <ncurses.h>
#include "setup.h"

Setup::Setup() {

	initscr();
	noecho(); //Disables echoing.
	keypad(stdscr, TRUE); //Enables keypad.
	curs_set(0); //Disables cursor.

	if (!has_colors || !can_change_color) { //Checks for color support
		endCurses();	
		std::cout << "Your terminal doesnt support colors.\n";
	}

	start_color(); //Enables colors.
	return;

}

void Setup::endCurses() {
	
	getch();
	endwin();

}
