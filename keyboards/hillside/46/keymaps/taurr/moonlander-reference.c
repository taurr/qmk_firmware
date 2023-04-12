/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"
#include "sendstring_danish.h"
#include "autocorrect_data.h"
#include "action_util.h"

//float esc_song[][2] = SONG(TERMINAL_SOUND);
float colemak_song[][2] = SONG(AG_NORM_SOUND);
float macro_record_start_song[][2] = SONG(PLOVER_SOUND);
float macro_record_stop_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
float macro_record_key_song[][2] = SONG(TERMINAL_SOUND);
float kvm_sw1[][2] = SONG(ODE_TO_JOY);
float kvm_sw2[][2] = SONG(ROCK_A_BYE_BABY);
float lock_song[][2] = SONG(NUM_LOCK_ON_SOUND);
float unlock_song[][2] = SONG(NUM_LOCK_OFF_SOUND);
float layer_song[][2] = SONG(TERMINAL_SOUND);

enum layers {
    COLE,
    NUMB,   // numberpad/Fx
    NAVI,   // navigation
    VSCODE, // vscode shortcuts
    MOUSE,  // mouse navigation
    SYMB,   // symbols
    UTIL,   // utility/media
    NEW,
};

// Tap Dance declarations
enum {
    TD_LT4,
    TD_RT4,
    TD_DELETE,
    TD_BACKSPACE,
    TD_LT3,
    TD_RT3,
    TD_LT1,
    TD_RT1,
    TD_LT2,
    TD_RT2,
    TD_DOT_COMM,
    TD_F1, TD_F2, TD_F3, TD_F4, TD_F5, TD_F6, TD_F7, TD_F8, TD_F9,
    TD_F10, TD_F11, TD_F12, TD_F14, TD_F15, TD_F16,
    TD_PAU_INS,
    TD_BACK_META,
    TD_REFERENCE,
    TD_NEXT_REF,
    TD_PREV_REF,
    TD_FOLD,
    TD_SYMB_HALF,
    TD_SYMB_SLASH,
    TD_SYMB_BACKTICK,
    TD_KVM_SWITCH,
    TD_AUDIO_PLAY,
    TD_PRINTSCREEN,
    TD_VSCODE_UP,
    TD_VSCODE_DOWN,
    TD_VSCODE_LEFT,
    TD_VSCODE_RIGHT,
    TD_VSCODE_TERMINAL,
    TD_VSCODE_BREAD,
    TD_NAVI_RT2,
    TD_NAVI_VSCODE,
    TD_NAVI_MOUSE,
    TD_NAVI_COPY,
    TD_NAVI_CUT,
    TD_NAVI_PASTE,
    TD_NAVI_DELETE,
    TD_NAVI_BACKSPACE,
    TD_NAVI_UNDO,
    TD_RGUI,
    TD_LGUI,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

#define UK_LT1 TD(TD_LT1)
#define UK_RT1 TD(TD_RT1)
//#define UK_LT2 TD(TD_LT2)
#define UK_RT2 TD(TD_RT2)
#define UK_LT3 TD(TD_LT3)
#define UK_RT3 TD(TD_RT3)
#define UK_LT4 TD(TD_LT4)
#define UK_RT4 TD(TD_RT4)

#define UK_PRN TD(TD_PRINTSCREEN)
#define UK_DEL TD(TD_DELETE)
#define UK_BSPC TD(TD_BACKSPACE)
#define UK_RGUI TD(TD_RGUI)
#define UK_LGUI TD(TD_LGUI)

//
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [COLE] = LAYOUT_moonlander(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        UK_DEL , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_NO  ,         KC_NO  , KC_J   , KC_L   , KC_U   , KC_Y   , DK_ARNG, UK_BSPC,
        KC_NO  , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_NO  ,         KC_NO  , KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , DK_OSTR,
        UK_LGUI, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                           KC_K   , KC_H   , KC_COMM, KC_DOT , DK_AE  , UK_RGUI,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , UK_LT1,          UK_LT4,         UK_RT4,          UK_RT1, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                            KC_SPC , UK_LT3, KC_NO  ,         KC_NO  , UK_RT3 , UK_RT2
    ),

#define NUM_DOT TD(TD_DOT_COMM)

