/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 F_YUUCHI
Copyright 2023 hariseldon78@gmail.com

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

#pragma once

// wiring of each half
#define MATRIX_ROW_PINS \
    { F4, F6, D7, E6, B4 }
#define MATRIX_COL_PINS \
    { B5, F7, B1, B3, B2, B6 }

#define MATRIX_ROW_PINS_RIGHT \
    { F4, D4, B3, B2, B6 }
#define MATRIX_COL_PINS_RIGHT \
    { B1, C6, D7, E6, B4, B5 }

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLED_NUM 12 // Number of LEDs

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
