#pragma once
// --- keycode macro groups
// inspired by https://github.com/noahfrederick/qmk-keymaps/blob/master/user/my.h
// --- convenience
// .--------------------.
// | Mute |VolDwn|VolUp |
// `--------------------'
#define VOLUME KC_MUTE, KC_VOLD, KC_VOLU

// .--------------------.
// |MPrev |MPlay |MNext |
// `--------------------'
#define MEDIA KC_MPRV, KC_MPLY, KC_MNXT

// navigation
#define NAV1 KC_PGUP, _______, KC_HOME, KC_UP, KC_END
#define NAV2 KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT

// mouse
// .----------------------------------.
// |      |ScrlL |  ^   |ScrlR |ScrlUp|
// |----------------------------------|
// |      |  <-  |  ;   |  ->  |ScrlDw|
// |----------------------------------|
// |      |      |      |      |      |
// '----------------------------------'
#define MOUSE1 _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define MOUSE2 _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define MOUSE3 _______, _______, _______, _______, _______

// .----------------------------------.
// |      | LClk | CClk | RClk |      |
// `----------------------------------'
#define MSCLK _______, KC_BTN1, KC_BTN3, KC_BTN2, _______

// modifiers
// .----------------------------------.
// |      | GUI  | Ctrl |  Alt | Shift|
// `----------------------------------'
#define MODKEYS _______, OS_GUI, OS_CTL, OS_ALT, OS_SFT

// function keys
// .----------------------------------.
// |      |  F7  |  F8  |  F9  |  F12 |
// |----------------------------------|
// |      |  F4  |  F5  |  F6  |  F11 |
// |----------------------------------|
// |      |  F1  |  F2  |  F3  |  F10 |
// '----------------------------------'
#define FN1 _______, KC_F7, KC_F8, KC_F9, KC_F12
#define FN2 _______, KC_F4, KC_F5, KC_F6, KC_F11 
#define FN3 _______, KC_F1, KC_F2, KC_F3, KC_F10 

// numpad
// remember to define the location of KC_EQLS and KC_0 on the same layer
// .----------------------------------.
// |   /  |   7  |   8  |   9  |   *  |
// |----------------------------------|
// |   .  |   4  |   5  |   6  |   -  |
// |----------------------------------|
// |   ,  |   1  |   2  |   3  |   +  |
// `----------------------------------'
#define NUM1 KC_SLSH, KC_7, KC_8, KC_9, KC_ASTR
#define NUM2 TD_DOT,  KC_4, KC_5, KC_6, KC_MINS
#define NUM3 TD_COMM, KC_1, KC_2, KC_3, KC_PLUS  

// brackets layer
// backslash and del should probably be on this layer
// .----------------------------------.
// |  *   |  {   |   ^  |   }  |      |
// |----------------------------------|
// |  ?   |  (   |   $  |   )  |      |
// |----------------------------------|
// |  |   |  [   |   #  |   ]  |      |
// '----------------------------------'
#define BRKTS1 KC_ASTR, TD_LCBR, KC_CIRC, KC_RCBR, _______
#define BRKTS2 KC_QUES, TD_LPRN, KC_DLR,  KC_RPRN, _______
#define BRKTS3 KC_PIPE, TD_LBRC, KC_HASH, KC_RBRC, _______

// regex layer
// .----------------------------------.
// |      |  .   |  *   |   ^  |   |  |
// |----------------------------------|
// |      |  ?   |  <   |  %   |   >  |
// |----------------------------------|
// |      |  +   |  @   |   \  |   !  |
// '----------------------------------'
#define REGEX1 _______, KC_TILD, KC_ASTR, KC_AMPR, KC_PIPE
#define REGEX2 _______, KC_QUES, KC_LT,   KC_PERC, KC_GT
#define REGEX3 _______, KC_PLUS, KC_AT,   KC_BSLS, KC_EXLM

// text operations
//
#define TXTOPS1 _______, _______, TMCOPY, TMPASTE, _______
#define TXTOPS2 UNDO,    CUT,     COPY,   PASTE,   _______
#define TXTOPS3 _______, NAK,     EOT,    _______, _______

#define CUSTOM _______, _______, TD_PRIV, TD_SEND, _______


#define BLANK _______, _______, _______, _______, _______
