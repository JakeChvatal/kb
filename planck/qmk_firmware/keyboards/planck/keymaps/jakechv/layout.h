#include "common/default_keys.h"

// helpful macros for laying out key groups
#ifdef WIDE_LAYOUT
#define flex_planck_layout(BL1, L1, R1, BR1, \
                           BL2, L2, R2, BR2, \
                           BL3, L3, R3, BR3, \
                           BL4, L4, R4, BR4) \
    planck_layout( \
      L1, BL1, BR1, R1, \
      L2, BL2, BR2, R2, \
      L3, BL3, BR3, R3, \
      BL4, L4, R4, BR4 \
    ) 
#else
#define flex_planck_layout(BL1, L1, R1, BR1, \
                           BL2, L2, R2, BR2, \
                           BL3, L3, R3, BR3, \
                           BL4, L4, R4, BR4) \
    planck_layout( \
      BL1, L1, R1, BR1, \
      BL2, L2, R2, BR2, \
      BL3, L3, R3, BR3, \
      BL4, L4, R4, BR4  \
    )
#endif

#define overlay_planck_layout(L1, R1, \
                              L2, R2, \
                              L3, R3, \
                              BL4, L4, R4, BR4) \
    flex_planck_layout( \
      _______, L1, R1, _______, \
      _______, L2, R2, _______, \
      _______, L3, R3, _______, \
      BL4,     L4, R4, BR4      \
    )

#define simple_overlay_planck_layout(L1, R1, \
                                     L2, R2, \
                                     L3, R3) \
   overlay_planck_layout( \
     L1, R1, \
     L2, R2, \
     L3, R3, \
     _______, BLANCK, BLANCK, _______ \
   )


#define BASE_L KC_LSFT, OS_GUI,  OS_ALT,  LT_ESC, LT_TAB
#define BASE_R LT_ENT, LT_LEFT, AT_DOWN,  GT_UP, CT_RGHT

#define LSHIFT_R KC_MINS, SL_LEFT, S_DOWN, S_UP, S_RGHT
#define RSHIFT_L KC_LSFT, OS_GUI,  OS_ALT, KC_CAPS, KC_UNDS

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
    KC_TAB,  KEYCL1, KEYCR1, _______, 
    GUI_ESC, KEYCL2, KEYCR2, KC_QUOT, 
    OS_CTL,  KEYCL3, KEYCR3, _______, 
    LT_TAB,  BASE_R, LSHIFT_R, KC_DEL
  ),

  // right shifted layer
  [_RSHIFT] = flex_planck_layout(
    KC_TAB,  KEYCL1, KEYCR1,   _______, 
    GUI_ESC, KEYCL2, KEYCR2,   KC_QUOT, 
    OS_CTL,  KEYCL3, KEYCRSR3, _______, 
    SL_TAB, RSHIFT_L,BASE_R,   ___fn__ 
    ),

  // num keypad layer
  [_NUMBER] = overlay_planck_layout(
    BLANK, NUM1, 
    BLANK, NUM2, 
    BLANK, NUM3, 
    _______, BLANK, TD_EQL, KC_0, ___x___,  ___x___,  ___x___, ___x___
  ),


  // function keys
  [_FNCKEY] = overlay_planck_layout(
    BLANCK,  FN1, 
    MODKEYS, FN2, 
    BLANCK,  FN3, 
    _______, BLANCK, BLANCK, KC_PLUS
  ),

  // symbol and navigation layer
  [_SYMBOL] = overlay_planck_layout(
   BRKTS1, NAV1,    
   BRKTS2, NAV2,    
   BRKTS3, BLANCK,  
   ___x___, ___x___, ___x___, KC_PIPE, LT_BSLS,  ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___, ___x___
  ),

  // regex layer
  [_SYMREG] = simple_overlay_planck_layout(
    REGEX1, BLANCK,
    REGEX3, BLANCK,
    REGEX3, BLANCK
  ),

  // mouse movement layer
  [_MOUSE] = simple_overlay_planck_layout(
    BLANCK, MOUSE1,
    MSCLK,  MOUSE2,
    BLANCK, BLANCK
  ),
  
  // editor shortcuts
  [_EDIT] = simple_overlay_planck_layout(
    TXTOPS1, BLANCK, 
    TXTOPS2, CUSTOM, 
    TXTOPS3, BLANCK
  ),
