#include QMK_KEYBOARD_H
#include "sendstring_danish.h"
#include "action_util.h"


enum layers {
    COLE,
    NUMB,   // numberpad/Fx
    SYMB,   // symbols
    NAVI,   // navigation
    VSCODE, // vscode shortcuts
    MOUSE,  // mouse navigation
    UTIL,   // utility/media
};

/*
 Tap-Dance key codes
 */
enum {
    // GENERAL
    TD_LT1,
    TD_RT1,
    TD_LT2,
    TD_RT2,
    TD_LT3,
    TD_RT3,
    TD_LT4,
    TD_RT4,
    TD_LT5,
    TD_RT5,

    TD_DELETE,
    TD_BACKSPACE,

    TD_DOT,
    TD_COMM,

    TD_OSTR,

    // NUMBER
    TD_NUM_4,
    TD_NUM_5,
    TD_NUM_6,
    TD_NUM_DOT,
    TD_F4,
    TD_F5,
    TD_F6,
    TD_F15,

    // NAVIGATION
    TD_NEXT_REF,
    TD_PREV_REF,
    TD_VSCODE_BREAD,
    TD_NAVI_RT2,
    TD_NAVI_VSCODE,
    TD_NAVI_MOUSE,
    TD_NAVI_COPY,
    TD_NAVI_CUT,
    TD_NAVI_PASTE,
    TD_NAV_DELETE,
    TD_NAV_BACKSPACE,
    TD_NAVI_UNDO,

    // MOUSE
    TD_MOUSE_1,
    TD_MOUSE_2,
    TD_MOUSE_3,

    // VSCODE
    TD_VSCODE_UP,
    TD_VSCODE_DOWN,
    TD_VSCODE_LEFT,
    TD_VSCODE_RIGHT,
    TD_VSCODE_TERMINAL,

    // SYMBOLIC
    TD_SYMB_DELETE,
    TD_SYMB_BACKSPACE,
    TD_SYMB_LT1,
    TD_SYMB_RT1,
    TD_SYMB_LT4,
    TD_SYMB_RT4,
    TD_SYMB_HALF,
    TD_SYMB_SLASH,
    TD_SYMB_BACKTICK,

    // UTILITY
    TD_UTIL_BACK_TO_BASICS,

    TD_PAU_INS,
    TD_BACK_META,
    TD_REFERENCE,
    TD_FOLD,
    TD_KVM_SWITCH,
    TD_AUDIO_PLAY,
    TD_PRINTSCREEN,
};

/*
General Tap-Dance keys
*/
#define UK_LT1  TD(TD_LT1)
#define UK_RT1  TD(TD_RT1)
#define UK_LT2  TD(TD_LT2)
#define UK_RT2  TD(TD_RT2)
#define UK_LT3  TD(TD_LT3)
#define UK_RT3  TD(TD_RT3)
#define UK_LT4  TD(TD_LT4)
#define UK_RT4  TD(TD_RT4)
#define UK_LT5  TD(TD_LT5)
#define UK_RT5  TD(TD_RT5)

#define UK_DEL  TD(TD_DELETE)
#define UK_BSPC TD(TD_BACKSPACE)

#define UK_PRN  TD(TD_PRINTSCREEN)

/*
Colemak Tap-Dance
*/
#define COL_A MT(MOD_LGUI, KC_A)
#define COL_R MT(MOD_LCTL, KC_R)
#define COL_S MT(MOD_LSFT, KC_S)
#define COL_T MT(MOD_LALT, KC_T)
#define COL_N MT(MOD_LALT, KC_N)
#define COL_E MT(MOD_LSFT, KC_E)
#define COL_I MT(MOD_RCTL, KC_I)
#define COL_O MT(MOD_LGUI, KC_O)
#define COL_DOT  TD(TD_DOT)
#define COL_COMM  TD(TD_COMM)
#define COL_OSTR  TD(TD_OSTR)

