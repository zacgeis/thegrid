#include <stdlib.h>
#include <math.h>

#include "vec.h"

vec_t *vec_new(double x, double y) {
  vec_t *v = malloc(sizeof(vec_t));

  v->x = x;
  v->y = y;

  return v;
}

void vec_free(vec_t *v) {
  free(v);
}

double vec_length(vec_t *v) {
  return sqrt(v->x * v->x + v->y * v->y);
}

void vec_add(vec_t *v1, vec_t *v2) {
  v1->x = v1->x + v2->x;
  v1->y = v1->y + v2->y;
}

void vec_sub(vec_t *v1, vec_t *v2) {
  v1->x = v1->x - v2->y;
  v1->y = v1->y - v2->y;
}

void vec_scale(vec_t *v1, double s) {
  v1->x = v1->x * s;
  v1->y = v1->y * s;
}

double vec_dot(vec_t *v1, vec_t *v2) {
  return v1->x * v2->x + v1->y * v2->y;
}

double vec_cross(vec_t *v1, vec_t *v2) {
  return v1->x * v2->x - v1->y * v2->y;
}

void vec_rotate(vec_t *v, double angle, vec_t *origin) {
  double x = v->x - origin->x;
  double y = v->y - origin->y;

  double x_prime = origin->x + ((v->x * cos(angle)) - (v->y * sin(angle)));
  double y_prime = origin->y + ((v->x * sin(angle)) - (v->y * cos(angle)));

  v->x = x_prime;
  v->y = y_prime;
}
