#include QMK_KEYBOARD_H
#include "sendstring_danish.h"
#include "action_util.h"

bool _caps_word_active = false;

enum layers {
    BASE,
    SYM,
    NAV,
    NAV2,
    MOUSE,
    NUMERIC,
    NUM,
    UTIL,
    LAYERS,
};

/*
 Tap-Dance key codes
 */
enum {
    TD_BASE_11,
    TD_BASE_13,
    TD_BASE_23,
    TD_BASE_24,
    TD_BASE_25,
    TD_BASE_26,
    TD_BASE_27,
    TD_BASE_28,
    TD_BASE_29,
    TD_BASE_31,
    TD_BASE_32,
    TD_BASE_34,
    TD_BASE_35,
    TD_BASE_36,
    TD_BASE_37,
    TD_BASE_38,
    TD_BASE_39,
    TD_BASE_40,
    TD_BASE_41,
    TD_BASE_42,
    TD_BASE_43,
    TD_BASE_44,
    TD_BASE_45,
    TD_BASE_46,

    TD_NUMERIC_26,
    TD_NUMERIC_27,
    TD_NUMERIC_28,
    TD_NUMERIC_29,
    TD_NUMERIC_34,
    TD_NUMERIC_35,
    TD_NUMERIC_36,
    TD_NUMERIC_37,

    TD_NUM_2,
    TD_NUM_3,
    TD_NUM_4,
    TD_NUM_5,
    TD_NUM_6,
    TD_NUM_7,
    TD_NUM_8,
    TD_NUM_9,
    TD_NUM_10,
    TD_NUM_11,
    TD_NUM_26,
    TD_NUM_27,
    TD_NUM_28,
    TD_NUM_29,
    TD_NUM_34,
    TD_NUM_35,
    TD_NUM_36,
    TD_NUM_37,

    TD_SYM_9,
    TD_SYM_13,
    TD_SYM_26,
    TD_SYM_27,
    TD_SYM_28,
    TD_SYM_29,
    TD_SYM_33,
    TD_SYM_34,
    TD_SYM_35,
    TD_SYM_36,
    TD_SYM_37,
    TD_SYM_41,

    TD_NAV_1,
    TD_NAV_7,
    TD_NAV_12,
    TD_NAV_14,
    TD_NAV_15,
    TD_NAV_16,
    TD_NAV_17,
    TD_NAV_18,
    TD_NAV_19,
    TD_NAV_26,
    TD_NAV_27,
    TD_NAV_28,
    TD_NAV_29,
    TD_NAV_33,
    TD_NAV_34,
    TD_NAV_35,
    TD_NAV_36,
    TD_NAV_37,
    TD_NAV_44,

    TD_NAV2_20,
    TD_NAV2_21,
    TD_NAV2_22,
    TD_NAV2_23,
    TD_NAV2_26,
    TD_NAV2_27,
    TD_NAV2_28,
    TD_NAV2_29,
    TD_NAV2_34,
    TD_NAV2_35,
    TD_NAV2_36,
    TD_NAV2_37,

    TD_MOUSE_26,
    TD_MOUSE_27,
    TD_MOUSE_28,
    TD_MOUSE_29,
    TD_MOUSE_34,
    TD_MOUSE_35,
    TD_MOUSE_36,
    TD_MOUSE_37,

    TD_UTIL_13,
    TD_UTIL_BACK_TO_BASICS,
    TD_UTIL_35,
};

#define BASE_11     TD(TD_BASE_11)
#define BASE_13     TD(TD_BASE_13)
#define BASE_23     TD(TD_BASE_23)
#define BASE_24     TD(TD_BASE_24)
#define BASE_25     TD(TD_BASE_25)
//#define BASE_26     MT(MOD_LGUI, KC_Z)
#define BASE_26     TD(TD_BASE_26)  // z + win
//#define BASE_27     MT(MOD_LCTL, KC_X)
#define BASE_27     TD(TD_BASE_27)  // x + ctrl
//#define BASE_28     MT(MOD_LSFT, KC_C)
#define BASE_28     TD(TD_BASE_28)  // c + shift
//#define BASE_29     MT(MOD_LALT, KC_D)
#define BASE_29     TD(TD_BASE_29)  // d + alt
#define BASE_31     TD(TD_BASE_31)
#define BASE_32     TD(TD_BASE_32)
//#define BASE_34     MT(MOD_LALT, KC_H)
#define BASE_34     TD(TD_BASE_34)  // h + alt
//#define BASE_35     MT(MOD_RSFT, DK_COMM)
#define BASE_35     TD(TD_BASE_35)  // , + shift
//#define BASE_36     MT(MOD_RCTL, DK_DOT)
#define BASE_36     TD(TD_BASE_36)  // . + ctrl
//#define BASE_37     MT(MOD_RGUI, S(DK_MINS))
#define BASE_37     TD(TD_BASE_37)  // _ + win
#define BASE_38     TD(TD_BASE_38)
#define BASE_39     TD(TD_BASE_39)
#define BASE_40     TD(TD_BASE_40)
#define BASE_41     TD(TD_BASE_41)
#define BASE_42     TD(TD_BASE_42)
#define BASE_43     TD(TD_BASE_43)
#define BASE_44     TD(TD_BASE_44)
#define BASE_45     TD(TD_BASE_45)
#define BASE_46     TD(TD_BASE_46)

#define NUMERIC_26  TD(TD_NUMERIC_26)
#define NUMERIC_27  TD(TD_NUMERIC_27)
#define NUMERIC_28  TD(TD_NUMERIC_28)
#define NUMERIC_29  TD(TD_NUMERIC_29)
#define NUMERIC_34  TD(TD_NUMERIC_34)
#define NUMERIC_35  TD(TD_NUMERIC_35)
#define NUMERIC_36  TD(TD_NUMERIC_36)
#define NUMERIC_37  TD(TD_NUMERIC_37)

#define NUM_2       TD(TD_NUM_2)
#define NUM_3       TD(TD_NUM_3)
#define NUM_4       TD(TD_NUM_4)
#define NUM_5       TD(TD_NUM_5)
#define NUM_6       TD(TD_NUM_6)
#define NUM_7       TD(TD_NUM_7)
#define NUM_8       TD(TD_NUM_8)
#define NUM_9       TD(TD_NUM_9)
#define NUM_10      TD(TD_NUM_10)
#define NUM_11      TD(TD_NUM_11)
#define NUM_26      TD(TD_NUM_26)
#define NUM_27      TD(TD_NUM_27)
#define NUM_28      TD(TD_NUM_28)
#define NUM_29      TD(TD_NUM_29)
#define NUM_34      TD(TD_NUM_34)
#define NUM_35      TD(TD_NUM_35)
#define NUM_36      TD(TD_NUM_36)
#define NUM_37      TD(TD_NUM_37)

