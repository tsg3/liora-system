// C/C++ sources
#include <stdbool.h>

// Third-party libraries
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Local sources
#include "animation.h"

static uint8_t run_sequence_effect(animation *animation, panel *panels);

animation create_animation(uint8_t total_childs, bool time_based,
                           uint16_t total_time, uint8_t n) {
  animation animation = {
    .current_child = 0,
    .childs = total_childs,
    .time_based = time_based,
    .cycles = total_time,
    .current_time = 0,
    .effect = -1,
    .effects = n,
  };
  reset_animation(&animation);
  return animation;
}

void reset_animation(animation *animation) {
  animation->effStep = 0;
  animation->effect = (animation->effect + 1) % animation->effects;
  animation->effStart = millis();
}

uint8_t run_sequence(animation *animation, panel *panels) {
  uint8_t ret = 0x00;

  // This switch manages the current effect being displayed
  switch(animation->current_child) {
    case 0: 
      ret = run_sequence_effect(animation, panels);
      break;
  }

  if (ret & 0x02) {
    ret &= 0xfd;
    if (animation->current_child + 1 >= animation->childs) {
      animation->current_child = 0;
      if (++animation->current_time >= animation->cycles) {
        animation->current_time = 0; ret |= 0x02;
      }
    }
    else {
      animation->current_child++;
    }
  }

  return ret;
}

static uint8_t run_sequence_effect(animation *animation,  panel *panels) {
  // This is a demo, we need to figure out how to dynamically change this
  //  (or define just a set of animations).
  // Strip ID: 0 - Effect: Blink - LEDS: 19
  // Steps: 498 - Delay: 1
  // Colors: 2 (0.0.0, 255.0.255)
  // Options: timeBegin=100, timeToOn=97, timeOn=99, timeToOff=99, timeOver=103, every=1, 
  if(millis() - animation->effStart < 1 * (animation->effStep)) return 0x00;
  uint8_t e,r,g,b;
  if(animation->effStep < 100) {
    for(uint16_t j=0;j<animation->effects;j++) 
      // animation->panels->strip->setPixelColor(j, 0, 0, 0);
      set_panel_color(panels + j, RGB(0, 0, 0));
  }
  else if(animation->effStep  < 597) {
    e = (animation->effStep * 1) - 100;
    r = (uint8_t) 255.0 * ( e / 497.0 ) + 0.0 * ( 1.0 - e / 497.0 );
    g = (uint8_t) 0.0 * ( e / 497.0 ) + 0.0 * ( 1.0 - e / 497.0 );
    b = (uint8_t) 255.0 * ( e / 497.0 ) + 0.0 * ( 1.0 - e / 497.0 );
    for(uint16_t j=0;j<animation->effects;j++) 
      // if((j%1)==0) animation->panels->strip->setPixelColor(j, r, g, b);
      if((j%1)==0) set_panel_color(panels + j, RGB(r, g, b));
      // else animation->panels->strip->setPixelColor(j, 0, 0, 0);
      else set_panel_color(panels + j, RGB(0, 0, 0));
  }
  else if(animation->effStep < 696) {
    for(uint16_t j=0;j<animation->effects;j++) 
      // if((j%1)==0) animation->panels->strip->setPixelColor(j, 255, 0, 255);
      if((j%1)==0) set_panel_color(panels + j, RGB(255, 0, 255));
      // else animation->panels->strip->setPixelColor(j, 0, 0, 0);
      else set_panel_color(panels + j, RGB(0, 0, 0));
  }
  else if(animation->effStep < 1195) {
    e = (animation->effStep * 1) - 696;
    r = (uint8_t) 0.0 * ( e / 499.0 ) + 255.0 * ( 1.0 - e / 499.0 );
    g = (uint8_t) 0.0 * ( e / 499.0 ) + 0.0 * ( 1.0 - e / 499.0 );
    b = (uint8_t) 0.0 * ( e / 499.0 ) + 255.0 * ( 1.0 - e / 499.0 );
    for(uint16_t j=0;j<animation->effects;j++) 
      // if((j%1)==0) animation->panels->strip->setPixelColor(j, r, g, b);
      if((j%1)==0) set_panel_color(panels + j, RGB(r, g, b));
      // else animation->panels->strip->setPixelColor(j, 0, 0, 0);
      else set_panel_color(panels + j, RGB(0, 0, 0));
  }
  else {
    for(uint16_t j=0;j<animation->effects;j++) 
      // animation->panels->strip->setPixelColor(j, 0, 0, 0);
      set_panel_color(panels + j, RGB(0, 0, 0));
  }
  if(animation->effStep >= 1298) {reset_animation(animation); return 0x03; }
  else animation->effStep++;
  return 0x01;
}
