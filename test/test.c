#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../src/array.h"

static int count = 0;
void test(void (*func)()) {
  (*func)();
  printf(".");
  count++;
}

typedef struct obj_t obj_t;
struct obj_t {
  double x, y;
};

void test_simple_array() {
  obj_t t1 = { .x = 5, .y = 3 };
  obj_t t2 = { .x = 3, .y = 3 };
  obj_t t3 = { .x = 1, .y = 10 };

  array_t *arr = array_new(sizeof(obj_t));
  assert(arr->length == 0);
  assert(arr->capacity == 2);
  array_add(obj_t, arr, t1);
  array_add(obj_t, arr, t2);
  array_add(obj_t, arr, t3);
  assert(arr->length == 3);
  assert(arr->capacity == 4);

  assert(((obj_t *) _array_get(arr, 0))->x == 5);
  assert(array_get(obj_t, arr, 0).x == 5);
  assert(array_get(obj_t, arr, 2).y == 10);

  array_remove(arr, 1);
  assert(arr->length == 2);
  assert(arr->capacity == 4);
  assert(array_get(obj_t, arr, 0).x == 5);
  assert(array_get(obj_t, arr, 1).y == 10);

  array_remove(arr, 0);
  assert(arr->length == 1);
  assert(arr->capacity == 2);
  assert(array_get(obj_t, arr, 0).y == 10);
}

int main(int argc, char **argv) {
  test(test_simple_array);

  printf("\n");
  printf("\n");
  printf("Success (%d tests)", count);
  printf("\n");
  printf("\n");

  return 0;
}
