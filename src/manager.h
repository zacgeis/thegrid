#ifndef MANAGER_H_
#define MANAGER_H_

#include "game.h"

void manager_switch_scene(game_state_t *gs, scene_t scene);
void manager_update_scene(game_state_t *gs, double delta);

#endif
