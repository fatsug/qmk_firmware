#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool     is_macos :1;
  };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
  KC_QWERTY = SAFE_RANGE,
  KC_LOWER,
  KC_RAISE,
  KC_ADJUST,
  KC_NAVI,
  KC_ISMAC,
  KC_TGOS,
  KC_PRVWD,
  KC_NXTWD,
  KC_LSTRT,
  KC_LEND,
  KC_DLINE,
  KC_ABHOM,
  KC_ABEND
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
#define KC_W_ABHOM   LCTL(KC_HOME)
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
#define KC_M_ABHOM LALT(KC_UP)
#define KC_M_ABEND LALT(KC_DOWN)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5
#define _NAVI 6

#define KC_RSSH RSFT_T(KC_SLSH)

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_BASE] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LOWER,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSSH, KC_UP, LT(_NAVI,KC_DEL),
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_LOWER, KC_RAISE,     KC_LEFT, KC_DOWN, KC_RGHT
 ),

[_LOWER] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        KC_CAPS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
        _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, KC_LSTRT, KC_PGDN, KC_LEND
),

[_RAISE] = LAYOUT(
        KC_ISMAC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        KC_TGOS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, KC_INS,  _______, KC_PSCR, _______, _______, XXXXXXX,
        RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST,
        RGB_VAD, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, KC_MPLY, KC_VOLU, KC_MUTE,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
),

[_ADJUST] = LAYOUT(
        KC_ISMAC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, RESET,
        KC_TGOS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST,
        _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, KC_APP,  _______
),

[_NAVI] = LAYOUT(
        KC_ISMAC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        KC_TGOS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST,
        _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, KC_ABHOM, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, KC_ABEND, _______
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
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
        case KC_ABHOM:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    tap_code16(KC_M_ABHOM);
                    return false;
                } else {
                    tap_code16(KC_W_ABHOM);
                    return false;
                }
            }
            return false;
        case KC_ABEND:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    tap_code16(KC_M_ABEND);
                    return false;
                } else {
                    tap_code16(KC_W_ABEND);
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
                    send_string(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_TAP(X_BSPC)SS_UP(X_LSFT));
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