/*
Number Tap-Dance
*/
#define NUM_F04 TD(TD_F4)
#define NUM_F05 TD(TD_F5)
#define NUM_F06 TD(TD_F6)
#define NUM_F15 TD(TD_F15)
#define NUM_4 TD(TD_NUM_4)
#define NUM_5 TD(TD_NUM_5)
#define NUM_6 TD(TD_NUM_6)
#define NUM_DOT TD(TD_NUM_DOT)

/*
Navigation Tap-Dance
*/
#define NAV_DEL TD(TD_NAV_DELETE)
#define NAV_PAU TD(TD_PAU_INS)
#define NAV_BSP TD(TD_NAV_BACKSPACE)
#define NAV_BCK TD(TD_BACK_META)
#define NAV_BRF TD(TD_PREV_REF)
#define NAV_FLD TD(TD_FOLD)
#define NAV_FRF TD(TD_NEXT_REF)
#define NAV_REF TD(TD_REFERENCE)
#define VS_BREA TD(TD_VSCODE_BREAD)
#define NAV_COD TD(TD_NAVI_VSCODE)
#define NAV_UND TD(TD_NAVI_UNDO)
#define NAV_CUT TD(TD_NAVI_CUT)
#define NAV_COP TD(TD_NAVI_COPY)
#define NAV_PAS TD(TD_NAVI_PASTE)
#define NAV_MOU TD(TD_NAVI_MOUSE)

/*
VSCode Tap-Dance
*/
#define VS_UP   TD(TD_VSCODE_UP)
#define VS_DOWN TD(TD_VSCODE_DOWN)
#define VS_LEFT TD(TD_VSCODE_LEFT)
#define VS_RIGH TD(TD_VSCODE_RIGHT)
#define VS_TERM TD(TD_VSCODE_TERMINAL)

/*
Mouse Tap-Dance
*/
#define MS_BT1 TD(TD_MOUSE_1)
#define MS_BT2 TD(TD_MOUSE_2)
#define MS_BT3 TD(TD_MOUSE_3)
/*
Symbolic Tap-Dance
*/
#define SYM_DEL TD(TD_SYMB_DELETE)
#define SYM_BSP TD(TD_SYMB_BACKSPACE)
#define SYM_HLF TD(TD_SYMB_HALF)
#define SYM_SLS TD(TD_SYMB_SLASH)
#define SYM_TCK TD(TD_SYMB_BACKTICK)

