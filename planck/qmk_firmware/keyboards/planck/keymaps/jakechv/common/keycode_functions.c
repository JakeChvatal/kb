#pragma once
#include "macros.h"
#include "../config.h"
#include "keycode_functions.h"

// press shift, then key
void register_shift(uint16_t keycode)
{
  register_code(KC_LSFT);
  register_code(keycode);
}

// unpress key, unpress shift
void unregister_shift(uint16_t keycode)
{
  unregister_code(keycode);
  unregister_code(KC_LSFT);
}

// quickly press key
void tap_key(uint16_t keycode) {
  register_code  (keycode);
  unregister_code(keycode);
}

// press shift over code
void shift_key(uint16_t keycode) {
  register_code  (KC_LSFT);
  tap_key        (keycode);
  unregister_code(KC_LSFT);
}

#define SHIFT   1
#define NOSHIFT 0

static uint16_t key_timer = 0; 

// key press for thumb_layer() and lt_shift() macros
// if time left, shift, else tap
bool key_press(uint8_t shift, uint16_t keycode) {
  if (keycode) {
    if (KEY_TAP) {
      if (shift) {
        shift_key(keycode);
      }
      else {
        tap_key(keycode);
      }
      return true;
    }
  }
  return false;
}

// ALT_T, CTL_T, GUI_T, SFT_T for shifted keycodes
void mt_shift(RECORD, uint16_t modifier, uint16_t modifier2, uint16_t keycode) {
  if (KEY_DOWN) {
    key_timer = timer_read();
    register_code(modifier);
    if (modifier2) {
      register_code(modifier2);
    }
  }
  else {
    unregister_code(modifier);
    if (modifier2) {
      unregister_code(modifier2);
    }
    if (timer_elapsed(key_timer) < TAPPING_TERM) {
      shift_key(keycode);
    }
    key_timer = 0;
  }
}

// ................................................................... Mod Masks

// tap dance persistent mods, see process_record_user()
// keyboard_report->mods (?) appears to be cleared by tap dance
static uint8_t mods = 0;

void tap_mods(RECORD, uint16_t keycode) {
  if (KEY_DOWN) {
    mods |= MOD_BIT(keycode);
  }
  else {
    mods &= ~(MOD_BIT(keycode));
  }
}

// (un)register modifiers
void modifier(void (*f)(uint8_t)) {
  if (mods & MOD_BIT(KC_LCTL)) {
    (*f)(KC_LCTL);
  }
  if (mods & MOD_BIT(KC_LGUI)) {
    (*f)(KC_LGUI);
  }
  if (mods & MOD_BIT(KC_LALT)) {
    (*f)(KC_LALT);
  }
}

// .................................................... Triple Dance Shift/Layer

static uint8_t dt_shift = 0;

// tap key, then oneshot off to shift layer
void double_shift(uint16_t keycode, uint8_t layer) {
  tap_key (keycode);
  if (DT_SHIFT) {
    layer_on         (_SHIFT);
    set_oneshot_layer(_SHIFT, ONESHOT_START);
    dt_shift = 1;
  }
  else {
    layer_on(layer);
  }
}

// tap dance LT (LAYER, KEY) emulation with <KEY><DOWN> -> <KEY><SHIFT> and auto-repeat extensions!
void tap_shift(STATE, uint16_t keycode, uint8_t layer) {
  // double tap plus down
  if (state->count > 2) {
    // double enter shift
    if (keycode == KC_ENT) {
      tap_key     (keycode);
      double_shift(keycode, layer);
    }
    // repeating keycode
    else {
      register_code(keycode);
    }
  }
  // tap plus down (or double tap): keycode (one shot) shift
  else if (state->count > 1) {
    double_shift(keycode, layer);
  }
  // down: shift
  else if (state->pressed) {
    layer_on(layer);
  }
  // tap: keycode
  else {
    modifier(register_code);
    tap_key (keycode);
    modifier(unregister_code);
  }
}

// reset tapping
void tap_reset(uint16_t keycode, uint8_t layer) {
  unregister_code(keycode);
  if (DT_SHIFT && dt_shift) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    dt_shift = 0;
  }
  else {
    layer_off(layer);
  }
}

// augment pseudo LT (_RSHIFT, KC_ENT) handling below for rapid <ENTER><SHIFT> sequences
void enter(STATE, void *user_data) {
  tap_shift(state, KC_ENT, _RSHIFT);
}

// reset enter
void enter_reset(STATE, void *user_data) {
  tap_reset(KC_ENT, _RSHIFT);
}


// augment pseudo LT (_RSHIFT, KC_ENT) handling below for rapid <ENTER><SHIFT> sequences
void bspc(STATE, void *user_data) {
  tap_shift(state, KC_BSPC, _RSHIFT);
}

// reset bspc
void bspc_reset(STATE, void *user_data) {
  tap_reset(KC_BSPC, _RSHIFT);
}

