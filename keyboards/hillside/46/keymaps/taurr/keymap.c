#include QMK_KEYBOARD_H
#include "sendstring_danish.h"
#include "action_util.h"


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

    TD_LP1,
    TD_RP1,

    // NUMBER
    TD_NUM_DOT,
    TD_F1,
    TD_F2,
    TD_F3,
    TD_F4,
    TD_F5,
    TD_F6,
    TD_F7,
    TD_F8,
    TD_F9,
    TD_F10,
    TD_F11,
    TD_F12,
    TD_F14,
    TD_F15,
    TD_F16,
    TD_F17,
    TD_F18,
    TD_NUM_RT2,
    TD_NUM_RT3,

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

#define UK_LP1  TD(TD_LP1)
#define UK_RP1  TD(TD_RP1)

#define UK_DEL  TD(TD_DELETE)
#define UK_BSPC TD(TD_BACKSPACE)

#define UK_PRN  TD(TD_PRINTSCREEN)

/*
Number Tap-Dance
*/
#define NUM_F01 TD(TD_F1)
#define NUM_F02 TD(TD_F2)
#define NUM_F03 TD(TD_F3)
#define NUM_F04 TD(TD_F4)
#define NUM_F05 TD(TD_F5)
#define NUM_F06 TD(TD_F6)
#define NUM_F07 TD(TD_F7)
#define NUM_F08 TD(TD_F8)
#define NUM_F09 TD(TD_F9)
#define NUM_F10 TD(TD_F10)
#define NUM_F11 TD(TD_F11)
#define NUM_F12 TD(TD_F12)
#define NUM_F14 TD(TD_F14)
#define NUM_F15 TD(TD_F15)
#define NUM_F16 TD(TD_F16)
#define NUM_F17 TD(TD_F17)
#define NUM_F18 TD(TD_F18)
#define NUM_DOT TD(TD_NUM_DOT)
#define NUM_RT2 TD(TD_NUM_RT2)
#define NUM_RT3 TD(TD_NUM_RT3)

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
#define SYM_LT1 TD(TD_SYMB_LT1)
#define SYM_RT1 TD(TD_SYMB_RT1)
#define SYM_LT4 TD(TD_SYMB_LT4)
#define SYM_RT4 TD(TD_SYMB_RT4)
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
        UK_DEL, KC_Q, KC_W, KC_F, KC_P, KC_B,                                              KC_J, KC_L, KC_U,    KC_Y,   DK_ARNG, UK_BSPC,
        DK_QUES,KC_A, KC_R, KC_S, KC_T, KC_G,                                              KC_M, KC_N, KC_E,    KC_I,   KC_O,    DK_OSTR,
        UK_LP1, KC_Z, KC_X, KC_C, KC_D, KC_V,      UK_LT1,                     UK_RT1,     KC_K, KC_H, KC_COMM, KC_DOT, DK_MINS, UK_RP1,
                                    UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, UK_RT4, UK_RT3, UK_RT2
    ),
	[NUMB] = LAYOUT(
        UK_DEL, NUM_F16, NUM_F07, NUM_F08, NUM_F09, NUM_F12,                                              KC_SCRL, KC_7, KC_8, KC_9, KC_NO, UK_BSPC,
        NUM_F18, NUM_F15, NUM_F04, NUM_F05, NUM_F06, NUM_F11,                                             KC_0,    KC_4, KC_5, KC_6, NUM_DOT, KC_NO,
        NUM_F17, NUM_F14, NUM_F01, NUM_F02, NUM_F03, NUM_F10,     UK_LT1,                     UK_RT1,     KC_NO,   KC_1, KC_2, KC_3, S(DK_MINS), KC_NO,
                                                  UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, UK_RT4, NUM_RT3, NUM_RT2
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
        UK_DEL, KC_NO, RGB_VAI, RGB_HUI, RGB_SPI, RGB_TOG,                                                KC_NO  , KC_WH_L, KC_MS_U, KC_WH_R, KC_NO  , UK_BSPC,
        KC_NO , KC_NO, MS_BT1,  MS_BT2,  MS_BT3,  RGB_M_P,                                                KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_NO,
        KC_NO , KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, RGB_M_R,        UK_LT1,                     UK_RT1,     KC_NO  , KC_WH_U, KC_MS_D, KC_WH_D, KC_NO  , KC_NO,
                                                UK_LT2, UK_LT3, UK_LT4, UK_LT5,     UK_RT5, UK_RT4, UK_RT3, UK_RT2
    ),
	[SYMB] = LAYOUT(
        SYM_DEL,   KC_NO,   DK_EXLM, DK_LCBR, DK_RCBR, DK_DIAE,                                               DK_QUOT, DK_ASTR, SYM_SLS, KC_NO,   KC_NO, SYM_BSP,
        SYM_HLF, DK_HASH, DK_AMPR, DK_LABK, DK_RABK, DK_TILD,                                               DK_DQUO, DK_LPRN, DK_RPRN, DK_EQL,  DK_PERC, DK_MICR,
        KC_NO,   DK_AT,   DK_DLR,  DK_LBRC, DK_RBRC, DK_CIRC,       SYM_LT1,                     SYM_RT1,   SYM_TCK, DK_PLUS, DK_MINS, KC_NO,   KC_NO,   KC_NO,
                                                    UK_LT2, UK_LT3, SYM_LT4, UK_LT5,     UK_RT5, SYM_RT4, UK_RT3, UK_RT2
    ),
	[UTIL] = LAYOUT(
        KC_SLEP, A(KC_F4), C(KC_W),DM_REC1, DM_REC2, KC_NO,                                                         KC_BRIU, KC_BRID, KC_VOLU, KC_NO  , KC_NO  , KC_NO,
        UTI_MON, KC_NO, KC_CALC, DM_PLY1, DM_PLY2, KC_NO,                                                           UK_PRN , KC_MPRV, KC_VOLD, KC_MNXT, AC_TOGG, AS_TOGG,
        KC_NO,   KC_NO, C(G(KC_UP)), KC_NO, C(G(KC_DOWN)),KC_NO,      UTI_RES,                           UTI_RES,   KC_NO, C(G(KC_LEFT)), UTI_PLY, C(G(KC_RIGHT)), KC_NO, QK_BOOT,
                                                    UK_LT2, TO(NUMB), TO(SYMB), TO(NAVI),     TO(MOUSE), TO(SYMB), TO(NUMB), UK_RT2
    ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
    // TODO: simplify this method if possible
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
TDF_TAPHOLD(
    TD_LT1,
    {
        register_code(KC_LALT);
        register_code(KC_LCTL);
    },
    {
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
    })

TDF_TAPHOLD(TD_LT2, register_code(KC_LSFT), unregister_code(KC_LSFT))

TDF_TAP(TD_LT3, tap_code(KC_TAB))
TDF_HOLD(TD_LT3, layer_on(NUMB), layer_off(NUMB))
TDF_TAPHOLD(TD_LT3, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_LT4, tap_code(KC_SPC))
TDF_HOLD(TD_LT4, layer_on(SYMB), layer_off(SYMB))
TDF_TAPHOLD(TD_LT4, register_code(KC_LCTL), unregister_code(KC_LCTL))

TDF_TAP(TD_LT5, tap_code(KC_ESC))
TDF_HOLD(TD_LT5, layer_on(NAVI), layer_off(NAVI))
TDF_TAPHOLD(TD_LT5, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_RT1, tap_code(KC_ENTER))
TDF_HOLD(TD_RT1, layer_on(UTIL), layer_off(UTIL))
TDF_TAPHOLD(
    TD_RT1,
    {
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_LGUI);
    },
    {
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
    })

