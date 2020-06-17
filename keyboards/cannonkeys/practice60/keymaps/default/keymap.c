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


typedef union {
  uint32_t raw;
  struct {
    bool     is_macos :1;
  };
} user_config_t;

user_config_t user_config;

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
  KC_ADJUST,
  KC_ISMAC,
  KC_TGOS,
  KC_PRVWD,
  KC_NXTWD,
  KC_LSTRT,
  KC_LEND,
  KC_DLINE
};

/* Linux/win variants */
#define KC_W_UNDO    LCTL(KC_Z)
#define KC_W_CUT     LCTL(KC_X)
#define KC_W_COPY    LCTL(KC_C)
#define KC_W_PASTE   LCTL(KC_V)
#define KC_W_PRVWD   LCTL(KC_LEFT)
#define KC_W_NXTWD   LCTL(KC_RIGHT)
#define KC_W_LSTRT   KC_HOME
#define KC_W_LEND    KC_END
#define KC_W_DLINE   LCTL(KC_BSPC)
#define KC_W_ABHME   LCTL(KC_HOME)
#define KC_W_ABEND   LCTL(KC_END)

/* Mac variants */
#define KC_M_UNDO  LALT(KC_Z)
#define KC_M_CUT   LALT(KC_X)
#define KC_M_COPY  LALT(KC_C)
#define KC_M_PASTE LALT(KC_V)
#define KC_M_PRVWD LGUI(KC_LEFT)
#define KC_M_NXTWD LGUI(KC_RIGHT)
#define KC_M_LSTRT LALT(KC_LEFT)
#define KC_M_LEND  LALT(KC_RIGHT)
#define KC_M_DLINE LGUI(KC_BSPC)
#define KC_M_ABHME LALT(KC_UP)
#define KC_M_ABEND LALT(KC_DOWN)

/*
 * QWERTY
 * ,---------------------------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -_  |   =+ |  Bspc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [{  |   ]} |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |  Lower   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |    Ent    |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |    LShift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |    RShift     |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+--------|
 * |  LCTL | LGUI  |  LALT  |               S P A C E                   | Lower  | Raise|Leader| RCTRL |
 * .------+------+------+------+------+------|------+------+------+------+------+------+------+--------.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS, \
    KC_LOWER, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,  \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT, \
    KC_LCTL,  KC_LGUI, KC_LALT,                        KC_SPC,                                KC_LOWER, KC_RAISE, KC_LEAD, KC_RCTL
  ),

  [_COLEMAK] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, \
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, \
    _______,       _______, KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,         _______, \
    _______,          _______, _______,  _______, _______, _______, KC_K,    _______, _______, _______, _______,              _______, \
    _______,  _______, _______,                        _______,                              _______,    _______,   _______,  _______
  ),

  [_LOWER] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,    KC_F8,    KC_F9,     KC_F10,  KC_F11,   KC_F12,  KC_DEL,  \
    KC_CAPS, RGB_MOD, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_LSTRT, KC_PRVWD, KC_NXTWD,  KC_LEND, KC_DLINE, KC_PGUP, XXXXXXX, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LSTRT, KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT,   KC_END,  KC_PGDN,           KC_L,    \
    _______,  BL_DEC, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_QWERTY, KC_COLEMAK,                 _______, \
    _______,  _______, _______,                            _______,                                  _______, _______, KC_APP, _______
  ),

  [_RAISE] = LAYOUT_60_ansi(
      RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR, _______, _______, _______, \
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          KC_R,    \
    _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2,             _______, \
    _______,  _______, _______,                            _______,                            _______, _______, _______, _______
  )

 ,[_ADJUST] = LAYOUT_60_ansi(
    RESET,   KC_ISMAC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_TGOS, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_A,    \
    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QWERTY, KC_COLEMAK,              XXXXXXX, \
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
        case KC_ISMAC:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    tap_code(KC_M);
                } else {
                    tap_code(KC_W);
                }
            }
            break;
        case KC_TGOS:
            if (record->event.pressed) {
                user_config.is_macos ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    tap_code16(KC_M_LSTRT);
                } else {
                    tap_code(KC_W_LSTRT);
                }
            }
            break;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    tap_code16(KC_M_PRVWD);
                    return false;
                } else {
                    tap_code16(KC_W_PRVWD);
                    return false;
                }
            }
            return false;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    tap_code16(KC_M_NXTWD);
                    return false;
                } else {
                    tap_code16(KC_W_NXTWD);
                    return false;
                }
            }
            return false;
        case KC_LEND:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    tap_code16(KC_M_LEND);
                    return false;
                } else {
                    tap_code16(KC_W_LEND);
                    return false;
                }
            }
            return false;
        case KC_DLINE:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    send_string(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_RGHT)SS_TAP(X_BSPC)SS_UP(X_LSFT)SS_UP(X_LALT));
                    return false;
                } else {
                    send_string(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_TAP(X_BSPC)SS_UP(X_LCTL)SS_UP(X_LSFT));
                    // tap_code16(KC_W_DLINE);
                    return false;
                }
            }
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();
}

bool did_leader_succeed;
#ifdef AUDIO_ENABLE
float leader_start[][2] = SONG(ONE_UP_SOUND );
float leader_succeed[][2] = SONG(ALL_STAR);
float leader_fail[][2] = SONG(RICK_ROLL);
#endif
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    SEQ_ONE_KEY(KC_E) {
      // Anything you can do in a macro.
      SEND_STRING(SS_LCTL(SS_LSFT("t")));
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_E, KC_D) {
      SEND_STRING(SS_LGUI("r") "cmd\n" SS_LCTL("c"));
      did_leader_succeed = true;
    }

    SEQ_TWO_KEYS(KC_1, KC_G) {
      SEND_STRING("1nd13r0ck@gmail.com");
      did_leader_succeed = true;
    }

    SEQ_THREE_KEYS(KC_G, KC_K, KC_G) {
      SEND_STRING("gus.kohtz@gmail.com");
      did_leader_succeed = true;
    }

    SEQ_THREE_KEYS(KC_P, KC_P, KC_Q) {
      SEND_STRING("Please let me know if you have any questions.");
      did_leader_succeed = true;
    }

    leader_end();
  }
}

void leader_start(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start);
#endif
}

void leader_end(void) {
  if (did_leader_succeed) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed);
#endif
  } else {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail);
#endif
  }
}
