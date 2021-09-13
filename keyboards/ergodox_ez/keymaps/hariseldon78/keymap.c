#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
};

// CAUTION: FOR SOME REASON CAPSLOCK AND LCTRL *KEYCODES* GOT SWAPPED
// SAME THING FOR ESCAPE AND GRAVE-TILDE. USE THE NEXT DEFINES TO FIX IT

#define REAL_ESCAPE   KC_GRAVE
#define REAL_GRAVE    KC_ESCAPE
#define REAL_CAPSLOCK KC_LCTRL
#define REAL_LCTRL KC_CAPSLOCK
#define NOTHING KC_TRANSPARENT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    REAL_ESCAPE,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                             KC_PSCREEN,     KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_BSLASH,                                        REAL_GRAVE,     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_SLASH,
    REAL_ESCAPE,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                             KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_ENTER,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_SCROLLLOCK,                                    KC_QUOTE,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_MINUS,       KC_RSHIFT,
    REAL_LCTRL,     MO(2),          MO(1),          KC_LALT,        KC_SPACE,                                                                                                         MO(1),          MO(2),          KC_LBRACKET,    KC_EQUAL,       KC_RBRACKET,
                                                                                                    RALT_T(KC_ENTER),KC_BSPACE,       NOTHING       , KC_INSERT,
                                                                                                                     MO(3),           RGUI(0),
                                                                                    LGUI(0),        TT(1),           REAL_CAPSLOCK,   KC_RALT,        KC_DELETE,      KC_SPACE
  ),
  // mouse
  [1] = LAYOUT_ergodox_pretty(
    TG(4)         , KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,             NOTHING       ,                                 NOTHING       , KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_DELETE,
    TO(0)         , KC_MS_BTN2    , KC_MS_UP      , KC_MS_BTN1    , NOTHING       , KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,                                TO(0),          KC_F11,         NOTHING       , NOTHING       , KC_LBRACKET,    KC_RBRACKET,    NOTHING       ,
    NOTHING       , KC_MS_LEFT    , KC_MS_DOWN    , KC_MS_RIGHT   , KC_MS_WH_UP   , KC_MS_BTN4,                                                                        KC_F12,         NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
    NOTHING       , KC_HOME       , KC_MS_BTN3    , KC_END        , KC_MS_WH_DOWN , KC_MS_BTN5,        MO(3),                                          KC_GRAVE,       NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                                                                                    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
                                                                                                       NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
                                                                                                                       NOTHING       , NOTHING       ,
                                                                                    NOTHING       ,    TO(2),          MO(3),          NOTHING       , NOTHING       , KC_HOME
  ),
  // arrows
  [2] = LAYOUT_ergodox_pretty(
    NOTHING       , KC_F1         , KC_F2         , KC_F3         , KC_F4         , KC_F5         , NOTHING       ,                                 NOTHING       , KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_DELETE,
    TO(0)         , NOTHING       , KC_UP         , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                 TO(0),          KC_F11,         NOTHING       , KC_UP,          NOTHING       , NOTHING       , KC_INSERT,
    NOTHING       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_PGUP       , NOTHING       ,                                                                 KC_F12,         KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGUP,        NOTHING       ,
    NOTHING       , KC_HOME       , NOTHING       , KC_END        , KC_PGDOWN     , NOTHING       , NOTHING       ,                                 NOTHING       , NOTHING       , KC_HOME,        NOTHING       , KC_END,         KC_PGDOWN,      NOTHING       ,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                                                                                 NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
                                                                                                    NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
                                                                                                                    NOTHING       , NOTHING       ,
                                                                                    NOTHING       , TO(0),          NOTHING       , NOTHING       , NOTHING       , NOTHING
  ),
  [3] = LAYOUT_ergodox_pretty(
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,    NOTHING       ,                                 NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
    TO(0),          NOTHING       , NOTHING       , NOTHING       , NOTHING       , KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,                                TO(0),          NOTHING       , KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, NOTHING       ,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , KC_AUDIO_MUTE ,                                                                    NOTHING       , KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_KP_ENTER,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,    NOTHING       ,                                 KC_NUMLOCK,     NOTHING       , KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_MINUS,    NOTHING       ,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                                                                                    KC_KP_0,        KC_KP_DOT,      KC_NUMLOCK,     KC_KP_SLASH,    NOTHING       ,
                                                                                                    NOTHING       , TO(0),          NOTHING       , NOTHING       ,
                                                                                                                    NOTHING       , NOTHING       ,
                                                                                    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING
  ),
  [4] = LAYOUT_ergodox_pretty(
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                 NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                 NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                                                 NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,                                 NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
    KC_LGUI,        KC_LCTRL,       NOTHING       , NOTHING       , NOTHING       ,                                                                                                 NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
                                                                                                    NOTHING       , NOTHING       , NOTHING       , NOTHING       ,
                                                                                                                    NOTHING       , NOTHING       ,
                                                                                    NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING       , NOTHING
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