#define SYM_9       TD(TD_SYM_9)
#define SYM_13      TD(TD_SYM_13)
#define SYM_26      TD(TD_SYM_26)
#define SYM_27      TD(TD_SYM_27)
#define SYM_28      TD(TD_SYM_28)
#define SYM_29      TD(TD_SYM_29)
#define SYM_33      TD(TD_SYM_33)
#define SYM_34      TD(TD_SYM_34)
#define SYM_35      TD(TD_SYM_35)
#define SYM_36      TD(TD_SYM_36)
#define SYM_37      TD(TD_SYM_37)
#define SYM_41      TD(TD_SYM_41)

#define NAV_1       TD(TD_NAV_1)
#define NAV_7       TD(TD_NAV_7)
#define NAV_12      TD(TD_NAV_12)
#define NAV_14      TD(TD_NAV_14)
#define NAV_15      TD(TD_NAV_15)
#define NAV_16      TD(TD_NAV_16)
#define NAV_17      TD(TD_NAV_17)
#define NAV_18      TD(TD_NAV_18)
#define NAV_19      TD(TD_NAV_19)
#define NAV_26      TD(TD_NAV_26)
#define NAV_27      TD(TD_NAV_27)
#define NAV_28      TD(TD_NAV_28)
#define NAV_29      TD(TD_NAV_29)
#define NAV_33      TD(TD_NAV_33)
#define NAV_34      TD(TD_NAV_34)
#define NAV_35      TD(TD_NAV_35)
#define NAV_36      TD(TD_NAV_36)
#define NAV_37      TD(TD_NAV_37)
#define NAV_44     TD(TD_NAV_44)

#define NAV2_21     TD(TD_NAV2_20)
#define NAV2_22     TD(TD_NAV2_21)
#define NAV2_20     TD(TD_NAV2_22)
#define NAV2_23     TD(TD_NAV2_23)
#define NAV2_26     TD(TD_NAV2_26)
#define NAV2_27     TD(TD_NAV2_27)
#define NAV2_28     TD(TD_NAV2_28)
#define NAV2_29     TD(TD_NAV2_29)
#define NAV2_34     TD(TD_NAV2_34)
#define NAV2_35     TD(TD_NAV2_35)
#define NAV2_36     TD(TD_NAV2_36)
#define NAV2_37     TD(TD_NAV2_37)

#define MOUSE_26    TD(TD_MOUSE_26)
#define MOUSE_27    TD(TD_MOUSE_27)
#define MOUSE_28    TD(TD_MOUSE_28)
#define MOUSE_29    TD(TD_MOUSE_29)
#define MOUSE_34    TD(TD_MOUSE_34)
#define MOUSE_35    TD(TD_MOUSE_35)
#define MOUSE_36    TD(TD_MOUSE_36)
#define MOUSE_37    TD(TD_MOUSE_37)

#define UTIL_13     TD(TD_UTIL_13)
#define UTIL_35     TD(TD_UTIL_35)
#define RST_LAY     TD(TD_UTIL_BACK_TO_BASICS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
        KC_DEL,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                               KC_J, KC_L,    KC_U,    KC_Y,    BASE_11, KC_BSPC,
        BASE_13,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                               KC_M, KC_N,    KC_E,    KC_I,    BASE_23, BASE_24,
        BASE_25,  BASE_26, BASE_27, BASE_28, BASE_29, KC_V,     BASE_31,                       BASE_32,   KC_K, BASE_34, BASE_35, BASE_36, BASE_37, BASE_38,
                                            BASE_39, BASE_40, BASE_41, BASE_42,     BASE_43, BASE_44, BASE_45, BASE_46
    ),
	[SYM] = LAYOUT(
        KC_DEL, KC_NO, DK_EXLM, DK_LCBR, DK_RCBR, DK_DIAE,                                                 DK_QUOT, DK_ASTR, SYM_9, DK_PIPE, DK_QUES, KC_BSPC,
        SYM_13, DK_HASH, DK_AMPR, DK_LABK, DK_RABK, DK_TILD,                                               DK_DQUO, DK_LPRN, DK_RPRN, DK_EQL,  DK_PERC, DK_MICR,
        _______, SYM_26,   SYM_27,  SYM_28, SYM_29, DK_CIRC,    _______,                     _______,     SYM_33, SYM_34, SYM_35, SYM_36, SYM_37, _______,
                                               _______, _______, SYM_41, _______,   _______, _______, _______, _______
    ),
	[NAV] = LAYOUT(
    NAV_1,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                      NAV_7,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  NAV_12,
    KC_NO, NAV_14,  NAV_15,  NAV_16,  NAV_17,  NAV_18,                                               NAV_19, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO,
    _______, NAV_26,  NAV_27,  NAV_28,  NAV_29,  KC_NO,     _______,                    _______,     NAV_33, NAV_34,  NAV_35 , NAV_36 , NAV_37,  _______,
                                            _______,_______,_______,_______,    _______, NAV_44,_______,_______
    ),
	[NAV2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______, _______,
        _______, G(C(KC_LEFT)), G(C(KC_DOWN)), G(C(KC_UP)), G(C(KC_RGHT)), _______,                        _______, NAV2_20, NAV2_21, NAV2_22, NAV2_23, _______,
        _______, NAV2_26, NAV2_27, NAV2_28, NAV2_29, _______,    _______,                       _______,   _______, NAV2_34, NAV2_35, NAV2_36, NAV2_37, _______,
                                                _______, _______, _______, _______,     _______, _______, _______, _______
    ),
	[MOUSE] = LAYOUT(
        _______, _______,  KC_BTN6,  KC_BTN4,  KC_BTN5,  _______,                                              _______, KC_WH_L,  KC_WH_U, KC_WH_D,   KC_WH_R,  _______,
        _______, _______,  KC_BTN2,  KC_BTN3,  KC_BTN1,  _______,                                              _______, KC_MS_L,  KC_MS_D , KC_MS_U,  KC_MS_R,  _______,
        _______, MOUSE_26, MOUSE_27, MOUSE_28, MOUSE_29, _______,    _______,                       _______,   _______, MOUSE_34, MOUSE_35, MOUSE_36, MOUSE_37, _______,
                                                _______, KC_ACL2, KC_ACL0, KC_ACL1,     KC_ACL1, KC_ACL0, KC_ACL2, _______
    ),
	[NUMERIC] = LAYOUT(
        KC_DEL,  KC_F11, KC_F7, KC_F8, KC_F9, KC_F12,                                                   KC_NUM_LOCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_NO, KC_BSPC,
        KC_TAB,  KC_F10, KC_F4, KC_F5, KC_F6, KC_NO,                                                    KC_0,  KC_KP_4, KC_KP_5, KC_KP_6, KC_DOT, KC_COMM,
        _______, NUMERIC_26,  NUMERIC_27, NUMERIC_28, NUMERIC_29, KC_NO,  _______,          _______,  KC_NO, NUMERIC_34, NUMERIC_35, NUMERIC_36, NUMERIC_37, _______,
                                                    _______, _______, _______, _______,     _______, _______, _______, _______
    ),
	[NUM] = LAYOUT(
        KC_DEL, NUM_2,  NUM_3,  NUM_4,  NUM_5,  NUM_6,                                                 NUM_7,   NUM_8,  NUM_9,  NUM_10, NUM_11, KC_BSPC,
        KC_TAB,  KC_6,   KC_4,   KC_0,   KC_2,   KC_8,                                                  KC_9,    KC_3,   KC_1,   KC_5,   KC_7,   KC_NO,
        _______, NUM_26, NUM_27, NUM_28, NUM_29, KC_NO,     _______,                       _______,   KC_NO, NUM_34, NUM_35, NUM_36, NUM_37, _______,
                                            _______, _______, _______, _______,     _______, _______, _______, _______
    ),
	[UTIL] = LAYOUT(
        KC_SLEP, _______, _______, DM_REC1, DM_REC2, RGB_TOG,                                                   KC_SCRL, _______, _______, _______, _______, QK_BOOT,
        UTIL_13, _______, _______, DM_PLY1, DM_PLY2, RGB_M_R,                                                   _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
        _______, _______, _______, KC_CALC, _______, _______,   RST_LAY,                            RST_LAY,    _______, _______, UTIL_35, _______, _______, _______,
                                            _______, _______, _______, _______,     _______, _______, _______, _______
    ),
	[LAYERS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                                   _______, _______, _______, _______, _______, _______,
        RST_LAY, _______, _______, _______, _______, _______,   _______,                            _______,    _______, _______, _______, _______, _______, RST_LAY,
                                            TO(NUMERIC), TO(NUM), TO(NAV), TO(SYM),     TO(SYM), TO(MOUSE), TO(NUM), TO(NUMERIC)
    ),
};