    [NUMB] = LAYOUT_moonlander(
        KC_NO  ,   KC_NO   ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO   , KC_NO  ,        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        UK_DEL , TD(TD_F16), TD(TD_F7), TD(TD_F8), TD(TD_F9), TD(TD_F15), KC_NO  ,        KC_NO  , KC_SCRL, KC_7   , KC_8   , KC_9   , KC_NO  , UK_BSPC,
        KC_NO  , TD(TD_F10), TD(TD_F4), TD(TD_F5), TD(TD_F6), TD(TD_F12), KC_NO  ,        KC_NO  , KC_0   , KC_4   , KC_5   , KC_6   , KC_0   , KC_NO  ,
        UK_LGUI, TD(TD_F11), TD(TD_F1), TD(TD_F2), TD(TD_F3), TD(TD_F14),                          KC_NO  , KC_1   , KC_2   , KC_3   , NUM_DOT, UK_RGUI,
        KC_NO  ,   KC_NO   ,   KC_NO  ,   KC_NO  , UK_LT1  ,             UK_LT4,        UK_RT4,          UK_RT1, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                                   KC_SPC   , UK_LT3   , KC_NO  ,        KC_NO  , UK_RT3 , UK_RT2
    ),

#define NAV_BCK TD(TD_BACK_META)
#define NAV_BRF TD(TD_PREV_REF)
#define NAV_FRF TD(TD_NEXT_REF)
#define NAV_FLD TD(TD_FOLD)
#define NAV_REF TD(TD_REFERENCE)
#define NAV_PAU TD(TD_PAU_INS)
#define NAV_COD TD(TD_NAVI_VSCODE)
#define NAV_MOU TD(TD_NAVI_MOUSE)
#define NAV_RT2 TD(TD_NAVI_RT2)
#define NAV_COP TD(TD_NAVI_COPY)
#define NAV_CUT TD(TD_NAVI_CUT)
#define NAV_PAS TD(TD_NAVI_PASTE)
#define NAV_DEL TD(TD_NAVI_DELETE)
#define NAV_BSP TD(TD_NAVI_BACKSPACE)
#define NAV_UND TD(TD_NAVI_UNDO)


#define VS_BREA TD(TD_VSCODE_BREAD)

    [NAVI] = LAYOUT_moonlander(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        NAV_DEL, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , NAV_PAU, KC_HOME, KC_UP  , KC_END , KC_NO  , NAV_BSP,
        KC_NO  , NAV_BCK, NAV_BRF, NAV_FLD, NAV_FRF, NAV_REF, KC_NO,           KC_NO  , VS_BREA, KC_LEFT, KC_DOWN, KC_RGHT, NAV_COD, KC_NO,
        UK_LGUI, NAV_UND, NAV_CUT, NAV_COP, NAV_PAS, KC_NO  ,                           KC_NO  , KC_PGUP, KC_DOWN, KC_PGDN, NAV_MOU, UK_RGUI,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , UK_LT1,          UK_LT4,         UK_RT4,          UK_RT1, KC_NO  , KC_NO,   KC_NO  , KC_NO,
                                            KC_SPC , KC_NO  , KC_NO  ,         KC_NO  , UK_RT3  , NAV_RT2
    ),

#define VS_UP TD(TD_VSCODE_UP)
#define VS_DOWN TD(TD_VSCODE_DOWN)
#define VS_LEFT TD(TD_VSCODE_LEFT)
#define VS_RIGH TD(TD_VSCODE_RIGHT)
#define VS_TERM TD(TD_VSCODE_TERMINAL)

    [VSCODE] = LAYOUT_moonlander(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        UK_DEL , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , C(KC_PGUP), VS_UP  , C(KC_PGDN), KC_NO  , UK_BSPC  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , VS_BREA, VS_LEFT, VS_TERM, VS_RIGH, NAV_COD, KC_NO  ,
        UK_LGUI, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                           KC_NO  , KC_NO  , VS_DOWN, KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , UK_LT1,          KC_NO  ,         KC_NO  ,          UK_RT1, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                            _______, _______  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO
    ),

    [MOUSE] = LAYOUT_moonlander(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        UK_DEL  , KC_NO  , RGB_MOD, RGB_SPD, RGB_SPI, RGB_TOG, KC_NO  ,         KC_NO  , KC_NO  , KC_WH_L, KC_MS_U, KC_WH_R, KC_NO  , UK_BSPC  ,
        KC_NO  , KC_NO  , KC_ACL0, KC_ACL1, KC_ACL2, KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_NO  ,
        UK_LGUI, KC_NO  , KC_BTN2, KC_BTN3, KC_BTN1, KC_NO  ,                           KC_NO  , KC_WH_U, KC_MS_D, KC_WH_D, KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , UK_LT1,          KC_NO  ,         KC_BTN3,          KC_BTN2, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                            _______, _______, KC_NO  ,         KC_NO  , UK_RT3 , KC_BTN1
    ),

#define SYM_HLF TD(TD_SYMB_HALF)
#define SYM_SLS TD(TD_SYMB_SLASH)
#define SYM_TCK TD(TD_SYMB_BACKTICK)

    [SYMB] = LAYOUT_moonlander(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        SYM_HLF, KC_NO  , DK_EXLM, DK_LCBR, DK_RCBR, DK_DIAE, KC_NO  ,         KC_NO  , DK_QUOT, DK_ASTR, SYM_SLS, DK_PIPE, DK_PERC, DK_MICR,
        DK_QUES, DK_HASH, DK_AMPR, DK_LABK, DK_RABK, DK_TILD, KC_NO  ,         KC_NO  , DK_DQUO, DK_LPRN, DK_RPRN, DK_EQL , DK_COLN, DK_SCLN,
        UK_LGUI, DK_AT  , DK_DLR , DK_LBRC, DK_RBRC, DK_CIRC,                           SYM_TCK, DK_PLUS, DK_MINS, KC_NO  , KC_NO  , UK_RGUI,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , UK_LT1,          KC_NO  ,         KC_NO  ,          UK_RT1, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                            DK_UNDS, UK_LT3, KC_NO  ,         KC_NO  , UK_RT3 , KC_NO
    ),

