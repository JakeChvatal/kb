/*
 * Central point of control for key mappings.
 * Brings all necessary files for compilation together.
 */
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// vararg macro -- delays macro expansion for home rows
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

// ........................................................ Default Alpha Layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#include "qwerty.h"
#include "colemak.h"
#include "beakl.h"
// ...................................................... Number / Function Keys
#include "common/number_fkey_layout.h"
// ......................................................... Symbol / Navigation
#include "common/symbol_guifn_layout.h"
// ............................................................... Toggle Layers
#ifdef CENTER_TT
#include "common/toggle_layout.h"
#endif
// ......................................................... Short Cuts / Adjust
#include "common/chord_layout.h"
};
