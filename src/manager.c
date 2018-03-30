#include "manager.h"

#include "mainmenu.h"
#include "level.h"

void manager_switch_scene(game_state_t *gs, scene_t scene) {
  if (gs->scene != scene) {
    switch (gs->scene) {
      case NOSCENE: break;
      case MAINMENU: mainmenu_destroy(gs); break;
      case LEVEL: level_destroy(gs); break;
    }

    switch (scene) {
      case NOSCENE: break;
      case MAINMENU: mainmenu_create(gs); break;
      case LEVEL: level_create(gs); break;
    }

    gs->scene = scene;
  }
}

void manager_update_scene(game_state_t *gs) {
    switch (gs->scene) {
      case NOSCENE: break;
      case MAINMENU: mainmenu_update(gs); break;
      case LEVEL: level_update(gs); break;
    }
}
