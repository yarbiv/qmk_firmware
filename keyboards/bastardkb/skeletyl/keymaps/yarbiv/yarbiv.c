#include "yarbiv.h"

// PHONE
// EMAIL
// UDIR

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!process_caps_word(keycode, record)) { return false; }
	// if (!process_custom_shift_keys(keycode, record)) { return false; }
	// if (!process_os_mode(keycode, record, QC_OS)) { return false; }

	switch (keycode) {
		case KC_UDIR:
			if (record->event.pressed)
			{
				SEND_STRING("../");
			}
			break;

		case PHONE:
			if (record->event.pressed)
			{
				SEND_STRING("+1 (416) 666-1841");
			}
			break;

		case EMAIL:
			if (record->event.pressed)
			{
				SEND_STRING("yoav.arbiv@gmail.com");
			}
			break;
	}

	return process_record_keymap(keycode, record);
}

void matrix_scan_user(void) {
	caps_word_task();
}

td_state_t cur_dance(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) {
			return TD_SINGLE_TAP;
		} else {
			return TD_SINGLE_HOLD;
		}
	} else if (state->count == 2) {
		if (state->pressed) {
			return TD_DOUBLE_HOLD;
		} else {
			return TD_DOUBLE_TAP;
		}
	} else if (state->count == 3) {
		if (!state->pressed) {
			return TD_TRIPLE_TAP;
		}
	}

	return TD_UNKNOWN;
}

static td_tap_t sft_tap_state = {
	.is_press_action = true,
	.state = TD_NONE
};

void sft_finished(qk_tap_dance_state_t *state, void *user_data) {
	sft_tap_state.state = cur_dance(state);
	switch (sft_tap_state.state) {
		case TD_SINGLE_TAP:
			if (caps_word_get()) {
				caps_word_set(false);
				clear_oneshot_mods();
			} else {
				set_oneshot_mods(MOD_LSFT);
			}
			break;
		case TD_SINGLE_HOLD:
			register_code(KC_LSFT);
			break;
		case TD_DOUBLE_TAP:
			caps_word_set(true);
			break;
		case TD_TRIPLE_TAP:
			tap_code(KC_CAPS);
			break;
		default:
			break;
	}
}

void sft_reset(qk_tap_dance_state_t *state, void *user_data) {
	switch (sft_tap_state.state) {
		case TD_SINGLE_TAP:
			break;
		case TD_SINGLE_HOLD:
			unregister_code(KC_LSFT);
			break;
		case TD_DOUBLE_TAP:
		case TD_TRIPLE_TAP:
		default:
			break;
	}
	sft_tap_state.state = TD_NONE;
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [QC_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [OSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset),
};