#include QMK_KEYBOARD_H

bool     is_alt_tab_active = false;
uint16_t alt_tab_timer      = 0;

enum custom_keycodes {
    ALT_TAB = QK_KB_0,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) { // This will do most of the grunt work with the keycodes.
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
    }
}

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

#ifdef OLED_ENABLE

#define ORIENTATION OLED_ROTATION_180

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return ORIENTATION;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return ORIENTATION;
}

void render_layer_state(void) {
    oled_write_ln_P(PSTR("artsey.io\n"), false);
}

bool oled_task_user(void) {
    render_layer_state();
    return true;
}

#endif
