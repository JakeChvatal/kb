#pragma once
#include "macros.h"
#include "../config.h"
#include "keycode_functions.h"


// ................................................................ Global Scope

// static uint8_t  reshifted  = 0;  // SFT_T timing trap, see map_shift(), process_record_user()
// static uint16_t tt_keycode = 0;  // current TT keycode

#define CLR_1SHOT clear_oneshot_layer_state(ONESHOT_PRESSED)
#define KEY_DOWN  record->event.pressed

// ................................................................. Local Scope

static uint8_t  i          = 0;  // inline for loop counter
static uint16_t key_timer  = 0;  // global event timer

#define KEY_TIMER key_timer = timer_read()
#define KEY_TAP   timer_elapsed(key_timer) < TAPPING_TERM
#define SHIFT   1
#define NOSHIFT 0

// --- simple helpers

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
// double tap key with count
#define SHIFTED_OR(k) shift ? shift_key(k) : tap_key(k)
void double_tap(uint8_t count, uint8_t shift, uint16_t keycode)
{
  SHIFTED_OR(keycode);
  if (count > 1) { SHIFTED_OR(keycode); }
}

#define SHIFT   1
#define NOSHIFT 0

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

/* // ALT_T, CTL_T, GUI_T, SFT_T for shifted keycodes */
/* void mt_shift(RECORD, uint16_t modifier, uint16_t modifier2, uint16_t keycode) { */
/*   if (KEY_DOWN) { */
/*     key_timer = timer_read(); */
/*     register_code(modifier); */
/*     if (modifier2) { */
/*       register_code(modifier2); */
/*     } */
/*   } */
/*   else { */
/*     unregister_code(modifier); */
/*     if (modifier2) { */
/*       unregister_code(modifier2); */
/*     } */
/*     if (timer_elapsed(key_timer) < TAPPING_TERM) { */
/*       shift_key(keycode); */
/*     } */
/*     key_timer = 0; */
/*   } */
/* } */

// ................................................................... Mod Masks

// tap dance persistent mods, see process_record_user()
// keyboard_report->mods (?) appears to be cleared by tap dance
static uint8_t mods = 0;

void register_modifier(uint16_t keycode) {
  register_code(keycode);
  mods |= MOD_BIT(keycode);
}

void unregister_modifier(uint16_t keycode) {
  unregister_code(keycode);
  mods &= ~(MOD_BIT(keycode));
}

#define MOD_KEY(x) mods & MOD_BIT(x)

// (un)register modifiers
void mod_all(void (*f)(uint8_t), uint8_t mask) {
  if (!mods)            { return; }
  if (MOD_KEY(KC_LGUI)) { f(KC_LGUI); }
  if (MOD_KEY(KC_LCTL)) { f(KC_LCTL); }
  if (MOD_KEY(KC_LALT)) { f(KC_LALT); }
  if (MOD_KEY(KC_LSFT)) { f(KC_LSFT); }
  if (MOD_KEY(KC_RSFT)) { f(KC_RSFT); }  // note: qmk macros all use left modifiers
  if (MOD_KEY(KC_RALT)) { f(KC_RALT); }
  if (MOD_KEY(KC_RCTL)) { f(KC_RCTL); }
  if (MOD_KEY(KC_RGUI)) { f(KC_RGUI); }
  mods &= (mask ? 0xFF : 0);             // 0 -> discard, otherwise -> retain state
}

// two or more active modifier keys (down) only, see mod_roll()
bool chained_modifier(void) {
  uint8_t bits = 0;
  uint8_t i    = mods;
  while(i) { bits += i % 2; i >>= 1; }
  return bits > 1;
}

void mod_bits(RECORD, uint16_t keycode) {
  if (KEY_DOWN) { mods |=   MOD_BIT(keycode); }
  else          { mods &= ~(MOD_BIT(keycode)); }
}
// base layer modifier
bool mod_down(uint16_t key_code) {
  return mods == MOD_BIT(key_code);  // on home row modifier only
}

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


void oneshot_shift(uint8_t layer)
{
  if (layer) { layer_off(layer); }           // disable key's assigned toggle layer
  layer_on         (_SHIFT);                 // sentence/paragraph capitalization
  set_oneshot_layer(_SHIFT, ONESHOT_START);  // see process_record_user() -> clear_oneshot_layer_state(ONESHOT_PRESSED)
}


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


// ............................................................ Keycode Modifier


