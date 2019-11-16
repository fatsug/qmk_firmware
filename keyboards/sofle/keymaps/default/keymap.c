#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

extern keymap_config_t keymap_config;
// extern uint8_t is_master;

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _M_COLEMAK,
    // _M_QWERTY,
    _W_COLEMAK,
    // _W_QWERTY,
    _M_LOWER,
    _W_LOWER,
    _M_RAISE,
    _W_RAISE,
    _ADJUST,
};

enum custom_keycodes {
  KC_M_QWERTY = SAFE_RANGE,
  KC_M_COLEMAK,
  KC_W_QWERTY,
  KC_W_COLEMAK,
  KC_M_LOWER,
  KC_W_LOWER,
  KC_M_RAISE,
  KC_W_RAISE,
  KC_ADJUST,
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

/* Mac variants */
#define KC_M_UNDO  LGUI(KC_Z)
#define KC_M_CUT   LGUI(KC_X)
#define KC_M_COPY  LGUI(KC_C)
#define KC_M_PASTE LGUI(KC_V)
#define KC_M_PRVWD LALT(KC_LEFT)
#define KC_M_NXTWD LALT(KC_RIGHT)
#define KC_M_LSTRT LGUI(KC_LEFT)
#define KC_M_LEND  LGUI(KC_RIGHT)
#define KC_M_DLINE LGUI(KC_BSPC)

#define KC_____ KC_TRNS
#define KC_XXXX KC_NO
#define KC_RESET RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/*
 [_QWERTY] = LAYOUT( \
  ESC,   1,   2,    3,    4,    5,                     6,    7,    8,    9,    0,    GRV, \
  TAB,   Q,   W,    E,    R,    T,                     Y,    U,    I,    O,    P,    MINS, \
  LCTRL, A,   S,    D,    F,    G,                     H,    J,    K,    L,    SCLN, QUOT, \
  LSFT,  Z,   X,    C,    V,    B, NO,      NO,  N,    M,    COMM, DOT,  SLSH, RSFT, \
                    LGUI, LALT, LCTRL,LOWER, ENT,   SPC,  RAISE,   RCTRL,RALT, RGUI \
),
*/

/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_M_COLEMAK] = LAYOUT_kc( \
  GRV,   1,   2,    3,    4,    5,                     6,    7,    8,    9,    0,  GRV, \
  ESC,   Q,   W,    F,    P,    G,                     J,    L,    U,    Y, SCLN,  BSPC, \
  TAB,   A,   R,    S,    T,    D,                     H,    N,    E,    I,    O,  QUOT, \
  LSFT,  Z,   X,    C,    V,    B, XXXX,       XXXX,   K,    M, COMM,  DOT, SLSH,  RSFT, \
           LCTRL,LALT,LGUI,M_LOWER, ENT,       SPC,  M_RAISE, RGUI, RALT, RCTRL \
),
[_W_COLEMAK] = LAYOUT_kc( \
  GRV,   1,   2,    3,    4,    5,                     6,    7,    8,    9,    0,  GRV, \
  ESC,   Q,   W,    F,    P,    G,                     J,    L,    U,    Y, SCLN,  BSPC, \
  TAB,   A,   R,    S,    T,    D,                     H,    N,    E,    I,    O,  QUOT, \
  LSFT,  Z,   X,    C,    V,    B, XXXX,        XXXX,  K,    M, COMM,  DOT, SLSH,  RSFT, \
           LGUI, LALT,LCTRL,W_LOWER,ENT,        SPC,  W_RAISE, RCTRL,RALT, RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_M_LOWER] = LAYOUT_kc( \
  ____,   F1,   F2,   F3,   F4,   F5,                     F6,   F7,   F8,   F9,  F10,  F11,\
  GRV,     1,    2,    3,    4,    5,                      6,    7,    8,    9,    0,  F12, \
  ____, EXLM,   AT, HASH,  DLR, PERC,                   CIRC, AMPR, ASTR, LPRN, RPRN, PIPE, \
  ____,  EQL, MINS, PLUS, LCBR, RCBR, ____,       ____, LBRC, RBRC, SCLN, COLN, BSLS, ____, \
              ____, ____, ____, ____, ____,       ____, ____, ____, ____, ____\
),
[_W_LOWER] = LAYOUT_kc( \
  ____,   F1,   F2,   F3,   F4,   F5,                     F6,   F7,   F8,   F9,  F10,  F11,\
  GRV,     1,    2,    3,    4,    5,                      6,    7,    8,    9,    0,  F12, \
  ____, EXLM,   AT, HASH,  DLR, PERC,                   CIRC, AMPR, ASTR, LPRN, RPRN, PIPE, \
  ____,  EQL, MINS, PLUS, LCBR, RCBR, ____,       ____, LBRC, RBRC, SCLN, COLN, BSLS, ____, \
              ____, ____, ____, ____, ____,       ____, ____, ____, ____, ____\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_M_RAISE] = LAYOUT_kc( \
  ____, ____ , ____ , ____ , ____ , ____,                     ____,  ____  , ____,  ____ ,  ____ ,____, \
  ____,   INS,  PSCR,   APP,  XXXX, XXXX,                     PGUP, M_PRVWD,   UP,M_NXTWD,M_DLINE,____, \
  ____,  LALT,  LCTL,  LSFT,  XXXX, CAPS,                     PGDN,    LEFT, DOWN,   RGHT,   DEL, XXXX, \
  ____,M_UNDO, M_CUT,M_COPY,M_PASTE,XXXX,  ____,       ____,  XXXX, M_LSTRT, XXXX, M_LEND,  XXXX, ____, \
            ____, ____, ____, ____,  ____, ____,       ____, ____, ____, ____ \
),
[_W_RAISE] = LAYOUT_kc( \
  ____, ____ , ____ , ____ , ____ , ____,                     ____,  ____  , ____,  ____ ,  ____ , ____, \
  ____,   INS,  PSCR,   APP,  XXXX, XXXX,                     PGUP, W_PRVWD,   UP,W_NXTWD,W_DLINE, ____, \
  ____,  LALT,  LCTL,  LSFT,  XXXX, CAPS,                     PGDN,    LEFT, DOWN,   RGHT,    DEL, XXXX, \
  ____,W_UNDO, W_CUT,W_COPY,W_PASTE,XXXX,  ____,       ____,  XXXX, W_LSTRT, XXXX, W_LEND,   XXXX, ____, \
            ____, ____, ____, ____,  ____, ____,       ____, ____, ____, ____ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT_kc( \
  XXXX , XXXX,  XXXX  ,  XXXX   , XXXX, XXXX,                   XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, \
  RESET, XXXX,M_QWERTY,M_COLEMAK, XXXX, XXXX,                   XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, \
  XXXX , XXXX,W_QWERTY,W_COLEMAK, XXXX, XXXX,                   XXXX, VOLD, MUTE, VOLU, XXXX, XXXX, \
  XXXX , XXXX,  XXXX  , XXXX    , XXXX, XXXX, XXXX,       XXXX, XXXX, MPRV, MPLY, MNXT, XXXX, XXXX, \
                      ____, ____, ____, ____, ____,       ____, ____, ____, ____, ____ \
  )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void print_status(void) {
  // Print current mode
  switch (biton32(default_layer_state)) {
  case _W_COLEMAK:
    oled_write_P(PSTR("Mode: Colemak Linux\n"), false);
    break;
  case _M_COLEMAK:
    oled_write_P(PSTR("Mode: Colemak Mac\n"), false);
    break;
  default:
    oled_write_P(PSTR("Mode: Undefined\n"), false);
  }
  // Print current layer
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _M_COLEMAK:
    case _W_COLEMAK:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case _M_RAISE:
    case _W_RAISE:
      oled_write_P(PSTR("Raise\n"), false);
      break;
    case _M_LOWER:
    case _W_LOWER:
      oled_write_P(PSTR("Lower\n"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("Adjust\n"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  oled_write_ln_P(PSTR(""), false);
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    print_status();
  } else {
    render_logo();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_W_COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_W_COLEMAK);
      }
      return false;
      break;
    case KC_M_COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_M_COLEMAK);
      }
      return false;
      break;
    case KC_M_LOWER:
      if (record->event.pressed) {
        layer_on(_M_LOWER);
        update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
      } else {
        layer_off(_M_LOWER);
        update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
      }
      return false;
      break;
    case KC_M_RAISE:
      if (record->event.pressed) {
        layer_on(_M_RAISE);
        update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
      } else {
        layer_off(_M_RAISE);
        update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
      }
      return false;
      break;
    case KC_W_LOWER:
      if (record->event.pressed) {
        layer_on(_W_LOWER);
        update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
      } else {
        layer_off(_W_LOWER);
        update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
      }
      return false;
      break;
    case KC_W_RAISE:
      if (record->event.pressed) {
        layer_on(_W_RAISE);
        update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
      } else {
        layer_off(_W_RAISE);
        update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
      }
      return false;
      break;

    case KC_ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  }
}
