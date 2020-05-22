#include <ncurses.h>
#include <unistd.h>
#include <string>
#include "battery.h"
#include "game.h"
#include "camera.h"

int Battery::startBattery() {

    sleep(2);

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    int batteryColor = 1;

    int y, x;
    getmaxyx(stdscr, y, x);

    WINDOW *batteryWin;

    batteryWin = newwin(1, 3, (y / 2) + 7, (x / 2) - 1);

    int batteryLevel = 100;

    while (true) {

        sleep(4);

        int batteryUsage = 1;

        switch (gameStatus) {

            case 0:
                return 0;

            case 1:
                return 1;

        }

        if (batteryLevel <= 0) {

            gameStatus = 0; //Death status
            return 0;

        }

        if (leftDoorClosed) {

            batteryUsage += 2;

        }

        if (rightDoorClosed) {

            batteryUsage += 2;

        }

        if (camOpen) {

            batteryUsage += 1;

        }

        batteryLevel -= batteryUsage;

        if (batteryLevel < 50 && batteryLevel > 20) {

            batteryColor = 2;

        } else if (batteryLevel <= 20) {

            batteryColor = 3;

        }

        wclear(batteryWin);
        wattron(batteryWin, COLOR_PAIR(batteryColor));
        wprintw(batteryWin, std::to_string(batteryLevel).c_str());
        wattroff(batteryWin, COLOR_PAIR(batteryColor));
        wrefresh(batteryWin);

    }

    delwin(batteryWin);
    return 0;

}
