#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

#include "common/keycodes.h"
#include "common/tapdance.h" 
#include "common/tapdance.c"
#include "common/keycode_functions.h" 
#include "common/keycode_functions.c"
#include "common/keycode_groups.h"

// vararg macro -- delays macro expansion for home rows
#define planck_layout(...) LAYOUT_planck_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#include "layout.h"
};

void eeconfig_init_user(void) {
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE)
  set_unicode_input_mode(UC_LNX);
#endif
}

#define BASE_1  1
#define BASE_2  2
#define BASE_12 3

static uint8_t base_n = 0;

bool process_record_user(uint16_t keycode, RECORD) {
  switch (keycode) {
#ifdef ROLLOVER
#ifdef QWERTY
  case HOME_A:
    mod_roll(record, LEFT, NOSHIFT, KC_LGUI, KC_A, 0);  break;
  case HOME_S:
    mod_roll(record, LEFT, NOSHIFT, KC_LCTL, KC_S, 1);  break;
  case HOME_D:
    mod_roll(record, LEFT, NOSHIFT, KC_LALT, KC_D, 2);  break;
  case HOME_F:
    leadercap = KEY_DOWN ? 1 : 0;  // space/enter + shift shortcut, see leader_cap()
    mod_roll(record, LEFT, SHIFT, KC_LSFT, KC_F, 3);    break;

  case HOME_J:
    mod_roll(record, RIGHT, SHIFT, KC_RSFT, KC_J, 6);   break;
  case HOME_K:
    mod_roll(record, RIGHT, NOSHIFT, KC_RALT, KC_K, 7); break;
  case HOME_L:
    mod_roll(record, RIGHT, NOSHIFT, KC_RCTL, KC_L, 8); break;
  case HOME_SC:
    mod_roll(record, RIGHT, NOSHIFT, KC_RGUI, KC_SCLN, 9); break;
#endif
#ifdef COLEMAK
  case HOME_A:
    mod_roll(record, LEFT, NOSHIFT, KC_LGUI, KC_A, 0);  break;
  case HOME_R:
    mod_roll(record, LEFT, NOSHIFT, KC_LCTL, KC_S, 1);  break;
  case HOME_S:
    mod_roll(record, LEFT, NOSHIFT, KC_LALT, KC_D, 2);  break;
  case HOME_T:
    leadercap = KEY_DOWN ? 1 : 0;  // space/enter + shift shortcut, see leader_cap()
    mod_roll(record, LEFT, SHIFT, KC_LSFT, KC_F, 3);    break;

  case HOME_N:
    mod_roll(record, RIGHT, SHIFT, KC_RSFT, KC_N, 6);   break;
  case HOME_E:
    mod_roll(record, RIGHT, NOSHIFT, KC_RALT, KC_E, 7); break;
  case HOME_I:
    mod_roll(record, RIGHT, NOSHIFT, KC_RCTL, KC_I, 8); break;
  case HOME_O:
    mod_roll(record, RIGHT, NOSHIFT, KC_RGUI, KC_O, 9); break;
#endif
#ifdef SOUL
  case HOME_A:
    mod_roll(record, LEFT, NOSHIFT, KC_LGUI, KC_A, 0);  break;
  case HOME_R:
    mod_roll(record, LEFT, NOSHIFT, KC_LCTL, KC_R, 1);  break;
  case HOME_S:
    mod_roll(record, LEFT, NOSHIFT, KC_LALT, KC_S, 2);  break;
  case HOME_T:
    leadercap = KEY_DOWN ? 1 : 0;  // space/enter + shift shortcut, see leader_cap()
    mod_roll(record, LEFT, SHIFT, KC_LSFT, KC_T, 3);    break;

  case HOME_N:
    mod_roll(record, RIGHT, SHIFT, KC_RSFT, KC_N, 6);   break;
  case HOME_E:
    mod_roll(record, RIGHT, NOSHIFT, KC_RALT, KC_E, 7); break;
  case HOME_I:
    mod_roll(record, RIGHT, NOSHIFT, KC_RCTL, KC_I, 8); break;
  case HOME_O:
    mod_roll(record, RIGHT, NOSHIFT, KC_RGUI, KC_O, 9); break;
#endif
#endif
    case BASE1:
      if (KEY_DOWN) {
        base_n = base_n | BASE_1;
        if (base_n == BASE_12) {
          base_layer();
        }
      }
      else {
        base_n = base_n & ~BASE_1;
      }
      return false;
    case BASE2:
      if (KEY_DOWN) {
        base_n = base_n | BASE_2;
        if (base_n == BASE_12) {
          base_layer();
        }
      }
      else {
        base_n = base_n & ~BASE_2;
      }
      return false;
    case AT_DOWN:
      tap_layer(record, _NUMBER); // TODO ??
    case LT_ESC:
      tap_layer(record, _NUMBER);
      break;
    case LT_LEFT:
    case SP_BSPC:
      tap_layer(record, _SYMBOL);
      // LT (_SYMBOL, KC_LEFT) left right combination layer
      thumb_layer(record, RIGHT, 0, 0, _SYMBOL, _LSHIFT);
      break;
    case OS_ALT:
      tap_mods(record, KC_LALT);
      break;
    case OS_CTL:
      tap_mods(record, KC_LCTL);
      break;
    case OS_GUI:
      tap_mods(record, KC_LGUI);
      break;
    case SM_CIRC:
      // GUI_T(S(KC_6))
      mt_shift(record, KC_LGUI, 0, KC_6);
      break;
    case SM_DLR:
      // SFT_T(S(KC_4))
      mt_shift(record, KC_LSFT, 0, KC_4);
      break;
    case SM_G:
      // MT(MOD_LALT | MOD_LSFT, S(KC_G))
      mt_shift(record, KC_LALT, KC_LSFT, KC_G);
      break;
    case SM_LPRN:
      // CTL_T(S(KC_9))
      mt_shift(record, KC_LCTL, 0, KC_9);
      break;
    case SM_PERC:
      // ALT_T(S(KC_5))
      mt_shift(record, KC_LALT, 0, KC_5);
      break;
    case LT_BSLS:
      tap_layer(record, _MOUSE);
      // LT (_MOUSE, KC_BSLS) left right combination layer, see #define LT_BSLS
      thumb_layer(record, LEFT, 0, 0, _MOUSE, _SYMBOL);
      break;
    case SL_LEFT:
      tap_layer(record, _MOUSE);
      // LT (_MOUSE, S(KC_LEFT)) left right combination layer
      thumb_layer(record, RIGHT, SHIFT, KC_LEFT, _MOUSE, _LSHIFT);
      break;
    case SP_DEL:
      tap_layer(record, _MOUSE);
      // LT (_MOUSE, S(KC_LEFT)) left right combination layer
      thumb_layer(record, RIGHT, NOSHIFT, KC_DEL, _MOUSE, _LSHIFT);
      break;
    case SL_PIPE:
      // LT (_ADJUST, S(KC_BSLS)) emulation TODO
      lt_shift(record, KC_BSLS, _FNCKEY); 
      break;
    case SL_TAB:
      // LT (_FNCKEY, S(KC_TAB)) emulation
      lt_shift(record, KC_TAB, _FNCKEY);
      break;
    case TD_ENT:
      tap_layer(record, _RSHIFT);
      // LT (_RSHIFT, KC_ENT) emulation, see tap dance enter
      //
    case TD_BSPC:
      tap_layer(record, _RSHIFT);
      // LT (_RSHIFT, KC_BSPC) emulation, see tap dance enter
      break;
    case TD_SPC:
      tap_layer(record, _LSHIFT);
      // LT (_LSHIFT, KC_SPC) left right combination layer, see tap dance TD_SPC
      thumb_layer(record, LEFT, 0, 0, _LSHIFT, _SYMBOL);
      break;
    case PS_BASE:
      if (KEY_DOWN) {
        base_layer();
      }
      return false;
  }
  return true;
}
