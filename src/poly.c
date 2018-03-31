#include <stdlib.h>

#include "poly.h"

poly_t *poly_new(int length, vec_t **vecs) {
  poly_t *poly = malloc(sizeof(poly_t));

  poly->length = length;
  poly->vecs = vecs;

  return poly;
}

void poly_free(poly_t *p) {
  for (int i = 0; i < p->length; i++) {
    vec_free(p->vecs[i]);
  }
  free(p);
}

void poly_add(poly_t *p, vec_t *v) {
  for (int i = 0; i < p->length; i++) {
    vec_add(p->vecs[i], v);
  }
}

void poly_sub(poly_t *p, vec_t *v) {
  for (int i = 0; i < p->length; i++) {
    vec_sub(p->vecs[i], v);
  }
}

void poly_scale(poly_t *p, double s) {
  for (int i = 0; i < p->length; i++) {
    vec_scale(p->vecs[i], s);
  }
}

void poly_rotate(poly_t *p, double angle, vec_t *origin) {
  for (int i = 0; i < p->length; i++) {
    vec_rotate(p->vecs[i], angle, origin);
  }
}
