/* Copyright 2019 Josef Adamcik
 *
 *  This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum katana_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _M_COLEMAK,
    _M_QWERTY,
    _W_COLEMAK,
    _W_QWERTY,
    _M_SPLIT,
    _W_SPLIT,
    _NUMB,
    _SYMB,
    _M_EXT,
    _W_EXT,
    _M_LOWER,
    _M_RAISE,
    _W_LOWER,
    _W_RAISE,
    _ADJUST,
};

enum katana_keycodes {
    M_COLEMAK = SAFE_RANGE,
    M_QWERTY,
    W_COLEMAK,
    W_QWERTY,
    M_SPLIT,
    W_SPLIT,
    M_LOWER,
    M_RAISE,
    W_LOWER,
    W_RAISE,
    ADJUST,
};

#define K_SPCEXW LT(_W_EXT, KC_SPACE) /* Tap for space, hold for layer */
#define K_SPCEXM LT(_M_EXT, KC_SPACE) /* Tap for space, hold for layer */
#define K_BSPFN LT(_SYMB, KC_BSPC)  /* Tap for backspace, hold for layer */
#define K_ENTFN LT(_SYMB, KC_ENT)  /* Tap for enter, hold for layer */
#define M_ENTLW LT(_M_LOWER, KC_ENT)  /* Tap for enter, hold for layer */
#define M_SPCRA LT(_M_RAISE, KC_SPACE) /* Tap for space, hold for layer */
#define W_ENTLW LT(_W_LOWER, KC_ENT)  /* Tap for enter, hold for layer */
#define W_SPCRA LT(_W_RAISE, KC_SPACE) /* Tap for space, hold for layer */
/* Linux/win variants */
#define W_LEFT_MOD MT(MOD_RCTL, KC_LEFT)
#define W_DOWN_MOD MT(MOD_RALT, KC_DOWN)
#define W_UP_MOD MT(MOD_RGUI, KC_UP)
#define W_UNDO    LCTL(KC_Z)
#define W_CUT     LCTL(KC_X)
#define W_COPY    LCTL(KC_C)
#define W_PASTE   LCTL(KC_V)
#define W_PRVWD LCTL(KC_LEFT)
#define W_NXTWD LCTL(KC_RIGHT)
#define W_LSTRT KC_HOME
#define W_LEND KC_END
#define W_DLINE LCTL(KC_BSPC)
/* Mac variants */
#define M_LEFT_MOD MT(MOD_RGUI, KC_LEFT)
#define M_DOWN_MOD MT(MOD_RALT, KC_DOWN)
#define M_UP_MOD MT(MOD_RCTL, KC_UP)
#define M_UNDO LGUI(KC_Z)
#define M_CUT LGUI(KC_X)
#define M_COPY LGUI(KC_C)
#define M_PASTE LGUI(KC_V)
#define M_PRVWD LALT(KC_LEFT)
#define M_NXTWD LALT(KC_RIGHT)
#define M_LSTRT LGUI(KC_LEFT)
#define M_LEND LGUI(KC_RIGHT)
#define M_DLINE LGUI(KC_BSPC)

#define XXXXX KC_NO
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_LOWER LOWER
#define KC_RAISE RAISE

#define KC_GUIZ LGUI_T(KC_Z)
#define KC_CTLZ LCTL_T(KC_Z)
#define KC_ALTX LALT_T(KC_X)
#define KC_ALTDOT RALT_T(KC_DOT)
#define KC_GUISLSH RGUI_T(KC_SLSH)
#define KC_CTLSLSH RCTL_T(KC_SLSH)

