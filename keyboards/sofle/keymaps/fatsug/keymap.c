#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool     is_macos :1;
  };
} user_config_t;

user_config_t user_config;

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_ISMAC,
    KC_TGOS,
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC/`|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \|  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTR |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GESC,  KC_1,   KC_2,      KC_3,     KC_4,     KC_5,                            KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,      KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC, \
  KC_LCTRL, KC_A,   KC_S,      KC_D,     KC_F,     KC_G,                            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,      KC_C,     KC_V,     KC_B,     KC_MUTE,     XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
                    KC_LCTRL,  KC_LGUI,  KC_LALT,  KC_LOWER, KC_SPC,       KC_ENT,  KC_RAISE, KC_RALT,  KC_RGUI,  KC_RCTRL \
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC/`|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |      |      |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTR |      |   R  |   S  |   T  |      |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT( \
  _______, _______,_______,  _______,  _______,  _______,                          _______,   _______,  _______,  _______,  _______,     _______, \
  KC_TAB,  _______,_______,     KC_F,     KC_P,     KC_B,                             KC_J,      KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC, \
  KC_LCTRL,_______,  KC_R,      KC_S,     KC_T,     KC_G,                             KC_M,      KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT, \
  KC_LSFT, _______,_______,  _______,     KC_D,     KC_V,   KC_MUTE,        XXXXXXX,  KC_K,      KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
                   KC_LCTRL, KC_LGUI,  KC_LALT,  KC_LOWER,  KC_SPC,         KC_ENT,   KC_RAISE,  KC_RALT,  KC_RGUI,  KC_RCTRL \
),
/* LOWER
 * ,-----------------------------------------.                       ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                       |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                       |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                       |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                       |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.       ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |       |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|       |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /        \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /          \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /            \      \ |      |      |      |      |
 *            `----------------------------------'              '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV,    KC_F1,     KC_F2,   KC_F3,    KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,\
  KC_GRV,    KC_1,      KC_2,    KC_3,     KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12, \
  _______,   KC_EXLM,   KC_AT,   KC_HASH,  KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______,   KC_EQL,    KC_MINS, KC_PLUS,  KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, \
                       _______, _______, _______, _______, KC_L,            _______, _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |LStart| PWrd |      | NWrd | DLine| PgUp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | PgDn |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______ , _______ , _______ , _______ , _______,                       _______,  _______  , _______,  _______, KC_ABHOM, KC_DEL, \
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_DLINE, KC_PRVWD, XXXXXXX, KC_NXTWD,  KC_ABEND, KC_PGUP, \
  KC_CAPS, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, _______,                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,   XXXXXXX,  KC_PGDN, \
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,   XXXXXXX,  KC_LSTRT, XXXXXXX, KC_LEND,   KC_APP,   _______, \
                         _______, _______, _______, _______, KC_R,     _______,   _______,  _______,  _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLEMAK|     |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  KC_TGOS, KC_ISMAC,  XXXXXXX ,  XXXXXXX , XXXXXXX, RESET,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, KC_A,     _______, _______, _______, _______, _______ \
  )
};

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
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
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // left
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == 1) {  // right
        if (IS_LAYER_ON(_LOWER))
        {
            if (clockwise)
            {
                tap_code(KC_PGUP);
            } else
            {
                tap_code(KC_PGDOWN);
            }
        }
        else
        {
            if (clockwise)
            {
                tap_code(KC_MS_WH_DOWN);
            }
            else
            {
                tap_code(KC_MS_WH_UP);
            }
        }
    }
}

#endif
