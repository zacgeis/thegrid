#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "array.h"
#include "poly.h"
#include "vec.h"

// Globals
#define FONT_PATH "res/IBMPlexMono-Medium.ttf"
#define FONT_SIZE 16
#define LARGE_FONT_SIZE 32
#define PI 3.14159265
#define WIDTH 800
#define HEIGHT 600
#define FPS 60.0

// Colors
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)

// Physics
#define SPEED_BASE 5000
#define FRICTION_BASE 5

typedef struct keyboard_state_t keyboard_state_t;
struct keyboard_state_t {
  bool w, a, s, d, space;
};

typedef struct mouse_state_t mouse_state_t;
struct mouse_state_t {
  vec_t pos;
  bool left, right;
};

typedef enum scene_t scene_t;
enum scene_t {
  NOSCENE, MAINMENU, LEVEL
};

typedef struct entity_t entity_t;
typedef struct color_t color_t;
struct color_t {
  int r, g, b;
};

struct entity_t {
  poly_t *poly;
  vec_t force;
  vec_t acc;
  vec_t vel;
  vec_t pos;
  double mass;
  // TODO: add something like static here?
  color_t color;
};


typedef struct level_data_t level_data_t;
struct level_data_t {
  entity_t *player;
  array_t *entities;
};

typedef struct game_state_t game_state_t;
struct game_state_t {
  keyboard_state_t *keyboard;
  mouse_state_t *mouse;
  scene_t scene;
  ALLEGRO_FONT *font;
  ALLEGRO_FONT *large_font;
  level_data_t *level_data;
};

#endif
