#include "common/default_keys.h"
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------'
  [_BASE] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  _________________KEYS_L1_________________, _________________KEYS_R1_________________, KC_BSPC,
    GUI_ESC, _________________KEYS_L2_________________, _________________KEYS_R2_________________, KC_QUOT, 
    OS_CTL,  _________________KEYS_L3_________________, _________________KEYS_R3_________________, KC_ENT,
    KC_LSFT, OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB, TD_SPC, TD_BSPC, LT_ENT, LT_LEFT, AT_DOWN,  GT_UP, CT_RGHT
  ),
  // hold ctrl for a keypress
  // hold gui for a keypress
  // hold alt for a keypress
  // press for Esc, hold for _FNCKEY layer (numbers on right) (do not need esc here!)
  // press for Tab, hold for _NUMBER layer (function keys on right)
  // press for Spc, double tap for space, hold for LShift
  // press for bspc, double tap for bspc, hold for RShift
  // press for Enter, hold for _EDIT layer
  // press for left, hold for _SYMBOL
  // press for down, hold for Alt
  // press for up, hold for Gui
  // press for right, hold for Ctrl

  [_SHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________KEYS_CAPS_L1_________________, ____________KEYS_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________KEYS_CAPS_L2_________________, ____________KEYS_CAPS_R2_________________, KC_QUOT,
    OS_CTL,  ____________KEYS_CAPS_L3_________________, ____________KEYS_CAPS_ShiftR3____________, KC_ENT,
    KC_LSFT,  OS_GUI,  OS_ALT, LT_ESC,  LT_TAB,  TD_SPC, TD_BSPC, LT_ENT, LT_LEFT, AT_DOWN, GT_UP, CT_RGHT
  ),

  [_LSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________KEYS_CAPS_L1_________________, ____________KEYS_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________KEYS_CAPS_L2_________________, ____________KEYS_CAPS_R2_________________, KC_QUOT,
    OS_CTL,  ____________KEYS_CAPS_L3_________________, ____________KEYS_CAPS_LShiftR3___________, KC_ENT,
    KC_LSFT, OS_GUI,  OS_ALT,  LT_ESC, LT_TAB, ___fn__, KC_MINS, KC_DEL, SL_LEFT, S_DOWN,  S_UP,   S_RGHT
  ),

  [_RSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________KEYS_CAPS_L1_________________, ____________KEYS_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________KEYS_CAPS_L2_________________, ____________KEYS_CAPS_R1_________________, KC_QUOT,
    OS_CTL,  ____________KEYS_CAPS_L3_________________, ____________KEYS_CAPS_RShiftR3___________, KC_ENT,
    KC_LSFT, OS_GUI,  OS_ALT, KC_CAPS, SL_TAB, KC_UNDS, TD_BSPC, ___fn__, SL_LEFT, S_DOWN, S_UP,   S_RGHT
  ),
