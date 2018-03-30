#include "mainmenu.h"

#include "manager.h"

void mainmenu_destroy(game_state_t *gs) {

}

void mainmenu_create(game_state_t *gs) {

}

void mainmenu_update(game_state_t *gs) {
  if (gs->keyboard->space) {
    manager_switch_scene(gs, LEVEL);
  }

  al_draw_textf(gs->large_font, WHITE, WIDTH / 2, (HEIGHT / 4), ALLEGRO_ALIGN_CENTER, "THE GRID");

  int line_height = al_get_font_line_height(gs->font);
  int text_width = 280;
  al_draw_multiline_text(
    gs->font,
    WHITE,
    (WIDTH / 2) - (text_width / 2) + 50,
    HEIGHT / 2,
    text_width,
    line_height,
    ALLEGRO_ALIGN_LEFT,
    "Basic Instructions:\n ESC to exit game.\n WASD to move.\n Mouse to aim.\n Left click to shoot\n 1-9 to switch weapons.\n\nPress SPACE key to continue."
  );
}
