#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            KC_MUTE,
            _______, LT(1, KC_S), LT(3, KC_O),
            _______, KC_T,        KC_I,
            _______, KC_R,        KC_Y,
            _______, LT(2, KC_A), LT(4, KC_E)
            ),
    [1] = LAYOUT(
            KC_MUTE,
            _______, _______, _______,
            _______, KC_3,    KC_6,
            _______, KC_2,    KC_5,
            _______, KC_1,    KC_4
            ),
    [2] = LAYOUT(
            KC_MUTE,
            _______, KC_LCBR, KC_RCBR,
            _______, KC_RPRN, KC_RBRC,
            _______, KC_LPRN, KC_LBRC,
            _______, _______, _______
            ),
    [3] = LAYOUT(
            KC_MUTE,
            _______, _______, _______,
            _______, _______, _______,
            _______, _______, _______,
            _______, _______, _______
            ),
    [4] = LAYOUT(
            KC_MUTE,
            _______, KC_TILD,      KC_EQUAL,
            _______, KC_SEMICOLON, KC_MINUS,
            _______, KC_BACKSLASH, KC_QUES,
            _______, KC_EXLM,      _______
            ),
};
