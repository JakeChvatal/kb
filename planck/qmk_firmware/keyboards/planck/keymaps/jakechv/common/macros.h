// convenient macros
#define RECORD keyrecord_t *record
// TODO refactor with these? may prove to be unnecessary obfuscation...
// #define KEYCODE uint16_t keycode
// #define LAYER uint8_t layer
// #define SHIFT uint8_t shift
// #define COL uint8_t column
// #define SIDE uint8_t side
#define KEY_DOWN record->event.pressed
#define KEY_TAP timer_elapsed(key_timer) < TAPPING_TERM

// TODO refactor td state?
#define TD_STATE qk_tap_dance_state_t *state
#define TAPPED_TWICE state->count > 2
#define TAPPED_ONCE state->count > 1
#define TD_PRESSED ye