void mod_key(uint16_t modifier, uint16_t keycode)
{
  switch (modifier) {
  case NOSHIFT:
    tap_key(keycode);   break;
  case SHIFT:
    shift_key(keycode); break;
  default:
    register_modifier  (modifier);
    tap_key            (keycode);
    unregister_modifier(modifier);
  }
}

#define SET_EVENT(c) e[c].key_timer = timer_read(); \
                     e[c].keycode   = keycode;      \
                     e[c].shift     = shift;        \
                     e[c].side      = side;         \
                     e[c].leadercap = leadercap;    \
                     prev_key       = next_key;     \
                     next_key       = c

// column 0 1 2 3 4 <- left, right -> 5 6 7 8 9
static struct column_event {
  uint16_t key_timer;            // event priority
  uint16_t keycode;
  uint8_t  shift;
  uint8_t  side;
  uint8_t  leadercap;
} e[12];                         // leader -> 10 11, see process_record_user(), mod_roll()

void clear_events(void)
{
  for (i = 0; i < 12; i++) { e[i].key_timer = 0; e[i].leadercap = 0; }
}

#define LEADER 10                // ,11 leader columns
#define LSHIFT 3                 // left shift column
#define RSHIFT 6                 // right shift column

#define LEFT   1                 // also see raise_layer(), rolling_layer()
#define RIGHT  2                 // for binary (LEFT | RIGHT) test

static uint8_t leadercap   = 0;  // substitute (0) keycode (1) leader + oneshot_SHIFT, see leader_cap()
static uint8_t leaderlayer = 0;  // thumb key's toggle layer, see process_record_user()
static uint8_t next_key    = 0;  // by column reference
static uint8_t prev_key    = 0;

#define ROLL(s, k) (e[RSHIFT].shift && s == LEFT) || (e[LSHIFT].shift && s == RIGHT) ? shift_key(k) : tap_key(k)

void roll_key(uint8_t side, uint16_t keycode, uint8_t column)
{
  if (e[column].key_timer < e[next_key].key_timer) {              // rolling sequence in progress
    mod_all(unregister_code, 0);                                  // disable modifier chord finger rolls
    if (e[column].shift && e[column].side != e[next_key].side) {  // shift only opposite side of rolling sequence
      shift_key(e[next_key].keycode);                             // shift opposite home row key
      e[next_key].key_timer = 0;                                  // don't re-echo this key
    } else { ROLL(side, keycode); }                               // tap (shifted?) key
  } else   { ROLL(side, keycode); e[prev_key].key_timer = 0; e[column].leadercap = 0; }  // don't echo preceeding modifier key
}

#define CLEAR_EVENT e[column].key_timer   = 0; \
                    e[column].shift       = 0; \
                    e[prev_key].leadercap = 0; \
                    leaderlayer           = 0

// handle rolling keys as shift keycode, a sequence of unmodified keycodes, or keycode leader oneshot_SHIFT
bool mod_roll(RECORD, uint8_t side, uint8_t shift, uint16_t modifier, uint16_t keycode, uint8_t column)
{
  if (KEY_DOWN) {
    SET_EVENT(column);
    if (modifier) { register_modifier(modifier); }
  } else {
    if (modifier) { unregister_modifier(modifier); }
    if (timer_elapsed(e[column].key_timer) < TAPPING_TERM) {
      roll_key(side, keycode, column);
      if (e[prev_key].leadercap && column >= LEADER) {  // punctuation leader capitalization chord?
        oneshot_shift(leaderlayer);
        CLEAR_EVENT;
        return true;
      }
    }
    CLEAR_EVENT;
  }
  return false;
}

// down -> always shift (versus SFT_t auto repeat), 
void mod_t(RECORD, uint16_t modifier, uint16_t keycode)
{
  if (KEY_DOWN) { KEY_TIMER; register_modifier(modifier); }
  else {
    unregister_modifier(modifier);
    if (KEY_TAP) { tap_key(keycode); }
    key_timer = 0;
  }
}

// ALT_T, CTL_T, GUI_T, SFT_T for shifted keycodes
void mt_shift(RECORD, uint16_t modifier, uint16_t modifier2, uint16_t keycode)
{
  if (KEY_DOWN) {
    KEY_TIMER;
    if (modifier2) { register_modifier(modifier2); }
    register_modifier(modifier);
  } else {
    unregister_modifier(modifier);
    if (modifier2) { unregister_modifier(modifier2); }
    if (KEY_TAP)   { shift_key(keycode); }
    key_timer = 0;
  }
}
