#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define KC_MS_U KC_MS_UP
#define KC_MS_D KC_MS_DOWN
#define KC_MS_L KC_MS_LEFT
#define KC_MS_R KC_MS_RIGHT
#define KC_MW_U KC_MS_WH_UP
#define KC_MW_D KC_MS_WH_DOWN
#define KC_MW_L KC_MS_WH_LEFT
#define KC_MW_R KC_MS_WH_RIGHT
#define KC_MSB1 KC_MS_BTN1
#define KC_MSB2 KC_MS_BTN2
#define KC_MSB3 KC_MS_BTN3

#define USE_HOME_ROW_MODS 1
#ifdef USE_HOME_ROW_MODS
  // Left-hand home row mods
  #define HOME_A LGUI_T(KC_A)
  #define HOME_S LALT_T(KC_S)
  #define HOME_D LSFT_T(KC_D)
  #define HOME_F LCTL_T(KC_F)

  // Right-hand home row mods
  #define HOME_J RCTL_T(KC_J)
  #define HOME_K RSFT_T(KC_K)
  #define HOME_L LALT_T(KC_L)
  #define HOME_SCLN RGUI_T(KC_SCLN)
#else
  // Left-hand
  #define HOME_A KC_A
  #define HOME_S KC_S
  #define HOME_D KC_D
  #define HOME_F KC_F

  // Right-hand
  #define HOME_J KC_J
  #define HOME_K KC_K
  #define HOME_L KC_L
  #define HOME_SCLN KC_SCLN
#endif


// Left-thumb later taps
#define ESC_ADJ LT(_ADJUST, KC_ESC)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define SPC_LOW LT(_LOWER, KC_SPC)

// Right-thumb layer taps
#define BS_LOW LT(_RAISE, KC_BSPC)
#define ENT_RSE LT(_LOWER, KC_ENT)
#define DEL_ADJ LT(_ADJUST, KC_DEL)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                               KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LGUI,           KC_LGUI,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘
                                    ESC_ADJ,  TAB_RSE,  SPC_LOW,                     BS_LOW, ENT_RSE, DEL_ADJ
                                // └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                            KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                             KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,          _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘
                                    KC_DOT,  KC_0,    KC_MINS,                   KC_BSPC, KC_ENT,  KC_DEL
                                // └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                            KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                            _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,          _______, _______, KC_MW_L, KC_MW_D, KC_MW_U, KC_MW_R, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LPRN, KC_RPRN, KC_UNDS,                   KC_MSB1, KC_MSB3,  KC_MSB2
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            BL_STEP, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                            _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                            _______, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_BRK, RESET,            RESET,   _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_MENU, KC_TAB,  KC_SPC,                   KC_MSTP, KC_MPLY, KC_MUTE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 75;
        case HOME_S:
            return TAPPING_TERM + 75;
        case HOME_L:
            return TAPPING_TERM + 75;
        case HOME_SCLN:
            return TAPPING_TERM + 75;
        default:
            return TAPPING_TERM;
    }
}