/*
Utility Tap-Dance
*/
#define UTI_MON TD(TD_KVM_SWITCH)
#define UTI_PLY TD(TD_AUDIO_PLAY)
#define UTI_RES TD(TD_UTIL_BACK_TO_BASICS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[COLE] = LAYOUT(
        UK_DEL, KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,                                              KC_J, KC_L,  KC_U,     KC_Y,    DK_ARNG, UK_BSPC,
        DK_QUES,COL_A, COL_R, COL_S, COL_T, KC_G,                                              KC_M, COL_N, COL_E,    COL_I,   COL_O,   DK_AE,
        KC_NO,  KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,      UK_LT1,                     UK_RT1,     KC_K, KC_H,  COL_COMM, COL_DOT, COL_OSTR, KC_NO,
                                    UK_LT2, UK_LT3, UK_LT4, UK_LT5,      UK_RT5, UK_RT4, UK_RT3, UK_RT2
    ),
	[NUMB] = LAYOUT(
        UK_DEL, KC_F16,  KC_F7,   KC_F8,   KC_F9,   KC_F12,                                             KC_SCRL, KC_7, KC_8, KC_9, KC_NO, UK_BSPC,
        KC_F18, NUM_F15, NUM_F04, NUM_F05, NUM_F06, KC_F11,                                             KC_0, NUM_4, NUM_5, NUM_6, NUM_DOT, KC_NO,
        KC_F17, KC_F14,  KC_F1,   KC_F2,   KC_F3,   KC_F10,     UK_LT1,                     UK_RT1,     KC_NO,   KC_1, KC_2, KC_3, KC_COMM, KC_NO,
                                                  UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, KC_0, KC_0, UK_RT2
    ),
	[SYMB] = LAYOUT(
        SYM_DEL, KC_NO,   DK_EXLM, DK_LCBR, DK_RCBR, DK_DIAE,                                               DK_QUOT, DK_ASTR, SYM_SLS, DK_PIPE,    KC_NO,   SYM_BSP,
        SYM_HLF, DK_HASH, DK_AMPR, DK_LABK, DK_RABK, DK_TILD,                                               DK_DQUO, DK_LPRN, DK_RPRN, DK_EQL,     DK_PERC, DK_MICR,
        KC_NO,   DK_AT,   DK_DLR,  DK_LBRC, DK_RBRC, DK_CIRC,       UK_LT1,                     UK_RT1,     SYM_TCK, DK_PLUS, DK_MINS, S(DK_MINS), KC_NO,   KC_NO,
                                                    UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, UK_RT4, UK_RT3, UK_RT2
    ),
	[NAVI] = LAYOUT(
        NAV_DEL,KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                              NAV_PAU, KC_HOME, KC_UP  , KC_END , KC_NO, NAV_BSP,
        KC_NO,  NAV_BCK, NAV_BRF, NAV_FLD, NAV_FRF, NAV_REF,                                            VS_BREA, KC_LEFT, KC_DOWN, KC_RGHT, NAV_COD, KC_NO,
        KC_NO,  NAV_UND, NAV_CUT, NAV_COP, NAV_PAS, KC_NO,      UK_LT1,                     UK_RT1,     KC_NO  , KC_PGUP, S(C(DK_HALF)), KC_PGDN, NAV_MOU, KC_NO,
                                                UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, UK_RT4, UK_RT3, UK_RT2
    ),
	[VSCODE] = LAYOUT(
        UK_DEL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                              KC_NO  , KC_NO  , VS_UP  , KC_NO  , KC_NO  , UK_BSPC,
        KC_NO,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,                                              VS_BREA, VS_LEFT, VS_DOWN, VS_RIGH, _______, KC_NO,
        KC_NO,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,      UK_LT1,                     UK_RT1,     KC_NO  , C(KC_PGUP), VS_TERM, C(KC_PGDN), KC_NO  , KC_NO,
                                                UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, UK_RT4, UK_RT3, UK_RT2
    ),
	[MOUSE] = LAYOUT(
        UK_DEL,  KC_NO,   RGB_MOD, RGB_SPD, RGB_SPI, RGB_TOG,                                                KC_NO  , KC_WH_L, KC_MS_U, KC_WH_R, KC_NO  , UK_BSPC,
        RGB_VAD, RGB_VAI, MS_BT1,  MS_BT2,  MS_BT3,  RGB_M_P,                                                KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_NO,
        RGB_HUD, RGB_HUI, KC_BTN2, KC_BTN3, KC_BTN1, RGB_M_R,        UK_LT1,                     UK_RT1,     KC_NO  , KC_WH_U, KC_MS_D, KC_WH_D, KC_NO  , KC_NO,
                                                UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, UK_RT4, UK_RT3, UK_RT2
    ),
	[UTIL] = LAYOUT(
        KC_SLEP, A(KC_F4), C(KC_W),DM_REC1, DM_REC2, KC_NO,                                                         KC_BRIU, KC_BRID, KC_VOLU, KC_NO  , KC_NO  , KC_NO,
        UTI_MON, KC_NO, KC_CALC, DM_PLY1, DM_PLY2, KC_NO,                                                           UK_PRN , KC_MPRV, KC_VOLD, KC_MNXT, KC_NO, AC_TOGG,
        KC_NO,   KC_NO, C(G(KC_UP)), KC_NO, C(G(KC_DOWN)),KC_NO,      UTI_RES,                           UTI_RES,   KC_NO, C(G(KC_LEFT)), UTI_PLY, C(G(KC_RIGHT)), KC_NO, QK_BOOT,
                                                    UK_LT2, TO(NUMB), TO(NUMB), TO(NAVI),     TO(MOUSE), TO(SYMB), TO(SYMB), UK_RT2
    ),
};


