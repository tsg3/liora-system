#include <Adafruit_NeoPixel.h>

struct tambor {
  uint32_t first_led;
  uint32_t last_led;
  uint32_t color;
  uint32_t brightness;
};

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    10

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 24

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

struct tambor tambor1 = {0, 4, strip.Color(255, 255, 255), 0};
struct tambor tambor2 = {4, 4, strip.Color(255, 255, 255), 0};
struct tambor tambor3 = {8, 4, strip.Color(255, 255, 255), 0};
struct tambor tambor4 = {12, 4, strip.Color(255, 255, 255), 0};
struct tambor tambor5 = {16, 4, strip.Color(255, 255, 255), 0};
struct tambor tambor6 = {20, 4, strip.Color(255, 255, 255), 0};

void updateTambor(struct tambor tamborN, uint32_t color) {
  tamborN.color = color;
  strip.fill(tamborN.color, tamborN.first_led, tamborN.last_led);
}

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  uint32_t color = strip.Color(255, 255, 255);
  //strip.setPixelColor(1, 255, 255, 255);
  //strip.fill(color, 0, 24);
  
  //updateTambor(tambor1, tambor1.color);
  //updateTambor(tambor2, tambor2.color);
  //updateTambor(tambor3, tambor3.color);
  //updateTambor(tambor4, tambor4.color);
  //updateTambor(tambor5, tambor5.color);
  //updateTambor(tambor6, tambor6.color);

  strip.setPixelColor(0, 255, 255, 255);
  strip.setPixelColor(4, 255, 255, 255);
  strip.setPixelColor(8, 255, 255, 255);
  strip.setPixelColor(12, 255, 255, 255);
  strip.setPixelColor(16, 255, 255, 255);
  strip.setPixelColor(20, 255, 255, 255);

  strip.setBrightness(255);
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  strip.show();
}