bool caps_word_active(void)
{
    return _caps_word_active;
}
void caps_word_on(void)
{
    _caps_word_active = true;
    add_weak_mods(MOD_LSFT);
}
void caps_word_off(void)
{
    _caps_word_active = false;
    del_weak_mods(MOD_LSFT);
}
void caps_word_toggle(void)
{
    if (caps_word_active()) {
        caps_word_off();
    } else {
        caps_word_on();
    }
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    layer_state_set_user(layer_state);
}

bool ANY_KEY_PRESSED = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed) ANY_KEY_PRESSED = true;

    if (BASE == layer_state)
    {
        if (caps_word_active())
        {
            if (record->event.pressed) {
                switch(keycode) {
                    case KC_DEL:
                    case BASE_11:
                    case BASE_25:
                    case BASE_31:
                    case BASE_32:
                    case BASE_35:
                    case BASE_36:
                    case BASE_38:
                    case BASE_42:
                    case BASE_43:
                        caps_word_off();
                        return process_record_user(keycode, record);
                }

                add_weak_mods(MOD_LSFT);
            } else {
                del_weak_mods(MOD_LSFT);
            }
        }
    }
    return process_record_user(keycode, record);
}

extern rgblight_config_t rgblight_config;

static bool recording = false;

void default_led_light(void) {
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
}

void recording_led_light(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING);
}

bool dynamic_macro_valid_key_user(uint16_t keycode, keyrecord_t *record) {
    return !(keycode == BASE_24);
}

void dynamic_macro_record_start_user(int8_t direction) {
    recording = true;
    recording_led_light();
}

void dynamic_macro_record_end_user(int8_t direction) {
    recording = false;
    default_led_light();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case NUMERIC:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case NUM:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(240, 255, 255);
            break;
        case SYM:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case NAV:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(95, 255, 255);
            break;
        case NAV2:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case MOUSE:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_CHARTREUSE);
            break;
        case UTIL:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        case LAYERS:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
            break;
        default: //  for any other layers , or the default layer
            if (recording) {
                recording_led_light();
            }
            else {
                default_led_light();
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
    TD_DEFAULT = 1,         // causes the td_each(…) function to execute the single_tap action on each furthe keypress
    TD_SINGLE_TAP = 2,      // take the tap action
    TD_SINGLE_HOLD = 4,     // take the hold action
    TD_DOUBLE_TAP = 8,      // take the double tap action
    TD_TAP_HOLD = 16,    // take the tap-hold hold action
    TD_UNKNOWN = 128,       // a condition without an action nor a default_kc
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
    td_hold_action_t tap_hold;
    td_state_t state;
    bool interrupt_hold;
} td_tap_user_t;

