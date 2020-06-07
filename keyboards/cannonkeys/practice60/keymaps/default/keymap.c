/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  KC_QWERTY = SAFE_RANGE,
  KC_COLEMAK,
  KC_LOWER,
  KC_RAISE,
  KC_ADJUST
};

/*
 * QWERTY
 * ,---------------------------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -_  |   =+ |  Bspc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [{  |   ]} | RGUI |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |   Caps   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |    Ent    |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |    LShift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |    RShift     |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |  LCTL | LGUI  |  LALT  |               S P A C E                   |  RALT  | RGUI | MO(1)| RCTRL |
 * .------+------+------+------+------+------|------+------+------+------+------+------+------+--------.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS, \
    MO(_LOWER), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,  \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT, \
    KC_LCTL,  KC_LGUI, KC_LALT,                        KC_SPC,                                   MO(_LOWER), MO(_RAISE), KC_APP, KC_RCTL
  ),

  [_COLEMAK] = LAYOUT_60_ansi(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, \
    KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,  KC_BSLS, \
    MO(_LOWER), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,           KC_ENT,  \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT, \
    KC_LCTL,  KC_LGUI, KC_LALT,                        KC_SPC,                                   MO(_LOWER), MO(_RAISE), KC_APP, KC_RCTL
  ),

  [_LOWER] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
    KC_CAPS, RGB_MOD, KC_UP,   _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______, _______, _______, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,          _______, \
    _______,  BL_DEC, KC_DEL,  _______, _______, _______, _______, _______, _______, KC_QWERTY, KC_COLEMAK,              _______, \
    _______,  _______, _______,                            _______,                            _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,          _______, \
    _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2,             _______, \
    _______,  _______, _______,                            _______,                            _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_60_ansi(
      RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX, \
    XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QWERTY, KC_COLEMAK,             XXXXXXX, \
    _______,  _______, _______,                            _______,                            _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}
