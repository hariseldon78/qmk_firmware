/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#define DIODE_DIRECTION COL2ROW

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define MOUSEKEY_WHEEL_TIME_TO_MAX 1
#define MOUSEKEY_WHEEL_MAX_SPEED 3
#define MOUSEKEY_WHEEL_DELAY 3
#define MOUSEKEY_WHEEL_INTERVAL 30
#define MOUSEKEY_DELAY 2
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_TIME_TO_MAX 20
#define MOUSEKEY_MAX_SPEED 16

#define TAPPING_TERM 160
#define IGNORE_MOD_TAP_INTERRUPT 1

#define CAPS_WORD_IDLE_TIMEOUT 5000
#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING
