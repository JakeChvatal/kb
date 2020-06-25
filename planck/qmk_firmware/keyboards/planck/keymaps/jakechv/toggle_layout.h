  // ......................................................... Number Keypad Layer
  // .-----------------------------------------------------------------------------------.  
  // |      |   F  |   E  |   D  |      |      |      |   /  |   7  |   8  |   9  |   *  |
  // |-----------------------------------------------------------------------------------|
  // | Ctrl |   C  |   B  |   A  |      |      |      |   .  |   4  |   5  |   6  |   -  |
  // |-----------------------------------------------------------------------------------|
  // |      |   #  |   G  |   \  |      |      |      |   ,  |   1  |   2  |   3  |   +  |
  // |-----------------------------------------------------------------------------------|
  // |                           |  f() | Space|   0  |   =  |                           |
  // '-----------------------------------------------------------------------------------'
  [_TTNUMBER] = LAYOUT_planck_grid_wrapper(
    ___x___, _______, KC_F,    MT_E,    KC_D,    _______, ______________________NUM1________________, ___x___,  
    ___x___, _______, GT_C,    AT_B,    ST_A,    _______, ______________________NUM2________________, ___x___,  
    ___x___, _______, KC_HASH, SM_G,    KC_BSLS, _______, ______________________NUM3________________, ___x___,  
    _______, _______, _______, _______, TT_ESC,  KC_SPC,  KC_0,   TD_EQL,  _______, _______, _______, _______
    // _______, _______, _______, _______, TT_ESC,  KC_SPC,  KC_EQL,  LT_0,    _______, _______, _______, _______
  ),

  // ............ .................................................. Function Keys
  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |      |  F7  |  F8  |  F9  |  F12 |
  // |-----------------------------------------------------------------------------------|
  // | Ctrl |  GUI |  Alt | Shift|      |      |      |      |  F4  |  F5  |  F6  |  F11 |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F10 |
  // |-----------------------------------------------------------------------------------|
  // |                           |  f() |      |   +  |      |                           |
  // '-----------------------------------------------------------------------------------'
  [_TTFNCKEY] = LAYOUT_planck_grid_wrapper(
   ___x___, _______, _______, _______, _______, _______,  _______, _______________FN1________________, ___x___,         
   ___x___, _____________MODKEYS______________, _______,  _______, _______________FN2________________, ___x___,         
   ___x___, _______, _______, _______, _______, _______,  _______, _______________FN3________________, ___x___,         
   _______, _______, _______, _______, _______, TT_ESC,   _______, _______, _______, _______, _______,  KC_PLUS
  ),

  // ....................................................................... Regex
  // ,-----------------------------------------------------------------------------------.
  // |      |   ~  |   {  |   }  |   &  |      |      |   %  |   [  |   ]  |   @  |      |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |      |   ^  |   <  |   >  |   ?  |      |      |   |  |   (  |   )  |   $  |      |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |      |   :  |   !  |   =  |   /  |      |      |   \  |   *  |   .  |   #  |      |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           |  f() |   -  |   +  | Space|                           |
  // `-----------------------------------------------------------------------------------'
  [_TTREGEX] = LAYOUT_planck_grid(
   ___x___,  ___x___, KC_TILD, KC_LCBR, KC_RCBR, KC_AMPR,  KC_PERC, KC_LBRC, KC_RBRC, KC_AT,   ___x___, ___x___,
   ___x___,  ___x___, KC_CIRC, KC_LT,   KC_GT,   KC_QUES,  KC_PIPE, KC_LPRN, KC_RPRN, KC_DLR,  ___x___, ___x___,
   ___x___,  ___x___, KC_COLN, KC_EXLM, KC_EQL,  KC_SLSH,  KC_BSLS, KC_ASTR, KC_DOT,  KC_HASH, ___x___, ___x___,
   KC_MINS,  _______, _______, _______, _______, TT_ESC,   KC_SPC,  _______, _______, _______, _______, KC_PLUS
  ),

  // ............................................................ Navigation Layer
  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |      | Home |  Up  |  End | PgUp |
  // |-----------------------------------------------------------------------------------|
  // | Ctrl |  GUI |  Alt | Shift|      |      |      |      | Left | Down | Right| PgDn |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |                           |  f() |      |      |      |                           |
  // '-----------------------------------------------------------------------------------'
  [_TTCURSOR] = LAYOUT_planck_grid_wrapper(
    ___x___, _______, _______, _______, _______, _______, __________________NAV1_____________________, ___x___,   
    ___x___, _____________MODKEYS______________,  _______, __________________NAV2_____________________, ___x___,   
    ___x___, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___x___,   
    _______, _______, _______, _______, _______, TT_ESC,  _______, _______, _______, _______, _______, _______   
  ),

  // ............................................................... Mouse Actions
  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |      | Left |  Up  | Right|  Up  |
  // |-----------------------------------------------------------------------------------|
  // |      | Btn3 | Btn2 | Btn1 |      |      |      |      | Left | Down | Right| Down |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |                           |  f() |      |      |      |                           |
  // '-----------------------------------------------------------------------------------' 
  [_TTMOUSE] = LAYOUT_planck_grid_wrapper(
   ___x___, _______, ______________MOUSE1______________, _______, _______, _______, _______, _______, ___x___, 
   ___x___, _______, ______________MOUSE2______________, _______, _________MOUSECLK________, _______, ___x___, 
   ___x___, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___x___, 
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TT_ESC,  _______ 
  ),
