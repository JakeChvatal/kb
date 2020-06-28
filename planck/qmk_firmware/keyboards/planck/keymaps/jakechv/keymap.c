#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

#include "common/keycodes.h"
#include "common/tapdance.h" 
#include "common/keycode_functions.h" 
#include "common/keycode_groups.h"

// vararg macro -- delays macro expansion for home rows
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#include "layout.h"
};

#include "common/process_record.h"
