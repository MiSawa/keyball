/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

enum layers {
    LAYER_WORKMAN,
    LAYER_QWERTY,
    LAYER_LOWER,
    LAYER_UPPER,
    LAYER_MOUSE,
    LAYER_ADJUST,
};

#ifndef _______
#    define _______ KC_TRNS
#endif
#ifndef XXXXXXX
#    define XXXXXXX KC_NO
#endif

#define MO_LOWER MO(LAYER_LOWER)
#define MO_RAISE MO(LAYER_UPPER)
#define MO_ADJ MO(LAYER_ADJUST)
#define MO_MOUSE MO(LAYER_MOUSE)
#define DF_QWERT DF(LAYER_QWERTY)
#define DF_WORK DF(LAYER_WORKMAN)

#define LALTMHEN ALT_T(KC_MHEN)
#define RALTHENK RALT_T(KC_HENK)
#define LCTLHENK LCTL_T(KC_HENK)

#define LCTLDEL LCTL_T(KC_DEL)
#define RCTLBSPC RCTL_T(KC_BSPC)

#define LOWERSPC LT(LAYER_LOWER, KC_SPC)
#define RAISEENT LT(LAYER_RAISE, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_WORKMAN] = LAYOUT_right_ball(
    KC_TAB   , KC_Q     , KC_D     , KC_R     , KC_W     , KC_B     ,                                        KC_J     , KC_F     , KC_U     , KC_P     , KC_SCLN  , KC_BSLS  ,
    KC_LCTL  , KC_A     , KC_S     , KC_H     , KC_T     , KC_G     ,                                        KC_Y     , KC_N     , KC_E     , KC_O     , KC_I     , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_M     , KC_C     , KC_V     ,                                        KC_K     , KC_L     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
                          LALTMHEN , LCTLHENK      , KC_BSPC  , MO_LOWER , KC_SPC   ,                   KC_ENT   , MO_RAISE ,                            MO_MOUSE
  ),

  [LAYER_QWERTY] = LAYOUT_right_ball(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSLS  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
                          LALTMHEN , LCTLHENK      , KC_BSPC  , MO_LOWER , KC_SPC   ,                   KC_ENT   , MO_RAISE ,                            MO_MOUSE
  ),

  [LAYER_LOWER] = LAYOUT_right_ball(
    KC_ESC   , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  ,                                        KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_DEL   ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_GRV   , KC_MINUS , KC_EQL   , KC_LCBR  , KC_RCBR  , KC_GRV   ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_TILD  , KC_UNDS  , KC_PLUS  , KC_LBRC  , KC_RBRC  , KC_TILD  ,
                          _______  , _______       , _______  , _______  , _______  ,                   _______  , _______  ,                            _______
  ),

  [LAYER_UPPER] = LAYOUT_right_ball(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                        KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                        KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_F12   ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , XXXXXXX  , _______  ,
                          _______  , _______       , _______  , _______  , _______  ,                   _______  , _______  ,                            _______
  ),

  [LAYER_MOUSE] = LAYOUT_right_ball(
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , XXXXXXX  , SCRL_MO  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , KC_BTN1  , KC_BTN2  , KC_BTN3  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  ,
                          _______  , _______       , _______  , _______  , _______  ,                   _______  , _______  ,                            _______
  ),

  [LAYER_ADJUST] = LAYOUT_right_ball(
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        DF_WORK  , DF_QWERT , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , SCRL_DVD , SCRL_DVI , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , XXXXXXX  , KBC_SAVE ,
                          RESET    , KBC_RST       , XXXXXXX  , _______  , XXXXXXX  ,                   XXXXXXX  , _______  ,                            XXXXXXX
  ),
};
// clang-format on

layer_state_t layer_state_set_user(const layer_state_t state) {
    return update_tri_layer_state(state, LAYER_LOWER, LAYER_UPPER, LAYER_ADJUST);
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// }

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
