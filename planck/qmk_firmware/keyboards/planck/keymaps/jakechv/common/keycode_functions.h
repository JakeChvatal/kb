#include "macros.h"

// .......................................................... Keycode Primitives
// quickly press key
void tap_key(uint16_t keycode);
// press shift over code
void shift_key(uint16_t keycode);

#define SHIFT   1
#define NOSHIFT 0

// key press for thumb_layer() and lt_shift() macros
// if time left, shift, else tap
bool key_press(uint8_t shift, uint16_t keycode);
// ALT_T, CTL_T, GUI_T, SFT_T for shifted keycodes
void mt_shift(RECORD, uint16_t modifier, uint16_t modifier2, uint16_t keycode);
// ................................................................... Mod Masks
// tap dance persistent mods, see process_record_user()
// keyboard_report->mods (?) appears to be cleared by tap dance
void tap_mods(RECORD, uint16_t keycode);
// (un)register modifiers
void modifier(void (*f)(uint8_t));
// .................................................... Triple Dance Shift/Layer

// tap key, then oneshot off to shift layer
void double_shift(uint16_t keycode, uint8_t layer);
void tap_shift(STATE, uint16_t keycode, uint8_t layer); // tap dance LT (LAYER, KEY) emulation with <KEY><DOWN> -> <KEY><SHIFT> and auto-repeat extensions!
void tap_reset(uint16_t keycode, uint8_t layer); // reset tapping
void enter(STATE, void *user_data); // augment pseudo LT (_RSHIFT, KC_ENT) handling below for rapid <ENTER><SHIFT> sequences
void enter_reset(STATE, void *user_data); // reset enter
void bspc(STATE, void *user_data); // augment pseudo LT (_RSHIFT, KC_ENT) handling below for rapid <ENTER><SHIFT> sequences
void bspc_reset(STATE, void *user_data); // reset bspc
void space(STATE, void *user_data); // augment pseudo LT (_LSHIFT, KC_SPC) handling below for rapid <SPACE><SHIFT> sequences
void space_reset(STATE, void *user_data); // reset spc
// ......................................................... Triple Dance Insert
// double tap if key pressed multiple times
void double_max(uint8_t count, uint8_t shift, uint16_t keycode);
void colon(STATE, void *user_data);
void eql(STATE, void *user_data);
void greater(STATE, void *user_data);
void lesser(STATE, void *user_data);
void tilde(STATE, void *user_data);
void tilde_reset(STATE, void *user_data);

// ............................................................. Tap Dance Pairs
// tap dance shift rules
#define S_NEVER  0
#define S_SINGLE 1
#define S_DOUBLE 2
#define S_ALWAYS S_SINGLE | S_DOUBLE
#define CLOSE 1

void symbol_pair(uint8_t shift, uint16_t left, uint16_t right); // press a pair of symbols together
void tap_pair(STATE, uint8_t shift, uint16_t left, uint16_t right, uint16_t modifier, uint8_t close); // tap dance symbol pairs
void doublequote(STATE , void *user_data); // close double quote
void grave(STATE , void *user_data); // close back quote
void lbrace(STATE , void *user_data); // close brace
void lcurly(STATE , void *user_data); // close curly brace
void lparen(STATE , void *user_data);  // close parens 
void lparen_reset(STATE , void *user_data); // reset parens
void quote(STATE , void *user_data);  // close quotes
void rangle(STATE , void *user_data);  // close angle brackets
void rbrace(STATE , void *user_data); // close braces
void rcurly(STATE , void *user_data); // close curly braces
void rparen(STATE , void *user_data);
void rparen_reset(STATE , void *user_data);
// ............................................................ Tap Dance Insert
void comma(STATE, void *user_data); // double tap comma for spc
void dot(STATE, void *user_data); // double tap dot for colon
// compile time macro string, see functions/hardware planck script
void private(STATE, void *user_data); // double tap for private string
// config.h defined string
void send(STATE, void *user_data); // double tap for public string
// .......................................................... Tap Dance One Shot
void caps(STATE, void *user_data); // double tap caps for perm caps
void caps_reset(STATE, void *user_data); // revoke clock
// ................................................................... Tap Dance

qk_tap_dance_action_t tap_dance_actions[] = {
  [_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps, caps_reset)
 ,[_COLN] = ACTION_TAP_DANCE_FN         (colon)
 ,[_COMM] = ACTION_TAP_DANCE_FN         (comma)
 ,[_DOT]  = ACTION_TAP_DANCE_FN         (dot)
 ,[_DQOT] = ACTION_TAP_DANCE_FN         (doublequote)
 ,[_ENT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter, enter_reset)
 ,[_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bspc, bspc_reset)
 ,[_EQL]  = ACTION_TAP_DANCE_FN         (eql)
 ,[_GRV]  = ACTION_TAP_DANCE_FN         (grave)
 ,[_GT]   = ACTION_TAP_DANCE_FN         (greater)
 ,[_LBRC] = ACTION_TAP_DANCE_FN         (lbrace)
 ,[_LCBR] = ACTION_TAP_DANCE_FN         (lcurly)
 ,[_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lparen, lparen_reset)
 ,[_LT]   = ACTION_TAP_DANCE_FN         (lesser)
 ,[_PRIV] = ACTION_TAP_DANCE_FN         (private)
 ,[_QUOT] = ACTION_TAP_DANCE_FN         (quote)
 ,[_RBRC] = ACTION_TAP_DANCE_FN         (rbrace)
 ,[_RCBR] = ACTION_TAP_DANCE_FN         (rcurly)
 ,[_RNGL] = ACTION_TAP_DANCE_FN         (rangle)
 ,[_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rparen, rparen_reset)
 ,[_SEND] = ACTION_TAP_DANCE_FN         (send)
 ,[_SPC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space, space_reset)
 ,[_TILD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tilde, tilde_reset)
};

// .............................................................. Dynamic Layers

#define        LEFT    1
#define        RIGHT   2
// LEFT (KC_SPC, S(KC_BSLS)), RIGHT (KC_LEFT, S(KC_LEFT)) opposite thumb combinations, see process_record_user()
// up,   up   -> _BASE
// up,   down -> _SYMBOL
// down, up   -> _NUMBER
// down, down -> _MOUSE                     // see layer keycodes that raise mouse layer
#define THUMBS_DOWN _MOUSE                  // layer
// left right thumb layer combinations
void thumb_layer(RECORD, uint8_t side, uint8_t shift, uint16_t keycode, uint8_t thumb_dn_layer, uint8_t thumb_up_layer);
 // LT for S(keycode)
void lt_shift(RECORD, uint16_t keycode, uint8_t layer); // toggle shift layer

// set layer asap to overcome macro latency errors, notably tap dance and LT usage
// this routine inexplicably (?) sets layer_on() faster than can be done in thumb_layer()
void tap_layer(RECORD, uint8_t layer); // set layer tap right away
void clear_layers(void);
void clear_tt(void);
void base_layer(void);
