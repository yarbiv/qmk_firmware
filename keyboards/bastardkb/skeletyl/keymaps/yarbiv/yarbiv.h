#include QMK_KEYBOARD_H

enum custom_keycodes {
    QC_PRNT = SAFE_RANGE,

};

enum layer_names {
    _COLEMAK,
    _NUMVIGATION,
    _SYM,
    _MEDIA,
};

#define QC_SPC LT(_NUMVIGATION, KC_SPC)
#define QC_TAB LT(_MEDIA, KC_TAB)
#define QC_ENT LT(_SYM, KC_ENT)
#define QC_Z MT(MOD_LGUI, KC_Z)
#define QC_X MT(MOD_LALT, KC_X)
#define QC_C MT(MOD_LCTL, KC_C)
#define QC_Q MT(KC_ESC, KC_Q)
#define QC_SLSH MT(MOD_RGUI, KC_SLSH)
#define QC_DOT MT(MOD_RALT, KC_DOT)
#define QC_COMM MT(MOD_RCTL, KC_COMM)