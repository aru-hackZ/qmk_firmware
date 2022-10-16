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

#pragma once

#define EE_HANDS

#ifdef RGBLIGHT_ENABLE
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL

#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_DEFAULT_HUE 100
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 255
#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5
#endif

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
