// ----------------------------------------------------------- Layers
enum layers {
  _BASE = 0
 ,_SHIFT
 ,_LSHIFT
 ,_RSHIFT
 ,_NUMBER
 ,_SYMBOL
 ,_FNCKEY
 ,_MOUSE
#ifdef CENTER_TT
 ,_TTNUMBER
 ,_TTREGEX
 ,_TTFNCKEY
 ,_TTCURSOR
 ,_TTMOUSE
#endif
#ifndef SHIFT_SYMBOLS
 ,_NUMSYM
 ,_SYMREG
#endif
 ,_EDIT
 ,_QWERTY
 ,_ADJUST
 ,_END_LAYERS
};

// ----------------------------------------------------------- Custom Keycodes
enum keycodes {
  BASE = SAFE_RANGE
 ,BASE1
 ,BASE2
 // gui when held, ^ when tapped
 ,SM_CIRC   // pseudo GUI_T(S(KC_6))                      for shifted key-codes, see process_record_user()
 // gui when held, $ when tapped
 ,SM_DLR    // pseudo SFT_T(S(KC_4))                      for shifted key-codes, see process_record_user()
 // shift alt when held, G when tapped
 ,SM_G      // pseudo MT   (MOD_LALT | MOD_LSFT, S(KC_G)) for shifted key-codes, see process_record_user()
 // alt when held, % when tapped
 ,SM_PERC   // pseudo ALT_T(S(KC_5))                      for shifted key-codes, see process_record_user()
 // control when held, ( when tapped
 ,SM_LPRN   // pseudo CTL_T(S(KC_9))                      for shifted key-codes, see process_record_user()
 // switch to mouse wehn held, cap left when tapped
 ,SL_LEFT   // pseudo LT   (_MOUSE, S(KC_LEFT))           for shifted key-codes, see process_record_user()
 // 
 ,SP_DEL    // pseudo LT   (_MOUSE, KC_DEL)               for shifted key-codes, see process_record_user()
 ,SL_PIPE   // pseudo LT   (_ADJUST, S(KC_BSLS))          for shifted key-codes, see process_record_user()
 ,SL_TAB    // pseudo LT   (_FNCKEY, S(KC_TAB))           for shifted key-codes, see process_record_user()
#ifdef CENTER_TT
 ,TT_ESC
#endif
 /*
 ,LT_C    = LT (_NUMBER, KC_C)
 ,LT_V    = LT (_FNCKEY, KC_V)
 ,LT_N    = LT (_EDIT,   KC_N)
 ,LT_M    = LT (_SYMBOL, KC_M)
 */
 ,PS_BASE // return to base layer
};

// ----------------------------------------------------------- Modifier Key Defs
// modifier keys
#define GUI_ESC GUI_T(KC_ESC)

// hold for the modifier, press for the inner key
#define AT_B    ALT_T(KC_B)
#define AT_DOWN ALT_T(KC_DOWN)
#define CT_RGHT CTL_T(KC_RGHT)
#define GT_C    GUI_T(KC_C)
#define GT_UP   GUI_T(KC_UP)
#define MT_E    MT   (MOD_LCTL | MOD_LALT, KC_E)
#define MT_X    MT   (MOD_LALT | MOD_LSFT, KC_X)
#define ST_A    SFT_T(KC_A)

// hold shift, press keycode
#define S_DOWN  S    (KC_DOWN)
#define S_LEFT  S    (KC_LEFT)
#define S_RGHT  S    (KC_RGHT)
#define S_TAB   S    (KC_TAB)
#define S_UP    S    (KC_UP)

// keycodes
#define ___x___ KC_TRNS
#define ___fn__ KC_TRNS
#undef  _______
#define _______ KC_NO

// hold control, press the key
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define EOT     LCTL(KC_D)
#define NAK     LCTL(KC_U)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(KC_Z)
// hold ctrl alt, press key: terminal copy and paste
#define TMCOPY  LALT(LCTL(KC_C))
#define TMPASTE LALT(LCTL(KC_V))

// mom activates layer when held, key when tapped
#define LT_BSLS LT  (_MOUSE,  KC_BSLS)      // see process_record_user() for extended handling
#define LT_BSPC LT  (_EDIT,   KC_BSPC)
#define SP_LEFT LT  (_EDIT,   KC_LEFT)
#define LT_ESC  LT  (_NUMBER, KC_ESC)
#define LT_LEFT LT  (_SYMBOL, KC_LEFT)      // see process_record_user() for extended handling
#define SP_BSPC LT  (_SYMBOL, KC_BSPC)      // see process_record_user() for extended handling
#define LT_TAB  LT  (_FNCKEY, KC_TAB)
#define LT_INS  LT  (_FNCKEY, KC_INS)
#define LT_ALTG LT  (_FNCKEY, KC_RALT)

#define ADJUST  MO  (_ADJUST) 
#define OS_ALT  OSM (MOD_LALT)
#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
#define OS_SFT  OSM (MOD_LSFT)
#define OS_CALT OSM (MOD_LALT | MOD_LCTL)
#define OS_CGUI OSM (MOD_LGUI | MOD_LCTL)
#define OS_CSFT OSM (MOD_LSFT | MOD_LCTL)
#define OS_SALT OSM (MOD_LALT | MOD_LSFT)
#define OS_SGUI OSM (MOD_LGUI | MOD_LSFT)

// unclear yet
#ifdef THUMB_0
#define LT_EQL  LT  (_ADJUST, KC_EQL)
#else
#define LT_0    LT  (_ADJUST, KC_0)
#endif
#ifndef SHIFT_SYMBOLS
#define LT_A    LT  (_NUMSYM, KC_A)
#define LT_LFTX LT  (_SYMREG, KC_LEFT)
#endif


// --- keycode macro groups
// inspired by https://github.com/noahfrederick/qmk-keymaps/blob/master/user/my.h
// --- convenience
#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT
