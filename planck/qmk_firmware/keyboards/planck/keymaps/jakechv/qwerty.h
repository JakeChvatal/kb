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
    KC_LSFT, ____________QWERTY_CAPS_L3_________________, ____________QWERTY_CAPS_ShiftR3____________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB,  TD_SPC,  LT_BSPC, TD_ENT,  LT_LEFT, AT_DOWN, GT_UP,   CT_RGHT
  ),

  //                                                                 ------+------+------|
  //                                                                    /  |   ?  |   "  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc |  f() |  Tab |  Del |   -  | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------' 
  [_LSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________QWERTY_CAPS_L1_________________, ____________QWERTY_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________QWERTY_CAPS_L2_________________, ____________QWERTY_CAPS_R2_________________, KC_QUOT,
    KC_LSFT, ____________QWERTY_CAPS_L3_________________,  ____________QWERTY_CAPS_LShiftR3___________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  LT_TAB,  ___fn__, KC_DEL,  KC_MINS, SL_LEFT, S_DOWN,  S_UP,    S_RGHT
  ),

  //                                                                +------+------+------|
  //                                                                |   ~  |   `  |   "  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt | Caps |   _  | ↑Tab | Bksp |  f() | Left | Down |  Up  | Right|
  // `-----------------------------------------------------------------------------------'
  [_RSHIFT] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  ____________QWERTY_CAPS_L1_________________, ____________QWERTY_CAPS_R1_________________, KC_BSPC,
    GUI_ESC, ____________QWERTY_CAPS_L2_________________, ____________QWERTY_CAPS_R1_________________, KC_QUOT,
    KC_LSFT, ____________QWERTY_CAPS_L3_________________, ____________QWERTY_CAPS_RShiftR3___________, KC_ENT,
    OS_CTL,  OS_GUI,  OS_ALT,  KC_CAPS, SL_TAB,  KC_UNDS, LT_BSPC, ___fn__, SL_LEFT, S_DOWN,  S_UP,    S_RGHT
  ),
#endif
