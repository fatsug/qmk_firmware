#include QMK_KEYBOARD_H
#include <stdio.h>
#include "sofle.h"

#define L_M_COLEMAK 1
#define L_W_COLEMAK 2

char mode_state_str[24];

const char *read_mode_state(void) {
  switch (default_layer_state)
  {
  case L_W_COLEMAK:
    snprintf(mode_state_str, sizeof(mode_state_str), "Mode: Colemak Linux");
    break;
  case L_M_COLEMAK:
    snprintf(mode_state_str, sizeof(mode_state_str), "Mode: Colemak Mac");
    break;
  default:
    snprintf(mode_state_str, sizeof(mode_state_str), "Mode: Undef-%ld", default_layer_state);
  }

  return mode_state_str;
}
