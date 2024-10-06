#ifndef PANEL_ANIMATION_H
#define PANEL_H

/******************************************************************************
 * Panel Animation library
 *
 * Handlers for the LED panels animations.
 ******************************************************************************/

// Local sources
#include "panel.h"

// Animation struct
typedef struct animation
{
  // Animation configuration
  uint8_t current_child;
  uint8_t childs;
  bool time_based;
  uint16_t cycles;
  uint16_t current_time;

  // Animation sequence variables
  // Current state
  uint8_t effect;
  // Number of effects
  uint8_t effects;
  // Effect step
  uint16_t effStep;
  // Effect start
  unsigned long effStart;
} animation;

// Create an animation instance
animation create_animation(uint8_t total_childs, bool time_based,
                           uint16_t total_time, uint8_t n);

// Reset an animation
void reset_animation(animation *animation);

// Runs a sequence
uint8_t run_sequence(animation *animation, panel *panels);

#endif
