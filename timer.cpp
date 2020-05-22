#include <ncurses.h>
#include <unistd.h>
#include <string>
#include "timer.h"
#include "game.h"

int Timer::startCount() {

	sleep(3); //removes glitches

	int mins = 0;
	int hours = 0;	
	int y, x;
	
	getmaxyx(stdscr, y, x);

	WINDOW *timerWin;

	timerWin = newwin(1, 7, (y / 2) - 6, (x / 2) - 2);

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

            switch (gameStatus) {

                case 0:
                    return 0;

                case 1:
                    return 1;

            }

		}

		mins = 0;
		hours++;
		
	}

	delwin(timerWin);

    return 0;

}
