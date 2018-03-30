#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

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

typedef struct game_state_t game_state_t;
struct game_state_t {
  keyboard_state_t *keyboard;
  mouse_state_t *mouse;
  scene_t scene;
  ALLEGRO_FONT *font;
  ALLEGRO_FONT *large_font;
};

#endif