    [NEW] = LAYOUT_moonlander(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        _______, _______, _______, _______, _______, _______, KC_NO  ,         KC_NO  , _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_NO  ,         KC_NO  , _______, _______, _______, _______, _______, _______,
        UK_LGUI, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , UK_LT1,          _______,         _______,          UK_RT1, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                            _______, _______, KC_NO  ,         KC_NO  , _______, _______
    ),

#define UTI_MON TD(TD_KVM_SWITCH)
#define UTI_PLY TD(TD_AUDIO_PLAY)

    [UTIL] = LAYOUT_moonlander(
        KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_SLEP , KC_NO  , KC_NO  , DM_REC1, DM_REC2, KC_NO  , KC_NO  ,         KC_NO  , KC_BRIU, KC_BRID, KC_VOLU, KC_NO  , KC_NO  , AU_TOGG,
        UTI_MON , KC_NO  , KC_CALC, DM_PLY1, DM_PLY2, KC_NO  , KC_NO  ,         KC_NO  , UK_PRN , KC_MPRV, KC_VOLD, KC_MNXT, AC_TOGG, AS_TOGG,
        TO(COLE), KC_NO  , KC_NO  , C(G(KC_UP)), C(G(KC_DOWN)), KC_NO ,                  KC_NO  , C(G(KC_LEFT)), UTI_PLY, C(G(KC_RIGHT)), KC_NO  , QK_BOOT,
        KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,         TO(NUMB),        TO(NUMB),          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                             TO(NAVI), TO(MOUSE), KC_NO,        KC_NO  , KC_NO  , TO(SYMB)
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VRSN:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
        break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    static bool in_navi_layer = false;
    static uint8_t modifiers;

    // disable all modifiers when entering the NAVI layer
    if (in_navi_layer && !IS_LAYER_ON_STATE(state, NAVI)) {
        in_navi_layer = false;
        set_mods(modifiers);
    } else if (!in_navi_layer && IS_LAYER_ON_STATE(state, NAVI)) {
        in_navi_layer = true;
        modifiers = get_mods();
        del_mods(modifiers);
    }
    return state;
}

void user_dynamic_macro_record_start_user(void) {
    PLAY_SONG(macro_record_start_song);
}

void user_dynamic_macro_record_end_user(int8_t direction) {
    PLAY_SONG(macro_record_stop_song);
}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
    PLAY_SONG(macro_record_key_song);
}

#ifdef AUTOCORRECT_ENABLE
#ifdef AUDIO_ENABLE
float autocorrect_song[][2] = SONG(TERMINAL_SOUND);
#endif

bool apply_autocorrect(uint8_t backspaces, const char *str) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(autocorrect_song);
#endif
    for (uint8_t i = 0; i < backspaces; ++i) {
        tap_code16(KC_BSPC);
    }
    send_string_P(str);
    return false;
}
#endif


typedef enum {
    TD_NONE,            // starting condition
    TD_UNKNOWN,         // a condition without an action nor a default_kc
    TD_DEFAULT,         // user pressed keys more times than we have tap actions, but we have default_kc
    TD_SINGLE_TAP,      // take the tap action
    TD_SINGLE_HOLD,     // take the hold action
    TD_DOUBLE_TAP,      // take the double tap action
    TD_DOUBLE_HOLD,     // take the tap-hold hold action
    TD_DOUBLE_DEFAULT,  // use 2*default_kc (interrupted double tap)
} td_state_t;

// Tap functions should ONLY use the sendXXX functions.
typedef struct {
    void (*tap_fn)(void);
} td_tap_action_t;

// Hold functions can react to the key release, thus they can unregister any registered keys
typedef struct {
    void (*hold_fn)(void);
    void (*reset_fn)(void);
} td_hold_action_t;

typedef struct {
    td_tap_action_t single_tap;
    td_hold_action_t single_hold;
    td_tap_action_t double_tap;
    td_hold_action_t double_hold;
    td_state_t state;
    bool is_press_action;
} td_tap_user_t;

// Return an integer that corresponds to what kind of tap dance should be executed.
td_state_t cur_dance(qk_tap_dance_state_t *state, td_tap_user_t *user_data) {
    if (user_data->state != TD_NONE) return user_data->state;

    if (state->count == 1) {
        if (state->interrupted) {
            if (!state->pressed) {
                user_data->is_press_action = false;
                return TD_SINGLE_TAP;
            } else {
                user_data->is_press_action = true;
                return TD_SINGLE_HOLD;
            }
        }
        else if (!state->pressed) {
            user_data->is_press_action = false;
            return TD_SINGLE_TAP;
        } else {
            user_data->is_press_action = true;
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        // TD_DOUBLE_DEFAULT is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) {
            if (!state->pressed) {
                user_data->is_press_action = false;
                return TD_DOUBLE_DEFAULT;
            } else {
                user_data->is_press_action = true;
                return TD_DOUBLE_HOLD;
            }
        }
        else if (!state->pressed) {
            user_data->is_press_action = false;
            return TD_DOUBLE_TAP;
        }
        else {
            user_data->is_press_action = true;
            return TD_DOUBLE_HOLD;
        }
    } else {
        return TD_UNKNOWN;
    }
}

