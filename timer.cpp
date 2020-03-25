#include <ncurses.h>
#include <unistd.h>
#include <string>
#include "timer.h"

void Timer::startCount() {

	sleep(1); //removes glitches
	WINDOW *timerWin;
	int mins = 0;
	int hours = 0;	
	int y, x;
	
	getmaxyx(stdscr, y, x);

	timerWin = newwin(2, 7, (y / 2) - 6, (x / 2) - 2);

	for (int i = 0; i < 6; i++) {

		for (int ii = 0; ii < 60; ii++) {
			
			wclear(timerWin);
			wprintw(timerWin, std::to_string(hours).c_str());
			wprintw(timerWin, " : ");
			wprintw(timerWin, std::to_string(mins).c_str());
			wprintw(timerWin, " ");
			wrefresh(timerWin);
			sleep(1);
			mins++;

		}

		mins = 0;
		hours++;
		
	}

	delwin(timerWin);

}
