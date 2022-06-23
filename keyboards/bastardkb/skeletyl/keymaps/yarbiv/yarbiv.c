#include "yarbiv.h"

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [QC_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    // [OSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset),
};

// PHONE
// EMAIL
// UDIR
