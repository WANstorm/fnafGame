//Compile with .sh file. 

#include <ncurses.h>
#include <fstream>
#include "setup.h"
#include "mapBuilder.h"
#include "player.h"
#include "game.h"

int main() {

	Setup setup;
	Player player;
	Game game;

	int y,x;
	getmaxyx(stdscr, y, x);

    int status = game.getInput(y / 2, x / 2);

    while (true) {

            if (status != -1) {

                gameStatus = -1;
                std::ofstream writeSave("night.save");
                writeSave << status + 1;
                writeSave.close();
                status = game.getInput(y / 2, x / 2);
                continue;

            } else if (status == -1) {

                gameStatus = -1;
                status = game.getInput(y / 2, x / 2);
                continue;

            }
    }

	setup.endCurses();

}
