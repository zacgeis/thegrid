#ifndef LEVEL_H_
#define LEVEL_H_

#include "game.h"

void level_new(game_state_t *gs);
void level_free(game_state_t *gs);
void level_update(game_state_t *gs, double delta);

#endif