void td_each(qk_tap_dance_state_t *state, void *_user_data) {
    td_tap_user_t *user_data = (td_tap_user_t *)_user_data;
    if (!user_data->single_tap.tap_fn) return;

    if (user_data->state != TD_NONE) {
        user_data->single_tap.tap_fn();
        return;
    }

    // detect when the user "falls off the end", that is, a key is pressed more times than is defined
    switch (state->count) {
    case 1:
        // single tap or hold is always ok, needs to be as the user may have defined double-tap
        break;
    case 2:
        if (!user_data->double_tap.tap_fn && !user_data->double_hold.hold_fn) {
            // no double actions defined, use the 2*default_kc
            user_data->state = TD_DEFAULT;
            user_data->single_tap.tap_fn();
            user_data->single_tap.tap_fn();
        }
        break;
    default:
        user_data->state = TD_UNKNOWN;
        user_data->single_tap.tap_fn();
        user_data->single_tap.tap_fn();
        user_data->single_tap.tap_fn();
        break;
    }
}

void td_finished(qk_tap_dance_state_t *state, void *_user_data) {
    td_tap_user_t *user_data = (td_tap_user_t *)_user_data;

    user_data->state = cur_dance(state, user_data);
    switch (user_data->state) {
        case TD_SINGLE_TAP:
            if (user_data->single_tap.tap_fn) {
                user_data->single_tap.tap_fn();
            }
            break;
        case TD_SINGLE_HOLD:
            if (user_data->single_hold.hold_fn) {
                user_data->single_hold.hold_fn();
            }
            break;
        case TD_DOUBLE_TAP:
            if (user_data->double_tap.tap_fn) {
                user_data->double_tap.tap_fn();
            }
            else if (user_data->single_tap.tap_fn) {
                user_data->single_tap.tap_fn();
                user_data->single_tap.tap_fn();
            }
            break;
        case TD_DOUBLE_HOLD:
            if (user_data->double_hold.hold_fn) {
                user_data->double_hold.hold_fn();
            }
            break;
        case TD_DOUBLE_DEFAULT:
            if (user_data->single_tap.tap_fn) {
                user_data->single_tap.tap_fn();
                user_data->single_tap.tap_fn();
            }
            break;
        default: break;
    }
}

void td_reset(qk_tap_dance_state_t *state, void *_user_data) {
    td_tap_user_t *user_data = (td_tap_user_t *)_user_data;

    switch (user_data->state) {
        case TD_SINGLE_HOLD:
            if (user_data->single_hold.reset_fn) {
                user_data->single_hold.reset_fn();
            }
            break;
        case TD_DOUBLE_HOLD:
            if (user_data->double_hold.reset_fn) {
                user_data->double_hold.reset_fn();
            }
            break;
        default:
            break;
    }
    user_data->state = TD_NONE;
    user_data->is_press_action = true;
}

// Define the Tap/Hold functions
#define TDF_TAP(KC, ST_ACTION) \
void KC ## _st_action(void) { ST_ACTION; }

#define TDF_HOLD(KC, SH_ACTION, SH_RESET) \
void KC ## _sh_action(void) { SH_ACTION; } \
void KC ## _sh_reset(void) { SH_RESET; }

#define TDF_DTAP(KC, DT_ACTION) \
void KC ## _dt_action(void) { DT_ACTION; }

#define TDF_TAPHOLD(KC, DH_ACTION, DH_RESET) \
void KC ## _dh_action(void) { DH_ACTION; } \
void KC ## _dh_reset(void) { DH_RESET; }

// Initialization of the tap dance actions, using our custom functions
#define __TDA_DEFINITION__(KC, ST_ACTION_FN, SH_ACTION_FN, SH_RESET_FN, DT_ACTION_FN, DH_ACTION_FN, DH_RESET_FN) [KC] = { \
        .fn = { \
            td_each, \
            td_finished, \
            td_reset \
        }, \
        .user_data = &(td_tap_user_t){ \
            .is_press_action = true, \
            .state = TD_NONE, \
            .single_tap = { \
                .tap_fn = ST_ACTION_FN, \
            }, \
            .single_hold = { \
                .hold_fn = SH_ACTION_FN, \
                .reset_fn = SH_RESET_FN \
            }, \
            .double_tap = { \
                .tap_fn = DT_ACTION_FN, \
            }, \
            .double_hold = { \
                .hold_fn = DH_ACTION_FN, \
                .reset_fn = DH_RESET_FN \
            } \
        }\
    }

// Permutations of definitions for Single Tap, Single Hold, Double Tap and Tap Hold (Double Hold).
// If using DEFAULT_KC, it'll be sent if a sequence is interrupted, or the user taps too many times.
#define TDA_TAP(KC) __TDA_DEFINITION__(KC, KC ## _st_action, NULL, NULL, NULL, NULL, NULL)

#define TDA_HOLD(KC) __TDA_DEFINITION__(KC, NULL, KC ## _sh_action, KC ## _sh_reset, NULL, NULL, NULL)

