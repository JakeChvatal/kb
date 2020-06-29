#pragma once
#include "keycode_functions.c"

// ........................................................... Context Multi Tap

#define TAP      state->count
#define TAPS     TAP > 1
#define TAP_DOWN state->pressed

#define REPEAT(f, k) for (uint8_t i = 0; i < TAP; i++) { f(k); }

#define DOUBLE_TAP(k, s) if (TAP_DOWN)      { register_code(k); } \
                         else if (TAP == 2) { send_string(s); }   \
                         else REPEAT(tap_key, k);

void doublequote(STATE, void *user_data) { // close double quote
  tap_pair(state, S_ALWAYS, KC_QUOT, KC_QUOT, 0, 0);
}

void grave(STATE, void *user_data) { // close back quote
  tap_pair(state, S_NEVER, KC_GRV, KC_GRV, 0, 0);
}

void lbrace(STATE, void *user_data) { // close brace
  tap_pair(state, S_NEVER, KC_LBRC, KC_RBRC, 0, 0);
}

void lcurly(STATE, void *user_data) { // close curly brace
  tap_pair(state, S_ALWAYS, KC_LBRC, KC_RBRC, 0, 0);
}

void lparen(STATE, void *user_data) { // close parens 
  tap_pair(state, S_ALWAYS, KC_9, KC_0, KC_LCTL, 0);
}

void lparen_reset(STATE, void *user_data) { // reset parens
  unregister_code(KC_LCTL);
}

void quote(STATE, void *user_data) { // close quotes
  tap_pair(state, S_NEVER, KC_QUOT, KC_QUOT, 0, 0);
}


// TODO why are these basically duplicated?
void rangle(STATE, void *user_data) {  // close angle brackets
  tap_pair(state, S_ALWAYS, KC_COMM, KC_DOT, 0, CLOSE);
}

void rbrace(STATE, void *user_data) { // close braces
  tap_pair(state, S_NEVER, KC_LBRC, KC_RBRC, 0, CLOSE);
}

void rcurly(STATE, void *user_data) { // close curly braces
  tap_pair(state, S_ALWAYS, KC_LBRC, KC_RBRC, 0, CLOSE);
}

void rparen(STATE, void *user_data) {
  tap_pair(state, S_ALWAYS, KC_9, KC_0, 0, CLOSE);
}

void rparen_reset(STATE, void *user_data) {
  unregister_code(KC_LCTL);
}

// ........................................................... Simple Double Tap

void asterisk(STATE, void *user_data) {
  if (TAPS) { tap_key(KC_DOT); }
  shift_key(KC_8);
  reset_tap_dance(state);
}

void comma(STATE, void *user_data) { // double tap for spc
  tap_key(KC_COMM);
  if (TAPS) { tap_key(KC_SPC); }
  reset_tap_dance(state);
}

void dot(STATE, void *user_data) { 
  if (biton32(layer_state) == _NUMBER) { TAPS ? shift_key(KC_COLN) : tap_key(KC_DOT); }
  else                                 { TAPS ? send_string("./") : tap_key(KC_DOT); }  // see symbol layer
  reset_tap_dance(state);
}


void percent(STATE, void *user_data) {
  if (TAPS && TAP_DOWN) { register_shift(KC_5); }
  else                  { TAP_DOWN ? register_code(KC_LALT) : double_tap(TAP, SHIFT, KC_5); }
  reset_tap_dance(state);
}

void percent_reset(STATE, void *user_data) {
  unregister_shift(KC_5);
  unregister_code (KC_LALT);
}

// compile time macro string, see functions/hardware planck script
void private(STATE, void *user_data) { // double tap for private string
  if (TAPS) {
#ifdef PRIVATE_STRING
#include "private_string.h"
#endif
  }
  reset_tap_dance(state);
}

// config.h defined string
void send(STATE, void *user_data) { // double tap for public string
  if (TAPS) { SEND_STRING(PUBLIC_STRING); }
  reset_tap_dance(state);
}

// .......................................................... Tap Dance One Shot