void keyboard_post_init_user(void) {
    // Enable the LED layers
    layer_state_set_user(layer_state);
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DK_AE:
        case DK_ARNG:
        case DK_OSTR:
        case DK_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

extern rgblight_config_t rgblight_config;

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case NUMB:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case SYMB:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case NAVI:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case VSCODE:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case MOUSE:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_AZURE);
            break;
        case UTIL:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        default: //  for any other layers, or the default layer
            // Read RGB Light State
            rgblight_config.raw = eeconfig_read_rgblight();
            // If enabled, set white
            if (rgblight_config.enable) {
                rgblight_reload_from_eeprom ();
                // rgblight_enable_noeeprom();
                //rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
            } else { // Otherwise go back to disabled
                rgblight_disable_noeeprom();
            }
            break;
    }
    return state;
}

/*
Tap-Dance special functions
*/
typedef enum {
    TD_NONE = 0,            // starting condition
    TD_UNKNOWN = 1,         // a condition without an action nor a default_kc
    TD_DEFAULT = 2,         // user pressed keys more times than we have tap actions, but we have default_kc
    TD_SINGLE_TAP = 4,      // take the tap action
    TD_SINGLE_HOLD = 8,     // take the hold action
    TD_DOUBLE_TAP = 16,     // take the double tap action
    TD_DOUBLE_HOLD = 32,    // take the tap-hold hold action
    TD_DOUBLE_DEFAULT = 64, // use 2*default_kc (interrupted double tap)
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

// Define the Tap/Hold functions
#define TDF_TAP(KC, ST_ACTION) void KC ## _st_action(void) { ST_ACTION; }
#define TDF_HOLD(KC, SH_ACTION, SH_RESET) void KC ## _sh_action(void) { SH_ACTION; } void KC ## _sh_reset(void) { SH_RESET; }
#define TDF_DTAP(KC, DT_ACTION) void KC ## _dt_action(void) { DT_ACTION; }
#define TDF_TAPHOLD(KC, DH_ACTION, DH_RESET) void KC ## _dh_action(void) { DH_ACTION; } void KC ## _dh_reset(void) { DH_RESET; }

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

// Return an integer that corresponds to what kind of tap dance should be executed.
td_state_t decide_tap_dance_outcome(tap_dance_state_t *state, td_tap_user_t *user_data) {
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

void td_each(tap_dance_state_t *state, void *_user_data) {
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

void td_finished(tap_dance_state_t *state, void *_user_data) {
    td_tap_user_t *user_data = (td_tap_user_t *)_user_data;

    user_data->state = decide_tap_dance_outcome(state, user_data);
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
            } else {
                if (user_data->single_tap.tap_fn) {
                    user_data->single_tap.tap_fn();
                }
                if (user_data->single_hold.hold_fn) {
                    user_data->single_hold.hold_fn();
                }
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

void td_reset(tap_dance_state_t *state, void *_user_data) {
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
            } else if (user_data->single_hold.reset_fn) {
                user_data->single_hold.reset_fn();
            }
            break;
        default:
            break;
    }
    user_data->state = TD_NONE;
    user_data->is_press_action = true;
}

/*
Define Tap-Dance functions and the lookup table
*/

// GENERAL
TDF_TAP(TD_LT1, tap_code(KC_ENTER))
TDF_HOLD(TD_LT1, layer_on(UTIL), layer_off(UTIL))

TDF_TAP(TD_LT2, tap_code(KC_CAPS))//caps_word_on())

TDF_TAP(TD_LT3, tap_code(KC_SPC))
TDF_HOLD(TD_LT3, layer_on(NUMB), layer_off(NUMB))

TDF_TAP(TD_LT4, tap_code(KC_SPC))
TDF_HOLD(TD_LT4, layer_on(NUMB), layer_off(NUMB))

TDF_TAP(TD_LT5, tap_code(KC_ESC))
TDF_HOLD(TD_LT5, layer_on(NAVI), layer_off(NAVI))
TDF_TAPHOLD(TD_LT5, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_RT1, tap_code(KC_ENTER))
TDF_HOLD(TD_RT1, layer_on(UTIL), layer_off(UTIL))

TDF_TAP(TD_RT2, caps_word_on())

TDF_TAP(TD_RT3, tap_code(KC_SPC))
TDF_HOLD(TD_RT3, layer_on(SYMB), layer_off(SYMB))

TDF_TAP(TD_RT4, tap_code(KC_SPC))
TDF_HOLD(TD_RT4, layer_on(SYMB), layer_off(SYMB))

TDF_TAP(TD_RT5, tap_code(KC_TAB))
TDF_HOLD(TD_RT5, layer_on(NAVI), layer_off(NAVI))
TDF_TAPHOLD(TD_RT5, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_DELETE, tap_code(KC_DEL))
TDF_HOLD(TD_DELETE, register_code(KC_DEL), unregister_code(KC_DEL))
TDF_TAPHOLD(TD_DELETE, tap_code16(A(KC_DEL)), {})

TDF_TAP(TD_BACKSPACE, tap_code(KC_BSPC))
TDF_HOLD(TD_BACKSPACE, register_code(KC_BSPC), unregister_code(KC_BSPC))
TDF_TAPHOLD(TD_BACKSPACE, tap_code16(A(KC_BSPC)), {})

// COLEMAK
TDF_TAP(TD_DOT, tap_code(KC_DOT))
TDF_HOLD(TD_DOT, tap_code16(S(KC_DOT)), {})

TDF_TAP(TD_COMM, tap_code(KC_COMM))
TDF_HOLD(TD_COMM, tap_code16(S(KC_COMM)), {})

TDF_TAP(TD_OSTR, tap_code(DK_OSTR))
TDF_HOLD(TD_OSTR, tap_code16(S(DK_MINS)), {})

// NUMBER
TDF_TAP(TD_NUM_4, tap_code(KC_4))
TDF_HOLD(TD_NUM_4, register_code(KC_LALT), unregister_code(KC_LALT))
TDF_TAP(TD_NUM_5, tap_code(KC_5))
TDF_HOLD(TD_NUM_5, register_code(KC_LSFT), unregister_code(KC_LSFT))
TDF_TAP(TD_NUM_6, tap_code(KC_6))
TDF_HOLD(TD_NUM_6, register_code(KC_LCTL), unregister_code(KC_LCTL))
TDF_TAP(TD_NUM_DOT, tap_code(KC_DOT))
TDF_HOLD(TD_NUM_DOT, register_code(KC_LGUI), unregister_code(KC_LGUI))
TDF_DTAP(TD_NUM_DOT, tap_code(KC_COMM))

TDF_TAP(TD_F15, tap_code16(KC_F15);)
TDF_HOLD(TD_F15, register_code(KC_LGUI), unregister_code(KC_LGUI))
TDF_TAP(TD_F4, tap_code16(KC_F4);)
TDF_HOLD(TD_F4, register_code(KC_LCTL), unregister_code(KC_LCTL))
TDF_TAP(TD_F5, tap_code16(KC_F5);)
TDF_HOLD(TD_F5, register_code(KC_LSFT), unregister_code(KC_LSFT))
TDF_TAP(TD_F6, tap_code16(KC_F6);)
TDF_HOLD(TD_F6, register_code(KC_LALT), unregister_code(KC_LALT))

// SYMBOLIC
TDF_TAP(TD_SYMB_SLASH, tap_code16(DK_SLSH))
TDF_HOLD(TD_SYMB_SLASH, register_code16(DK_BSLS), unregister_code16(DK_BSLS))
TDF_TAPHOLD(TD_SYMB_SLASH, register_code16(DK_SLSH), unregister_code16(DK_SLSH))

TDF_TAP(TD_SYMB_BACKTICK, tap_code16(DK_GRV))
TDF_HOLD(TD_SYMB_BACKTICK, register_code16(DK_ACUT), unregister_code16(DK_ACUT))
TDF_TAPHOLD(TD_SYMB_BACKTICK, register_code16(DK_GRV), unregister_code16(DK_GRV))

TDF_TAP(TD_SYMB_HALF, { tap_code16(DK_HALF); })
TDF_DTAP(TD_SYMB_HALF, { tap_code16(DK_PND); })
TDF_HOLD(TD_SYMB_HALF, { tap_code16(ALGR(KC_E)); }, {})
TDF_TAPHOLD(TD_SYMB_HALF, { tap_code16(DK_SECT); }, {})

TDF_TAP(TD_SYMB_DELETE, tap_code16(C(KC_DEL)))
TDF_TAP(TD_SYMB_BACKSPACE, tap_code16(C(KC_BSPC)))

// NAVIGATION
TDF_TAP(TD_NAV_DELETE, SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(100) SS_TAP(X_DELETE)))
TDF_TAP(TD_NAV_BACKSPACE, SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(100) SS_TAP(X_BACKSPACE)))

