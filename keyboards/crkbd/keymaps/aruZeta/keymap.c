/*
  Copyright 2019 @foostan
  Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

#define DVORAK 0
#define NUMBERS_N_MOVEMENT 1
#define SYMBOLS 2
#define QMK_KEYS 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
  //                                    `--------------------------'  `--------------------------'
  ),

  [NUMBERS_N_MOVEMENT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_EQL,    KC_9,    KC_6,    KC_3, KC_ASTR,                      KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_0,    KC_8,    KC_5,    KC_2, KC_MINS,                      KC_BTN1, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_SLSH,    KC_7,    KC_4,    KC_1, KC_PLUS,                      KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,     KC_SPC,   MO(3), KC_RGUI
  //                                    `--------------------------'  `--------------------------'
  ),

  [SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, XXXXXXX, KC_BSLS, KC_PIPE, KC_SLSH, XXXXXXX,                      KC_UNDS, XXXXXXX, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_QUES, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_GRV, XXXXXXX, KC_MINS, KC_LBRC, KC_RBRC, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   MO(3),  KC_SPC,    XXXXXXX, _______, XXXXXXX
  //                                    `--------------------------'  `--------------------------'
  ),

  [QMK_KEYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  BL_INC, BL_BRTG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_SPD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  BL_DEC, BL_STEP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
  //                                    `--------------------------'  `--------------------------'
  )
};

const rgblight_segment_t PROGMEM numbers_n_movement_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  6, HSV_PURPLE},
  {27, 6, HSV_PURPLE},
  {6,  1, HSV_PURPLE},
  {33, 1, HSV_PURPLE},
  {13, 2, HSV_PURPLE},
  {40, 2, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM symbols_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  6, HSV_BLUE},
  {27, 6, HSV_BLUE},
  {6,  1, HSV_BLUE},
  {33, 1, HSV_BLUE},
  {13, 2, HSV_BLUE},
  {40, 2, HSV_BLUE}
);

const rgblight_segment_t PROGMEM qmk_keys_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  6, HSV_ORANGE},
  {27, 6, HSV_ORANGE},
  {6,  1, HSV_ORANGE},
  {33, 1, HSV_ORANGE},
  {13, 2, HSV_ORANGE},
  {40, 2, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  numbers_n_movement_rgb,
  symbols_rgb,
  qmk_keys_rgb
);

void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, NUMBERS_N_MOVEMENT));
  rgblight_set_layer_state(1, layer_state_cmp(state, SYMBOLS));
  rgblight_set_layer_state(2, layer_state_cmp(state, QMK_KEYS));
  return state;
}

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();

  switch (keycode) {
  case KC_BSPC:
    {
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool delkey_registered;
      if (record->event.pressed) {
	// Detect the activation of either shift keys
	if (mod_state & MOD_MASK_SHIFT) {
	  // First temporarily canceling both shifts so that
	  // shift isn't applied to the KC_DEL keycode
	  del_mods(MOD_MASK_SHIFT);
	  register_code(KC_DEL);
	  // Update the boolean variable to reflect the status of KC_DEL
	  delkey_registered = true;
	  // Reapplying modifier state so that the held shift key(s)
	  // still work even after having tapped the Backspace/Delete key.
	  set_mods(mod_state);
	  return false;
	}
      } else { // on release of KC_BSPC
	// In case KC_DEL is still being sent even after the release of KC_BSPC
	if (delkey_registered) {
	  unregister_code(KC_DEL);
	  delkey_registered = false;
	  return false;
	}
      }
      // Let QMK process the KC_BSPC keycode as usual outside of shift
      return true;
    }

  case KC_SPC:
    {
      // Initialize a boolean variable that keeps track
      // of the space key status: registered or not?
      static bool tabkey_registered;
      if (record->event.pressed) {
	// Detect the activation of either shift keys
	if (mod_state & MOD_MASK_SHIFT) {
	  // If only one shift is applied, register a normal tabkey
	  // else register a shift+tabkey
	  if ((mod_state & MOD_MASK_SHIFT) != MOD_MASK_SHIFT) {
	    del_mods(MOD_MASK_SHIFT);
	  }
	  register_code(KC_TAB);
	  // Update the boolean variable to reflect the status of KC_TAB
	  tabkey_registered = true;
	  // Reapplying modifier state so that the held shift key(s)
	  // still work even after having tapped the Space/Tab key.
	  set_mods(mod_state);
	  return false;
	}
      } else { // on release of KC_SPC
	// In case KC_TAB is still being sent even after the release of KC_SPC
	if (tabkey_registered) {
	  unregister_code(KC_TAB);
	  tabkey_registered = false;
	  return false;
	}
      }
      // Let QMK process the KC_SPC keycode as usual outside of shift
      return true;
    }

  }
  return true;
};