void caps(STATE, void *user_data) { // double tap caps for perm caps
  if (TAPS) { tap_key(KC_CAPS); }
  else {
    set_oneshot_mods(MOD_LSFT);
    register_code   (KC_LSFT);              // on hold down
  }
}

void caps_reset(STATE, void *user_data) { // revoke clock
  unregister_code(KC_LSFT);
}

// ......................................................... Triple Dance Insert


void colon(STATE, void *user_data) {
  if (mod_down(KC_RSFT)) {  // handle like map_shift()
#ifdef EMOJI
    if (TAPS){ DOUBLE_TAP(KC_SCLN, " :-"); } 
#else
    if (TAPS){ REPEAT(tap_key, KC_SCLN); } 
#endif
    else     { TAP_DOWN ? register_code(KC_SCLN) : double_tap(TAP, NOSHIFT, KC_SCLN); } // ;
  } else if (TAPS) {
    if (TAP_DOWN)      { register_shift(KC_SCLN); }
#ifdef HASKELL
    else if (TAP == 2) { send_string(" :: "); } 
#endif
    else REPEAT(shift_key, KC_SCLN);
  } else { TAP_DOWN ? register_shift(KC_SCLN) : double_tap(TAP, SHIFT, KC_SCLN); }
  reset_tap_dance(state);
}

void colon_reset(STATE, void *user_data) {
  unregister_shift(KC_SCLN);
  if (mod_down(KC_RSFT)) { register_code(KC_RSFT); }  // restore HOME_T, see process_record_user() TD_COLN
}

void equal(STATE, void *user_data) { // send_string " /= "
  if (TAPS) { DOUBLE_TAP(KC_EQL, EQLEQL); }
  else      { TAP_DOWN ? register_code(KC_EQL) : double_tap(TAP, NOSHIFT, KC_EQL); }
  reset_tap_dance(state);
}

#define DOUBLE_SHIFT(k, s) if (TAP_DOWN)          { register_shift(k); } \
                           else if (TAP == 2)     { send_string(s); }    \
                           else REPEAT(shift_key, k);

// tap for ->
void greater(STATE, void *user_data) {
  if (TAPS) { DOUBLE_SHIFT(KC_DOT, " -> "); }
  else      { TAP_DOWN ? register_code(KC_LSFT) : double_tap(TAP, SHIFT, KC_DOT); }
  reset_tap_dance(state);
}

void greater_reset(STATE, void *user_data) {
  unregister_shift(KC_DOT);
  unregister_code (KC_LSFT);
}

// tap for <- 
void lesser(STATE, void *user_data) {
  if (TAPS) { DOUBLE_SHIFT(KC_COMM, " <- "); }
  else      { TAP_DOWN ? register_code(KC_LCTL) : double_tap(TAP, SHIFT, KC_COMM); }
  reset_tap_dance(state);
}

void lesser_reset(STATE, void *user_data) {
  unregister_shift(KC_COMM);
  unregister_code (KC_LCTL);
}

void tilde(STATE, void *user_data)
{
  if (TAPS) { DOUBLE_SHIFT(KC_GRV, "~/"); }
  else      { TAP_DOWN ? register_shift(KC_GRV) : shift_key(KC_GRV); }
  reset_tap_dance(state);
}

void tilde_reset(STATE, void *user_data)
{
  unregister_shift(KC_GRV);
  unregister_code (KC_DOT);
  if (mod_down(KC_RSFT)) { register_code(KC_RSFT); }  // restore HOME_T, see process_record_user() TD_TILD
}


// ................................................................... Tap Dance
qk_tap_dance_action_t tap_dance_actions[] = {
  [_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps, caps_reset)
 ,[_COLN] = ACTION_TAP_DANCE_FN         (colon)
 ,[_COMM] = ACTION_TAP_DANCE_FN         (comma)
 ,[_DOT]  = ACTION_TAP_DANCE_FN         (dot)
 ,[_DQOT] = ACTION_TAP_DANCE_FN         (doublequote)
 ,[_ENT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter, enter_reset)
 ,[_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bspc, bspc_reset)
 ,[_EQL]  = ACTION_TAP_DANCE_FN         (equal)
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


