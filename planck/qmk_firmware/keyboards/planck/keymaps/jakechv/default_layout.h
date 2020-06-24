#include "common/default_keys.h"
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------'
  [_BASE] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  _________________KEYS_L1_________________, _________________KEYS_R1_________________, KC_BSPC,
    GUI_ESC, _________________KEYS_L2_________________, _________________KEYS_R2_________________, KC_QUOT, 
    KC_LSFT, _________________KEYS_L3_________________, _________________KEYS_R3_________________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB, TD_SPC, LT_BSPC, TD_ENT, LT_LEFT, AT_DOWN,  GT_UP, CT_RGHT
  ),

  [_SHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________KEYS_CAPS_L1_________________, ____________KEYS_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________KEYS_CAPS_L2_________________, ____________KEYS_CAPS_R2_________________, KC_QUOT,
    KC_LSFT, ____________KEYS_CAPS_L3_________________, ____________KEYS_CAPS_ShiftR3____________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT, LT_ESC,  LT_TAB,  TD_SPC, LT_BSPC, TD_ENT, LT_LEFT, AT_DOWN,  GT_UP, CT_RGHT
  ),

  //                                                                 ------+------+------|
  //                                                                    /  |   ?  |   "  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc |  f() |  Tab |  Del |   -  | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------' 
  [_LSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________KEYS_CAPS_L1_________________, ____________KEYS_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________KEYS_CAPS_L2_________________, ____________KEYS_CAPS_R2_________________, KC_QUOT,
    KC_LSFT, ____________KEYS_CAPS_L3_________________,  ____________KEYS_CAPS_LShiftR3___________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB,  ___fn__, KC_DEL,  KC_MINS, SL_LEFT, S_DOWN,  S_UP,    S_RGHT
  ),

  //                                                                +------+------+------|
  //                                                                |   ~  |   `  |   "  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt | Caps |   _  | ↑Tab | Bksp |  f() | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------'
  [_RSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________KEYS_CAPS_L1_________________, ____________KEYS_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________KEYS_CAPS_L2_________________, ____________KEYS_CAPS_R1_________________, KC_QUOT,
    KC_LSFT, ____________KEYS_CAPS_L3_________________, ____________KEYS_CAPS_RShiftR3___________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  KC_CAPS, SL_TAB,  KC_UNDS, LT_BSPC, ___fn__, SL_LEFT, S_DOWN,  S_UP,    S_RGHT
  ),