#define KC_CTLEQ LCTL_T(KC_EQUAL)
#define KC_GUIEQ LGUI_T(KC_EQUAL)
#define KC_ALTMINS LALT_T(KC_MINS)
#define KC_ALTCOLN RALT_T(KC_COLN)
#define KC_GUIBSLS RGUI_T(KC_BSLS)
#define KC_CTLBSLS RCTL_T(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_M_COLEMAK] = LAYOUT(
    KC_ESC,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   TG(_NUMB),KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC,          KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    MO(_M_EXT),KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_MINS,          KC_QUOT, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,  KC_DEL,  KC_BSLS, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(_SYMB), KC_LCTL, KC_LALT, KC_LGUI,                   K_ENTFN, KC_ENT,  K_SPCEXM,         M_LEFT_MOD,M_DOWN_MOD,M_UP_MOD,  KC_RIGHT,MO(_SYMB)
),
[_M_QWERTY] = LAYOUT(
    KC_ESC,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   TG(_NUMB),KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MO(_M_EXT),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,          KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,  KC_DEL,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(_SYMB), KC_LCTL, KC_LALT, KC_LGUI,                   K_ENTFN, KC_ENT,  K_SPCEXM,         M_LEFT_MOD,M_DOWN_MOD,M_UP_MOD,   KC_RIGHT,MO(_SYMB)
),
[_W_COLEMAK] = LAYOUT(
    KC_ESC,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   TG(_NUMB),KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC,          KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    MO(_W_EXT),KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_MINS,          KC_QUOT, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,  KC_DEL,  KC_BSLS, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(_SYMB), KC_LGUI, KC_LALT, KC_LCTL,                   K_ENTFN, KC_ENT,  K_SPCEXW,         W_LEFT_MOD,W_DOWN_MOD,W_UP_MOD,  KC_RIGHT,MO(_SYMB)
),
[_W_QWERTY] = LAYOUT(
    KC_ESC,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   TG(_NUMB),KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MO(_W_EXT),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,          KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,  KC_DEL,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(_SYMB), KC_LGUI, KC_LALT, KC_LCTL,                   K_ENTFN, KC_ENT,  K_SPCEXW,         W_LEFT_MOD,W_DOWN_MOD,W_UP_MOD,   KC_RIGHT,MO(_SYMB)
),
[_M_SPLIT] = LAYOUT(
    XXXXX,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  XXXXX,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    XXXXX,   XXXXX,
    KC_ESC,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXX,          XXXXX,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXX,          XXXXX,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXX,  XXXXX,  XXXXX,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL,  KC_LALT, KC_LGUI, M_LOWER,                   KC_ENT, XXXXX,  KC_SPACE,        M_RAISE, KC_RGUI, KC_RALT, KC_RCTL,   XXXXX
),
[_W_SPLIT] = LAYOUT(
    XXXXX,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  XXXXX,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    XXXXX,   XXXXX,
    KC_ESC,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXX,          XXXXX,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXX,          XXXXX,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXX,  XXXXX,  XXXXX,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LGUI,  KC_LALT, KC_LCTL, W_LOWER,                   KC_ENT, XXXXX, KC_SPACE,         W_RAISE, KC_RCTL, KC_RALT, KC_RGUI,   XXXXX
),
[_NUMB] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, KC_PSLS, KC_PAST, KC_PMNS, _______, _______,
    _______, _______, _______, KC_MS_U, _______, _______, _______,          _______,_______, KC_7,    KC_8,    KC_9,    KC_PPLS, _______,
    _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,          _______,_______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______,_______, KC_1,    KC_2,    KC_3,    KC_PENT, _______,
    _______, _______, _______, _______,                   KC_BTN1, _______, KC_P0,            KC_PDOT, _______, _______, _______, _______
),
[_SYMB] = LAYOUT(
    RESET,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_VOLD,          KC_VOLU, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_EQL, KC_MINS, KC_PLUS ,  KC_LCBR, KC_RCBR, KC_MPRV, KC_MPLY, KC_MNXT, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
    _______, _______, _______, _______,                   KC_DEL,  _______, _______,          _______, _______, _______, _______, _______
),
[_M_EXT] = LAYOUT(
    RESET  ,M_COLEMAK,M_QWERTY,W_COLEMAK,W_QWERTY,M_SPLIT,_______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGUP, M_PRVWD, KC_UP,   M_NXTWD, M_DLINE, _______,
    _______, KC_LALT, KC_LCTL, KC_LSFT, _______, KC_CAPS, _______,          _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_DEL,  _______,
    _______, M_UNDO,  M_CUT,   M_COPY,  M_PASTE, _______, _______, _______, _______, _______, M_LSTRT, _______, M_LEND,  _______, _______,
    _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
),
[_W_EXT] = LAYOUT(
    RESET  ,M_COLEMAK,M_QWERTY,W_COLEMAK,W_QWERTY,M_SPLIT,W_SPLIT, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGUP, W_PRVWD, KC_UP,   W_NXTWD, W_DLINE, _______,
    _______, KC_LALT, KC_LCTL, KC_LSFT, _______, KC_CAPS, _______,          _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_DEL,  _______,
    _______, W_UNDO,  W_CUT,   W_COPY,  W_PASTE, _______, _______, _______, _______, _______, W_LSTRT, _______, W_LEND,  _______, _______,
    _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
),
[_M_LOWER] = LAYOUT(
     XXXXX,   XXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXX, KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,     XXXXX,
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXX,          XXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_F12,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXX,          XXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_PIPE,
    KC_LSFT, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, XXXXX,   XXXXX, XXXXX, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS,  KC_RSFT,
    KC_LCTL,  KC_LALT, KC_LGUI, M_LOWER,                  KC_ENT, XXXXX,  KC_SPACE,        M_RAISE, KC_RGUI, KC_RALT, KC_RCTL,   XXXXX

),
[_M_RAISE] = LAYOUT(
    RESET,  M_COLEMAK,M_QWERTY,W_COLEMAK,W_QWERTY,M_SPLIT,  W_SPLIT,  XXXXX,  XXXXX, XXXXX,     XXXXX,   XXXXX,   XXXXX,    XXXXX,   XXXXX,
    KC_ESC,  KC_INS,  KC_PSCR,  KC_APP,   XXXXX,   XXXXX,    XXXXX,          XXXXX, KC_PGUP, M_PRVWD,   KC_UP, M_NXTWD,    XXXXX,   KC_BSPC,
    KC_TAB,  KC_LALT, KC_LCTL,  KC_LSFT,  XXXXX, KC_CAPS,    XXXXX,          XXXXX, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT,   KC_DEL,   XXXXX,
    KC_LSFT,  M_UNDO,   M_CUT,  M_COPY, M_PASTE,   XXXXX,    XXXXX,  XXXXX,  XXXXX, XXXXX,   M_LSTRT,   XXXXX,  M_LEND,    XXXXX, KC_RSFT,
    KC_LCTL,  KC_LALT, KC_LGUI, M_LOWER,                     KC_ENT, XXXXX,  KC_SPACE,        M_RAISE, KC_RGUI, KC_RALT, KC_RCTL,   XXXXX
),
[_W_LOWER] = LAYOUT(
    XXXXX,   XXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXX, KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,      XXXXX,
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXX,          XXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_F12,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXX,          XXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_PIPE,
    KC_LSFT, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, XXXXX,   XXXXX, XXXXX, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS,  KC_RSFT,
    KC_LGUI,  KC_LALT, KC_LCTL, W_LOWER,                  KC_ENT, XXXXX, KC_SPACE,         W_RAISE, KC_RCTL, KC_RALT, KC_RGUI,   XXXXX
),
[_W_RAISE] = LAYOUT(
    RESET,  M_COLEMAK,M_QWERTY,W_COLEMAK,W_QWERTY,M_SPLIT,  W_SPLIT,  XXXXX,  XXXXX, XXXXX,     XXXXX,   XXXXX,   XXXXX,    XXXXX,   XXXXX,
    KC_ESC,  KC_INS,  KC_PSCR,  KC_APP,   XXXXX,   XXXXX,    XXXXX,          XXXXX, KC_PGUP, W_PRVWD,   KC_UP, W_NXTWD,    XXXXX,   KC_BSPC,
    KC_TAB,  KC_LALT, KC_LCTL,  KC_LSFT,  XXXXX, KC_CAPS,    XXXXX,          XXXXX, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT,   KC_DEL,   XXXXX,
    KC_LSFT, M_UNDO,   M_CUT,  M_COPY, M_PASTE,   XXXXX,     XXXXX,  XXXXX,  XXXXX, XXXXX,   W_LSTRT,   XXXXX,  W_LEND,    XXXXX, KC_RSFT,
    KC_LGUI,  KC_LALT, KC_LCTL, W_LOWER,                     KC_ENT, XXXXX, KC_SPACE,         W_RAISE, KC_RCTL, KC_RALT, KC_RGUI,   XXXXX
)//,
// /* not used = not properly defined */
// [_ADJUST] = LAYOUT(
//     RESET,  M_COLEMAK,M_QWERTY,W_COLEMAK,W_QWERTY,M_SPLIT, XXXXX,  XXXXX,  XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX,    XXXXX,   XXXXX,
//     XXXXX,   XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX,    XXXXX,          XXXXX, XXXXX, XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,
//     XXXXX,   XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX,    XXXXX,          XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX,
//     KC_LSFT, XXXXX, XXXXX, XXXXX,   XXXXX,    XXXXX,   XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_RSFT,
//     XXXXX,    KC_LCTL, KC_LALT, KC_LGUI,                 W_ENTLW,  XXXXX,  W_SPCRA,         KC_RGUI, KC_RALT, KC_RCTL,   XXXXX,   XXXXX
// )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_M_QWERTY);
            }
            return false;
            break;
        case M_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_M_COLEMAK);
            }
            return false;
            break;
        case W_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_W_QWERTY);
            }
            return false;
            break;
        case W_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_W_COLEMAK);
            }
            return false;
            break;
        case M_SPLIT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_M_SPLIT);
            }
            return false;
            break;
        case W_SPLIT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_W_SPLIT);
            }
            return false;
            break;
        case W_LOWER:
            if (record->event.pressed) {
                layer_on(_W_LOWER);
                // update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
            } else {
                layer_off(_W_LOWER);
                // update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
            }
            return false;
            break;
        case W_RAISE:
            if (record->event.pressed) {
                layer_on(_W_RAISE);
                // update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
            } else {
                layer_off(_W_RAISE);
                // update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
            }
            return false;
            break;
        case M_LOWER:
            if (record->event.pressed) {
                layer_on(_M_LOWER);
                // update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
            } else {
                layer_off(_M_LOWER);
                // update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
            }
            return false;
            break;
        case M_RAISE:
            if (record->event.pressed) {
                layer_on(_M_RAISE);
                // update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
            } else {
                layer_off(_M_RAISE);
                // update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
            }
            return false;
            break;
        // case ADJUST:
        // if (record->event.pressed) {
                // layer_on(_ADJUST);
            // } else {
            //     layer_off(_ADJUST);
            // }
            // return false;
            // break;
        }
    return true;
}

void led_set_user(uint8_t usb_led) {

}
