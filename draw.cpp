#include <ncurses.h>
#include "draw.h"
#include "mapBuilder.h"

void Draw::drawVertLine(int y, int x, int intended, const char* symbol) {

	if (y <= intended) {
		
		for (y; y <= intended; y++) {
			
			mvprintw(y, x, symbol);

		}

	} else if (y >= intended) {
		
		for (y; y <= intended; ++y) {
			
			mvprintw(y, x, symbol);

		}
	
	}
}

void Draw::drawHorzLine(int y, int x, int intended, const char* symbol) {

	if (x <= intended) {

		for (x; x <= intended; x++) {

			mvprintw(y, x, symbol);

		}

	} else if (x >= intended) {

		for (x; x >= intended; ++x) {

			mvprintw(y, x, symbol);

		}

	}

}
