#include <math.h>

#include "vec.h"

double vec_length(vec_t v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

vec_t vec_add(vec_t v1, vec_t v2) {
  vec_t v = { .x = v1.x + v2.x, .y = v1.y + v2.y };
  return v;
}

vec_t vec_sub(vec_t v1, vec_t v2) {
  vec_t v = { .x = v1.x - v2.x, .y = v1.y - v2.y };
  return v;
}

vec_t vec_scale(vec_t v1, double s) {
  vec_t v = { .x = v1.x * s, .y = v1.y * s };
  return v;
}

double vec_dot(vec_t v1, vec_t v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

double vec_cross(vec_t v1, vec_t v2) {
  return v1.x * v2.x - v1.y * v2.y;
}

vec_t vec_rotate(vec_t v, double angle, vec_t origin) {
  double x = v.x - origin.x;
  double y = v.y - origin.y;

  double x_prime = origin.x + ((v.x * cos(angle)) - (v.y * sin(angle)));
  double y_prime = origin.y + ((v.x * sin(angle)) - (v.y * cos(angle)));

  vec_t new_v = { .x = x_prime, .y = y_prime };
  return new_v;
}
