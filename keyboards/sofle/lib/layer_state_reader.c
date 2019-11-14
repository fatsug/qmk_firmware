#include QMK_KEYBOARD_H
#include <stdio.h>
#include "sofle.h"

#define L_DEFAULT 0
#define L_M_LOWER 4
#define L_W_LOWER 8
#define L_M_RAISE 16
#define L_W_RAISE 32
#define L_ADJUST 104


char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_DEFAULT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_W_RAISE:
  case L_M_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_W_LOWER:
  case L_M_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
