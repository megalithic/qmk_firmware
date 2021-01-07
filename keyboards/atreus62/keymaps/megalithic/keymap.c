// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _FN 1
#define _RESET 2

#define MG_CTRL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define MG_F_FN     LT(_FN, KC_F)
#define MG_FN       MO(_FN)
#define MG_RESET    MO(_RESET)
#define MG_WB       A(KC_LEFT) // FIXME - presently not working as we'd expect
#define MG_WF       A(KC_RIGHT) // FIXME - presently not working as we'd expect

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwerty */
    KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS ,
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS ,
    MG_CTRL_ESC,    KC_A,    KC_S,    KC_D,    MG_F_FN, KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
    KC_LSPO,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC ,
    MG_FN,          KC_TRNS, KC_TRNS, KC_LALT, KC_LGUI, MG_FN, KC_F19,     KC_ENT,      KC_SPC,  KC_BSPC,  KC_DEL,  KC_TRNS, KC_TRNS, KC_RGUI
  ),

  [_FN] = LAYOUT(
    KC_TRNS,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL  ,
    KC_TRNS,        KC_TRNS, MG_WF  , KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS ,
    TO(_DEFAULT),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS ,
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MG_WB  ,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  MG_RESET,    KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RESET] = LAYOUT(
    KC_NO  ,        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    TO(_DEFAULT)  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET
  )
};


// -- COMBOS:
//
/* enum combos { */
/*     CTRL_BSPC_DEL */
/* }; */

/* const uint16_t PROGMEM ctrl_bspc_del_combo[] = {KC_LCTL, KC_BSPC, COMBO_END}; */

/* combo_t key_combos[COMBO_COUNT] = { */
/*     [CTRL_BSPC_DEL] = COMBO(ctrl_bspc_del_combo, KC_DEL) */
/* }; */
