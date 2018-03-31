#include "world.h"

entity_t *entity_new(poly_t *poly, double mass, color_t color) {
  entity_t *entity = malloc(sizeof(entity_t));

  entity->poly = poly;
  entity->mass = mass;
  entity->color = color;

  entity->force.x = 0;
  entity->force.y = 0;

  entity->acc.x = 0;
  entity->acc.y = 0;

  entity->vel.x = 0;
  entity->vel.y = 0;

  return entity;
}

void entity_free(entity_t *entity) {
  poly_free(entity->poly);
  free(entity);
}

void update_entities(array_t *entities, double delta) {
  for (int i = 0; i < entities->length; i++) {
    entity_t *entity = array_get(entity_t *, entities, i);

    // Friction
    entity->force.x += (-1 * entity->vel.x) * FRICTION_BASE;
    entity->force.y += (-1 * entity->vel.y) * FRICTION_BASE;

    // Standard
    entity->acc.x = entity->force.x / entity->mass;
    entity->acc.y = entity->force.y / entity->mass;

    entity->vel.x += entity->acc.x * delta;
    entity->vel.y += entity->acc.y * delta;

    vec_t t = { .x = entity->vel.x * delta * SPEED_BASE, .y = entity->vel.y * delta * SPEED_BASE };
    // printf("%f, %f\n", t.x, t.y);
    poly_add(entity->poly, &t);

    // Clear force
    vec_scale(&entity->force, 0);
  }
}

void render_entities(array_t *entities) {
  for (int i = 0; i < entities->length; i++) {
    entity_t *entity = array_get(entity_t *, entities, i);

    float *verts = malloc(sizeof(float) * (entity->poly->length * 2));

    verts[0] = entity->poly->vecs[0]->x;
    verts[1] = entity->poly->vecs[0]->y;
    verts[2] = entity->poly->vecs[1]->x;
    verts[3] = entity->poly->vecs[1]->y;
    verts[4] = entity->poly->vecs[2]->x;
    verts[5] = entity->poly->vecs[2]->y;
    verts[6] = entity->poly->vecs[3]->x;
    verts[7] = entity->poly->vecs[3]->y;

    al_draw_filled_polygon(verts, entity->poly->length, al_map_rgb(entity->color.r, entity->color.g, entity->color.b));

    free(verts);
  }
}