TDF_TAPHOLD(TD_RT2, register_code(KC_LSFT), unregister_code(KC_LSFT) )

TDF_TAP(TD_RT3, tap_code(KC_TAB))
TDF_HOLD(TD_RT3, layer_on(NUMB), layer_off(NUMB))
TDF_TAPHOLD(TD_RT3, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_RT4, tap_code(KC_SPC))
TDF_HOLD(TD_RT4, layer_on(SYMB), layer_off(SYMB))
TDF_TAPHOLD(TD_RT4, register_code(KC_LCTL), unregister_code(KC_LCTL))

TDF_TAP(TD_RT5, tap_code(KC_ESC))
TDF_HOLD(TD_RT5, layer_on(NAVI), layer_off(NAVI))
TDF_TAPHOLD(TD_RT5, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_DELETE, tap_code(KC_DEL))
TDF_HOLD(TD_DELETE, tap_code16(A(KC_DEL)), {})

TDF_TAP(TD_BACKSPACE, tap_code(KC_BSPC) )
TDF_HOLD(TD_BACKSPACE, tap_code16(A(KC_BSPC)), {})

TDF_TAP(TD_LP1, tap_code16(DK_PIPE))
TDF_TAPHOLD(TD_LP1, register_code(KC_LGUI), unregister_code(KC_LGUI))

