/* Copyright 2015-2021 Jack Humbert
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

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"

#define BMV846_1                    H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), \
                                    H__NOTE(_C6), H__NOTE(_D6), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_C6), H__NOTE(_D6), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), \
                                    H__NOTE(_A5), H__NOTE(_D6), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_A5), H__NOTE(_D6), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), \
                                    H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7),

#define SYM9_4TH                    

#define MY_CAPS_LOCK_ON_SOUND       Q__NOTE(_C5), Q__NOTE(_E5), Q__NOTE(_G5), Q__NOTE(_C6),
#define MY_CAPS_LOCK_OFF_SOUND      Q__NOTE(_C6), Q__NOTE(_G5), Q__NOTE(_E5), Q__NOTE(_C5),
#define MY_SCROLL_LOCK_ON_SOUND     Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_G4), Q__NOTE(_C5),
#define MY_SCROLL_LOCK_OFF_SOUND    Q__NOTE(_C5), Q__NOTE(_G4), Q__NOTE(_E4), Q__NOTE(_C4),
#define MY_NUM_LOCK_ON_SOUND        Q__NOTE(_C6), Q__NOTE(_E6), Q__NOTE(_G6), Q__NOTE(_C7),
#define MY_NUM_LOCK_OFF_SOUND       Q__NOTE(_C7), Q__NOTE(_G6), Q__NOTE(_E6), Q__NOTE(_C6),
float bmv846_1 [][2]       = SONG(BMV846_1);

float tone_caps_on[][2]    = SONG(MY_CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]   = SONG(MY_CAPS_LOCK_OFF_SOUND);
float tone_numlk_on[][2]   = SONG(MY_NUM_LOCK_ON_SOUND);
float tone_numlk_off[][2]  = SONG(MY_NUM_LOCK_OFF_SOUND);
float tone_scroll_on[][2]  = SONG(MY_SCROLL_LOCK_ON_SOUND);
float tone_scroll_off[][2] = SONG(MY_SCROLL_LOCK_OFF_SOUND);

#endif


#if __has_include("password.h")
#  include "password.h"
#endif

#ifndef PASSWORD
#define PASSWORD "Made by ReVanTis"
#endif

#ifndef PINCODE
#define PINCODE "This is a pin code"
#endif


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};


enum planck_keycodes {
  BACKLIT = SAFE_RANGE,
  BACH,
  PASSWD,
  PINCD,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN    MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ,  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   .  |  UP  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | FN   | GUI  | Alt  |Lower |Space |RShift|Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_COMM, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_DOT,  KC_UP,   KC_ENT,
    KC_LCTL, FN,      KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |Pg Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_UP,   KC_LBRC, KC_RBRC, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN , KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   -  |   =  |   \  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |Pg Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_UP,   KC_LCBR, KC_RCBR, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    KC_BTN3, _______, _______, KC_INS , _______, _______, _______, _______, KC_MS_U, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
    _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_MPLY, KC_VOLD, KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RGB_TOG, PASSWD,  PINCD,   BACH,    RGB_MOD, RGB_HUI, RGB_HUD, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______,
    KC_CAPS, QK_BOOT, CK_UP,   AU_TOGG, RGB_RMOD,RGB_SAI, RGB_SAD, KC_P4,   KC_P5,   KC_P6,   _______, _______,
    CK_TOGG, MU_TOGG, MU_NEXT, AU_NEXT, DB_TOGG, RGB_VAI, RGB_VAD, KC_P1,   KC_P2,   KC_P3,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_NUM,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PASSWD:
      if (record -> event.pressed) {}
      else {
          SEND_STRING(PASSWORD);
      }
      break;
    case BACH:
      if (record -> event.pressed) {}
      else {
          PLAY_SONG(bmv846_1);
      }
      break;
    case PINCD:
      if (record -> event.pressed) {}
      else {
          SEND_STRING(PINCODE);
      }
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

#ifdef AUDIO_ENABLE

static led_t old_led_state = {0};
bool led_update_user(led_t led_state)
{
    //wait_ms(10); // gets rid of tick
    //if (!is_playing_notes())
    {
        if ((led_state.caps_lock) && (!old_led_state.caps_lock))
        {
                // If CAPS LK LED is turning on...
                PLAY_SONG(tone_caps_on);
        }
        else if ((!led_state.caps_lock) && (old_led_state.caps_lock))
        {
                // If CAPS LK LED is turning off...
                PLAY_SONG(tone_caps_off);
        }
        else if ((led_state.num_lock) && (!old_led_state.num_lock))
        {
                // If NUM LK LED is turning on...
                PLAY_SONG(tone_numlk_on);
        }
        else if ((!led_state.num_lock) && (old_led_state.num_lock))
        {
                // If NUM LED is turning off...
                PLAY_SONG(tone_numlk_off);
        }
        else if ((led_state.scroll_lock) && (!old_led_state.scroll_lock))
        {
                // If SCROLL LK LED is turning on...
                PLAY_SONG(tone_scroll_on);
        }
        else if ((!led_state.scroll_lock) && (old_led_state.scroll_lock))
        {
                // If SCROLL LED is turning off...
                PLAY_SONG(tone_scroll_off);
        }
    }

    old_led_state = led_state;
    return true;
}

#endif