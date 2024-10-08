#ifndef SYSTEM_PANEL_H
#define SYSTEM_PANEL_H

/******************************************************************************
 * Panel library
 *
 * Manages the LED panels (known as "Tambores") in the system.
 ******************************************************************************/

// Panel struct
typedef struct panel {
  // LED range in the NeoPixel strip
  uint8_t index;
  uint8_t n;

  // Color change flag
  bool has_color_changed;

  // Current LED RGB value
  uint32_t color;
} panel;

// Create NeoPixel LED strip object
Adafruit_NeoPixel create_strip(uint8_t n, uint8_t pin, uint16_t type);

// Create panel struct
panel create_panel(uint8_t index, uint8_t n);

// Set panel color
void set_panel_color(panel *panel, Adafruit_NeoPixel *strip, uint8_t r,
                     uint8_t g, uint8_t b);

// Set 'has_color_changed' to false
void panel_update_flag(panel *panel);

#endif
