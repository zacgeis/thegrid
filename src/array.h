#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h>

#define MIN_CAPACITY 2

typedef struct array_t array_t;
struct array_t {
  void **buffer;
  int capacity;
  int length;
  size_t object_size;
};

array_t *array_new();
void array_free(array_t *arr);
#define array_get(type, arr, i) (* ((type *) _array_get(arr, i)))
void *_array_get(array_t *arr, int i);
#define array_add(type, arr, val) (* ((type *) _array_add(arr))) = val;
void *_array_add(array_t *arr);
void array_pop(array_t *arr);
void array_remove(array_t *arr, int i);

/*
for (int i = 0; i < arr->length; i++) {
  obj_t o = array_get(obj_t, arr, i);
  printf("%f", o.x);
}
*/

#endif

