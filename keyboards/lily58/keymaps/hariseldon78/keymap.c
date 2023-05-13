#include QMK_KEYBOARD_H
#include <stdio.h>
#include "caps_word.h"

enum custom_keycodes {
    IN_PAREN = SAFE_RANGE,
    IN_CURLY,
    IN_BRACK,
    IN_ANGLE,
    IN_QOSIN,
    IN_QODOU,
    IN_QOREV,
    ARROW_FU,
    DEL_BSPC,
    NL_INDNT,
};

enum layer_number {
    _BASE   = 0,
    _SYMBOL = 1,
    _ARROWS = 2,
    _FN     = 3,
    _MOUSE  = 4,
    _MACRO  = 5,

};

#define ESC_FN LT(3, KC_ESC)

#define I_CTL LCTL_T(KC_I)
#define E_ALT LALT_T(KC_E)
#define A_SFT LSFT_T(KC_A)

#define S_SFT RSFT_T(KC_S)
#define T_ALT LALT_T(KC_T)
#define N_CTL LCTL_T(KC_N)
#define MOUSE TG(_MOUSE)

#define EQL_GUI LGUI_T(KC_EQL)
#define CLN_MCR LT(_MACRO, KC_COLN)
#define SPC_SYM LT(_SYMBOL, KC_SPC)
#define SCLN_ARR LT(_ARROWS, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BEAKL 15
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Tab  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BckSpc|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   H  |   O  |   U  |   X  |                    |   G  |   C  |   R  |   F  |   Z  |BckSpc|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |ESC_FN|   Y  | I+ctl| E+alt|A+shft|  '"  |-------.    ,-------|   D  |S+shft|T+alt |N+ctl |   B  |Enter |
     * |------+------+------+------+------+------|ScrlLck|    |ScrlLck|------+------+------+------+------+------|
     * |MOUSE |   J  |  /?  |   .  |   ,  |   K  |-------|    |-------|   W  |   M  |   L  |   P  |   V  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |  -   | /   =   /       \  :   \  |Space |  ;   |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_BASE] = LAYOUT(

        KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, /*-----------------------------*/ KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,

        KC_TAB, KC_Q, KC_H, KC_O, KC_U, KC_X, /*-----------------------------*/ KC_G, KC_C, KC_R, KC_F, KC_Z, KC_BSPC,

        ESC_FN, KC_Y, I_CTL, E_ALT, A_SFT, KC_QUOT, /*-----------------------*/ KC_D, S_SFT, T_ALT, N_CTL, KC_B, KC_ENT,

        MOUSE, KC_J, KC_SLSH, KC_DOT, KC_COMM, KC_K, KC_SCRL, /*----*/ KC_SCRL, KC_W, KC_M, KC_L, KC_P, KC_V, KC_SPC,

        /*-------------*/ KC_SPC, KC_LEAD, KC_MINS, EQL_GUI, /*----*/ CLN_MCR, SPC_SYM, SCLN_ARR, KC_SPC),

    [_SYMBOL] = LAYOUT(

        /*---------------------*/ _______, _______, _______, _______, _______, _______, /*--------------------------------*/ _______, _______, _______, _______, _______, KC_DEL,

        /*---------------------*/ _______, _______, _______, _______, _______, _______, /*--------------------------------*/ _______, _______, _______, _______, _______, KC_DEL,

        LCTL(KC_G), KC_HASH, LCTL_T(KC_LPRN), LALT_T(KC_RPRN), LSFT_T(KC_AT), KC_PLUS, /*---------------------------------*/ KC_TILD, RSFT_T(KC_DLR), LALT_T(KC_LCBR), LCTL_T(KC_RCBR), KC_AMPR, _______,

        /*---------------------*/ _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR, KC_GRV, _______, /*---------------*/ _______, KC_UNDS, KC_EXLM, KC_LT, KC_GT, KC_BSLS, _______,

        /*-----------------------------------------------*/ _______, _______, _______, _______, /*---------------*/ _______, _______, _______, _______, ),

    [_ARROWS] = LAYOUT(

        /*--*/ _______, _______, _______, _______, _______, _______, /*-------------------------------------*/ _______, _______, _______, _______, _______, KC_DEL,

        /*--*/ _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*---------------------------------------*/ KC_SCRL, KC_INS, KC_UP, XXXXXXX, KC_PGUP, KC_DEL,

        /*--*/ _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, /*--------------------------------------*/ KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,

        /*--*/ _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*---------------------*/ XXXXXXX, KC_PSCR, KC_HOME, XXXXXXX, KC_END, XXXXXXX, _______,

        /*----------------------------*/ _______, _______, _______, _______, /*---------------------*/ _______, _______, _______, _______, ),

    [_FN] = LAYOUT(

        /*--*/ _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*--------------------------------------------------*/ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL,

        /*--*/ _______, KC_F11, LCTL_T(KC_F12), KC_LALT, KC_LSFT, XXXXXXX, /*--------------------------------*/ XXXXXXX, KC_RSFT, KC_LALT, KC_LCTL, KC_DEL,

        /*--*/ _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, /*--------------------------------------*/ KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,

        /*--*/ _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*--------------------*/ XXXXXXX, KC_PSCR, KC_HOME, XXXXXXX, KC_END, XXXXXXX, _______,

        /*----------------------------*/ _______, _______, _______, _______, /*---------------------*/ _______, _______, _______, _______, ),

    [_MOUSE] = LAYOUT(

        /*---*/ LCTL(KC_TAB), RCS(KC_TAB), _______, _______, _______, _______, /*-----------------------------*/ _______, _______, _______, _______, _______, KC_DEL,

        /*---*/ LCTL(KC_TAB), RCS(KC_TAB), KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, /*-----------------------------*/ XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, KC_PGUP, KC_DEL,

        /*------------*/ _______, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, /*-----------------------------*/ XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,

        /*------------*/ _______, KC_BTN5, KC_LEFT, KC_BTN3, KC_RGHT, LCTL(KC_W), _______, /*--------*/ _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

        /*--------------------------------------*/ _______, _______, _______, _______, /*---------------------*/ _______, _______, _______, _______, ),

    [_MACRO] = LAYOUT(

        /*--------*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*----------------------------*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEL_BSPC,

        /*--------*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*----------------------------*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEL_BSPC,

        /*--------*/ XXXXXXX, XXXXXXX, IN_PAREN, IN_PAREN, IN_QODOU, IN_QOSIN, /*------------------------*/ XXXXXXX, XXXXXXX, IN_CURLY, IN_CURLY, XXXXXXX, NL_INDNT,

        /*--------*/ XXXXXXX, XXXXXXX, IN_BRACK, IN_BRACK, XXXXXXX, IN_QOREV, _______, /*-------*/ _______, XXXXXXX, XXXXXXX, IN_ANGLE, IN_ANGLE, XXXXXXX, XXXXXXX,

        /*--------------------------------------*/ _______, _______, _______, _______, /*-------*/ _______, _______, _______, _______, )};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }
    return rotation;
}

