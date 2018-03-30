#include "game.h"

#include "manager.h"

void main_loop();

int main(int argc, char **argv) {
  if (!al_init()) {
    return -1;
  }

  if (!al_init_font_addon()) {
    return -1;
  }

  if (!al_init_ttf_addon()) {
    return -1;
  }

  if (!al_install_keyboard()) {
    return -1;
  }

  if (!al_install_mouse()) {
    return -1;
  }

  ALLEGRO_DISPLAY *display = al_create_display(WIDTH, HEIGHT);
  if (!display) {
    return -1;
  }

  ALLEGRO_FONT *font = al_load_ttf_font(FONT_PATH, FONT_SIZE, 0);
  ALLEGRO_FONT *large_font = al_load_ttf_font(FONT_PATH, LARGE_FONT_SIZE, 0);

  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
  if (!event_queue) {
    return -1;
  }

  ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_display_event_source(display));

  al_start_timer(timer);

  // Main Loop

  keyboard_state_t ks = {
    .w = false, .a = false, .s = false, .d = false, .space = false
  };
  mouse_state_t ms = {
    .pos = { .x = 0, .y = 0 }, .left = false, .right = false
  };
  game_state_t gs = {
    .keyboard = &ks,
    .mouse = &ms,
    .scene = NOSCENE,
    .font = font,
    .large_font = large_font
  };

  manager_switch_scene(&gs, MAINMENU);

  ALLEGRO_EVENT event;
  bool doexit = false;
  bool redraw = false;
  double current_fps = 0;
  double time_since_last_fps = 0;

  double old_time = al_get_time();
  while (true) {
    al_wait_for_event(event_queue, &event);

    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      doexit = true;
    }
    if (event.type == ALLEGRO_EVENT_TIMER) {
      redraw = true;
    }
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_ESCAPE: doexit = true; break;
        case ALLEGRO_KEY_W: ks.w = true; break;
        case ALLEGRO_KEY_A: ks.a = true; break;
        case ALLEGRO_KEY_S: ks.s = true; break;
        case ALLEGRO_KEY_D: ks.d = true; break;
        case ALLEGRO_KEY_SPACE: ks.space = true; break;
        default: break;
      }
    }
    if (event.type == ALLEGRO_EVENT_KEY_UP) {
      switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_W: ks.w = false; break;
        case ALLEGRO_KEY_A: ks.a = false; break;
        case ALLEGRO_KEY_S: ks.s = false; break;
        case ALLEGRO_KEY_D: ks.d = false; break;
        case ALLEGRO_KEY_SPACE: ks.space = false; break;
        default: break;
      }
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
      ms.pos.x = event.mouse.x;
      ms.pos.y = event.mouse.y;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
      if (event.mouse.button == 1) {
        ms.left = true;
      }
      if (event.mouse.button == 2) {
        ms.left = true;
      }
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
      if (event.mouse.button == 1) {
        ms.left = false;
      }
      if (event.mouse.button == 2) {
        ms.left = false;
      }
    }
    if (doexit) {
      break;
    }

    if (redraw && al_is_event_queue_empty(event_queue)) {
      redraw = false;

      double new_time = al_get_time();
      double delta = new_time - old_time;
      old_time = new_time;

      al_clear_to_color(BLACK);

      time_since_last_fps += delta;
      if (time_since_last_fps > 1) {
        current_fps = 1 / delta;
        time_since_last_fps = 0;
      }
      al_draw_textf(
        font,
        WHITE,
        WIDTH,
        0,
        ALLEGRO_ALIGN_RIGHT,
        "FPS: %3.0f",
        current_fps
      );

      manager_update_scene(&gs);

      al_flip_display();
    }
  }

  // End Main Loop

  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  al_destroy_display(display);
  al_destroy_font(font);
  al_destroy_font(large_font);

  al_uninstall_mouse();
  al_uninstall_keyboard();
  al_shutdown_font_addon();
  al_shutdown_ttf_addon();
  al_uninstall_system();

  return 0;
}
