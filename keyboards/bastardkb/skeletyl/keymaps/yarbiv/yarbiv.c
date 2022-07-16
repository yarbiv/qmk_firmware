#include "yarbiv.h"

// PHONE
// EMAIL
// UDIR

const os_key_t os_keys[] = {
	{QC_CPY, LCTL(KC_C), LGUI(KC_C)},
	{QC_PAS, LCTL(KC_V), LGUI(KC_V)},
	{QC_CUT, LCTL(KC_X), LGUI(KC_X)},
	{QC_SAVE, LCTL(KC_S), LGUI(KC_S)},
	{QC_LWRD, LCTL(KC_LEFT), LALT(KC_LEFT)},
	{QC_RWRD, LCTL(KC_RIGHT), LALT(KC_RIGHT)},
	{QC_UNDO, LCTL(KC_Z), LGUI(KC_Z)},
	{QC_REDO, RCS(KC_Z), RSG(KC_Z)},
	{QC_PRNT, LGUI(LSFT(KC_S)), SCMD(KC_4)},
	{QC_MOD1, KC_LCTL, KC_LGUI},
	{QC_MOD2, KC_LALT, KC_LCTL},
	{QC_MOD3, KC_LGUI, KC_LALT},
	{QC_LOCK, LGUI(KC_L), LCTL(LGUI(KC_Q))},
	{CLOSE, LALT(KC_F4), LGUI(KC_Q)},
	{TASKMAN, RCS(KC_ESC), LAG(KC_ESC)},
};

const os_key_t os_mods[] = {
	{QC_Z, KC_LGUI, KC_LALT},
	{QC_X, KC_LALT, KC_LCTL},
	{QC_C, KC_LCTL, KC_LGUI},
	{QC_SLSH, KC_RGUI, KC_RALT},
	{QC_DOT, KC_RALT, KC_RCTL},
	{QC_COMM, KC_RCTL, KC_RGUI},
};

uint8_t NUM_OS_KEYS = sizeof(os_keys) / sizeof(os_key_t);
uint8_t NUM_OS_MODS = sizeof(os_mods) / sizeof(os_key_t);

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!process_caps_word(keycode, record)) { return false; }
	// if (!process_custom_shift_keys(keycode, record)) { return false; }
	if (!process_os_mode(keycode, record, QC_OS)) { return false; }

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
				SEND_STRING("+1 (415) 832-9511");
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

static td_tap_t swap_tap_state = {
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

void swap_finished(qk_tap_dance_state_t *state, void *user_data) {
	swap_tap_state.state = cur_dance(state);
	switch (swap_tap_state.state) {
		case TD_SINGLE_TAP:
			if (get_os_mode() == WINDOWS) {
				tap_code16(LALT(KC_TAB));
			} else {
				tap_code16(LGUI(KC_TAB));
			}
			break;
		case TD_SINGLE_HOLD:
			if (get_os_mode() == WINDOWS) {
				register_code(KC_LALT);
				tap_code(KC_TAB);
			} else {
				register_code(KC_LGUI);
				tap_code(KC_TAB);
			}
			break;
		case TD_DOUBLE_TAP:
			if (get_os_mode() == WINDOWS) {
				tap_code16(LALT(KC_SPC));
			} else {
				tap_code16(LGUI(KC_SPC));
			}
			break;
		default:
			break;
	}
}

void swap_reset(qk_tap_dance_state_t *state, void *user_data) {
	switch (swap_tap_state.state) {
		case TD_SINGLE_TAP:
			break;
		case TD_SINGLE_HOLD:
			if (get_os_mode() == WINDOWS) {
				unregister_code(KC_LALT);
			} else {
				unregister_code(KC_LGUI);
			}
			break;
		case TD_DOUBLE_TAP:
		default:
			break;
	}
	swap_tap_state.state = TD_NONE;
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [QC_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [OSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset),
	[SWAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, swap_finished, swap_reset),
};