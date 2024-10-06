// Third-party libraries
#include <Adafruit_NeoPixel.h>

// Local sources
#include "panel.h"

// No color / LED off
#define BLACK 0

Adafruit_NeoPixel create_strip(uint8_t n, uint8_t pin, uint16_t type) {
  return Adafruit_NeoPixel(n, pin, type);
}

panel create_panel(uint8_t index, uint8_t n) {
  panel panel = {index, n, BLACK};
  panel.has_color_changed = true;
  return panel;
}

void set_panel_color(panel *panel, Adafruit_NeoPixel *strip, uint8_t r,
                     uint8_t g, uint8_t b) {
  panel->color = strip->Color(r, g, b);
  panel->has_color_changed = true;
}

void panel_update_flag(panel *panel) {
  panel->has_color_changed = false;
}