TDF_TAP(TD_PAU_INS, tap_code16(KC_PAUSE))
TDF_DTAP(TD_PAU_INS, tap_code16(KC_INS))

TDF_TAP(TD_REFERENCE, tap_code16(C(S(KC_F10))))
TDF_DTAP(TD_REFERENCE, tap_code16(KC_F12))
TDF_HOLD(TD_REFERENCE, tap_code16(S(KC_F12)), {})
TDF_TAPHOLD(TD_REFERENCE, SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_F12)))), {})

TDF_TAP(TD_VSCODE_UP, {
    tap_code16(C(KC_J));
    tap_code16(KC_UP);
})
TDF_DTAP(TD_VSCODE_UP, {
    tap_code16(C(KC_K));
    tap_code16(KC_UP);
})
TDF_HOLD(TD_VSCODE_UP,
         {
             tap_code16(C(KC_J));
             tap_code16(A(C(KC_UP)));
         },
         {})

TDF_TAP(TD_VSCODE_DOWN, {
    tap_code16(C(KC_J));
    tap_code16(KC_DOWN);
})
TDF_DTAP(TD_VSCODE_DOWN, {
    tap_code16(C(KC_K));
    tap_code16(KC_DOWN);
})
TDF_HOLD(TD_VSCODE_DOWN,
         {
             tap_code16(C(KC_J));
             tap_code16(A(C(KC_DOWN)));
         },
         {})

