#include <string.h>

#include "array.h"

array_t *array_new(size_t object_size) {
  array_t *arr = malloc(sizeof(array_t));

  arr->object_size = object_size;
  arr->capacity = MIN_CAPACITY;
  arr->buffer = malloc(arr->object_size * arr->capacity);
  arr->length = 0;

  return arr;
}

void array_free(array_t *arr) {
  free(arr->buffer);
  free(arr);
}

void *_array_get(array_t *arr, int i) {
  return arr->buffer + (arr->object_size * i);
}

void *_array_add(array_t *arr) {
  arr->length += 1;
  if (arr->length > arr->capacity) {
    arr->capacity *= 2;
    arr->buffer = realloc(arr->buffer, arr->object_size * arr->capacity);
  }
  return _array_get(arr, arr->length - 1);
}

void array_pop(array_t *arr) {
  arr->length -= 1;
  if (arr->capacity > MIN_CAPACITY && arr->length < (arr->capacity / 2)) {
    arr->capacity /= 2;
    arr->buffer = realloc(arr->buffer, arr->object_size * arr->capacity);
  }
}

void array_remove(array_t *arr, int i) {
  if (i < arr->length - 1) {
    memcpy(_array_get(arr, i), _array_get(arr, arr->length - 1), arr->object_size);
  }
  array_pop(arr);
}