// Initialization of the tap dance actions, using our custom functions
#define __TDA_DEFINITION__(KC, ihold, ST_ACTION_FN, SH_ACTION_FN, SH_RESET_FN, DT_ACTION_FN, DH_ACTION_FN, DH_RESET_FN) [KC] = { \
        .fn = { \
            td_each, \
            td_finished, \
            td_reset \
        }, \
        .user_data = &(td_tap_user_t){ \
            .interrupt_hold = ihold, \
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
            .tap_hold = { \
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
#define TDA_TAP(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, NULL, NULL, NULL, NULL, NULL)
#define TDA_HOLD(KC) __TDA_DEFINITION__(KC, true, NULL, KC ## _sh_action, KC ## _sh_reset, NULL, NULL, NULL)
#define TDA_TAP_HOLD(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, NULL, NULL, NULL)
#define TDA_DTAP(KC) __TDA_DEFINITION__(KC, true, NULL, NULL, NULL, KC ## _dt_action, NULL, NULL)
#define TDA_TAP_DTAP(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, NULL, NULL, KC ## _dt_action, NULL, NULL)
#define TDA_HOLD_DTAP(KC) __TDA_DEFINITION__(KC, true, NULL, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, NULL, NULL)
#define TDA_TAP_HOLD_DTAP(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, NULL, NULL)
#define TDA_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, NULL, NULL, NULL, NULL, KC ## _dh_action, KC ## _dh_reset)
#define TDA_TAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, NULL, NULL, NULL,  KC ## _dh_action, KC ## _dh_reset)
#define TDA_HOLD_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, NULL, KC ## _sh_action, KC ## _sh_reset, NULL,  KC ## _dh_action, KC ## _dh_reset)
#define TDA_TAP_HOLD_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, NULL, KC ## _dh_action, KC ## _dh_reset)
#define TDA_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, NULL, NULL, NULL, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)
#define TDA_TAP_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, NULL, NULL, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)
#define TDA_HOLD_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, NULL, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)
#define TDA_TAP_HOLD_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, true, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)

#define TDA_NOINTERRUPT_TAP(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, NULL, NULL, NULL, NULL, NULL)
#define TDA_NOINTERRUPT_HOLD(KC) __TDA_DEFINITION__(KC, false, NULL, KC ## _sh_action, KC ## _sh_reset, NULL, NULL, NULL)
#define TDA_NOINTERRUPT_TAP_HOLD(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, NULL, NULL, NULL)
#define TDA_NOINTERRUPT_DTAP(KC) __TDA_DEFINITION__(KC, false, NULL, NULL, NULL, KC ## _dt_action, NULL, NULL)
#define TDA_NOINTERRUPT_TAP_DTAP(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, NULL, NULL, KC ## _dt_action, NULL, NULL)
#define TDA_NOINTERRUPT_HOLD_DTAP(KC) __TDA_DEFINITION__(KC, false, NULL, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, NULL, NULL)
#define TDA_NOINTERRUPT_TAP_HOLD_DTAP(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, NULL, NULL)
#define TDA_NOINTERRUPT_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, NULL, NULL, NULL, NULL, KC ## _dh_action, KC ## _dh_reset)
#define TDA_NOINTERRUPT_TAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, NULL, NULL, NULL,  KC ## _dh_action, KC ## _dh_reset)
#define TDA_NOINTERRUPT_HOLD_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, NULL, KC ## _sh_action, KC ## _sh_reset, NULL,  KC ## _dh_action, KC ## _dh_reset)
#define TDA_NOINTERRUPT_TAP_HOLD_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, NULL, KC ## _dh_action, KC ## _dh_reset)
#define TDA_NOINTERRUPT_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, NULL, NULL, NULL, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)
#define TDA_NOINTERRUPT_TAP_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, NULL, NULL, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)
#define TDA_NOINTERRUPT_HOLD_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, NULL, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)
#define TDA_NOINTERRUPT_TAP_HOLD_DTAP_TAPHOLD(KC) __TDA_DEFINITION__(KC, false, KC ## _st_action, KC ## _sh_action, KC ## _sh_reset, KC ## _dt_action, KC ## _dh_action, KC ## _dh_reset)

// Return an integer that corresponds to what kind of tap dance should be executed.
td_state_t decide_tap_dance_outcome(tap_dance_state_t *state, td_tap_user_t *user_data) {
    if (user_data->state != TD_NONE) return user_data->state;

    if (state->count == 1) {
        if (state->interrupted) {
            if (!state->pressed) {
                return TD_SINGLE_TAP;
            } else {
                return user_data->interrupt_hold ? TD_SINGLE_HOLD : TD_SINGLE_TAP;
            }
        }
        else if (!state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        // TD_DOUBLE_DEFAULT is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) {
            if (!state->pressed) {
                return TD_SINGLE_TAP;
            } else {
                return TD_TAP_HOLD;
            }
        }
        else if (!state->pressed) {
            return TD_DOUBLE_TAP;
        }
        else {
            return TD_TAP_HOLD;
        }
    } else {
        return TD_UNKNOWN;
    }
}

void td_finished(tap_dance_state_t *state, void *_user_data);

void td_each(tap_dance_state_t *state, void *_user_data) {
    td_tap_user_t *user_data = (td_tap_user_t *)_user_data;

    if (user_data->state == TD_DEFAULT) {
        if (user_data->single_tap.tap_fn) {
            user_data->single_tap.tap_fn();
        }
        return;
    }

    // detect when the user "falls off the end", that is, a key is pressed more times than is defined
    switch (state->count) {
    case 1:
    case 2:
        // Just counting keypresses for now…
        break;
    default:
        // This must be the 3'rd tap... hit the key 3 times now, further keypresses
        // are handled in the top of this function.
        user_data->single_tap.tap_fn();
        user_data->single_tap.tap_fn();
        user_data->single_tap.tap_fn();
        user_data->state = TD_DEFAULT;
        ANY_KEY_PRESSED=true;
        break;
    }
}

uint finished_td = 0;

void td_finished(tap_dance_state_t *state, void *_user_data) {
    td_tap_user_t *user_data = (td_tap_user_t *)_user_data;

    ++finished_td;

    user_data->state = decide_tap_dance_outcome(state, user_data);
    switch (user_data->state) {
        case TD_DEFAULT:
            // nothing to do... all keypresses were handled in td_each(…)
            break;
        case TD_SINGLE_TAP:
            ANY_KEY_PRESSED=true;
            if (user_data->single_tap.tap_fn) {
                for (int x=0; x<state->count; ++x) {
                    user_data->single_tap.tap_fn();
                }
            }
            break;
        case TD_SINGLE_HOLD:
            if (ANY_KEY_PRESSED)
            ANY_KEY_PRESSED = false;
            if (user_data->single_hold.hold_fn) {
                user_data->single_hold.hold_fn();
            }
            break;
        case TD_DOUBLE_TAP:
            ANY_KEY_PRESSED=true;
            if (user_data->double_tap.tap_fn) {
                user_data->double_tap.tap_fn();
            }
            else if (user_data->single_tap.tap_fn) {
                user_data->single_tap.tap_fn();
                user_data->single_tap.tap_fn();
            }
            break;
        case TD_TAP_HOLD:
            if (user_data->tap_hold.hold_fn) {
                ANY_KEY_PRESSED = false;
                user_data->tap_hold.hold_fn();
            } else {
                if (user_data->single_tap.tap_fn) {
                    ANY_KEY_PRESSED = true;
                    user_data->single_tap.tap_fn();
                }
                if (user_data->single_hold.hold_fn) {
                    ANY_KEY_PRESSED = false;
                    user_data->single_hold.hold_fn();
                }
            }
            break;
        default: break;
    }
}

void td_reset(tap_dance_state_t *state, void *_user_data) {
    td_tap_user_t *user_data = (td_tap_user_t *)_user_data;

    --finished_td;

    switch (user_data->state) {
        case TD_SINGLE_HOLD:
            if (user_data->single_hold.reset_fn) {
                user_data->single_hold.reset_fn();
            }
            if (!finished_td && !ANY_KEY_PRESSED && user_data->single_tap.tap_fn) {
                user_data->single_tap.tap_fn();
            }
            break;
        case TD_TAP_HOLD:
            if (user_data->tap_hold.reset_fn) {
                user_data->tap_hold.reset_fn();
            } else if (user_data->single_hold.reset_fn) {
                user_data->single_hold.reset_fn();
            }
            if (!finished_td && !ANY_KEY_PRESSED) {
                if (!user_data->tap_hold.hold_fn) {
                    // without a tap-hold function, single-tap was pressed before holding the single-hold
                    if(user_data->single_tap.tap_fn) {
                        user_data->single_tap.tap_fn();
                    }
                }
                else {
                    // with a tap-hold function, we haven't pressed any keys yet
                    if(user_data->double_tap.tap_fn) {
                        user_data->double_tap.tap_fn();
                    }
                    else if(user_data->single_tap.tap_fn) {
                        user_data->single_tap.tap_fn();
                    }
                }
            }
            break;
        default:
            break;
    }
    user_data->state = TD_NONE;
    ANY_KEY_PRESSED = true;
}

/*
Define Tap-Dance functions and the lookup table
*/

// GENERAL
TDF_TAP(TD_BASE_11, {
    caps_word_off();
    tap_code16(DK_QUES);
})
TDF_HOLD(TD_BASE_11, {
    caps_word_off();
    tap_code(DK_ARNG);
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_BASE_13, {
    caps_word_off();
    tap_code16(KC_TAB);
})

TDF_TAP(TD_BASE_23, tap_code(KC_O))
TDF_HOLD(TD_BASE_23, {
    caps_word_off();
    tap_code(DK_AE);
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_BASE_24, {
    keyrecord_t record = {
        .event = {
            .pressed = false
        }
    };
    process_dynamic_macro(QK_DYNAMIC_MACRO_PLAY_1, &record);
})
TDF_DTAP(TD_BASE_24, {
    if (!recording) {
        keyrecord_t record = {
            .event = {
                .pressed = false
            }
        };
        process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_START_1, &record);
    } else {
        keyrecord_t record = {
            .event = {
                .pressed = true
            }
        };
        process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_STOP, &record);
    }
})
TDF_HOLD(TD_BASE_24, {
    caps_word_off();
    tap_code(DK_OSTR);
    ANY_KEY_PRESSED = true;
}, {})
TDF_TAPHOLD(TD_BASE_24, {
    caps_word_toggle();
    ANY_KEY_PRESSED = true;
}, {})

TDF_HOLD(TD_BASE_25, {
    layer_on(LAYERS);
    ANY_KEY_PRESSED = true;
}, layer_off(LAYERS))

TDF_TAP(TD_BASE_26, tap_code(KC_Z))
TDF_HOLD(TD_BASE_26, register_code(KC_LGUI), unregister_code(KC_LGUI))

TDF_TAP(TD_BASE_27, tap_code(KC_X))
TDF_HOLD(TD_BASE_27, register_code(KC_LCTL), unregister_code(KC_LCTL))

TDF_TAP(TD_BASE_28, tap_code(KC_C))
TDF_HOLD(TD_BASE_28, {
    caps_word_off();
    register_code(KC_LSFT);
}, unregister_code(KC_LSFT))

TDF_TAP(TD_BASE_29, tap_code(KC_D))
TDF_HOLD(TD_BASE_29, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_BASE_31, tap_code(KC_ENTER))
TDF_HOLD(TD_BASE_31, {
    layer_on(UTIL);
    ANY_KEY_PRESSED = true;
}, layer_off(UTIL))

TDF_TAP(TD_BASE_32, tap_code(KC_ENTER))
TDF_HOLD(TD_BASE_32, {
    layer_on(UTIL);
    ANY_KEY_PRESSED = true;
}, layer_off(UTIL))

TDF_TAP(TD_BASE_34, tap_code(DK_H))
TDF_HOLD(TD_BASE_34, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_BASE_35, tap_code(DK_COMM))
TDF_HOLD(TD_BASE_35, {
    caps_word_off();
    register_code(KC_RSFT);
}, unregister_code(KC_RSFT))

TDF_TAP(TD_BASE_36, tap_code(DK_DOT))
TDF_HOLD(TD_BASE_36, register_code(KC_RCTL), unregister_code(KC_RCTL))

TDF_TAP(TD_BASE_37, tap_code16(S(DK_MINS)))
TDF_HOLD(TD_BASE_37, register_code(KC_RGUI), unregister_code(KC_RGUI))

TDF_HOLD(TD_BASE_38, {
    layer_on(LAYERS);
    ANY_KEY_PRESSED = true;
}, layer_off(LAYERS))

TDF_HOLD(TD_BASE_39, layer_on(NUMERIC), layer_off(NUMERIC))

TDF_TAP(TD_BASE_40, {
    if (caps_word_active()) {
        tap_code16(DK_MINS);
        return;
    }
    tap_code(KC_SPC);
})
TDF_DTAP(TD_BASE_40, {
    if (caps_word_active()) {
        caps_word_off();
        tap_code(KC_SPC);
        return;
    }
    tap_code(KC_SPC);
    tap_code(KC_SPC);
})
TDF_HOLD(TD_BASE_40, layer_on(NUM), layer_off(NUM))

TDF_TAP(TD_BASE_41, {
    if (caps_word_active()) {
        tap_code16(DK_MINS);
        return;
    }
    tap_code(KC_SPC);
})
TDF_HOLD(TD_BASE_41, {
    caps_word_off();
    layer_on(NAV);
}, layer_off(NAV))
TDF_DTAP(TD_BASE_41, {
    if (caps_word_active()) {
        caps_word_off();
        tap_code(KC_SPC);
        return;
    }
    tap_code(KC_SPC);
    tap_code(KC_SPC);
})

TDF_TAP(TD_BASE_42, {
    caps_word_off();
    tap_code16(S(DK_DOT)); // :
})
TDF_DTAP(TD_BASE_42, {
    caps_word_off();
    tap_code16(S(DK_COMM)); // ;
})
TDF_HOLD(TD_BASE_42, layer_on(SYM), layer_off(SYM))
TDF_TAPHOLD(TD_BASE_42, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_BASE_43, {
    tap_code(KC_ESC);
})
TDF_HOLD(TD_BASE_43, layer_on(NAV), layer_off(NAV))
TDF_TAPHOLD(TD_BASE_43, layer_on(MOUSE), layer_off(MOUSE))

TDF_TAP(TD_BASE_44, {
    if (caps_word_active()) {
        tap_code16(DK_MINS); // - => _
        return;
    }
    tap_code(KC_SPC);
})
TDF_HOLD(TD_BASE_44, {
    caps_word_off();
    layer_on(SYM);
}, layer_off(SYM))
TDF_DTAP(TD_BASE_44, {
    if (caps_word_active()) {
        caps_word_off();
        tap_code(KC_SPC);
        return;
    }
    tap_code(KC_SPC);
    tap_code(KC_SPC);
})

TDF_TAP(TD_BASE_45, {
    if (caps_word_active()) {
        tap_code16(DK_MINS); // - => _
        return;
    }
    tap_code(KC_SPC);
})
TDF_DTAP(TD_BASE_45, {
    if (caps_word_active()) {
        caps_word_off();
        tap_code(KC_SPC);
        return;
    }
    tap_code(KC_SPC);
    tap_code(KC_SPC);
})
TDF_HOLD(TD_BASE_45, layer_on(NUM), layer_off(NUM))

TDF_HOLD(TD_BASE_46, layer_on(NUMERIC), layer_off(NUMERIC))

TDF_HOLD(TD_NUMERIC_26, register_code(KC_LGUI), unregister_code(KC_LGUI))

TDF_TAP(TD_NUMERIC_27, tap_code(KC_F1))
TDF_HOLD(TD_NUMERIC_27, register_code(KC_LCTL), unregister_code(KC_LCTL))

TDF_TAP(TD_NUMERIC_28, tap_code(KC_F2))
TDF_HOLD(TD_NUMERIC_28, register_code(KC_LSFT), unregister_code(KC_LSFT))

TDF_TAP(TD_NUMERIC_29, tap_code(KC_F3))
TDF_HOLD(TD_NUMERIC_29, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_NUMERIC_34, tap_code(KC_KP_1))
TDF_HOLD(TD_NUMERIC_34, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_NUMERIC_35, tap_code(KC_KP_2))
TDF_HOLD(TD_NUMERIC_35, register_code(KC_RSFT), unregister_code(KC_RSFT))

TDF_TAP(TD_NUMERIC_36, tap_code(KC_KP_3))
TDF_HOLD(TD_NUMERIC_36, register_code(KC_RCTL), unregister_code(KC_RCTL))

TDF_TAP(TD_NUMERIC_37, tap_code16(S(DK_MINS)))
TDF_HOLD(TD_NUMERIC_37, register_code(KC_RGUI), unregister_code(KC_RGUI))

TDF_TAP(TD_NUM_2, tap_code(KC_F6))
TDF_DTAP(TD_NUM_2, tap_code(KC_F16))

TDF_TAP(TD_NUM_3, tap_code(KC_F4))
TDF_DTAP(TD_NUM_3, tap_code(KC_F14))

TDF_TAP(TD_NUM_4, tap_code(KC_F10))
TDF_DTAP(TD_NUM_4, tap_code(KC_F20))

TDF_TAP(TD_NUM_5, tap_code(KC_F2))
TDF_DTAP(TD_NUM_5, tap_code(KC_F12))

TDF_TAP(TD_NUM_6, tap_code(KC_F8))
TDF_DTAP(TD_NUM_6, tap_code(KC_F18))

TDF_TAP(TD_NUM_7, tap_code(KC_F9))
TDF_DTAP(TD_NUM_7, tap_code(KC_F19))

TDF_TAP(TD_NUM_8, tap_code(KC_F3))
TDF_DTAP(TD_NUM_8, tap_code(KC_F13))

TDF_TAP(TD_NUM_9, tap_code(KC_F1))
TDF_DTAP(TD_NUM_9, tap_code(KC_F11))

TDF_TAP(TD_NUM_10, tap_code(KC_F5))
TDF_DTAP(TD_NUM_10, tap_code(KC_F15))

TDF_TAP(TD_NUM_11, tap_code(KC_F7))
TDF_DTAP(TD_NUM_11, tap_code(KC_F17))

TDF_HOLD(TD_NUM_26, register_code(KC_LGUI), unregister_code(KC_LGUI))
TDF_HOLD(TD_NUM_27, register_code(KC_LCTL), unregister_code(KC_LCTL))
TDF_HOLD(TD_NUM_28, register_code(KC_LSFT), unregister_code(KC_LSFT))
TDF_HOLD(TD_NUM_29, register_code(KC_LALT), unregister_code(KC_LALT))
TDF_HOLD(TD_NUM_34, register_code(KC_LALT), unregister_code(KC_LALT))
TDF_TAP(TD_NUM_35, tap_code(DK_COMM))
TDF_HOLD(TD_NUM_35, register_code(KC_RSFT), unregister_code(KC_RSFT))
TDF_TAP(TD_NUM_36, tap_code(DK_DOT))
TDF_HOLD(TD_NUM_36, register_code(KC_RCTL), unregister_code(KC_RCTL))
TDF_TAP(TD_NUM_37, tap_code16(S(DK_MINS)))
TDF_HOLD(TD_NUM_37, register_code(KC_RGUI), unregister_code(KC_RGUI))

TDF_TAP(TD_SYM_9, tap_code16(DK_SLSH))
TDF_HOLD(TD_SYM_9, {
    register_code16(DK_BSLS);
    ANY_KEY_PRESSED = true;
}, unregister_code16(DK_BSLS))
TDF_TAPHOLD(TD_SYM_9, {
    register_code16(DK_SLSH);
    ANY_KEY_PRESSED = true;
}, unregister_code16(DK_SLSH))

TDF_TAP(TD_SYM_13, { tap_code16(DK_HALF); })
TDF_DTAP(TD_SYM_13, { tap_code16(DK_PND); })
TDF_HOLD(TD_SYM_13, {
    tap_code16(ALGR(KC_E));
    ANY_KEY_PRESSED = true;
}, {})
TDF_TAPHOLD(TD_SYM_13, {
    tap_code16(DK_SECT);
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_SYM_26, tap_code16(DK_AT))
TDF_HOLD(TD_SYM_26, register_code(KC_LGUI), unregister_code(KC_LGUI))

TDF_TAP(TD_SYM_27, tap_code16(DK_DLR))
TDF_HOLD(TD_SYM_27, register_code(KC_LCTL), unregister_code(KC_LCTL))

TDF_TAP(TD_SYM_28, tap_code16(DK_LBRC))
TDF_HOLD(TD_SYM_28, register_code(KC_LSFT), unregister_code(KC_LSFT))

TDF_TAP(TD_SYM_29, tap_code16(DK_RBRC))
TDF_HOLD(TD_SYM_29, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_SYM_33, tap_code16(DK_GRV))
TDF_HOLD(TD_SYM_33, {
    register_code16(DK_ACUT);
    ANY_KEY_PRESSED = true;
}, unregister_code16(DK_ACUT))
TDF_TAPHOLD(TD_SYM_33, {
    register_code16(DK_GRV);
    ANY_KEY_PRESSED = true;
}, unregister_code16(DK_GRV))

TDF_TAP(TD_SYM_34, tap_code16(DK_PLUS))
TDF_HOLD(TD_SYM_34, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_SYM_35, tap_code16(DK_MINS))
TDF_HOLD(TD_SYM_35, register_code(KC_RSFT), unregister_code(KC_RSFT))

TDF_HOLD(TD_SYM_36, register_code(KC_RCTL), unregister_code(KC_RCTL))

TDF_TAP(TD_SYM_37, tap_code16(S(DK_MINS)))
TDF_HOLD(TD_SYM_37, register_code(KC_RGUI), unregister_code(KC_RGUI))

TDF_TAP(TD_SYM_41, tap_code(KC_SPC))
TDF_HOLD(TD_SYM_41, layer_on(NAV2), layer_off(NAV2))

TDF_TAP(TD_NAV_1, tap_code16(KC_DEL))
TDF_HOLD(TD_NAV_1, {
    SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(100) SS_TAP(X_DELETE));
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_NAV_7, tap_code16(KC_PAUSE))
TDF_DTAP(TD_NAV_7, tap_code16(KC_INS))

TDF_TAP(TD_NAV_12, tap_code16(KC_BSPC))
TDF_HOLD(TD_NAV_12, {
    SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(100) SS_TAP(X_BACKSPACE));
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_NAV_14, { tap_code16(C(KC_SLSH)); }) // Go back
TDF_HOLD(TD_NAV_14, register_code16(KC_LGUI), unregister_code16(KC_LGUI))

TDF_TAP(TD_NAV_15, { tap_code16(C(S(KC_J))); }) // Previous bookmark
TDF_DTAP(TD_NAV_15, { tap_code16(S(KC_F7)); }) // Previous reference
TDF_HOLD(TD_NAV_15, register_code16(KC_LCTL), unregister_code16(KC_LCTL))

TDF_TAP(TD_NAV_16, { tap_code16(A(C(S(KC_K)))); }) // Set bookmark
TDF_DTAP(TD_NAV_16, { tap_code16(C(KC_K)); tap_code16(C(KC_L)); }) // Fold
TDF_HOLD(TD_NAV_16, register_code16(KC_LSFT), unregister_code16(KC_LSFT))

TDF_TAP(TD_NAV_17, { tap_code16(C(S(KC_L))); }) // Next bookmark
TDF_DTAP(TD_NAV_17, { tap_code16(KC_F7); }) // Next reference
TDF_HOLD(TD_NAV_17, register_code16(KC_LALT), unregister_code16(KC_LALT))

TDF_TAP(TD_NAV_18, tap_code16(KC_F12))   // Go to definition
TDF_DTAP(TD_NAV_18, tap_code16(S(KC_F12))) // Go to references
TDF_HOLD(TD_NAV_18, {
    tap_code16(C(S(KC_F12)));
    ANY_KEY_PRESSED = true;
}, {}) // Peek definition
TDF_TAPHOLD(TD_NAV_18, {
    tap_code16(A(S(KC_F12)));
    ANY_KEY_PRESSED = true;
}, {}) // Find all references

TDF_TAP(TD_NAV_19, tap_code16(C(S(KC_DOT)))) // Breadcrumb

TDF_TAP(TD_NAV_26, tap_code16(C(KC_Z))) // Undo
TDF_HOLD(TD_NAV_26, register_code(KC_LGUI), unregister_code(KC_LGUI))

TDF_TAP(TD_NAV_27, { tap_code16(C(KC_X)); }) // Cut
TDF_HOLD(TD_NAV_27, register_code(KC_LCTL), unregister_code(KC_LCTL))

TDF_TAP(TD_NAV_28, { tap_code16(C(KC_C)); }) // Copy
TDF_HOLD(TD_NAV_28, register_code(KC_LSFT), unregister_code(KC_LSFT))

TDF_TAP(TD_NAV_29, { tap_code16(C(KC_V)); }) // Paste
TDF_HOLD(TD_NAV_29, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_NAV_33, { tap_code16(KC_PSCR); })
TDF_DTAP(TD_NAV_33, { tap_code16(A(KC_PSCR)); })
TDF_HOLD(TD_NAV_33, {
    tap_code16(G(KC_PSCR));
    ANY_KEY_PRESSED = true;
}, {})
TDF_TAPHOLD(TD_NAV_33, {
    tap_code16(G(S(KC_PSCR)));
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_NAV_34, {
    tap_code16(C(KC_J));
    tap_code16(KC_HOME);
})
TDF_HOLD(TD_NAV_34, register_code(KC_LALT), unregister_code(KC_LALT))

TDF_TAP(TD_NAV_35, { tap_code16(S(C(DK_HALF))); }) // next/prev ({[]})
TDF_HOLD(TD_NAV_35, register_code(KC_RSFT), unregister_code(KC_RSFT))

TDF_TAP(TD_NAV_36, { tap_code16(C(DK_AE)); }) // toggle terminal
TDF_HOLD(TD_NAV_36, register_code(KC_RCTL), unregister_code(KC_RCTL))

TDF_TAP(TD_NAV_37, { tap_code16(KC_APP); })
TDF_HOLD(TD_NAV_37, register_code(KC_RGUI), unregister_code(KC_RGUI))

TDF_TAP(TD_NAV_44, tap_code(KC_SPC))
TDF_HOLD(TD_NAV_44, layer_on(NUM), layer_off(NUM))

TDF_TAP(TD_NAV2_20, {
    tap_code16(C(KC_J));
    tap_code16(KC_UP);
})
TDF_DTAP(TD_NAV2_20, {
    tap_code16(C(KC_K));
    tap_code16(KC_UP);
})
TDF_HOLD(TD_NAV2_20,
{
    tap_code16(C(KC_J));
    tap_code16(A(C(KC_UP)));
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_NAV2_21, {
    tap_code16(C(KC_J));
    tap_code16(KC_LEFT);
})
TDF_DTAP(TD_NAV2_21, {
    tap_code16(C(KC_K));
    tap_code16(KC_LEFT);
})
TDF_HOLD(TD_NAV2_21,
{
    tap_code16(C(KC_J));
    tap_code16(A(C(KC_LEFT)));
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_NAV2_22, {
    tap_code16(C(KC_J));
    tap_code16(KC_DOWN);
})
TDF_DTAP(TD_NAV2_22, {
    tap_code16(C(KC_K));
    tap_code16(KC_DOWN);
})
TDF_HOLD(TD_NAV2_22,
{
    tap_code16(C(KC_J));
    tap_code16(A(C(KC_DOWN)));
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_NAV2_23, {
    tap_code16(C(KC_J));
    tap_code16(KC_RIGHT);
})
TDF_DTAP(TD_NAV2_23, {
    tap_code16(C(KC_K));
    tap_code16(KC_RIGHT);
})
TDF_HOLD(TD_NAV2_23,
{
    tap_code16(C(KC_J));
    tap_code16(A(C(KC_RIGHT)));
    ANY_KEY_PRESSED = true;
}, {})

TDF_HOLD(TD_NAV2_26, register_code(KC_LGUI), unregister_code(KC_LGUI))
TDF_HOLD(TD_NAV2_27, register_code(KC_LCTL), unregister_code(KC_LCTL))
TDF_HOLD(TD_NAV2_28, register_code(KC_LSFT), unregister_code(KC_LSFT))
TDF_HOLD(TD_NAV2_29, register_code(KC_LALT), unregister_code(KC_LALT))
TDF_HOLD(TD_NAV2_34, register_code(KC_LALT), unregister_code(KC_LALT))
TDF_HOLD(TD_NAV2_35, register_code(KC_RSFT), unregister_code(KC_RSFT))
TDF_HOLD(TD_NAV2_36, register_code(KC_RCTL), unregister_code(KC_RCTL))
TDF_HOLD(TD_NAV2_37, register_code(KC_RGUI), unregister_code(KC_RGUI))

TDF_HOLD(TD_MOUSE_26, register_code(KC_LGUI), unregister_code(KC_LGUI))
TDF_HOLD(TD_MOUSE_27, register_code(KC_LCTL), unregister_code(KC_LCTL))
TDF_HOLD(TD_MOUSE_28, register_code(KC_LSFT), unregister_code(KC_LSFT))
TDF_HOLD(TD_MOUSE_29, register_code(KC_LALT), unregister_code(KC_LALT))
TDF_HOLD(TD_MOUSE_34, register_code(KC_LALT), unregister_code(KC_LALT))
TDF_HOLD(TD_MOUSE_35, register_code(KC_RSFT), unregister_code(KC_RSFT))
TDF_HOLD(TD_MOUSE_36, register_code(KC_RCTL), unregister_code(KC_RCTL))
TDF_HOLD(TD_MOUSE_37, register_code(KC_RGUI), unregister_code(KC_RGUI))

TDF_TAP(TD_UTIL_13, { SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "1"); })
TDF_DTAP(TD_UTIL_13, { SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(25) SS_TAP(X_SCRL) SS_DELAY(25) "2"); })

TDF_TAP(TD_UTIL_35, { tap_code16(KC_MPLY); })
TDF_HOLD(TD_UTIL_35, {
    tap_code16(KC_MUTE);
    ANY_KEY_PRESSED = true;
}, {})

TDF_TAP(TD_UTIL_BACK_TO_BASICS, {
    layer_move(BASE);
    clear_mods();
    clear_weak_mods();
    _caps_word_active = false;
})

tap_dance_action_t tap_dance_actions[] = {
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_11),       // å
    TDA_TAP(TD_BASE_13),
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_23),       // æ
    TDA_NOINTERRUPT_TAP_HOLD_DTAP_TAPHOLD(TD_BASE_24),   // ø
    TDA_NOINTERRUPT_HOLD(TD_BASE_25),
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_26),   // z
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_27),   // x
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_28),   // c
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_29),   // d
    TDA_TAP_HOLD(TD_BASE_31),
    TDA_TAP_HOLD(TD_BASE_32),
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_34),   // h
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_35),   // ,
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_36),   // .
    TDA_NOINTERRUPT_TAP_HOLD(TD_BASE_37),   // -
    TDA_NOINTERRUPT_HOLD(TD_BASE_38),

    TDA_HOLD(TD_BASE_39),                   // numeric
    TDA_TAP_HOLD_DTAP(TD_BASE_40),          // spc+num
    TDA_TAP_HOLD_DTAP(TD_BASE_41),          // spc+nav
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_BASE_42),  // :+;+sym+mouse

    TDA_TAP_HOLD_TAPHOLD(TD_BASE_43),       // esc+nav+mouse
    TDA_TAP_HOLD_DTAP(TD_BASE_44),          // spc+sym
    TDA_TAP_HOLD_DTAP(TD_BASE_45),          // spc+num
    TDA_HOLD(TD_BASE_46),                   // numeric

    TDA_HOLD(TD_NUMERIC_26),
    TDA_TAP_HOLD(TD_NUMERIC_27),
    TDA_TAP_HOLD(TD_NUMERIC_28),
    TDA_TAP_HOLD(TD_NUMERIC_29),
    TDA_TAP_HOLD(TD_NUMERIC_34),
    TDA_TAP_HOLD(TD_NUMERIC_35),
    TDA_TAP_HOLD(TD_NUMERIC_36),
    TDA_TAP_HOLD(TD_NUMERIC_37),

    TDA_TAP_DTAP(TD_NUM_2),
    TDA_TAP_DTAP(TD_NUM_3),
    TDA_TAP_DTAP(TD_NUM_5),
    TDA_TAP_DTAP(TD_NUM_5),
    TDA_TAP_DTAP(TD_NUM_6),
    TDA_TAP_DTAP(TD_NUM_7),
    TDA_TAP_DTAP(TD_NUM_8),
    TDA_TAP_DTAP(TD_NUM_9),
    TDA_TAP_DTAP(TD_NUM_10),
    TDA_TAP_DTAP(TD_NUM_11),
    TDA_HOLD(TD_NUM_26),
    TDA_HOLD(TD_NUM_27),
    TDA_HOLD(TD_NUM_28),
    TDA_HOLD(TD_NUM_29),
    TDA_HOLD(TD_NUM_34),
    TDA_TAP_HOLD(TD_NUM_35),
    TDA_TAP_HOLD(TD_NUM_36),
    TDA_TAP_HOLD(TD_NUM_37),

    TDA_TAP_HOLD_TAPHOLD(TD_SYM_9),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_SYM_13),
    TDA_TAP_HOLD(TD_SYM_26),
    TDA_TAP_HOLD(TD_SYM_27),
    TDA_TAP_HOLD(TD_SYM_28),
    TDA_TAP_HOLD(TD_SYM_29),
    TDA_TAP_HOLD_TAPHOLD(TD_SYM_33),
    TDA_TAP_HOLD(TD_SYM_34),
    TDA_TAP_HOLD(TD_SYM_35),
    TDA_HOLD(TD_SYM_36),
    TDA_TAP_HOLD(TD_SYM_37),
    TDA_TAP_HOLD(TD_SYM_41),

    TDA_TAP_HOLD(TD_NAV_1),
    TDA_TAP_DTAP(TD_NAV_7),
    TDA_TAP_HOLD(TD_NAV_12),
    TDA_TAP_HOLD(TD_NAV_14),
    TDA_TAP_HOLD_DTAP(TD_NAV_15),
    TDA_TAP_HOLD_DTAP(TD_NAV_16),
    TDA_TAP_HOLD_DTAP(TD_NAV_17),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_NAV_18),
    TDA_TAP(TD_NAV_19),
    TDA_TAP_HOLD(TD_NAV_26),
    TDA_TAP_HOLD(TD_NAV_27),
    TDA_TAP_HOLD(TD_NAV_28),
    TDA_TAP_HOLD(TD_NAV_29),
    TDA_TAP_HOLD_DTAP_TAPHOLD(TD_NAV_33),
    TDA_TAP_HOLD(TD_NAV_34),
    TDA_TAP_HOLD(TD_NAV_35),
    TDA_TAP_HOLD(TD_NAV_36),
    TDA_TAP_HOLD(TD_NAV_37),
    TDA_TAP_HOLD(TD_NAV_44),

    TDA_TAP_HOLD_DTAP(TD_NAV2_20),
    TDA_TAP_HOLD_DTAP(TD_NAV2_21),
    TDA_TAP_HOLD_DTAP(TD_NAV2_22),
    TDA_TAP_HOLD_DTAP(TD_NAV2_23),
    TDA_HOLD(TD_NAV2_26),
    TDA_HOLD(TD_NAV2_27),
    TDA_HOLD(TD_NAV2_28),
    TDA_HOLD(TD_NAV2_29),
    TDA_HOLD(TD_NAV2_34),
    TDA_HOLD(TD_NAV2_35),
    TDA_HOLD(TD_NAV2_36),
    TDA_HOLD(TD_NAV2_37),

    TDA_HOLD(TD_MOUSE_26),
    TDA_HOLD(TD_MOUSE_27),
    TDA_HOLD(TD_MOUSE_28),
    TDA_HOLD(TD_MOUSE_29),
    TDA_HOLD(TD_MOUSE_34),
    TDA_HOLD(TD_MOUSE_35),
    TDA_HOLD(TD_MOUSE_36),
    TDA_HOLD(TD_MOUSE_37),

    TDA_TAP(TD_UTIL_BACK_TO_BASICS),
    TDA_TAP_DTAP(TD_UTIL_13),
    TDA_TAP_HOLD(TD_UTIL_35),
};
