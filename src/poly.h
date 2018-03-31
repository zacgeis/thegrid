#ifndef POLY_H_
#define POLY_H_

#include "vec.h"

typedef struct poly_t poly_t;
struct poly_t {
  int length;
  vec_t **vecs;
};

poly_t *poly_new(int length, vec_t **vecs);
void poly_free();
void poly_add(poly_t *p1, vec_t *v);
void poly_sub(poly_t *p1, vec_t *v);
void poly_scale(poly_t *p, double s);
void poly_rotate(poly_t *p, double angle, vec_t *origin);

#endif
