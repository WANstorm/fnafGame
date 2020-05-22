#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>
#include "camera.h"
#include "bonnie.h"
#include "game.h"

int Bonnie::activate(int level) {

    int currentYPos;
    int currentXPos;

    getmaxyx(stdscr, currentYPos, currentXPos);

    currentYPos /= 2;
    currentXPos /= 2;

    currentYPos -= 13;
    currentXPos -= 2;

    int requiredYPos = currentYPos;
    int requiredXPos = currentXPos;

    while (true) {

        switch (gameStatus) {

            case 0:
                return 0;

            case 1:
                return 1;

        }

        sleep(3); //4

        std::srand(std::time(0));
	    int randNum = std::rand() % 20 + 1;

	    if (randNum <= level) {

            if (camOpen) {

                mvaddch(currentYPos, currentXPos, ' ');

            }

            if (currentYPos < requiredYPos + 5) {

                currentYPos++;

            } else if (currentXPos > requiredXPos - 6 && currentYPos == requiredYPos + 5) {

                currentXPos--; 

            } else if (currentYPos < requiredYPos + 11 && currentXPos == requiredXPos - 6) {

                currentYPos++; 

            } else if (currentXPos < requiredXPos - 3 && currentYPos == requiredYPos + 11) {

                currentXPos++;

            } else if (currentXPos == requiredXPos - 3 && currentYPos == requiredYPos + 11) {

                for (int i = 0; i <= 3; i++) {
                    
                    sleep(1);
                                       
                    if (!leftDoorClosed) {

                        currentXPos += 5;
                        gameStatus = 0; //Death status
                        return 0;
                
                    } else if (leftDoorClosed && i == 3) {

                        currentXPos = requiredXPos;
                        currentYPos = requiredYPos;
                        break;

                    } else if (leftDoorClosed && i != 3) {

                        continue;

                    }
                }
            }
        }
    
        if (camOpen) {

            init_pair(6, COLOR_CYAN, COLOR_BLACK);
            attron(COLOR_PAIR(6) | A_BOLD | A_BLINK);
		    mvaddch(currentYPos, currentXPos, 'B');
            attroff(COLOR_PAIR(6) | A_BOLD | A_BLINK);
		    refresh();

        } 
    }
}
