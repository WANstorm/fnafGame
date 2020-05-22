#include "player.h"

#ifndef GAME_H
#define GAME_H

extern bool leftDoorClosed;
extern bool rightDoorClosed;
extern int gameStatus;

class Game : public Player {

	public:
		int getInput(int y, int x);

};

#endif
