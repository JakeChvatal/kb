#pragma once
// --- keycode macro groups
// inspired by https://github.com/noahfrederick/qmk-keymaps/blob/master/user/my.h
// --- convenience
// .--------------------.
// | Mute |VolDwn|VolUp |
// `--------------------'
#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU

// .--------------------.
// |MPrev |MPlay |MNext |
// `--------------------'
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT

// navigation
#define __________________NAV1_____________________ KC_PGUP, _______, KC_HOME, KC_UP, KC_END
#define __________________NAV2_____________________ KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT

// mouse
// .----------------------------------.
// |      |ScrlL |  ^   |ScrlR |ScrlUp|
// |----------------------------------|
// |      |  <-  |  ;   |  ->  |ScrlDw|
// |----------------------------------|
// |      |      |      |      |      |
// '----------------------------------'
#define ______________MOUSE1______________ KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define ______________MOUSE2______________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define ______________MOUSE3______________ _______, _______, _______, _______

// .--------------------.
// | LClk | CClk | RClk |
// `--------------------'
#define _________MOUSECLK________ KC_BTN1, KC_BTN3, KC_BTN2 

// modifiers
// .---------------------------.
// | Ctrl |  GUI |  Alt | Shift|
// `---------------------------'
#define _____________MODKEYS______________ OS_GUI, OS_CTL, OS_ALT, OS_SFT

// function keys
// .---------------------------.
// |  F7  |  F8  |  F9  |  F12 |
// |---------------------------|
// |  F4  |  F5  |  F6  |  F11 |
// |---------------------------|
// |  F1  |  F2  |  F3  |  F10 |
// '---------------------------'
#define _______________FN1________________ KC_F7, KC_F8, KC_F9, KC_F12
#define _______________FN2________________ KC_F4, KC_F5, KC_F6, KC_F11 
#define _______________FN3________________ KC_F1, KC_F2, KC_F3, KC_F10 

// numpad
// remember to define the location of KC_EQLS and KC_0 on the same layer
// .----------------------------------.
// |   /  |   7  |   8  |   9  |   *  |
// |----------------------------------|
// |   .  |   4  |   5  |   6  |   -  |
// |----------------------------------|
// |   ,  |   1  |   2  |   3  |   +  |
// `----------------------------------'
#define ______________________NUM1________________ KC_SLSH, KC_7, KC_8, KC_9, KC_ASTR
#define ______________________NUM2________________ TD_DOT,  KC_4, KC_5, KC_6, KC_MINS
#define ______________________NUM3________________ TD_COMM, KC_1, KC_2, KC_3, KC_PLUS  

// brackets layer
// backslash and del should probably be on this layer
// .----------------------------------.
// |  *   |  {   |   ^  |   }  |      |
// |----------------------------------|
// |  ?   |  (   |   $  |   )  |      |
// |----------------------------------|
// |  |   |  [   |   #  |   ]  |      |
// '----------------------------------'
#define ____________BRACKETS1_____________ KC_ASTR, TD_LCBR, KC_CIRC, KC_RCBR
#define ____________BRACKETS2_____________ KC_QUES, TD_LPRN, KC_DLR,  KC_RPRN
#define ____________BRACKETS3_____________ KC_PIPE, TD_LBRC, KC_HASH, KC_RBRC

// regex layer
// .----------------------------------.
// |      |  .   |  *   |   ^  |   |  |
// |----------------------------------|
// |      |  ?   |  <   |  %   |   >  |
// |----------------------------------|
// |      |  +   |  @   |   \  |   !  |
// '----------------------------------'
#define ______________REGEX1______________ KC_TILD, KC_ASTR, KC_AMPR, KC_PIPE
#define ______________REGEX2______________ KC_QUES, KC_LT,   KC_PERC, KC_GT
#define ______________REGEX3______________ KC_PLUS, KC_AT,   KC_BSLS, KC_EXLM

// text operations
#define ______________TEXTOPS_____________ UNDO,CUT,COPY,PASTE 
