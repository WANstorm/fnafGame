#include <iostream>
#include <ncurses.h>
#include "setup.h"

Setup::Setup() {

	initscr();
	noecho(); 
	keypad(stdscr, TRUE); 
	curs_set(0); 

	if (!has_colors || !can_change_color) { 
		endCurses();	
		std::cout << "Your terminal doesnt support colors.\n";
	}

	start_color(); 
	return;

}

void Setup::endCurses() {
	
	getch();
	endwin();

}