TDF_TAP(TD_RP1, tap_code16(DK_AE))
TDF_HOLD(TD_RP1, tap_code16(S(DK_AE)), {})
TDF_TAPHOLD(TD_RP1, register_code(KC_LGUI), unregister_code(KC_LGUI))

// NUMBER
TDF_TAP(TD_NUM_RT2, tap_code(KC_0))
TDF_TAPHOLD(TD_NUM_RT2, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_NUM_RT3, tap_code(KC_0))
TDF_TAPHOLD(TD_NUM_RT3, register_code(KC_LSFT), unregister_code(KC_LSFT) )

TDF_TAP(TD_NUM_DOT, tap_code(KC_DOT))
TDF_DTAP(TD_NUM_DOT, tap_code(KC_COMM))
#define TDF_FX(FN) \
    TDF_TAP(TD_ ## FN, tap_code16(KC_ ## FN); ) \
    TDF_DTAP(TD_ ## FN, tap_code16(C(KC_ ## FN)); ) \
    TDF_HOLD(TD_ ## FN, tap_code16(S(KC_ ## FN));, {}) \
    TDF_TAPHOLD(TD_ ## FN, tap_code16(C(S(KC_ ## FN)));, {})
TDF_FX(F1) TDF_FX(F2) TDF_FX(F3) TDF_FX(F4) TDF_FX(F5) TDF_FX(F6) TDF_FX(F7) TDF_FX(F8)
TDF_FX(F9) TDF_FX(F10) TDF_FX(F11) TDF_FX(F12) TDF_FX(F14) TDF_FX(F15) TDF_FX(F16) TDF_FX(F17) TDF_FX(F18)

// SYMBOLIC
TDF_TAP(TD_SYMB_LT1, tap_code16(C(S(KC_ENTER))))
TDF_HOLD(TD_SYMB_LT1, layer_on(UTIL), layer_off(UTIL))
TDF_TAP(TD_SYMB_RT1, tap_code16(C(KC_ENTER)))
TDF_HOLD(TD_SYMB_RT1, layer_on(UTIL), layer_off(UTIL))
TDF_TAP(TD_SYMB_LT4, tap_code16(C(KC_DOT)))
TDF_TAP(TD_SYMB_RT4, tap_code16(C(KC_SPC)))

TDF_TAP(TD_SYMB_SLASH, tap_code16(DK_SLSH))
TDF_HOLD(TD_SYMB_SLASH, register_code16(DK_BSLS), unregister_code16(DK_BSLS))
TDF_TAPHOLD(TD_SYMB_SLASH, register_code16(DK_SLSH), unregister_code16(DK_SLSH))

TDF_TAP(TD_SYMB_BACKTICK, tap_code16(DK_GRV))
TDF_HOLD(TD_SYMB_BACKTICK, register_code16(DK_ACUT), unregister_code16(DK_ACUT))
TDF_TAPHOLD(TD_SYMB_BACKTICK, register_code16(DK_GRV), unregister_code16(DK_GRV))

TDF_TAP(TD_SYMB_HALF, { tap_code16(DK_HALF); } )
TDF_DTAP(TD_SYMB_HALF, { tap_code16(DK_PND); } )
TDF_HOLD(TD_SYMB_HALF, { tap_code16(ALGR(KC_E)); }, {} )
TDF_TAPHOLD(TD_SYMB_HALF, { tap_code16(DK_SECT); }, {} )

TDF_TAP(TD_SYMB_DELETE, tap_code16(C(KC_DEL)))
TDF_TAP(TD_SYMB_BACKSPACE, tap_code16(C(KC_BSPC)))

// NAVIGATION
TDF_TAP(TD_NAV_DELETE, SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(100) SS_TAP(X_DELETE)))
TDF_TAP(TD_NAV_BACKSPACE, SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(100) SS_TAP(X_BACKSPACE)))

TDF_TAP(TD_PAU_INS, tap_code16(KC_PAUSE))
TDF_DTAP(TD_PAU_INS, tap_code16(KC_INS))

TDF_TAP(TD_REFERENCE, tap_code16(C(S(KC_F10))) )
TDF_DTAP(TD_REFERENCE, tap_code16(KC_F12) )
TDF_HOLD(TD_REFERENCE, tap_code16(S(KC_F12)), {} )
TDF_TAPHOLD(TD_REFERENCE, SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_F12)))), {} )

