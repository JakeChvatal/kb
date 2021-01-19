#include "macros.h"

// void register_shift(uint16_t keycode):
// void unregister_shift(uint16_t keycode):
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

// ............................................................. Tap Dance Pairs
// tap dance shift rules
#define S_NEVER  0
#define S_SINGLE 1
#define S_DOUBLE 2
#define S_ALWAYS S_SINGLE | S_DOUBLE
#define CLOSE 1

void symbol_pair(uint8_t shift, uint16_t left, uint16_t right); // press a pair of symbols together
void tap_pair(STATE, uint8_t shift, uint16_t left, uint16_t right, uint16_t modifier, uint8_t close); // tap dance symbol pairs

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