TDF_TAP(TD_VSCODE_LEFT, {
    tap_code16(C(KC_J));
    tap_code16(KC_LEFT);
})
TDF_DTAP(TD_VSCODE_LEFT, {
    tap_code16(C(KC_K));
    tap_code16(KC_LEFT);
})
TDF_HOLD(TD_VSCODE_LEFT,
         {
             tap_code16(C(KC_J));
             tap_code16(A(C(KC_LEFT)));
         },
         {})

TDF_TAP(TD_VSCODE_RIGHT, {
    tap_code16(C(KC_J));
    tap_code16(KC_RIGHT);
})
TDF_DTAP(TD_VSCODE_RIGHT, {
    tap_code16(C(KC_K));
    tap_code16(KC_RIGHT);
})
TDF_HOLD(TD_VSCODE_RIGHT,
         {
             tap_code16(C(KC_J));
             tap_code16(A(C(KC_RIGHT)));
         },
         {})

TDF_TAP(TD_VSCODE_TERMINAL, {
    tap_code16(C(KC_J));
    tap_code16(KC_HOME);
})
TDF_DTAP(TD_VSCODE_TERMINAL, { tap_code16(C(DK_AE)); })
TDF_HOLD(TD_VSCODE_TERMINAL,
         {
             tap_code16(C(KC_K));
             tap_code16(C(KC_H));
         },
         {})