TDF_TAP(TD_VSCODE_UP, { tap_code16(C(KC_J)); tap_code16(KC_UP); } )
TDF_DTAP(TD_VSCODE_UP, { tap_code16(C(KC_K)); tap_code16(KC_UP); } )
TDF_HOLD(TD_VSCODE_UP, { tap_code16(C(KC_J)); tap_code16(A(C(KC_UP))); }, {} )

TDF_TAP(TD_VSCODE_DOWN, { tap_code16(C(KC_J)); tap_code16(KC_DOWN); } )
TDF_DTAP(TD_VSCODE_DOWN, { tap_code16(C(KC_K)); tap_code16(KC_DOWN); } )
TDF_HOLD(TD_VSCODE_DOWN, { tap_code16(C(KC_J)); tap_code16(A(C(KC_DOWN))); }, {} )

TDF_TAP(TD_VSCODE_LEFT, { tap_code16(C(KC_J)); tap_code16(KC_LEFT); } )
TDF_DTAP(TD_VSCODE_LEFT, { tap_code16(C(KC_K)); tap_code16(KC_LEFT); } )
TDF_HOLD(TD_VSCODE_LEFT, { tap_code16(C(KC_J)); tap_code16(A(C(KC_LEFT))); }, {} )

TDF_TAP(TD_VSCODE_RIGHT, { tap_code16(C(KC_J)); tap_code16(KC_RIGHT); } )
TDF_DTAP(TD_VSCODE_RIGHT, { tap_code16(C(KC_K)); tap_code16(KC_RIGHT); } )
TDF_HOLD(TD_VSCODE_RIGHT, { tap_code16(C(KC_J)); tap_code16(A(C(KC_RIGHT))); }, {} )

TDF_TAP(TD_VSCODE_TERMINAL, { tap_code16(C(KC_J));tap_code16(KC_HOME); } )
TDF_DTAP(TD_VSCODE_TERMINAL, { tap_code16(C(DK_AE)); } )
TDF_HOLD(TD_VSCODE_TERMINAL, { tap_code16(C(KC_K)); tap_code16(C(KC_H)); }, {} )

TDF_TAP(TD_VSCODE_BREAD, tap_code16(C(S(KC_DOT))) )

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

TDF_TAP(TD_KVM_SWITCH, { SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "1"); } )
TDF_DTAP(TD_KVM_SWITCH, { SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "2"); } )

TDF_TAP(TD_AUDIO_PLAY, { tap_code16(KC_MPLY); } )
TDF_HOLD(TD_AUDIO_PLAY, { tap_code16(KC_MUTE); }, {})

TDF_TAP(TD_PRINTSCREEN, { tap_code16(KC_PSCR); } )
TDF_DTAP(TD_PRINTSCREEN, { tap_code16(A(KC_PSCR)); } )
TDF_HOLD(TD_PRINTSCREEN, { tap_code16(G(KC_PSCR)); }, {} )
TDF_TAPHOLD(TD_PRINTSCREEN, { tap_code16(G(S(KC_PSCR))); }, {} )

TDF_TAP(TD_BACK_META, { tap_code16(C(KC_SLSH)); } )
TDF_HOLD(TD_BACK_META, register_code16(KC_LGUI), unregister_code16(KC_LGUI))

TDF_TAP(TD_PREV_REF, { tap_code16(S(KC_F7)); } )
TDF_DTAP(TD_PREV_REF, { tap_code16(C(S(KC_J))); } )
TDF_HOLD(TD_PREV_REF, register_code16(KC_LCTL), unregister_code16(KC_LCTL))

TDF_TAP(TD_FOLD, { tap_code16(C(KC_K)); tap_code16(C(KC_L)); } )
TDF_DTAP(TD_FOLD, { tap_code16(A(C(S(KC_K)))); } )
TDF_HOLD(TD_FOLD, register_code16(KC_LSFT), unregister_code16(KC_LSFT))

