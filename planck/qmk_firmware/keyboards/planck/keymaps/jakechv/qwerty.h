// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ...................................................................... Qwerty
#ifdef QWERTY
#include "common/qwerty_keys.h"

  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------'

  [_BASE] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    GUI_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT, 
    KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB,  TD_SPC,  LT_BSPC, TD_ENT,  LT_LEFT, AT_DOWN, GT_UP,   CT_RGHT
  ),

  [_SHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________QWERTY_CAPS_L1_________________, ____________QWERTY_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________QWERTY_CAPS_L2_________________, ____________QWERTY_CAPS_R2_________________, KC_QUOT,
    KC_LSFT, ____________QWERTY_CAPS_L2_________________, S(KC_N), S(KC_M), KC_COMM, KC_DOT,  TD_QUOT, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB,  TD_SPC,  LT_BSPC, TD_ENT,  LT_LEFT, AT_DOWN, GT_UP,   CT_RGHT
  ),

  // TODO: sort out lshift and rshift, what distinguishes from shift! how do I better arrange this?

  // ,-----------------------------------------------------------------------------------.
  // |   Q  |   W  |   E  |   R  |   T  | ^Alt | ^GUI |   Y  |   U  |   I  |   O  |   P  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   A  |   S  |   D  |   F  |   G  | ↑Alt | ↑GUI |   H  |   J  |   K  |   L  |   :  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   Z  |   X  |   C  |   V  |   B  | Caps |^Shift|   N  |   M  |   /  |   ?  |   "  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc |  f() |  Tab |  Del |   -  | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------'
  
  [_LSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________QWERTY_CAPS_L1_________________, ____________QWERTY_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), TD_COLN, KC_QUOT,
    KC_LSFT, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), KC_SLSH, KC_QUES, TD_DQOT, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB,  ___fn__, KC_DEL,  KC_MINS, SL_LEFT, S_DOWN,  S_UP,    S_RGHT
  ),

  // ,-----------------------------------------------------------------------------------.
  // |   Q  |   W  |   E  |   R  |   T  | ^Alt | ^GUI |   Y  |   U  |   I  |   O  |   P  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   A  |   S  |   D  |   F  |   G  | ↑Alt | ↑GUI |   H  |   J  |   K  |   L  |   :  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   Z  |   X  |   C  |   V  |   B  | Caps |^Shift|   N  |   M  |   ~  |   `  |   "  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt | Caps |   _  | ↑Tab | Bksp |  f() | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------'

  [_RSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________QWERTY_CAPS_L1_________________, ____________QWERTY_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________QWERTY_CAPS_L2_________________, S(KC_H), S(KC_J), S(KC_K), S(KC_L), TD_COLN, KC_QUOT,
    KC_LSFT, ____________QWERTY_CAPS_L2_________________, S(KC_N), S(KC_M), TD_TILD, TD_GRV,  TD_DQOT, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  KC_CAPS, SL_TAB,  KC_UNDS, LT_BSPC, ___fn__, SL_LEFT, S_DOWN,  S_UP,    S_RGHT
  ),
#endif

