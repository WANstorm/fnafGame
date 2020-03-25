#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game : public Player {

	public:
		int getInput(int y, int x);
};

#endif