// augment pseudo LT (_LSHIFT, KC_SPC) handling below for rapid <SPACE><SHIFT> sequences
void space(STATE, void *user_data) {
  tap_shift(state, KC_SPC, _LSHIFT);
}

// reset spc
void space_reset(STATE, void *user_data) {
  tap_reset(KC_SPC, _LSHIFT);
}

// ......................................................... Triple Dance Insert
// double tap if key pressed multiple times
void double_max(uint8_t count, uint8_t shift, uint16_t keycode) {
  if (shift) {
    shift_key(keycode);
    if (count > 1) {
      shift_key(keycode);
    }
  }
  else {
    tap_key(keycode);
    if (count > 1) {
      tap_key(keycode);
    }
  }
}

// ............................................................. Tap Dance Pairs

// tap dance shift rules
#define S_NEVER  0
#define S_SINGLE 1
#define S_DOUBLE 2
#define S_ALWAYS S_SINGLE | S_DOUBLE

// press a pair of symbols together
void symbol_pair(uint8_t shift, uint16_t left, uint16_t right) {
  if (shift & S_DOUBLE) {  // if shift both, apply shift
    shift_key(left);
    shift_key(right);
  }
  else { // else, press both unshifted
    tap_key(left);
    tap_key(right);
  }
}

#define CLOSE 1

// tap dance symbol pairs
void tap_pair(STATE, uint8_t shift, uint16_t left, uint16_t right, uint16_t modifier, uint8_t close) {
  // triple tap: left right with cursor between symbol pair a la vim :-)
  if (state->count > 2) { // triple tap: left, right, then start in middle (_)
    symbol_pair(shift, left, right);
    tap_key    (KC_LEFT);
  }
  // double tap: left right
  else if (state->count > 1) { // double tap: left and right ()_
    symbol_pair(shift, left, right);
  }
  else if (state->pressed) { // down: modifier
    if (modifier) {
      register_code(modifier);
    }
  }
  else { // tap: left (close: right)
    if (shift & S_SINGLE) {
      shift_key(close ? right : left);
    }
    else {
      tap_key(close ? right : left);
    }
  }
  if (!modifier) {
    reset_tap_dance(state);
  }
}



// .............................................................. Dynamic Layers

#define        LEFT    1
#define        RIGHT   2
static uint8_t thumb = 0;

// LEFT (KC_SPC, S(KC_BSLS)), RIGHT (KC_LEFT, S(KC_LEFT)) opposite thumb combinations, see process_record_user()
// up,   up   -> _BASE
// up,   down -> _SYMBOL
// down, up   -> _NUMBER
// down, down -> _MOUSE                     // see layer keycodes that raise mouse layer
#define THUMBS_DOWN _MOUSE                  // layer

static uint8_t overlayer = 0;
// left right thumb layer combinations
void thumb_layer(RECORD, uint8_t side, uint8_t shift, uint16_t keycode, uint8_t thumb_dn_layer, uint8_t thumb_up_layer) {
  if (KEY_DOWN) {
    // layer_on via tap_layer(), see process_record_user()
    key_timer = timer_read();
    thumb     = thumb | side;
  }
  else {
    layer_off(thumb_dn_layer);
    // opposite thumb_layer() thumb may have switched effective layer!
    if (overlayer) {
      layer_off(overlayer);
      overlayer = 0;
    }
    if (!key_press(shift, keycode)) {
      layer_off(THUMBS_DOWN);               // both thumbs needed
      // opposite thumb down? see left right combination layer table above
      if (thumb & (side == LEFT ? RIGHT : LEFT)) {
        layer_on(thumb_up_layer);
        overlayer = thumb_up_layer;
      }
    }
    clear_mods();
    thumb     = thumb & ~side;
    key_timer = 0;
  }
}
 
// LT for S(keycode)
void lt_shift(RECORD, uint16_t keycode, uint8_t layer) { // toggle shift layer
  if (KEY_DOWN) {
    key_timer = timer_read();
    layer_on(layer);
  }
  else {
    layer_off(layer);
    // for shifted keycodes, hence, LT_SHIFT
    key_press(SHIFT, keycode);
    clear_mods();
    key_timer = 0;
  }
}

// set layer asap to overcome macro latency errors, notably tap dance and LT usage
// this routine inexplicably (?) sets layer_on() faster than can be done in thumb_layer()
void tap_layer(RECORD, uint8_t layer) { // set layer tap right away
  if (KEY_DOWN) {
    layer_on(layer);
  }
  else {
    layer_off(layer);
  }
}

// ..................................................................... Keymaps
void clear_layers(void) {
  uint8_t layer;
  for (layer = 0; layer < _END_LAYERS; layer++) {
    layer_off(layer);
  }
}


// reset layers to base layer
void base_layer(void) {
  clear_layers();
  set_single_persistent_default_layer(_BASE);
}
