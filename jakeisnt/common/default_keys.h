// definitions for the default and shifted key layers
#ifdef QWERTY
#define KEYS_L1 KC_Q,   KC_W,   KC_E,   KC_R,   KC_T
#define KEYS_L2 HOME_A, HOME_S, HOME_D, HOME_F, KC_G
#define KEYS_L3 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B

#define KEYCL1 S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T)
#define KEYCL2 S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G)
#define KEYCL3 S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B)

#define KEYS_R1 KC_Y, KC_U,   KC_I,    KC_O,   KC_P
#define KEYS_R2 KC_H, HOME_J, HOME_K,  HOME_L, HOME_SC
#define KEYS_R3 KC_N, KC_M,   KC_COMM, KC_DOT, TD_QUOT

#define KEYCR1 S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P)
#define KEYCR2 S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN
#define KEYCR3 S(KC_N), S(KC_M), KC_COMM, KC_DOT,  TD_QUOT

#define KEYCSR3  S(KC_N), S(KC_M), KC_COMM, KC_DOT,  TD_QUOT
#define KEYCLSL3 S(KC_N), S(KC_M), KC_SLSH, KC_QUES, TD_DQOT
#define KEYCRSR3 S(KC_N), S(KC_M), TD_TILD, TD_GRV,  TD_DQOT
#endif

#ifdef SOUL
#define KEYS_L1 KC_Q,   KC_W,   KC_F,   KC_P,   KC_B
#define KEYS_L2 HOME_A, HOME_R, HOME_S, HOME_T, KC_G
#define KEYS_L3 KC_Z,   KC_X,   KC_C,   KC_D,   KC_V

#define KEYCL1 S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B)
#define KEYCL2 S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G)
#define KEYCL3 S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V)

#define KEYS_R1 KC_J, KC_L,   KC_U,    KC_Y,   KC_SCLN
#define KEYS_R2 KC_M, HOME_N, HOME_E,  HOME_I, HOME_O   
#define KEYS_R3 KC_K, KC_H,   KC_COMM, KC_DOT, TD_QUOT

#define KEYCR1 S(KC_J), S(KC_L), S(KC_U), S(KC_Y), KC_SCLN
#define KEYCR2 S(KC_M), S(KC_N), S(KC_E), S(KC_I), S(KC_O)
#define KEYCR3 S(KC_K), S(KC_H), KC_COMM, KC_DOT,  TD_QUOT

#define KEYCSR3  S(KC_K), S(KC_H), KC_COMM, KC_DOT,  TD_QUOT
#define KEYCLSL3 S(KC_K), S(KC_H), KC_SLSH, KC_QUES, TD_DQOT
#define KEYCRSR3 S(KC_K), S(KC_H), TD_TILD, TD_GRV,  TD_DQOT
#endif

#ifdef COLEMAK
#define KEYS_L1 KC_Q,   KC_W,   KC_F,   KC_P,   KC_G
#define KEYS_L2 HOME_A, HOME_R, HOME_S, HOME_T, KC_G
#define KEYS_L3 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B

#define KEYCL1 S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_G)
#define KEYCL2 S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D)
#define KEYCL3 S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B)

#define KEYS_R1 KC_J, KC_L,   KC_U,    KC_Y,   KC_SCLN
#define KEYS_R2 KC_H, HOME_N, HOME_E,  HOME_I, HOME_O   
#define KEYS_R3 KC_K, KC_M,   KC_COMM, KC_DOT, KC_SLSH

#define KEYCR1 S(KC_J), S(KC_L), S(KC_U),    S(KC_Y),   S(KC_SCLN)
#define KEYCR2 S(KC_H), S(KC_N), S(KC_E),    S(KC_I),   S(KC_O) 
#define KEYCR3 S(KC_K), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH)

#define KEYCSR3  S(KC_K), S(KC_M), KC_COMM, KC_DOT,  TD_QUOT
#define KEYCLSL3 S(KC_K), S(KC_M), KC_SLSH, KC_QUES, TD_DQOT
#define KEYCRSR3 S(KC_K), S(KC_M), TD_TILD, TD_GRV,  TD_DQOT
#endif
