#include QMK_KEYBOARD_H

#define WB A(KC_LEFT)
#define WF A(KC_RIGHT)
#define DWB A(KC_BSPACE)
#define DWF A(KC_DELETE)
#define FINE_VOLUP S(A(KC__VOLUP))
#define FINE_VOLDOWN S(A(KC__VOLDOWN))

// #define HYPER_TAB MT(KC_F19, KC_TAB)
// #define HYPER_SPC MT(KC_F19, KC_SPC)

// #define HYPER ALL_T(KC_ESC)
// #define CTRL_ESC MT(MOD_LCTL, KC_ESC)
#define CTRL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
// #define HYPER_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
// #define HYPER_ESC ALL_T(KC_ESC)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
/* #define MEH_GRV MEH_T(KC_GRV)  // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift) */
/* #define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift */
/* #define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift */
/* #define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift */
/* #define UMLAUT  RALT(KC_U)     // Combine Alt and U */

enum layers {
  _BASE,
  _ARROWS,
  _HDUE, // Home, PgDown, PgUp, End
  _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Base (default) layer:
        * Caps Lock is LCtrl on hold, Esc on tap
        * Hold CSpace to activate L1
        * Hold LSpace to activate layer 3 (FN keys)
        * Hold `_FN` to activate L3
        * Hold `_HDUE` to activate L2
    */
    [_BASE] = LAYOUT_all(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        CTRL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
        MO(_FN), KC_LALT, KC_LGUI, LT(_FN, KC_SPC), KC_F19, KC_SPC, KC_RGUI, MO(_ARROWS), KC_LEFT, KC_DOWN, KC_RIGHT),

    /*  L1:
        * Vim arrows (HJKL)
        * Vim-like movement across words with W(ord), and B(eginning)
        * Vim-like movement across pages with N(ext), and P(revious)
        * Media controls (fine volume controls using Option+Shift)
        * Backspace/Del on N/M
        * Hold `F` to activate layer 2
    */
    [_ARROWS] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, FINE_VOLDOWN, FINE_VOLUP, KC__MUTE, _______,
        _______, _______, WF, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_MRWD, KC_MFFD, KC_MPLY,
        _______, _______, _______, _______, LT(_HDUE, _______), _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, WB, KC_PGDN, KC_DEL, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /*  L2:
        * Home, Page Down, Page Up, End
        * Delete word forward/back on W/B
        * RESET firmware on RBackspace
    */
    [_HDUE] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, DWF,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, DWB,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /*  L3:
        * F1-10
        * Mute on backspace
        * RGB (underglow) controls
        * Vim arrows (HJKL)
    */
    [_FN] = LAYOUT_all(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, FINE_VOLDOWN, FINE_VOLUP, KC__MUTE, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, KC_MRWD, KC_MFFD, KC_MPLY,
        _______, _______, _______, _______, LT(_HDUE, _______), _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, LT(_HDUE, _______), _______, _______, _______, _______),
};

static bool control_disabled = false;
static bool delete_pressed = false;

/**
 * Change ctrl+backspace into delete and do not register the ctrl modifier.
 */
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if(keycode == KC_BSPC) {
    if (record->event.pressed) {
      if(keyboard_report->mods & MOD_BIT(KC_LCTL)) {
        delete_pressed = true;
        control_disabled = true;
        unregister_code(KC_LCTL);
        register_code(KC_DEL);
        return false;
      }
    } else if(delete_pressed) {
      delete_pressed = false;
      unregister_code(KC_DEL);

      if(control_disabled) {
        control_disabled = false;
        register_code(KC_LCTL);
      }
      return false;
    }
  } else if(keycode == KC_LCTL && !record->event.pressed && delete_pressed) {
    delete_pressed = false;
    control_disabled = false;
    unregister_code(KC_DEL);
    register_code(KC_BSPC);
    return false;
  }
  return true;
}

// vim:ft=c:ts=2:sw=2
