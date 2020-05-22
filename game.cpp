#include <ncurses.h>
#include <thread>
#include <unistd.h>
#include <fstream>
#include "game.h"
#include "mapBuilder.h"
#include "camera.h"
#include "door.h"
#include "timer.h"
#include "bonnie.h"
#include "battery.h"

bool leftDoorClosed = false;
bool rightDoorClosed = false;
int gameStatus = -1;

int Game::getInput(int y, int x) {

    MapBuilder map;
    Camera camera;
    Door door;
    Timer timer;
    Bonnie bonnie;
    Battery battery;

	int input;
    int xCamPos = x, yCamPos = y - 2;

    std::ifstream readSave("night.save");
    std::string strNightNumber;
    std::getline(readSave, strNightNumber);
    readSave.close();

    int nightNumber = std::stoi(strNightNumber);
    int bonnieLevel;

    switch (nightNumber) {

        case 1:
            bonnieLevel = 4;
            break;

        case 2:
            bonnieLevel = 6;
            break;

        case 3:
            bonnieLevel = 8;
            break;

        case 4:
            bonnieLevel = 10;
            break;

        case 5:
            bonnieLevel = 15;
            break;
    }

    std::thread bonnieThread(&Bonnie::activate, &bonnie, bonnieLevel);
    std::thread batteryThread(&Battery::startBattery, &battery);
	std::thread timerThread(&Timer::startCount, &timer);

    mvprintw(y, x - 2, "Night ");
    printw(strNightNumber.c_str());
    refresh();
    sleep(2);
    clear();

    map.drawMap(y * 2, x * 2, '#');

	while (true) {

        switch (gameStatus) {

            case 1:     //The player survived

                bonnieThread.join();
                batteryThread.join();
                timerThread.join();

                erase();
                mvprintw(y, x, "6:00");
                refresh();
                sleep(2);
                return nightNumber; 

            case 0:     //The player is dead

                bonnieThread.join();
                batteryThread.join();
                timerThread.join();

                erase();
                mvprintw(y, x, "You Are Dead");
                refresh();
                sleep(10);
                return -1;

        }

        switch (camOpen) {

            case 0:

                init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
                attron(A_BOLD);
                attron(COLOR_PAIR(5));
		        mvaddch(y, x, '*');
                attroff(COLOR_PAIR(5));
                attroff(A_BOLD);
		        refresh();

        }


		input = getch();
		
		switch(input) {

            case '`':

                gameStatus = 1;
                break;

			case 'e':
			case 'E':

				if (mvinch(y - 1, x) == '=' && !camOpen) {

					camera.openCamera();

				} else if (camOpen) {

					camera.closeCamera();			
                    x = xCamPos;
                    y = yCamPos;

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

				switch (moveOk(y, x + 1)) {

                    case 1:

					    mvaddch(y, x, ' ');
					    x++;

				}

				break;

			case 'a':	
			case 'A':

				switch (moveOk(y, x - 1)) {

                    case 1:
					    mvaddch(y, x, ' ');
					    x--;

				}

				break;
	
			case 's':
			case 'S':

				switch (moveOk(y + 1, x)) {

                    case 1:
					    mvaddch(y, x, ' ');
					    y++;

				}

				break;

			case 'w':
			case 'W':

				switch (moveOk(y - 1, x)) {

                    case 1:
					    mvaddch(y, x, ' ');
					    y--;

				}

				break;
		}
	}
}
