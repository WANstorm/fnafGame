#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "camera.h"
#include "bonnie.h"

void Bonnie::activate(int level) {

	int currentYPos = 1;
	int nextYPos = 1;

	int currentXPos = 10;
	int nextXPos = 10;

	while (true) {

		std::srand(std::time(0));
		int randNum = std::rand() % 20 + 1;
		
		if (randNum <= level) {

			mvaddch(currentYPos, currentXPos, ' ');
			currentYPos = nextYPos;
			currentXPos = nextXPos;
			nextYPos++;

			if (Camera::camOpen == true) {
		
				mvaddch(currentYPos, currentXPos, 'B');
				refresh();

			}

		}

		sleep(4);

	}	

}