#    define L_BASE 0
#    define L_NUM_SYMBOLS 2
#    define L_NAVIGATION 4
#    define L_FUNCTIONS 8
#    define L_MOUSE 16
#    define L_MACRO 32

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("-------"), false);
            break;
        case L_NUM_SYMBOLS:
            oled_write_ln_P(PSTR("<+*{(["), false);
            break;
        case L_NAVIGATION:
            oled_write_ln_P(PSTR("<-  ->"), false);
            break;
        case L_FUNCTIONS:
            oled_write_ln_P(PSTR("F1 F2 F3"), false);
            break;
        case L_MOUSE:
            oled_write_ln_P(PSTR("MOUSE"), false);
            break;
        case L_MACRO:
            oled_write_ln_P(PSTR("{()=>[]}"), false);
            break;
            /* case L_ADJUST: */
            /* case L_ADJUST|L_LOWER: */
            /* case L_ADJUST|L_RAISE: */
            /* case L_ADJUST|L_LOWER|L_RAISE: */
            /*     oled_write_ln_P(PSTR("Adjust"), false); */
            /*     break; */
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

/* void set_keylog(uint16_t keycode, keyrecord_t *record) { */
/*     char name = ' '; */
/*     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { */
/*         keycode = keycode & 0xFF; */
/*     } */
/*     if (keycode < 60) { */
/*         name = code_to_name[keycode]; */
/*     } */

/*     // update keylog */
/*     snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name); */
/* } */

/* void oled_render_keylog(void) { oled_write(keylog_str, false); } */

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

