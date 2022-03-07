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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
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

  [1] = LAYOUT_split_3x6_3(
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

  [2] = LAYOUT_split_3x6_3(
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

  [3] = LAYOUT_split_3x6_3(
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
      // of the delete key status: registered or not?
      static bool tabkey_registered;
      if (record->event.pressed) {
	// Detect the activation of either shift keys
	if (mod_state & MOD_MASK_SHIFT) {
	  // First temporarily canceling both shifts so that
	  // shift isn't applied to the KC_TAB keycode
	  del_mods(MOD_MASK_SHIFT);
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
