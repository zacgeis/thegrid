#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "game.h"

void mainmenu_new(game_state_t *gs);
void mainmenu_free(game_state_t *gs);
void mainmenu_update(game_state_t *gs, double delta);

#endif
