/******************************************************************************
 ******************************* Liora's System *******************************
 ******************************************************************************/

// Third-party libraries
#include <Adafruit_NeoPixel.h>

// Local sources
#include "panel.h"

/******************************************************************************
 ************************** Configuration parameters **************************
 ******************************************************************************/

// Number of LEDs on the NeoPixel strip
#define LED_COUNT 24

// Pin on the Arduino connected to the NeoPixel strip
#define LED_PIN 10

/*
 * Number of LED panels (this number must match the number of rows of
 * "panel_ranges").
 */
#define PANEL_N 19

// Default brightness for LEDs
#define BRIGHTNESS 255

// Panel ranges mapping (this number must match the value of "PANEL_N"
const static uint8_t panel_ranges[][2] = {
  {0, 1},  // 1st left panel
  {1, 1},  // 2nd left panel
  {2, 1},  // 3rd left panel
  {3, 1},  // 4th left panel
  {4, 1},  // 5th left panel
  {5, 1},  // 6th left panel
  {6, 1},  // 7th left panel
  {7, 1},  // 1st right panel
  {8, 1},  // 2nd right panel
  {9, 1},  // 3rd right panel
  {10, 1}, // 4th right panel
  {11, 1}, // 5th right panel
  {12, 1}, // 6th right panel
  {13, 1}, // 7th right panel
  {14, 2}, // Central panel
  {16, 2}, // Upper-left arrow panel
  {18, 2}, // Upper-right arrow panel
  {20, 2}, // Bottom-right arrow panel
  {22, 2}  // Bootom-left arrow panel
};

// Delay time
#define DELAY 1000

// Debug flag
#define DEBUG false

// Baud rate for the serial monitor
#define BAUD_RATE 9600

/******************************************************************************
 ****************************** Configuration end *****************************
 ******************************************************************************/

// NeoPixel strip object
Adafruit_NeoPixel strip;

// System panels
panel panels[PANEL_N];

// Update colors in the strip
void update_strip_colors() {
  for (size_t i = 0; i < PANEL_N; i++) {
    if (panels[i].has_color_changed) {
      strip.fill(panels[i].color, panels[i].index, panels[i].n);
      panel_update_flag(&panels[i]);
    }
  }
}

void setup() {
#if DEBUG == true
  Serial.begin(BAUD_RATE);
#endif

  // Initialize NeoPixel strip and turn LEDs off
  strip = create_strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.show();

  // Initialize system panels
  for (size_t i = 0; i < PANEL_N; i++) {
    panels[i] = create_panel(panel_ranges[i][0], panel_ranges[i][1]);
  }

  // Set strip brightness
  strip.setBrightness(BRIGHTNESS);

  // Set panels to their default colors
  strip.show();
}

void loop() {
  // Update strip
  update_strip_colors();
  strip.show();

  // Wait
  delay(DELAY);
}
