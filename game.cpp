#include <ncurses.h>
#include <thread>
#include "game.h"
#include "camera.h"
#include "door.h"
#include "timer.h"
#include "bonnie.h"

int Game::getInput(int y, int x) {

	Camera camera;
	Door door;
	Timer timer;
	Bonnie bonnie;

	int input;
	bool leftDoorClosed = false;
	bool rightDoorClosed = false;

	std::thread timerThread(&Timer::startCount, &timer);
	std::thread bonnieThread(&Bonnie::activate, &bonnie, 20);

	while (true) {

		mvaddch(y, x, '*');
		refresh();

		input = getch();
		
		switch(input) {

			case 'e':
			case 'E':
				if (mvinch(y - 1, x) == '=' && Camera::camOpen == false) {

					camera.openCamera();
					Camera::camOpen = true;

				} else if (Camera::camOpen == true) {

					camera.closeCamera();			
					Camera::camOpen = false;
	
				} else if (mvinch(y, x - 1) == '&' && !leftDoorClosed) {

					door.closeLeftDoor();
					leftDoorClosed = true;

				} else if (mvinch(y, x - 1) == '&' && leftDoorClosed) {

					door.openLeftDoor();
					leftDoorClosed = false;

				} else if (mvinch(y, x + 1) == '&' && !rightDoorClosed) {

					door.closeRightDoor();
					rightDoorClosed = true;

				} else if (mvinch(y, x + 1) == '&' && rightDoorClosed) {

					door.openRightDoor();
					rightDoorClosed = false;

				}

				break;

			case 'D':
			case 'd':
				if (moveOk(y, x + 1)) {

					mvaddch(y, x, ' ');
					x++;

				}

				break;

			case 'a':	
			case 'A':
				if (moveOk(y, x - 1)) {

					mvaddch(y, x, ' ');
					x--;

				}

				break;
	
			case 's':
			case 'S':
				if (moveOk(y + 1, x)) {

					mvaddch(y, x, ' ');
					y++;

				}

				break;

			case 'w':
			case 'W':
				if (moveOk(y - 1, x)) {

					mvaddch(y, x, ' ');
					y--;

				}

				break;
		}
	}
}
