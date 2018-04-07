#include "manager.h"

#include "mainmenu.h"
#include "level.h"

void manager_switch_scene(game_state_t *gs, scene_t scene) {
  if (gs->scene != scene) {
    switch (gs->scene) {
      case NOSCENE: break;
      case MAINMENU: mainmenu_free(gs); break;
      case LEVEL: level_free(gs); break;
    }

    switch (scene) {
      case NOSCENE: break;
      case MAINMENU: mainmenu_new(gs); break;
      case LEVEL: level_new(gs); break;
    }

    gs->scene = scene;
  }
}

void manager_update_scene(game_state_t *gs, double delta) {
    switch (gs->scene) {
      case NOSCENE: break;
      case MAINMENU: mainmenu_update(gs, delta); break;
      case LEVEL: level_update(gs, delta); break;
    }
}
