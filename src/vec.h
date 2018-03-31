#ifndef VEC_H_
#define VEC_H_

typedef struct vec_t vec_t;
struct vec_t {
  double x, y;
};

vec_t *vec_new(double x, double y);
void vec_free(vec_t *v);
double vec_length(vec_t *v);
void vec_add(vec_t *v1, vec_t *v2);
void vec_sub(vec_t *v1, vec_t *v2);
void vec_scale(vec_t *v, double s);
double vec_dot(vec_t *v1, vec_t *v2);
double vec_cross(vec_t *v1, vec_t *v2);
void vec_rotate(vec_t *v, double angle, vec_t *origin);

#endif
