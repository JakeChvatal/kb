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
 ,SL_TAB    // pseudo LT   (_FNCKEY, S(KC_TAB))           for shifted key-codes, see process_record_user()
#ifdef CENTER_TT
 ,TT_ESC
#endif
 ,SL_PIPE
#ifdef ROLLOVER
#ifdef QWERTY
 ,HOME_A  // pseudo GUI_T(KC_A)
 ,HOME_S  // pseudo CTL_T(KC_S)
 ,HOME_D  // pseudo ALT_T(KC_D)
 ,HOME_F  // pseudo SFT_T(KC_F)
 ,HOME_J  // pseudo SFT_T(KC_J)
 ,HOME_K  // pseudo ALT_T(KC_K)
 ,HOME_L  // pseudo CTL_T(KC_L)
 ,HOME_SC // pseudo GUI_T(KC_SCLN)
#endif
#ifdef COLEMAK
 ,HOME_A
 ,HOME_R
 ,HOME_S
 ,HOME_T
 ,HOME_N
 ,HOME_E
 ,HOME_I
 ,HOME_O
#endif
#ifdef SOUL
 ,HOME_A
 ,HOME_R
 ,HOME_S
 ,HOME_T
 ,HOME_N
 ,HOME_E
 ,HOME_I
 ,HOME_O
#endif
#endif
 ,PS_BASE // return to base layer
};

// ----------------------------------------------------------- Modifier Key Defs
// modifier keys
#define GUI_ESC GUI_T(KC_ESC)

// rollover definitions
#ifndef ROLLOVER
#ifdef QWERTY
#define HOME_A KC_A 
#define HOME_S KC_S
#define HOME_D KC_D
#define HOME_F KC_F
#define HOME_J KC_J 
#define HOME_K KC_K
#define HOME_L KC_L
#define HOME_SC KC_SCLN
#endif
#ifdef COLEMAK
#define HOME_A KC_A
#define HOME_R KC_R
#define HOME_S KC_S
#define HOME_T KC_T
#define HOME_N KC_N
#define HOME_E KC_E
#define HOME_I KC_I
#define HOME_O KC_O
#endif
#ifdef SOUL
#define HOME_A KC_A
#define HOME_R KC_R
#define HOME_S KC_S
#define HOME_T KC_T
#define HOME_N KC_N
#define HOME_E KC_E
#define HOME_I KC_I
#define HOME_O KC_O
#endif
#endif

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
#define LT_LEFT LT  (_EDIT, KC_LEFT)      // see process_record_user() for extended handling
#define LT_TAB  LT  (_NUMBER, KC_TAB)
#define LT_ENT  LT  (_SYMBOL,   KC_ENT)
#define SP_BSPC LT  (_SYMBOL, KC_BSPC)      // see process_record_user() for extended handling
#define LT_ESC  LT  (_FNCKEY, KC_ESC)
#define LT_INS  LT  (_FNCKEY, KC_INS)
#define LT_ALTG LT  (_FNCKEY, KC_RALT)

#define OS_ALT  OSM (MOD_LALT)
#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
#define OS_SFT  OSM (MOD_LSFT)
#define OS_CALT OSM (MOD_LALT | MOD_LCTL)
#define OS_CGUI OSM (MOD_LGUI | MOD_LCTL)
#define OS_CSFT OSM (MOD_LSFT | MOD_LCTL)
#define OS_SALT OSM (MOD_LALT | MOD_LSFT)
#define OS_SGUI OSM (MOD_LGUI | MOD_LSFT)



// --- keycode macro groups
// inspired by https://github.com/noahfrederick/qmk-keymaps/blob/master/user/my.h
// --- convenience
// .--------------------.
// | Mute |VolDwn|VolUp |
// `--------------------'
#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU

// .--------------------.
// |MPrev |MPlay |MNext |
// `--------------------'
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT

// navigation
#define __________________NAV1_____________________ _______, KC_HOME, KC_UP, KC_END,  KC_PGUP
#define __________________NAV2_____________________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGDN

// mouse
// .----------------------------------.
// |      |ScrlL |  ^   |ScrlR |ScrlUp|
// |----------------------------------|
// |      |  <-  |  ;   |  ->  |ScrlDw|
// |----------------------------------|
// |      |      |      |      |      |
// '----------------------------------'
#define ______________MOUSE1______________ KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define ______________MOUSE2______________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define ______________MOUSE3______________ _______, _______, _______, _______

// .--------------------.
// | LClk | CClk | RClk |
// `--------------------'
#define _________MOUSECLK________ KC_BTN1, KC_BTN3, KC_BTN2 

// modifiers
// .---------------------------.
// | Ctrl |  GUI |  Alt | Shift|
// `---------------------------'
#define _____________MODKEYS______________ OS_CTL, OS_GUI, OS_ALT, OS_SFT

// function keys
// .----------------------------------.
// |      |  F7  |  F8  |  F9  |  F12 |
// |----------------------------------|
// |      |  F4  |  F5  |  F6  |  F11 |
// |----------------------------------|
// |      |  F1  |  F2  |  F3  |  F10 |
// '----------------------------------'
#define _______________FN1________________ KC_F7, KC_F8, KC_F9, KC_F12
#define _______________FN2________________ KC_F4, KC_F5, KC_F6, KC_F11 
#define _______________FN3________________ KC_F1, KC_F2, KC_F3, KC_F10 

// numpad
// remember to define the location of KC_EQLS and KC_0 on the same layer
// .----------------------------------.
// |   /  |   7  |   8  |   9  |   *  |
// |----------------------------------|
// |   .  |   4  |   5  |   6  |   -  |
// |----------------------------------|
// |   ,  |   1  |   2  |   3  |   +  |
// `----------------------------------'
#define ______________________NUM1________________ KC_SLSH, KC_7, KC_8, KC_9, KC_ASTR
#define ______________________NUM2________________ TD_DOT,  KC_4, KC_5, KC_6, KC_MINS
#define ______________________NUM3________________ TD_COMM, KC_1, KC_2, KC_3, KC_PLUS  


// brackets layer
// backslash and del should probably be on this layer
// .----------------------------------.
// |  *   |  {   |   ^  |   }  |      |
// |----------------------------------|
// |  ?   |  (   |   $  |   )  |      |
// |----------------------------------|
// |  |   |  [   |   #  |   ]  |      |
// '----------------------------------'
#define ____________BRACKETS1_____________ KC_ASTR, TD_LCBR, KC_CIRC, KC_RCBR
#define ____________BRACKETS2_____________ KC_QUES, TD_LPRN, KC_DLR,  KC_RPRN
#define ____________BRACKETS3_____________ KC_PIPE, TD_LBRC, KC_HASH, KC_RBRC

// regex layer
// .----------------------------------.
// |      |  .   |  *   |   ^  |   |  |
// |----------------------------------|
// |      |  <   |  %   |   >  |   ?  |
// |----------------------------------|
// |      |  +   |  @   |   \  |   !  |
// '----------------------------------'
#define ______________REGEX1______________ KC_TILD, KC_ASTR, KC_AMPR, KC_PIPE
#define ______________REGEX2______________ KC_LT,   KC_PERC, KC_GT,   KC_QUES
#define ______________REGEX3______________ KC_PLUS, KC_AT,   KC_BSLS, KC_EXLM

// text operations
#define ______________TEXTOPS_____________ UNDO,CUT,COPY,PASTE 
