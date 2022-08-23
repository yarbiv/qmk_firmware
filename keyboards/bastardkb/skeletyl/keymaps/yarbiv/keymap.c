/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "yarbiv.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_split_3x5_3(
//	  		-------------------------------------------------			-------------------------------------------------
        	TD(QC_Q), KC_W,     KC_F,     KC_P,     KC_B,               KC_J,     KC_L,     KC_U,     KC_Y,    KC_QUOT,
//	  		-------------------------------------------------			-------------------------------------------------
            KC_A,     KC_R,     KC_S,     KC_T,     KC_G,               KC_M,     KC_N,     KC_E,     KC_I,    KC_O,
//	  		-------------------------------------------------			-------------------------------------------------
            QC_Z,     QC_X,     QC_C,     KC_D,     KC_V,               KC_K,     KC_H,     QC_COMM,  QC_DOT,  QC_SLSH,
//	  		-------------------------------------------------			-------------------------------------------------
            					TD(OSFT), KC_BSPC,  TD(SWAP),            QC_ENT,   QC_SPC, QC_TAB  
//	  							-----------------------------			-----------------------------
  ),

  [_NUMVIGATION] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QC_CUT,  QC_CPY,  KC_UP,   QC_PAS,  QC_UNDO,                      KC_SLSH, KC_7,    KC_8,    KC_9,   KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QC_LWRD, KC_LEFT, KC_DOWN, KC_RIGHT,QC_RWRD,                      KC_0,    KC_4,    KC_5,    KC_6,   KC_DOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QC_MOD3, QC_MOD2, QC_MOD1, QC_SAVE, QC_REDO,                      KC_MINS, KC_1,    KC_2,    KC_3,   KC_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_SPC,  _______,     MO(3), KC_ENT, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,   KC_LBRC,  KC_RBRC,  KC_TILD,  KC_AT,                    KC_CIRC,  KC_UDIR,  KC_LABK,  KC_RABK,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_COLN,  KC_LPRN,  KC_RPRN,  KC_EXLM,  KC_SCLN,                  KC_GOEQ,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DLR,   KC_PERC,  KC_HASH,  KC_QUES,  KC_AMPR,                  KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_MINS,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_SPC,  MO(3),     _______, KC_ENT, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,  QC_LOCK,                        KC_VOLU, EMAIL,   PHONE,   CLOSE,   TASKMAN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F5,   KC_F6,   KC_F7,   KC_F8,  QC_OS,                        KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F9,   KC_F10,  KC_F11,  KC_F12, QC_POS,                        KC_MUTE, QC_PRNT, QC_MOD1, QC_MOD2, QC_MOD3,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_SPC, _______,     KC_ENT, KC_SPC, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	if (!process_os_print(keycode, record, QC_POS)) { return false; }

	return true;
}