#define TDA_TAP_HOLD(KC) __TDA_DEFINITION__(KC, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, NULL, NULL, NULL)

#define TDA_DTAP(KC) __TDA_DEFINITION__(KC, NULL, NULL, NULL, KC ## _dt_action, NULL, NULL)

#define TDA_TAP_DTAP(KC) __TDA_DEFINITION__(KC, KC ## _st_action, NULL, NULL, KC ## _dt_action, NULL, NULL)

#define TDA_HOLD_DTAP(KC) __TDA_DEFINITION__(KC, NULL, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, NULL, NULL)

#define TDA_TAP_HOLD_DTAP(KC) __TDA_DEFINITION__(KC, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, NULL, NULL)

#define TDA_TAPHOLD(KC) __TDA_DEFINITION__(KC, NULL, NULL, NULL, NULL, KC ## _dh_action, KC ## _dh_reset)

#define TDA_TAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, KC ## _st_action, NULL, NULL, NULL,  KC ## _dh_action, KC ## _dh_reset)

#define TDA_HOLD_TAPHOLD(KC) __TDA_DEFINITION__(KC, NULL, KC ## _sh_action, KC ## _sh_reset, NULL,  KC ## _dh_action, KC ## _dh_reset)

#define TDA_TAP_HOLD_TAPHOLD(KC) __TDA_DEFINITION__(KC, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, NULL, KC ## _dh_action, KC ## _dh_reset)

#define TDA_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, NULL, NULL, NULL, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)

#define TDA_TAP_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, KC ## _st_action, NULL, NULL, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)

#define TDA_HOLD_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, NULL, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)

#define TDA_TAP_HOLD_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)


static bool shift_lock_enabled = false;
static bool ctrl_lock_enabled = false;
static bool alt_lock_enabled = false;
static bool gui_lock_enabled = false;

void invert_sticky_mod(bool *mod_state, int8_t mod) {
    if (*mod_state) {
        unregister_code(mod);
    } else {
        register_code(mod);
    }
}

void reset_sticky_mod(bool *mod_state, int8_t mod) {
    if (*mod_state) {
        register_code(mod);
    } else {
        unregister_code(mod);
    }
}

void toggle_mod(bool *mod_state, int8_t mod) {
    if (!*mod_state) {
        register_code(mod);
        *mod_state = true;
        PLAY_SONG(lock_song);
    } else {
        unregister_code(mod);
        *mod_state = false;
        PLAY_SONG(unlock_song);
    } \
}

#define WITHOUT_MODS(...) \
  do { \
    const uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    clear_weak_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)


TDF_TAP(TD_LT4, tap_code16(KC_ENTER))
TDF_HOLD(TD_LT4, layer_on(NUMB), layer_off(NUMB))
TDF_TAPHOLD(TD_LT4, WITHOUT_MODS( tap_code16(C(S(KC_ENTER))); ), {} )

TDF_TAP(TD_RT4, tap_code16(KC_ENTER))
TDF_HOLD(TD_RT4, layer_on(NUMB), layer_off(NUMB))
TDF_TAPHOLD(TD_RT4, WITHOUT_MODS( tap_code16(C(KC_ENTER)); ), {} )

TDF_TAP(TD_LGUI, tap_code16(KC_APP))
TDF_HOLD(TD_LGUI, invert_sticky_mod(&gui_lock_enabled, KC_LGUI), reset_sticky_mod(&gui_lock_enabled, KC_LGUI) )
TDF_TAPHOLD(TD_LGUI, toggle_mod(&gui_lock_enabled, KC_LGUI), {})

TDF_HOLD(TD_RGUI, invert_sticky_mod(&shift_lock_enabled, KC_LSFT), reset_sticky_mod(&shift_lock_enabled, KC_LSFT) )
TDF_TAPHOLD(TD_RGUI, toggle_mod(&shift_lock_enabled, KC_LSFT), {})

TDF_HOLD(TD_LT1, { layer_on(UTIL); PLAY_SONG(layer_song); }, layer_off(UTIL))
TDF_DTAP(TD_LT1, { \
    ctrl_lock_enabled = false; \
    shift_lock_enabled = false; \
    alt_lock_enabled = false; \
    gui_lock_enabled = false; \
    unregister_code(KC_LCTL); \
    unregister_code(KC_LSFT); \
    unregister_code(KC_LALT); \
    unregister_code(KC_LGUI); \
    clear_mods(); \
    clear_weak_mods(); \
    layer_move(COLE); \
    PLAY_SONG(colemak_song); \
})

TDF_HOLD(TD_RT1, invert_sticky_mod(&alt_lock_enabled, KC_LALT), reset_sticky_mod(&alt_lock_enabled, KC_LALT) )
TDF_TAPHOLD(TD_RT1, toggle_mod(&alt_lock_enabled, KC_LALT), {})

//TDF_TAP(TD_LT2, tap_code(KC_SPC))
//TDF_HOLD(TD_LT2, layer_on(NAVI), layer_off(NAVI))
//TDF_TAPHOLD(TD_LT2, layer_on(SYMB), layer_off(SYMB))

