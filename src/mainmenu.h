#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "game.h"

void mainmenu_destroy(game_state_t *gs);
void mainmenu_create(game_state_t *gs);
void mainmenu_update(game_state_t *gs, double delta);

#endif
