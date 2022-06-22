#pragma once

#include QMK_KEYBOARD_H
#include "features/caps_word.h"
#include "features/custom_shift_keys.h"
#include "features/os_mode.h"

enum custom_keycodes {
    QC_PRNT = SAFE_RANGE,
    PHONE,
    EMAIL,
    CLOSE,
    TASKMAN,
    KC_UDIR,
    QC_CPY,
    QC_PAS,
    QC_CUT,
    QC_SAVE,
    QC_LWRD,
    QC_RWRD,
    QC_UNDO,
    QC_REDO,
};

enum tapdance_declarations {
    QC_Q,
    OSFT,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
	TD_TRIPLE_TAP,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

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
#define QC_SLSH MT(MOD_RGUI, KC_SLSH)
#define QC_DOT MT(MOD_RALT, KC_DOT)
#define QC_COMM MT(MOD_RCTL, KC_COMM)

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [QC_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};