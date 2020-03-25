#include <ncurses.h>
#include "player.h"
#include "camera.h"

bool Player::moveOk(int y, int x) {

	if(mvinch(y, x) == ' ')	{

		return true;

	} else if (mvinch(y, x) == '#') {

		return false;

	}

	return false;

}