TDF_TAP(TD_VSCODE_BREAD, tap_code16(C(S(KC_DOT))))

TDF_TAP(TD_NAVI_VSCODE, tap_code(KC_APP))
TDF_HOLD(TD_NAVI_VSCODE, layer_on(VSCODE), layer_off(VSCODE))

TDF_HOLD(TD_NAVI_MOUSE, layer_on(MOUSE), layer_off(MOUSE))
TDF_TAPHOLD(TD_NAVI_MOUSE, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_MOUSE_1, tap_code(KC_BTN2))
TDF_HOLD(TD_MOUSE_1, register_code(KC_ACL0), unregister_code(KC_ACL0))
TDF_TAP(TD_MOUSE_2, tap_code(KC_BTN3))
TDF_HOLD(TD_MOUSE_2, register_code(KC_ACL1), unregister_code(KC_ACL1))
TDF_TAP(TD_MOUSE_3, tap_code(KC_BTN1))
TDF_HOLD(TD_MOUSE_3, register_code(KC_ACL2), unregister_code(KC_ACL2))

TDF_TAP(TD_KVM_SWITCH, { SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "1"); })
TDF_DTAP(TD_KVM_SWITCH, { SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "2"); })

TDF_TAP(TD_AUDIO_PLAY, { tap_code16(KC_MPLY); })
TDF_HOLD(TD_AUDIO_PLAY, { tap_code16(KC_MUTE); }, {})

TDF_TAP(TD_PRINTSCREEN, { tap_code16(KC_PSCR); })
TDF_DTAP(TD_PRINTSCREEN, { tap_code16(A(KC_PSCR)); })
TDF_HOLD(TD_PRINTSCREEN, { tap_code16(G(KC_PSCR)); }, {})
TDF_TAPHOLD(TD_PRINTSCREEN, { tap_code16(G(S(KC_PSCR))); }, {})

TDF_TAP(TD_BACK_META, { tap_code16(C(KC_SLSH)); })
TDF_HOLD(TD_BACK_META, register_code16(KC_LGUI), unregister_code16(KC_LGUI))

TDF_TAP(TD_PREV_REF, { tap_code16(S(KC_F7)); })
TDF_DTAP(TD_PREV_REF, { tap_code16(C(S(KC_J))); })
TDF_HOLD(TD_PREV_REF, register_code16(KC_LCTL), unregister_code16(KC_LCTL))

TDF_TAP(TD_FOLD, {
    tap_code16(C(KC_K));
    tap_code16(C(KC_L));
})
TDF_DTAP(TD_FOLD, { tap_code16(A(C(S(KC_K)))); })
TDF_HOLD(TD_FOLD, register_code16(KC_LSFT), unregister_code16(KC_LSFT))

TDF_TAP(TD_NEXT_REF, { tap_code16(KC_F7); })
TDF_DTAP(TD_NEXT_REF, { tap_code16(C(S(KC_L))); })
TDF_HOLD(TD_NEXT_REF, register_code16(KC_LALT), unregister_code16(KC_LALT))

TDF_DTAP(TD_NAVI_RT2, { tap_code16(C(KC_DOT)); })
TDF_TAP(TD_NAVI_RT2, { tap_code16(C(KC_SPC)); })

TDF_TAP(TD_NAVI_COPY, { tap_code16(C(KC_C)); })
TDF_HOLD(TD_NAVI_COPY, register_code16(KC_LSFT), unregister_code16(KC_LSFT))

TDF_TAP(TD_NAVI_CUT, { tap_code16(C(KC_X)); })
TDF_HOLD(TD_NAVI_CUT, register_code16(KC_LCTL), unregister_code16(KC_LCTL))

