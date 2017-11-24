#include "split70.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define FN1  1 // Fn layer

#define _______ KC_TRNS

/* Matrix (row:col):
 *
 *    ,----------------------------------------.  ,----------------------------------------.
 *    | 5:0 | 5:1  | 5:2  | 5:3  | 5:4  | 5:5  |  | 5:6  | 5:7  | 5:8  | 5:9  | 5:10 | 5:11|
 * ,--------+------+------+------+------+------|  |------+------+------+------+------+--------.
 * |    4:0 | 4:1  | 4:2  | 4:3  | 4:4  | 4:5  |  | 4:6  | 4:7  | 4:8  | 4:9  | 4:10 | 4:11   |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |    3:0 | 3:1  | 3:2  | 3:3  | 3:4  | 3:5  |  | 3:6  | 3:7  | 3:8  | 3:9  | 3:10 | 3:11   |
 * '--------+------+------+------+------+------|  |------+------+------+------+------+--------'
 *    | 2:0 | 2:1  | 2:2  | 2:3  | 2:4  | 2:5  |  | 2:6  | 2:7  | 2:8  | 2:9  | 2:10 | 2:11|
 *    |-----+------+------+------+------+------'  '------+------+------+------+------+-----|
 *    | 1:0 | 1:1  | 1:2  | 1:3  | 1:4  |                | 1:7  | 1:8  | 1:9  | 1:10 | 1:11|
 *    '---------------------------------'                '---------------------------------'
 *                        ,--------------------.  ,--------------------.
 *                        | 0:5  | 0:4  | 0:3  |  | 0:8  | 0:7  | 0:6  |
 *                        |------|------|      |  |      |------+------|
 *                        |      |      |------|  |------|      |      |
 *                        | 0:2  | 0:1  |      |  |      | 0:10 | 0:9  |
 *                        |      |      | 0:0  |  | 0:11 |      |      |
 *                        '-------------|      |  |      |-------------'
 *                                      '------'  '------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 *    ,----------------------------------------.  ,----------------------------------------.
 *    | `   |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  | F19 |
 * ,--------+------+------+------+------+------|  |------+------+------+------+------+--------.
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |   '    |
 * '--------+------+------+------+------+------|  |------+------+------+------+------+--------'
 *    | F1  |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  | F12 |
 *    |-----+------+------+------+------+------'  '------+------+------+------+------+-----|
 *    | F2  |  F3  |  F4  |  F5  |  F6  |                |  F7  |  F8  |  F9  |  F10 | F11 |
 *    '---------------------------------'                '---------------------------------'
 *                        ,--------------------.  ,--------------------.
 *                        |   -  |   [  | Super|  |Shift |  ]   |  =   |
 *                        |------|------|      |  |      |------+------|
 *                        |      |      |------|  |------|      |      |
 *                        | Ctrl |Shift |      |  |      |Space |Bksp  |
 *                        |      |      |Alt   |  | Enter|      |      |
 *                        '-------------|      |  | /Fn  |-------------'
 *                                      '------'  '------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
// COL: 0         1        2        3        4       5
//ROW:
/*5*/   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
/*4*/   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
/*3*/   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
/*2*/   KC_F1,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
/*1*/   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
/*0*/   KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_LBRC, KC_MINS,
        // right hand
// COL: 6         7        8        9        10       11
//ROW:
/*5*/   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_F19,
/*4*/   KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
/*3*/   KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
/*2*/   KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_F12,
/*1*/             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
/*0*/   KC_EQL,   KC_RBRC, KC_RSFT, KC_BSPC, KC_SPC,  LT(FN1, KC_ENT)
    ),
/* Keymap 1: Fn Layer
 *
 *    ,----------------------------------------.  ,----------------------------------------.
 *    |     |      |      |      |      |      |  |      |      |      |      |      |     |
 * ,--------+------+------+------+------+------|  |------+------+------+------+------+--------.
 * |        |      | MoB1 | MoUp | MoB3 |      |  | INS  | PGUP | PGDN |      |      |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        |      | MoL  | MoDn | MoR  |      |  |  <   |  v   |  ^   |  >   |      |        |
 * '--------+------+------+------+------+------|  |------+------+------+------+------+--------'
 *    | F13 |      |      |      |      |      |  | M1   | M2   | M3   | M4   | M5   | VUp |
 *    |-----+------+------+------+------+------'  '------+------+------+------+------+-----|
 *    | F14 | F15  | F16  | F17  | F18  |                | Prev | Play | Next | Mute | VDn |
 *    '---------------------------------'                '---------------------------------'
 *                        ,--------------------.  ,--------------------.
 *                        |      |      |      |  |      |      |      |
 *                        |------|------|      |  |      |------+------|
 *                        |      |      |------|  |------|      |      |
 *                        |      | Caps |      |  |      |      | Del  |
 *                        |      |      |      |  |      |      |      |
 *                        '-------------|      |  |      |-------------'
 *                                      '------'  '------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[FN1] = KEYMAP(  // layer 1 : Fn
        // left hand
// COL: 0         1        2        3        4        5
//ROW:
/*5*/   _______,  _______, _______, _______, _______, _______,
/*4*/   _______,  _______, KC_BTN1, KC_MS_U, KC_BTN2, _______,
/*3*/   _______,  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
/*2*/   KC_F13,   _______, _______, _______, _______, _______,
/*1*/   KC_F14,   KC_F15,  KC_F16,  KC_F17,  KC_F18,
/*0*/   _______,  _______, _______, _______, _______, _______,
        // right hand
// COL: 6         7        8        9        10       11
//ROW:
/*5*/   _______,  _______, _______, _______, _______, _______,
/*4*/   KC_INS,   KC_PGDN, KC_PGUP, _______, _______, _______,
/*3*/   KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
/*2*/   _______,  _______, _______, _______, _______, KC_VOLU,
/*1*/             KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,
/*0*/   _______,  _______, _______, KC_DEL,  _______, _______
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FN1)                // FN1 - Momentary Layer 1
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    /* if (!record->event.pressed) { */
    /*   switch(id) { */
    /*     case 0: */
		  /* SEND_STRING ("tIs only game. Why you have to be mad?"); */
    /*       return MACRO(T(ENT), END); */
    /*     case 1: */
		  /* SEND_STRING ("tWhat the fuck did you just fucking say about me, you little bitch?"); */
    /*       return MACRO(T(ENT), END); */
		/* case 2: */
		  /* SEND_STRING ("t"); */
    /*       return MACRO(T(ENT), END); */
		/* case 3: */
		  /* SEND_STRING ("t"); */
    /*       return MACRO(T(ENT), END); */
		/* case 4: */
		  /* SEND_STRING ("t"); */
    /*       return MACRO(T(ENT), END); */
    /*   } */
	/* } */
    /* return MACRO_NONE; */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