/* void oled_render_logo(void) { */
/*     static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0}; */
/*     oled_write_P(crkbd_logo, false); */
/* } */
void oled_render_logo(void) {
    // chess horse
    /* static const char PROGMEM raw_logo[] = { */
    /*     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  128, 128, 128, 192, 64, 64, 64, 192, 192, 128, 128, 128, 128, 0,  0,  0,  0,  0,   0,   0,   0,   0,   128, 64, 224, 32, 32, 32, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 120, 14, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 2, 2, 3, 1, 1, 255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, */
    /*     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 63, 16, 16, 16, 48,  96,  192, 136, 0,  0,  0,  0,   24,  248, 136, 24,  24,  16, 48, 32, 96, 192, 128, 128, 128, 255, 0,   0,  255, 0,  0,  0,  255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0, 0, 0, 0, 1, 3, 6, 4, 6, 6, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   1, 2, 7,   4, 4, 4, 7,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, */
    /* }; */
    // chess unicorn
    static const char PROGMEM raw_logo[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0,  0,  128, 128, 128, 192, 64, 64, 64, 192, 192, 128, 128, 128, 128, 0,  0,  0,  0,  0,   0,   0,   0,   0,   128, 64, 224, 32, 32, 32, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 120, 14, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 2, 2, 3, 1, 1, 255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 96, 48, 56, 20, 19, 8, 16, 16, 48,  96,  192, 136, 0,  0,  0,  0,   24,  248, 136, 24,  24,  16, 48, 32, 96, 192, 128, 128, 128, 255, 0,   0,  255, 0,  0,  0,  255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0, 0, 0, 0, 1, 3, 6, 4, 6, 6, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   1, 2, 7,   4, 4, 4, 7,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        /* oled_render_keylog(); */
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE
LEADER_EXTERNS();

void matrix_scan_user() {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_B) {
            SEND_STRING(SS_LCTL("b"));
        }
    }
    caps_word_task();
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) {
        return false;
    }
    /* #ifdef OLED_ENABLE */
    /*     if (record->event.pressed) { */
    /*         set_keylog(keycode, record); */
    /*     } */
    /* #endif  // OLED_ENABLE */
    if (record->event.pressed) {
        switch (keycode) {
            case IN_PAREN:
                SEND_STRING("()");
                tap_code16(KC_LEFT);
                return false;
            case IN_CURLY:
                SEND_STRING("{}");
                tap_code16(KC_LEFT);
                return false;
            case IN_BRACK:
                SEND_STRING("[]");
                tap_code16(KC_LEFT);
                return false;
            case IN_ANGLE:
                SEND_STRING("<>");
                tap_code16(KC_LEFT);
                return false;
            case ARROW_FU:
                SEND_STRING("=>");
                return false;
            case IN_QOSIN:
                SEND_STRING("''");
                tap_code16(KC_LEFT);
                return false;
            case IN_QODOU:
                SEND_STRING("\"\"");
                tap_code16(KC_LEFT);
                return false;
            case IN_QOREV:
                SEND_STRING("``");
                tap_code16(KC_LEFT);
                return false;
            case DEL_BSPC:
                tap_code16(KC_DEL);
                tap_code16(KC_BSPC);
                return false;
            case NL_INDNT:
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_UP);
                tap_code16(KC_TAB);
                return false;

            case LT(5, KC_COLN):
                if (record->tap.count) {
                    tap_code16(KC_COLN);
                    return false;
                }
                break;
            case RSFT_T(KC_DLR):
                if (record->tap.count) {
                    tap_code16(KC_DLR);
                    return false;
                }
                break;
            case LSFT_T(KC_AT):
                if (record->tap.count) {
                    tap_code16(KC_AT);
                    return false;
                }
                break;
            case LCTL_T(KC_LPRN):
                if (record->tap.count) {
                    tap_code16(KC_LPRN);
                    return false;
                }
                break;
            case LALT_T(KC_RPRN):
                if (record->tap.count) {
                    tap_code16(KC_RPRN);
                    return false;
                }
                break;
            case LCTL_T(KC_RCBR):
                if (record->tap.count) {
                    tap_code16(KC_RCBR);
                    return false;
                }
                break;

            case LALT_T(KC_LCBR):
                if (record->tap.count) {
                    tap_code16(KC_LCBR);
                    return false;
                }
                break;
        }
    }
    return true;
}

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

/* // SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk */
/* #ifdef OLED_ENABLE */

/* oled_rotation_t oled_init_user(oled_rotation_t rotation) { */
/*     if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand */
/*     return rotation; */
/* } */

/* // When you add source files to SRC in rules.mk, you can use functions. */
/* const char *read_layer_state(void); */
/* const char *read_logo(void); */
/* void        set_keylog(uint16_t keycode, keyrecord_t *record); */
/* const char *read_keylog(void); */
/* const char *read_keylogs(void); */

/* // const char *read_mode_icon(bool swap); */
/* // const char *read_host_led_state(void); */
/* // void set_timelog(void); */
/* // const char *read_timelog(void); */

/* bool oled_task_user(void) { */
/*     if (is_keyboard_master()) { */
/*         // If you want to change the display of OLED, you need to change here */
/*         oled_write_ln(read_layer_state(), false); */
/*         oled_write_ln(read_keylog(), false); */
/*         oled_write_ln(read_keylogs(), false); */
/*         // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false); */
/*         // oled_write_ln(read_host_led_state(), false); */
/*         // oled_write_ln(read_timelog(), false); */
/*     } else { */
/*         oled_write(read_logo(), false); */
/*     } */
/*     return false; */
/* } */
/* #endif // OLED_ENABLE */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     if (record->event.pressed) { */
/* #ifdef OLED_ENABLE */
/*         set_keylog(keycode, record); */
/* #endif */
/*         // set_timelog(); */
/*     } */
/*     return true; */
/* } */
