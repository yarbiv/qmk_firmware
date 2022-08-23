#pragma once

#include QMK_KEYBOARD_H
#include "features/caps_word.h"
#include "features/custom_shift_keys.h"
#include "features/os_mode.h"

enum custom_keycodes {
    PHONE = SAFE_RANGE,
    EMAIL,
    KC_UDIR,
    KC_GOEQ,
    QC_PRNT,
    CLOSE,
    TASKMAN,
    QC_CPY,
    QC_PAS,
    QC_CUT,
    QC_SAVE,
    QC_LWRD,
    QC_RWRD,
    QC_UNDO,
    QC_REDO,
    QC_MOD1,
	QC_MOD2,
	QC_MOD3,
    QC_LOCK,
    QC_OS,
    QC_POS,
};

enum tapdance_declarations {
    QC_Q,
    OSFT,
    SWAP,
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

td_state_t cur_dance(qk_tap_dance_state_t *state);
void sft_finished(qk_tap_dance_state_t *state, void *user_data);
void sft_reset(qk_tap_dance_state_t *state, void *user_data);