TDF_TAP(TD_RT2, tap_code(KC_SPC))
TDF_HOLD(TD_RT2, layer_on(SYMB), layer_off(SYMB))
TDF_TAPHOLD(TD_RT2, layer_on(NAVI), layer_off(NAVI))

TDF_TAP(TD_LT3, tap_code(KC_TAB) )
TDF_HOLD(TD_LT3, layer_on(NAVI), layer_off(NAVI))
TDF_TAPHOLD(TD_LT3, layer_on(SYMB), layer_off(SYMB))

TDF_TAP(TD_RT3, tap_code(KC_ESC))
TDF_HOLD(TD_RT3, invert_sticky_mod(&ctrl_lock_enabled, KC_LCTL), reset_sticky_mod(&ctrl_lock_enabled, KC_LCTL) )
TDF_TAPHOLD(TD_RT3, toggle_mod(&ctrl_lock_enabled, KC_LCTL), {})

TDF_TAP(TD_DELETE, SEND_STRING(SS_TAP(X_DELETE)) )
TDF_HOLD(TD_DELETE, WITHOUT_MODS( SEND_STRING(SS_LCTL(SS_TAP(X_DELETE))); ), {})
TDF_TAPHOLD(TD_DELETE, WITHOUT_MODS( SEND_STRING(SS_LALT(SS_TAP(X_DELETE))); ), {})

TDF_TAP(TD_NAVI_DELETE, WITHOUT_MODS( SEND_STRING(SS_TAP(X_DELETE)); ) )
TDF_HOLD(TD_NAVI_DELETE, WITHOUT_MODS( SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(100) SS_TAP(X_DELETE)); ), {})

TDF_TAP(TD_BACKSPACE, SEND_STRING(SS_TAP(X_BACKSPACE)) )
TDF_HOLD(TD_BACKSPACE, WITHOUT_MODS( SEND_STRING(SS_LCTL(SS_TAP(X_BACKSPACE))); ), {})
TDF_TAPHOLD(TD_BACKSPACE, WITHOUT_MODS( SEND_STRING(SS_LALT(SS_TAP(X_BACKSPACE))); ), {})

TDF_TAP(TD_NAVI_BACKSPACE, WITHOUT_MODS( SEND_STRING(SS_TAP(X_BACKSPACE)); ) )
TDF_HOLD(TD_NAVI_BACKSPACE, WITHOUT_MODS( SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(100) SS_TAP(X_BACKSPACE)); ), {})

TDF_TAP(TD_DOT_COMM, tap_code16(KC_DOT))
TDF_DTAP(TD_DOT_COMM, tap_code16(KC_COMM))

#define TDF_FX(FN) \
TDF_TAP(TD_ ## FN, tap_code16(KC_ ## FN); ) \
TDF_DTAP(TD_ ## FN, tap_code16(C(KC_ ## FN)); ) \
TDF_HOLD(TD_ ## FN, tap_code16(S(KC_ ## FN));, {}) \
TDF_TAPHOLD(TD_ ## FN, tap_code16(C(S(KC_ ## FN)));, {})
TDF_FX(F1)
TDF_FX(F2)
TDF_FX(F3)
TDF_FX(F4)
TDF_FX(F5)
TDF_FX(F6)
TDF_FX(F7)
TDF_FX(F8)
TDF_FX(F9)
TDF_FX(F10)
TDF_FX(F11)
TDF_FX(F12)
TDF_FX(F14)
TDF_FX(F15)
TDF_FX(F16)

TDF_TAP(TD_PAU_INS, tap_code16(KC_PAUSE))
TDF_DTAP(TD_PAU_INS, tap_code16(KC_INS))

TDF_TAP(TD_REFERENCE, tap_code16(C(S(KC_F10))) )
TDF_DTAP(TD_REFERENCE, tap_code16(KC_F12) )
TDF_HOLD(TD_REFERENCE, tap_code16(S(KC_F12)), {} )
TDF_TAPHOLD(TD_REFERENCE, SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_F12)))), {} )

TDF_TAP(TD_VSCODE_UP, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(KC_UP); ) )
TDF_DTAP(TD_VSCODE_UP, WITHOUT_MODS( tap_code16(C(KC_K)); tap_code16(KC_UP); ) )
TDF_HOLD(TD_VSCODE_UP, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(A(C(KC_UP))); ), {} )

TDF_TAP(TD_VSCODE_DOWN, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(KC_DOWN); ) )
TDF_DTAP(TD_VSCODE_DOWN, WITHOUT_MODS( tap_code16(C(KC_K)); tap_code16(KC_DOWN); ) )
TDF_HOLD(TD_VSCODE_DOWN, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(A(C(KC_DOWN))); ), {} )

TDF_TAP(TD_VSCODE_LEFT, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(KC_LEFT); ) )
TDF_DTAP(TD_VSCODE_LEFT, WITHOUT_MODS( tap_code16(C(KC_K)); tap_code16(KC_LEFT); ) )
TDF_HOLD(TD_VSCODE_LEFT, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(A(C(KC_LEFT))); ), {} )

