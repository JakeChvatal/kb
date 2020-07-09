
/* #include "common/keycodes.h" */
/* #include "common/tapdance.h" */
/* #include "common/tapdance.c" */
/* #include "common/keycode_functions.c" */
/* #include "common/keycode_functions.h" */

#include "common/keycode_groups.h"
#include "common/default_keys.h"

#define BASE_L KC_LSFT, OS_GUI,  OS_ALT,  LT_ESC, LT_TAB
#define BASE_R LT_ENT,  LT_LEFT, AT_DOWN, GT_UP,  CT_RGHT

#define LSHIFT_R KC_MINS, SL_LEFT, S_DOWN, S_UP,    S_RGHT
#define RSHIFT_L KC_LSFT, OS_GUI,  OS_ALT, KC_CAPS, KC_UNDS

#define SYM_LFT ___x___, ___x___, ___x___, KC_PIPE, LT_BSLS
#define NUM_RGT KC_0, ___x___,  ___x___,  ___x___, ___x___

  // base and shifted layers
  [_BASE] = flex_planck_layout(
    KC_TAB, KEYS_L1, KEYS_R1, _______,    
    GUI_ESC,KEYS_L2, KEYS_R2, KC_QUOT,    
    OS_CTL, KEYS_L3, KEYS_R3, _______,    
    TD_SPC, BASE_L,  BASE_R,  TD_BSPC
  ),

  // normal shifted layer
  [_SHIFT] = flex_planck_layout(
    KC_TAB,  KEYCL1, KEYCR1,  _______, 
    GUI_ESC, KEYCL2, KEYCR2,  KC_QUOT, 
    OS_CTL,  KEYCL3, KEYCSR3, _______, 
    LT_TAB,  BASE_L, BASE_R,  LT_ENT
  ),

  // left shifted layer
  [_LSHIFT] = flex_planck_layout(
    KC_TAB,  KEYCL1, KEYCR1,   _______, 
    GUI_ESC, KEYCL2, KEYCR2,   KC_QUOT, 
    OS_CTL,  KEYCL3, KEYCLSL3, _______, 
    LT_TAB,  BASE_R, LSHIFT_R, KC_DEL
  ),

  // right shifted layer
  [_RSHIFT] = flex_planck_layout(
    KC_TAB,  KEYCL1,  KEYCR1,   _______, 
    GUI_ESC, KEYCL2,  KEYCR2,   KC_QUOT, 
    OS_CTL,  KEYCL3,  KEYCRSR3, _______, 
    SL_TAB, RSHIFT_L, BASE_R,   ___fn__ 
    ),

// num keypad layer
  [_NUMBER] = flex_planck_layout(
    _______, BLANK, NUM1, _______,
    _______, BLANK, NUM2, _______,
    _______, BLANK, NUM3, _______,
    _______, BLANK, NUM_RGT, TD_EQL
  ),

// function keys
  [_FNCKEY] = flex_planck_layout(
    _______, BLANK,  FN1, _______,
    _______, MODKEYS, FN2, _______,
    _______, BLANK,  FN3, _______,
    _______, BLANK, BLANK, KC_PLUS
  ),

  // symbol and navigation layer
  [_SYMBOL] = flex_planck_layout(
   _______, BRKTS1, NAV1,    _______,
   _______, BRKTS2, NAV2,    _______,
   _______, BRKTS3, BLANK,  _______,
   _______, SYM_LFT, BLANK, _______
  ),

  // regex layer
  [_SYMREG] = flex_planck_layout(
    _______, REGEX1, BLANK, _______,
    _______, REGEX3, BLANK, _______,
    _______, REGEX3, BLANK, _______,
    _______, BLANK, BLANK, _______
  ),

  // mouse movement layer
  [_MOUSE] = flex_planck_layout(
    _______, BLANK, MOUSE1, _______,
    _______, MSCLK,  MOUSE2, _______,
    _______, BLANK, BLANK, _______,
    _______, BLANK, BLANK, _______
  ),
  
  // editor shortcuts
  [_EDIT] = flex_planck_layout(
    _______, TXTOPS1, BLANK, _______,
    _______, TXTOPS2, CUSTOM, _______,
    _______, TXTOPS3, BLANK, _______,
    _______, BLANK,  BLANK, _______
  ),
