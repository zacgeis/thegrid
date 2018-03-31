#ifndef WORLD_H_
#define WORLD_H_

#include "game.h"

entity_t *entity_new(poly_t *poly, double mass, color_t color);
void entity_free(entity_t *entity);
void update_entities(array_t *entities, double delta);
void render_entities(array_t *entities);

#endif