TDF_TAP(TD_VSCODE_RIGHT, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(KC_RIGHT); ) )
TDF_DTAP(TD_VSCODE_RIGHT, WITHOUT_MODS( tap_code16(C(KC_K)); tap_code16(KC_RIGHT); ) )
TDF_HOLD(TD_VSCODE_RIGHT, WITHOUT_MODS( tap_code16(C(KC_J)); tap_code16(A(C(KC_RIGHT))); ), {} )

TDF_TAP(TD_VSCODE_TERMINAL, WITHOUT_MODS( tap_code16(C(KC_J));tap_code16(KC_HOME); ) )
TDF_DTAP(TD_VSCODE_TERMINAL, WITHOUT_MODS( tap_code16(C(DK_AE)); ) )
TDF_HOLD(TD_VSCODE_TERMINAL, WITHOUT_MODS( tap_code16(C(KC_K)); tap_code16(C(KC_H)); ), {} )

TDF_TAP(TD_VSCODE_BREAD, WITHOUT_MODS( tap_code16(C(S(KC_DOT))); ) )

TDF_HOLD(TD_NAVI_VSCODE, layer_on(VSCODE), layer_off(VSCODE))
TDF_TAPHOLD(TD_NAVI_VSCODE, layer_on(VSCODE), layer_off(VSCODE))

TDF_HOLD(TD_NAVI_MOUSE, layer_on(MOUSE), layer_off(MOUSE))
TDF_TAPHOLD(TD_NAVI_MOUSE, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_SYMB_SLASH, tap_code16(DK_SLSH))
TDF_HOLD(TD_SYMB_SLASH, register_code16(DK_BSLS), unregister_code16(DK_BSLS))
TDF_TAPHOLD(TD_SYMB_SLASH, register_code16(DK_SLSH), unregister_code16(DK_SLSH))

TDF_TAP(TD_SYMB_BACKTICK, tap_code16(DK_GRV))
TDF_HOLD(TD_SYMB_BACKTICK, register_code16(DK_ACUT), unregister_code16(DK_ACUT))
TDF_TAPHOLD(TD_SYMB_BACKTICK, register_code16(DK_GRV), unregister_code16(DK_GRV))

TDF_TAP(TD_SYMB_HALF, WITHOUT_MODS( tap_code16(DK_HALF); ) )
TDF_DTAP(TD_SYMB_HALF, WITHOUT_MODS( tap_code16(DK_PND); ) )
TDF_HOLD(TD_SYMB_HALF, WITHOUT_MODS( tap_code16(ALGR(KC_E)); ), {} )
TDF_TAPHOLD(TD_SYMB_HALF, WITHOUT_MODS( tap_code16(DK_SECT); ), {} )

TDF_TAP(TD_KVM_SWITCH, WITHOUT_MODS( PLAY_SONG(kvm_sw1); SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "1"); ) )
TDF_DTAP(TD_KVM_SWITCH, WITHOUT_MODS( PLAY_SONG(kvm_sw2); SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "2"); ) )

TDF_TAP(TD_AUDIO_PLAY, WITHOUT_MODS( tap_code16(KC_MPLY); ) )
TDF_HOLD(TD_AUDIO_PLAY, WITHOUT_MODS( tap_code16(KC_MUTE); ), {})

TDF_TAP(TD_PRINTSCREEN, WITHOUT_MODS( tap_code16(KC_PSCR); ) )
TDF_DTAP(TD_PRINTSCREEN, WITHOUT_MODS( tap_code16(A(KC_PSCR)); ) )
TDF_HOLD(TD_PRINTSCREEN, WITHOUT_MODS( tap_code16(G(KC_PSCR)); ), {} )
TDF_TAPHOLD(TD_PRINTSCREEN, WITHOUT_MODS( tap_code16(G(S(KC_PSCR))); ), {} )

TDF_TAP(TD_BACK_META, WITHOUT_MODS( tap_code16(C(KC_SLSH)); ) )
TDF_HOLD(TD_BACK_META, register_code16(KC_LGUI), unregister_code16(KC_LGUI))

TDF_TAP(TD_PREV_REF, WITHOUT_MODS( tap_code16(S(KC_F7)); ) )
TDF_DTAP(TD_PREV_REF, WITHOUT_MODS( tap_code16(C(S(KC_J))); ) )
TDF_HOLD(TD_PREV_REF, register_code16(KC_LCTL), unregister_code16(KC_LCTL))

TDF_TAP(TD_FOLD, WITHOUT_MODS( tap_code16(C(KC_K)); tap_code16(C(KC_L)); ) )
TDF_DTAP(TD_FOLD, WITHOUT_MODS( tap_code16(A(C(S(KC_K)))); ) )
TDF_HOLD(TD_FOLD, register_code16(KC_LSFT), unregister_code16(KC_LSFT))

TDF_TAP(TD_NEXT_REF, WITHOUT_MODS( tap_code16(KC_F7); ) )
TDF_DTAP(TD_NEXT_REF, WITHOUT_MODS( tap_code16(C(S(KC_L))); ) )
TDF_HOLD(TD_NEXT_REF, register_code16(KC_LALT), unregister_code16(KC_LALT))

TDF_DTAP(TD_NAVI_RT2, WITHOUT_MODS( tap_code16(C(KC_DOT)); ) )
TDF_TAP(TD_NAVI_RT2, WITHOUT_MODS( tap_code16(C(KC_SPC)); ) )

