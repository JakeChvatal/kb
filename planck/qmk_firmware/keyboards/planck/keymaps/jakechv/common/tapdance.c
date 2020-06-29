#include "keycode_functions.c"

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

// ............................................................ Tap Dance Insert

void comma(STATE, void *user_data) { // double tap comma for spc
  tap_key(KC_COMM);
  if (state->count > 1) {
    tap_key(KC_SPC);
  }
  reset_tap_dance(state);
}

void dot(STATE, void *user_data) { // double tap dot for colon
  if (state->count > 1) {
    shift_key(KC_COLN);
  }
  else {
    tap_key(KC_DOT);
  }
  reset_tap_dance(state);
}

// compile time macro string, see functions/hardware planck script
void private(STATE, void *user_data) { // double tap for private string
  if (state->count > 1) {
#ifdef PRIVATE_STRING
#include "private_string.h"
#endif
  }
  reset_tap_dance(state);
}

// config.h defined string
void send(STATE, void *user_data) { // double tap for public string
  if (state->count > 1) {
    SEND_STRING(PUBLIC_STRING);
  }
  reset_tap_dance(state);
}

// .......................................................... Tap Dance One Shot

void caps(STATE, void *user_data) { // double tap caps for perm caps
  if (state->count > 1) {
    tap_key(KC_CAPS);
  }
  else {
    set_oneshot_mods(MOD_LSFT);
    register_code   (KC_LSFT);              // on hold down
  }
}

void caps_reset(STATE, void *user_data) { // revoke clock
  unregister_code(KC_LSFT);
}

// ......................................................... Triple Dance Insert
// double tap if key pressed multiple times
void colon(STATE, void *user_data) {
  if (state->count > 2) { // triple tap colon: _;;_
    tap_key  (KC_SPC);
    shift_key(KC_SCLN);
    shift_key(KC_SCLN);
    tap_key  (KC_SPC);
  }
  else { // shift scln 
    double_max(state->count, SHIFT, KC_SCLN);
  }
  reset_tap_dance(state);
}

void eql(STATE, void *user_data) {
  if (state->count > 2) { // triple tap eql: _/=_
    tap_key(KC_SPC);
    tap_key(KC_SLSH);
    tap_key(KC_EQL);
    tap_key(KC_SPC);
  }
  else {
    double_max(state->count, NOSHIFT, KC_EQL);
  }
  reset_tap_dance(state);
}

void greater(STATE, void *user_data) {
  if (state->count > 2) { // triple tap dot: _-._ (?? TODO)
    tap_key  (KC_SPC);
    tap_key  (KC_MINS);
    shift_key(KC_DOT);
    tap_key  (KC_SPC);
  }
  else {
    double_max(state->count, SHIFT, KC_DOT);
  }
  reset_tap_dance(state);
}

void lesser(STATE, void *user_data) {
  if (state->count > 2) { // triple tap comm: _,-_
    tap_key  (KC_SPC);
    shift_key(KC_COMM);
    tap_key  (KC_MINS);
    tap_key  (KC_SPC);
  }
  else {
    double_max(state->count, SHIFT, KC_COMM);
  }
  reset_tap_dance(state);
}

void tilde(STATE, void *user_data) {
  if (state->count > 2) { // triple tap tilde: ~ TODO
    register_code(KC_LSFT);
    register_code(KC_GRV);
  }
  else {  // tap: keycode
    shift_key(KC_GRV);
    if (state->count > 1) { // double tap: ~/
      tap_key(KC_SLSH);
    }
  }
}

void tilde_reset(STATE, void *user_data) {
  unregister_code(KC_GRV);
  unregister_code(KC_LSFT);
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