TDF_TAP(TD_NEXT_REF, { tap_code16(KC_F7); } )
TDF_DTAP(TD_NEXT_REF, { tap_code16(C(S(KC_L))); } )
TDF_HOLD(TD_NEXT_REF, register_code16(KC_LALT), unregister_code16(KC_LALT))

TDF_DTAP(TD_NAVI_RT2, { tap_code16(C(KC_DOT)); } )
TDF_TAP(TD_NAVI_RT2, { tap_code16(C(KC_SPC)); } )

TDF_TAP(TD_NAVI_COPY, { tap_code16(C(KC_C)); } )
TDF_HOLD(TD_NAVI_COPY, register_code16(KC_LSFT), unregister_code16(KC_LSFT))

TDF_TAP(TD_NAVI_CUT, { tap_code16(C(KC_X)); } )
TDF_HOLD(TD_NAVI_CUT, register_code16(KC_LCTL), unregister_code16(KC_LCTL))

TDF_TAP(TD_NAVI_PASTE, { tap_code16(C(KC_V)); } )
TDF_DTAP(TD_NAVI_PASTE, { tap_code16(C(KC_D)); } )
TDF_HOLD(TD_NAVI_PASTE, register_code16(KC_LALT), unregister_code16(KC_LALT))

TDF_TAP(TD_NAVI_UNDO, tap_code16(C(KC_Z)))
TDF_HOLD(TD_NAVI_UNDO, register_code16(KC_LGUI), unregister_code16(KC_LGUI))

TDF_TAP(TD_UTIL_BACK_TO_BASICS, {
    caps_word_off();
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
    TDA_TAP_HOLD_TAPHOLD(TD_LT1),
    TDA_TAPHOLD(TD_LT2),
    TDA_TAP_HOLD_TAPHOLD(TD_LT3),
    TDA_TAP_HOLD_TAPHOLD(TD_LT4),
    TDA_TAP_HOLD_TAPHOLD(TD_LT5),
    TDA_TAP_HOLD_TAPHOLD(TD_RT1),
    TDA_TAPHOLD(TD_RT2),
    TDA_TAP_HOLD_TAPHOLD(TD_RT3),
    TDA_TAP_HOLD_TAPHOLD(TD_RT4),
    TDA_TAP_HOLD_TAPHOLD(TD_RT5),

    TDA_TAP_HOLD(TD_DELETE),
    TDA_TAP_HOLD(TD_BACKSPACE),

    TDA_TAP_TAPHOLD(TD_LP1),
    TDA_TAP_HOLD_TAPHOLD(TD_RP1),

    // NUMBER
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
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F17),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_F18),
    TDA_TAP_DTAP(TD_NUM_DOT),
    TDA_TAP_TAPHOLD(TD_NUM_RT2),
    TDA_TAP_TAPHOLD(TD_NUM_RT3),

    // SYMBOLIC
    TDA_TAP_HOLD(TD_SYMB_LT1),
    TDA_TAP_HOLD(TD_SYMB_RT1),
    TDA_TAP(TD_SYMB_LT4),
    TDA_TAP(TD_SYMB_RT4),
    TDA_TAP_HOLD_TAPHOLD(TD_SYMB_SLASH),
    TDA_TAP_HOLD_TAPHOLD(TD_SYMB_BACKTICK),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_SYMB_HALF),
    TDA_TAP(TD_SYMB_DELETE),
    TDA_TAP(TD_SYMB_BACKSPACE),

    // NAVIGATION
    TDA_TAP(TD_NAV_DELETE),
    TDA_TAP(TD_NAV_BACKSPACE),

    // MOUSE
    TDA_TAP_HOLD(TD_MOUSE_1),
    TDA_TAP_HOLD(TD_MOUSE_2),
    TDA_TAP_HOLD(TD_MOUSE_3),


    TDA_TAP(TD_UTIL_BACK_TO_BASICS),

    TDA_TAP_DTAP(TD_NAVI_RT2),
    TDA_TAP_DTAP(TD_PAU_INS),
    TDA_TAP_HOLD(TD_BACK_META),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_REFERENCE),
    TDA_TAP_HOLD_DTAP(TD_PREV_REF),
    TDA_TAP_HOLD_DTAP(TD_NEXT_REF),
    TDA_TAP_HOLD_DTAP(TD_FOLD),
    TDA_TAP_HOLD(TD_NAVI_VSCODE),
    TDA_HOLD_TAPHOLD(TD_NAVI_MOUSE),
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
