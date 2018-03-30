#ifndef VEC_H_
#define VEC_H_

typedef struct vec_t vec_t;
struct vec_t {
  double x, y;
};

double vec_length(vec_t v);
vec_t vec_add(vec_t v1, vec_t v2);
vec_t vec_sub(vec_t v1, vec_t v2);
vec_t vec_scale(vec_t v, double s);
double vec_dot(vec_t v1, vec_t v2);
double vec_cross(vec_t v1, vec_t v2);
vec_t vec_rotate(vec_t v, double angle, vec_t origin);

#endif
