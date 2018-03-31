#include "level.h"

#include "manager.h"
#include "world.h"

void level_destroy(game_state_t *gs) {
  for (int i = 0; i < gs->level_data->entities->length; i++) {
    entity_free(array_get(entity_t *, gs->level_data->entities, i));
    array_remove(gs->level_data->entities, i);
  }
  // TODO: figure out why this isn't working?
  // array_free(gs->level_data->entities);
  free(gs->level_data);
}

void level_create(game_state_t *gs) {
  int width = 40;
  int height = 40;
  int x = 100;
  int y = 100;
  vec_t **pv = malloc(sizeof(vec_t *) * 4);
  pv[0] = vec_new(x, y);
  pv[1] = vec_new(x, y + height);
  pv[2] = vec_new(x + width, y + height);
  pv[3] = vec_new(x + width, y);
  poly_t *player_poly = poly_new(4, pv);
  color_t color = { .r = 255, .g = 255, .b = 255 };
  entity_t *player = entity_new(player_poly, 1, color);
  array_t *entities = array_new(sizeof(entity_t *));
  array_add(entity_t *, entities, player);

  level_data_t *ld = malloc(sizeof(level_data_t));
  ld->entities = entities;
  ld->player = player;
  gs->level_data = ld;
}

void level_update(game_state_t *gs, double delta) {
  if (gs->keyboard->space) {
    manager_switch_scene(gs, MAINMENU);
  }

  vec_t force = { .x = 0, .y = 0 };
  if (gs->keyboard->w) {
    vec_t up = { .x = 0, .y = -1 };
    vec_add(&force, &up);
  }
  if (gs->keyboard->s) {
    vec_t down = { .x = 0, .y = 1 };
    vec_add(&force, &down);
  }
  if (gs->keyboard->a) {
    vec_t left = { .x = -1, .y = 0 };
    vec_add(&force, &left);
  }
  if (gs->keyboard->d) {
    vec_t right = { .x = 1, .y = 0 };
    vec_add(&force, &right);
  }
  vec_add(&gs->level_data->player->force, &force);

  update_entities(gs->level_data->entities, delta);
  render_entities(gs->level_data->entities);
}
