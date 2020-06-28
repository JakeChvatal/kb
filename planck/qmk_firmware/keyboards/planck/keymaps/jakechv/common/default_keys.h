// definitions for the default and shifted key layers
#ifdef QWERTY
#define _________________KEYS_L1_________________ KC_Q,   KC_W,   KC_E,   KC_R,   KC_T
#define _________________KEYS_L2_________________ HOME_A, HOME_S, HOME_D, HOME_F, KC_G
#define _________________KEYS_L3_________________ KC_Z,   KC_X,   KC_C,   KC_V,   KC_B

#define ____________KEYS_CAPS_L1_________________ S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T)
#define ____________KEYS_CAPS_L2_________________ S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G)
#define ____________KEYS_CAPS_L3_________________ S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B)

#define _________________KEYS_R1_________________ KC_Y, KC_U,   KC_I,    KC_O,   KC_P
#define _________________KEYS_R2_________________ KC_H, HOME_J, HOME_K,  HOME_L, HOME_SC
#define _________________KEYS_R3_________________ KC_N, KC_M,   KC_COMM, KC_DOT, TD_QUOT

#define ____________KEYS_CAPS_R1_________________ S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P)
#define ____________KEYS_CAPS_R2_________________ S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN
#define ____________KEYS_CAPS_R3_________________ S(KC_N), S(KC_M), KC_COMM, KC_DOT,  TD_QUOT

#define ____________KEYS_CAPS_ShiftR3____________ S(KC_N), S(KC_M), KC_COMM, KC_DOT,  TD_QUOT
#define ____________KEYS_CAPS_LShiftR3___________ S(KC_N), S(KC_M), KC_SLSH, KC_QUES, TD_DQOT
#define ____________KEYS_CAPS_RShiftR3___________ S(KC_N), S(KC_M), TD_TILD, TD_GRV,  TD_DQOT
#endif

#ifdef SOUL
#define _________________KEYS_L1_________________ KC_Q,   KC_W,   KC_F,   KC_P,   KC_B
#define _________________KEYS_L2_________________ HOME_A, HOME_R, HOME_S, HOME_T, KC_G
#define _________________KEYS_L3_________________ KC_Z,   KC_X,   KC_C,   KC_D,   KC_V

#define ____________KEYS_CAPS_L1_________________ S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B)
#define ____________KEYS_CAPS_L2_________________ S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G)
#define ____________KEYS_CAPS_L3_________________ S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V)

#define _________________KEYS_R1_________________ KC_J, KC_L,   KC_U,    KC_Y,   KC_SCLN
#define _________________KEYS_R2_________________ KC_M, HOME_N, HOME_E,  HOME_I, HOME_O   
#define _________________KEYS_R3_________________ KC_K, KC_H,   KC_COMM, KC_DOT, TD_QUOT

#define ____________KEYS_CAPS_R1_________________ S(KC_J), S(KC_L), S(KC_U), S(KC_Y), KC_SCLN
#define ____________KEYS_CAPS_R2_________________ S(KC_M), S(KC_N), S(KC_E), S(KC_I), S(KC_O)
#define ____________KEYS_CAPS_R3_________________ S(KC_K), S(KC_H), KC_COMM, KC_DOT,  TD_QUOT

#define ____________KEYS_CAPS_ShiftR3____________ S(KC_K), S(KC_H), KC_COMM, KC_DOT,  TD_QUOT
#define ____________KEYS_CAPS_LShiftR3___________ S(KC_K), S(KC_H), KC_SLSH, KC_QUES, TD_DQOT
#define ____________KEYS_CAPS_RShiftR3___________ S(KC_K), S(KC_H), TD_TILD, TD_GRV,  TD_DQOT
#endif

#ifdef COLEMAK
#define _________________KEYS_L1_________________ KC_Q,   KC_W,   KC_F,   KC_P,   KC_G
#define _________________KEYS_L2_________________ HOME_A, HOME_R, HOME_S, HOME_T, KC_G
#define _________________KEYS_L3_________________ KC_Z,   KC_X,   KC_C,   KC_V,   KC_B

#define ____________KEYS_CAPS_L1_________________ S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_G)
#define ____________KEYS_CAPS_L2_________________ S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D)
#define ____________KEYS_CAPS_L3_________________ S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B)

#define _________________KEYS_R1_________________ KC_J, KC_L,   KC_U,    KC_Y,   KC_SCLN
#define _________________KEYS_R2_________________ KC_H, HOME_N, HOME_E,  HOME_I, HOME_O   
#define _________________KEYS_R3_________________ KC_K, KC_M,   KC_COMM, KC_DOT, KC_SLSH

#define ____________KEYS_CAPS_R1_________________ S(KC_J), S(KC_L), S(KC_U),    S(KC_Y),   S(KC_SCLN)
#define ____________KEYS_CAPS_R2_________________ S(KC_H), S(KC_N), S(KC_E),    S(KC_I),   S(KC_O) 
#define ____________KEYS_CAPS_R3_________________ S(KC_K), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH)

#define ____________KEYS_CAPS_ShiftR3____________ S(KC_K), S(KC_M), KC_COMM, KC_DOT,  TD_QUOT
#define ____________KEYS_CAPS_LShiftR3___________ S(KC_K), S(KC_M), KC_SLSH, KC_QUES, TD_DQOT
#define ____________KEYS_CAPS_RShiftR3___________ S(KC_K), S(KC_M), TD_TILD, TD_GRV,  TD_DQOT
#endif