TDF_TAP(TD_NAVI_PASTE, { tap_code16(C(KC_V)); })
TDF_DTAP(TD_NAVI_PASTE, { tap_code16(C(KC_D)); })
TDF_HOLD(TD_NAVI_PASTE, register_code16(KC_LALT), unregister_code16(KC_LALT))

TDF_TAP(TD_NAVI_UNDO, tap_code16(C(KC_Z)))
TDF_HOLD(TD_NAVI_UNDO, register_code16(KC_LGUI), unregister_code16(KC_LGUI))

TDF_TAP(TD_UTIL_BACK_TO_BASICS, {
    // caps_word_off();
    unregister_code(KC_LCTL);
    unregister_code(KC_LSFT);
    unregister_code(KC_LALT);
    unregister_code(KC_LGUI);
    clear_mods();
    clear_weak_mods();
    layer_move(COLE);
})

tap_dance_action_t tap_dance_actions[] = {
    // GENERAL
    TDA_TAP_HOLD(TD_LT1),
    TDA_TAP(TD_LT2),
    TDA_TAP_HOLD(TD_LT3),
    TDA_TAP_HOLD(TD_LT4),
    TDA_TAP_HOLD_TAPHOLD(TD_LT5),

    TDA_TAP_HOLD(TD_RT1),
    TDA_TAP(TD_RT2),
    TDA_TAP_HOLD(TD_RT3),
    TDA_TAP_HOLD(TD_RT4),
    TDA_TAP_HOLD_TAPHOLD(TD_RT5),

    TDA_TAP_HOLD_TAPHOLD(TD_DELETE),
    TDA_TAP_HOLD_TAPHOLD(TD_BACKSPACE),

    // COLEMAK
    TDA_TAP_HOLD(TD_DOT),
    TDA_TAP_HOLD(TD_COMM),
    TDA_TAP_HOLD(TD_OSTR),

    // NUMBER
    TDA_TAP_HOLD(TD_F4),
    TDA_TAP_HOLD(TD_F5),
    TDA_TAP_HOLD(TD_F6),
    TDA_TAP_HOLD(TD_F15),

    TDA_TAP_HOLD(TD_NUM_4),
    TDA_TAP_HOLD(TD_NUM_5),
    TDA_TAP_HOLD(TD_NUM_6),
    TDA_TAP_HOLD_DTAP(TD_NUM_DOT),

    // SYMBOLIC
    TDA_TAP_HOLD_TAPHOLD(TD_SYMB_SLASH),
    TDA_TAP_HOLD_TAPHOLD(TD_SYMB_BACKTICK),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_SYMB_HALF),
    TDA_TAP(TD_SYMB_DELETE),
    TDA_TAP(TD_SYMB_BACKSPACE),

    // NAVIGATION
    TDA_TAP(TD_NAV_DELETE),
    TDA_TAP(TD_NAV_BACKSPACE),
    TDA_TAP_DTAP(TD_NAVI_RT2),
    TDA_TAP_HOLD(TD_BACK_META),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_REFERENCE),
    TDA_TAP_HOLD_DTAP(TD_PREV_REF),
    TDA_TAP_HOLD_DTAP(TD_NEXT_REF),
    TDA_TAP_HOLD_DTAP(TD_FOLD),
    TDA_TAP_HOLD(TD_NAVI_VSCODE),
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

    // MOUSE
    TDA_TAP_HOLD(TD_MOUSE_1),
    TDA_TAP_HOLD(TD_MOUSE_2),
    TDA_TAP_HOLD(TD_MOUSE_3),

    TDA_TAP(TD_UTIL_BACK_TO_BASICS),

    TDA_TAP_DTAP(TD_PAU_INS),
    TDA_HOLD_TAPHOLD(TD_NAVI_MOUSE),
    TDA_TAP_DTAP(TD_KVM_SWITCH),
    TDA_TAP_HOLD(TD_AUDIO_PLAY),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_PRINTSCREEN),
};