TDF_TAP(TD_NAVI_COPY, WITHOUT_MODS( tap_code16(C(KC_C)); ) )
TDF_HOLD(TD_NAVI_COPY, register_code16(KC_LSFT), unregister_code16(KC_LSFT))

TDF_TAP(TD_NAVI_CUT, WITHOUT_MODS( tap_code16(C(KC_X)); ) )
TDF_HOLD(TD_NAVI_CUT, register_code16(KC_LCTL), unregister_code16(KC_LCTL))

TDF_TAP(TD_NAVI_PASTE, WITHOUT_MODS( tap_code16(C(KC_V)); ) )
TDF_DTAP(TD_NAVI_PASTE, WITHOUT_MODS( tap_code16(C(KC_D)); ) )
TDF_HOLD(TD_NAVI_PASTE, register_code16(KC_LALT), unregister_code16(KC_LALT))

TDF_TAP(TD_NAVI_UNDO, WITHOUT_MODS( tap_code16(C(KC_Z)); ) )
TDF_HOLD(TD_NAVI_UNDO, register_code16(KC_LGUI), unregister_code16(KC_LGUI))


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    TDA_TAP_HOLD_TAPHOLD(TD_LT4),
    // enter, hold NUMB, tap-hold CTRL+SHIFT+ENTER

    TDA_TAP_HOLD_TAPHOLD(TD_RT4),
    // enter, hold NUMB, tap-hold CTRL+ENTER

    TDA_TAP_HOLD_TAPHOLD(TD_LGUI),
    TDA_HOLD_TAPHOLD(TD_RGUI),

    // tap APP, hold LGUI, tap-hold LGUI toggle

    TDA_HOLD_DTAP(TD_LT1),
    // hold CTRL, tap-hold CTRL toggle

    TDA_HOLD_TAPHOLD(TD_RT1),
    // hold LALT, tap-hold LALT toggle

    //TDA_TAP(TD_LT2),
    //TDA_TAP_HOLD_TAPHOLD(TD_LT2),
    // space, hold NAVI, tap-hold SYMB

    TDA_TAP(TD_RT2),
    TDA_TAP_HOLD_TAPHOLD(TD_RT2),
    // space, hold SYMB, tap-hold NAVI

    TDA_TAP_HOLD_TAPHOLD(TD_LT3),
    // tap TAB, hold SHIFT, tap-hold SHIFT toggle

    TDA_TAP_HOLD_TAPHOLD(TD_RT3),
    // tap ESC, hold SHIFT, tap-hold SHIFT toggle


    TDA_TAP_HOLD_TAPHOLD(TD_DELETE),
    // del, hold ALT+DEL, tap-hold CTRL+DEL
    TDA_TAP_HOLD(TD_NAVI_DELETE),
    // del, hold SHIFT+END DEL

    TDA_TAP_HOLD_TAPHOLD(TD_BACKSPACE),
    // bspc, hold ALT+BSPC, tap-hold CTRL+BSPC
    TDA_TAP_HOLD(TD_NAVI_BACKSPACE),
    // bspc, hold  SHIFT+HOME BSPC

    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F1),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F2),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F3),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F4),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F5),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F6),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F7),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F8),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F9),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F10),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F11),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F12),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F14),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F15),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F16),

    TDA_TAP_DTAP(TD_DOT_COMM),
    TDA_TAP_DTAP(TD_NAVI_RT2),

    TDA_TAP_DTAP(TD_PAU_INS),
    TDA_TAP_HOLD(TD_BACK_META),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_REFERENCE),
    TDA_TAP_HOLD_DTAP(TD_PREV_REF),
    TDA_TAP_HOLD_DTAP(TD_NEXT_REF),
    TDA_TAP_HOLD_DTAP(TD_FOLD),
    TDA_HOLD_TAPHOLD(TD_NAVI_VSCODE),
    TDA_HOLD_TAPHOLD(TD_NAVI_MOUSE),

    TDA_TAP_HOLD_TAPHOLD(TD_SYMB_SLASH),
    TDA_TAP_HOLD_TAPHOLD(TD_SYMB_BACKTICK),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_SYMB_HALF),

    TDA_TAP_DTAP(TD_KVM_SWITCH),
    TDA_TAP_HOLD(TD_AUDIO_PLAY),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_PRINTSCREEN),

    TDA_TAP_HOLD_DTAP(TD_VSCODE_UP),
    TDA_TAP_HOLD_DTAP(TD_VSCODE_DOWN),
    TDA_TAP_HOLD_DTAP(TD_VSCODE_LEFT),
    TDA_TAP_HOLD_DTAP(TD_VSCODE_RIGHT),

    TDA_TAP(TD_VSCODE_BREAD),

    TDA_TAP_HOLD(TD_NAVI_COPY),
    TDA_TAP_HOLD(TD_NAVI_CUT),
    TDA_TAP_HOLD_DTAP(TD_NAVI_PASTE),
    TDA_TAP_HOLD(TD_NAVI_UNDO),

    TDA_TAP_HOLD_DTAP(TD_VSCODE_TERMINAL),
};
