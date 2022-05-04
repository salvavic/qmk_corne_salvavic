#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

enum layers {
  _QWERTY,
  _COLEMAK,
  _FN,
  _SIMBOLOS,
  _MOUSE,
  _NUMERICO,
  _ADJUST,
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMA,
    FN,
    FNDEL,
    FNBSPC,
    SIMBO,
    SIMBOENT,
    ESPACENT,
    MOUSE,
    NUMERIC,
    ADJUST,
    TDPC,
    TDALT
};

enum {
    TD_PC = 0,
    TD_MAY,
};

#define QWERTY DF(_QWERTY)
#define COLEMA DF(_COLEMAK)
#define FN MO(_FN)
#define FNDEL LT(_FN, KC_DEL)
#define FNBSPC LT(_FN, KC_BSPC)

#define SIMBO MO(_SIMBOLOS)
#define SIMBOENT LT(_SIMBOLOS, KC_ENTER)
#define ESPACENT LT(_SIMBOLOS, KC_SPC)

#define MOUSE MO(_MOUSE)
#define NUMERIC MO(_NUMERICO)

// COLEMAK - home row mods
#define HOMEQ_A LGUI_T(KC_A)
#define HOMEQ_R LALT_T(KC_R)
#define HOMEQ_S LSFT_T(KC_S)
#define HOMEQ_T LCTL_T(KC_T)
#define HOMEQ_O LGUI_T(KC_O)
#define HOMEQ_I LALT_T(KC_I)
#define HOMEQ_E RSFT_T(KC_E)
#define HOMEQ_N LCTL_T(KC_N)
// QWERTY - home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_NT LGUI_T(KC_SCLN)
#define HOME_K RCTL_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_J RSFT_T(KC_J)

#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
  [TD_MAY] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, HOME_A,   HOME_S,  HOME_D, HOME_F,   KC_G,                         KC_H,    HOME_J,  HOME_K,  HOME_L, HOME_NT, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    TD(TD_MAY), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, TD(TD_PC),  KC_DOT, KC_SLSH,  RSFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          NUMERIC, FNDEL,  SIMBOENT,     ESPACENT, FNBSPC, NUMERIC
                                      //`--------------------------'  `--------------------------'
  ),

  [_SIMBOLOS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, S(KC_0),S(KC_RBRC),KC_RBRC,ALGR(KC_2),ALGR(KC_GRV),               ALGR(KC_5),S(KC_4),ALGR(KC_LBRC),ALGR(KC_RBRC),KC_GRV, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, S(KC_2), KC_MINS, S(KC_7), S(KC_6),ALGR(KC_1),                    KC_EQL, S(KC_1),  S(KC_8),S(KC_9), KC_MINS, S(KC_LBRC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_NUBS,S(KC_NUBS),S(KC_5), KC_SLSH,ALGR(KC_3),                  S(KC_EQL),S(KC_MINS),ALGR(KC_QUOT), ALGR(KC_NUHS),KC_LBRC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,_______,_______,     _______,_______,_______
                                      //`--------------------------'  `--------------------------'
  ),

  [_FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    SGUI(KC_S), KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_APP, _______, _______, _______, _______, LCTL(KC_F4),                   KC_INS,  XXXXXXX, KC_UP,  KC_PGUP, KC_PGDN,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,LCTL(KC_Y),LCTL(KC_Z),LCTL(KC_X), LCTL(KC_V), LCTL(KC_C),          KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,   KC_VOLD, KC_VOLU, SGUI(KC_S)
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMERICO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_7,    KC_8,    KC_9,    _______, KC_PGUP, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_4,    KC_5,    KC_6,    _______, KC_PGDN, KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_1,    KC_2,    KC_3,   _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_0, KC_DOT, KC_ENT
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, QWERTY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, COLEMA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_MUTE
                                      //`--------------------------'  `--------------------------'
  )

//     [_NUMERICO] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           _______, _______, _______,    _______, _______, _______
//                                       //`--------------------------'  `--------------------------'

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SIMBOLOS, _FN, _ADJUST);
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return true;
        case HOME_S:
            return true;
        case HOME_D:
            return true;
        case HOME_F:
            return true;
        case HOME_J:
            return true;
        case HOME_K:
            return true;
        case HOME_L:
            return true;
        case HOME_NT:
            return true;

        case LALT_T(KC_R):
            return true;
        case LSFT_T(KC_S):
            return true;
        case LCTL_T(KC_T):
            return true;
        case RGUI_T(KC_O):
            return true;
        case RALT_T(KC_I):
            return true;
        case RSFT_T(KC_N):
            return true;
        case RCTL_T(KC_E):
            return true;

        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return true;
        case HOME_S:
            return true;
        case HOME_D:
            return true;
        case HOME_F:
            return true;
        case HOME_J:
            return true;
        case HOME_K:
            return true;
        case HOME_L:
            return true;
        case HOME_NT:
            return true;

        case LALT_T(KC_R):
            return true;
        case LSFT_T(KC_S):
            return true;
        case LCTL_T(KC_T):
            return true;
        case RGUI_T(KC_O):
            return true;
        case RALT_T(KC_I):
            return true;
        case RSFT_T(KC_N):
            return true;
        case RCTL_T(KC_E):
            return true;

        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_S:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_D:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_F:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_J:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_K:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_L:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_NT:
            return TAPPING_TERM + LONG_TAPPING_TERM;

        case LALT_T(KC_R):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LSFT_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LCTL_T(KC_T):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RGUI_T(KC_O):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_I):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RSFT_T(KC_N):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(KC_E):
            return TAPPING_TERM + LONG_TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
