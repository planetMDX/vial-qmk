/*
Copyright 2023 Morgan Venable @_claussen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// clang-format off
#include "../keymap_support.c"
#include "keycodes.h"
#include "keymap_us.h"
#include "modifiers.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>
#include "svalboard.h"
// clang-format on

layer_state_t default_layer_state_set_user(layer_state_t state) {
    sval_set_active_layer(0, false);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    sval_set_active_layer(get_highest_layer(state), false);
    return state;
}

enum custom_keycodes {
    WS_YOUTUBE = SV_SAFE_RANGE,
    WS_MUSIC,
    WS_WORK,
    WS_PROG,
    WS_FIREFOX,
    WS_CHROME,
    WS_STEAM,
    MON_1,
    MON_2,
    MON_3,
    MON_MOV_1,
    MON_MOV_2,
    MON_MOV_3,
};

enum custom_keycodes_short {
    WS_YT = WS_YOUTUBE,
    WS_MU = WS_MUSIC,
    WS_WO = WS_WORK,
    WS_PG = WS_PROG,
    WS_FF = WS_FIREFOX,
    WS_CH = WS_CHROME,
    WS_ST = WS_STEAM,
};

enum layer {
    NORMAL = 0,
    NAV,
    SYM,
    NUM,
    WNN,
    WKB1,
    WKB2,
    WSN,
    WSI,
    MON,
    MBO = MH_AUTO_BUTTONS_LAYER,
};

#if __has_include("keymap_all.h")
#    include "keymap_all.h"
#else
int     sval_macro_size = 0;
uint8_t sval_macros[]   = {0};
// clang-format off
const uint16_t PROGMEM keymaps[DYNAMIC_KEYMAP_LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
            /* Center           North                   East                South               West*/

    /*R1*/ KC_N,            KC_L,           KC_RSFT,        KC_M,           KC_H,       XXXXXXX,
    /*R2*/ KC_E,            KC_U,           KC_RCTL,        KC_COMMA,       KC_J,       XXXXXXX,
    /*R3*/ KC_I,            KC_Y,           KC_RALT,        KC_DOT,         KC_K,       XXXXXXX,
    /*R4*/ KC_O,            KC_MINS,        KC_QUOTE,       KC_SLSH,        KC_RGUI,    XXXXXXX,
    /*L1*/ KC_T,            KC_P,           KC_D,           KC_V,           KC_LSFT,    XXXXXXX,
    /*L2*/ KC_S,            KC_F,           KC_G,           KC_C,           KC_LCTL,    XXXXXXX,
    /*L3*/ KC_R,            KC_W,           KC_B,           KC_X,           KC_LALT,    XXXXXXX,
    /*L4*/ KC_A,            KC_Q,           KC_LGUI,        KC_Z,           KC_SCLN,    XXXXXXX,
    /*         Down                 Pad                 Up                  Nail                Knuckle         DoubleDown*/
    /*RT*/ KC_SPACE,        TL_UPPR,        KC_ENTER,       KC_BSPC,        QK_REP,     XXXXXXX,
    /*LT*/ KC_LSFT,         TL_LOWR,        KC_TAB,         KC_ESC,         MO(WNN),    SV_CAPS_WORD
        ),

    [NAV] = LAYOUT(
            /* Center               North               East                South               West*/

    /*R1*/ KC_LEFT,         KC_PASTE,       KC_TRNS,        KC_HOME,        KC_TRNS,        KC_TRNS,
    /*R2*/ KC_UP,           KC_COPY,        KC_TRNS,        KC_PGUP,        KC_TRNS,        KC_TRNS,
    /*R3*/ KC_DOWN,         KC_CUT,         KC_TRNS,        KC_PGDN,        KC_TRNS,        KC_TRNS,
    /*R4*/ KC_RIGHT,        KC_TRNS,        KC_TRNS,        KC_END,         KC_TRNS,        KC_TRNS,
    /*L1*/ KC_LSFT,         KC_BSPC,        OSM(MOD_LSFT),  SV_CAPS_WORD,   OSM(MOD_LSFT),  KC_TRNS,
    /*L2*/ KC_LCTL,         KC_DEL,         OSM(MOD_LCTL),  KC_TRNS,        OSM(MOD_LCTL),  KC_TRNS,
    /*L3*/ KC_LALT,         KC_ENTER,       OSM(MOD_LALT),  KC_TRNS,        OSM(MOD_LALT),  KC_TRNS,
    /*L4*/ KC_LGUI,         KC_TRNS,        OSM(MOD_LGUI),  KC_TRNS,        OSM(MOD_LGUI),  KC_TRNS,
    /*         Down                 Pad                 Up                  Nail                Knuckle             DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
        ),

    [SYM] = LAYOUT(
            /* Center               North               East                South               West*/

    /*R1*/ OSM(MOD_RSFT),   KC_EQL,         KC_ESC,         KC_BSLS,        KC_PLUS,    KC_TRNS,
    /*R2*/ OSM(MOD_RCTL),   KC_AT,          KC_TRNS,        KC_PIPE,        KC_DQUO,    KC_TRNS,
    /*R3*/ OSM(MOD_RALT),   KC_COLON,       KC_SCLN,        KC_QUES,        KC_TRNS,    KC_TRNS,
    /*R4*/ OSM(MOD_RGUI),   KC_GRV,         KC_UNDS,        KC_UNDS,        KC_TRNS,    KC_TRNS,
    /*L1*/ KC_LPRN,         KC_DOLLAR,      KC_PERC,        KC_RPRN,        KC_AMPR,    KC_TRNS,
    /*L2*/ KC_LCBR,         KC_HASH,        KC_ASTR,        KC_RCBR,        KC_TRNS,    KC_TRNS,
    /*L3*/ KC_LBRC,         KC_TRNS,        KC_TRNS,        KC_RBRC,        KC_MINS,    KC_TRNS,
    /*L4*/ KC_TILD,         KC_EXLM,        KC_TRNS,        KC_CIRC,        KC_TRNS,    KC_TRNS,
    /*         Down                 Pad                 Up                  Nail                Knuckle         DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS
        ),

    [NUM] = LAYOUT(
            /* Center               North               East                South               West*/

    /*R1*/ KC_0,            KC_F10,         KC_F12,         OSM(MOD_RSFT),  KC_8,       KC_TRNS,
    /*R2*/ KC_2,            KC_F2,          KC_TRNS,        OSM(MOD_RCTL),  KC_TRNS,    KC_TRNS,
    /*R3*/ KC_4,            KC_F4,          KC_TRNS,        OSM(MOD_RALT),  KC_TRNS,    KC_TRNS,
    /*R4*/ KC_6,            KC_F6,          KC_F8,          OSM(MOD_RGUI),  KC_TRNS,    KC_TRNS,
    /*L1*/ KC_1,            KC_F1,          KC_9,           OSM(MOD_LSFT),  KC_F11,     KC_TRNS,
    /*L2*/ KC_3,            KC_F3,          KC_TRNS,        OSM(MOD_LCTL),  KC_TRNS,    KC_TRNS,
    /*L3*/ KC_5,            KC_F5,          KC_TRNS,        OSM(MOD_LALT),  KC_TRNS,    KC_TRNS,
    /*L4*/ KC_7,            KC_F7,          KC_TRNS,        OSM(MOD_LGUI),  KC_F9,      KC_TRNS,
    /*         Down                 Pad                 Up                  Nail                Knuckle         DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS
        ),

    [WNN] = LAYOUT(
            /* Center               North                   East            South                   West*/

    /*R1*/ MO(WSN),         LM(WSN, MOD_LCTL),  KC_TRNS,    LM(WSN, MOD_LALT),  KC_TRNS,    KC_TRNS,
    /*R2*/ MO(WSI),         LM(WSI, MOD_LCTL),  KC_TRNS,    LM(WSI, MOD_LALT),  KC_TRNS,    KC_TRNS,
    /*R3*/ MO(MON),         LM(MON, MOD_LCTL),  KC_TRNS,    LM(MON, MOD_LALT),  KC_TRNS,    KC_TRNS,
    /*R4*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*L1*/ MO(WSN),         LM(WSN, MOD_LCTL),  KC_TRNS,    LM(WSN, MOD_LALT),  KC_TRNS,    KC_TRNS,
    /*L2*/ MO(WSI),         LM(WSI, MOD_LCTL),  KC_TRNS,    LM(WSI, MOD_LALT),  KC_TRNS,    KC_TRNS,
    /*L3*/ MO(MON),         LM(MON, MOD_LCTL),  KC_TRNS,    LM(MON, MOD_LALT),  KC_TRNS,    KC_TRNS,
    /*L4*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*         Down                 Pad                     Up              Nail                    Knuckle         DoubleDown*/
    /*RT*/ MO(WKB1),        MO(WKB2),           KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*LT*/ MO(WKB1),        MO(WKB2),           KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS
        ),

    [WKB1] = LAYOUT(
            /* Center               North                   East            South                   West*/

    /*R1*/ LGUI(KC_D),      KC_TRNS,            KC_TRNS,    LGUI(KC_Q),         LGUI(KC_C), KC_TRNS,
    /*R2*/ LGUI(KC_SPACE),  KC_TRNS,            KC_TRNS,    LGUI(KC_Q),         KC_TRNS,    KC_TRNS,
    /*R3*/ LGUI(KC_R),      KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*R4*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*L1*/ LGUI(KC_D),      KC_TRNS,            LGUI(KC_C), LGUI(KC_Q),         KC_TRNS,    KC_TRNS,
    /*L2*/ LGUI(KC_SPACE),  KC_TRNS,            KC_TRNS,    LGUI(KC_Q),         KC_TRNS,    KC_TRNS,
    /*L3*/ LGUI(KC_R),      KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*L4*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*         Down                 Pad                     Up              Nail                    Knuckle         DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS
        ),

    [WKB2] = LAYOUT(
            /* Center               North                   East            South                   West*/

    /*R1*/ LGUI(KC_G),      LGUI(KC_V),         KC_TRNS,    LGUI(KC_F),         LGUI(KC_U), KC_TRNS,
    /*R2*/ LGUI(KC_S),      LGUI(KC_I),         KC_TRNS,    LGUI(KC_T),         KC_TRNS,    KC_TRNS,
    /*R3*/ LGUI(LSFT(KC_S)),KC_TRNS,            KC_TRNS,    LGUI(KC_P),         KC_TRNS,    KC_TRNS,
    /*R4*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*L1*/ LGUI(KC_G),      LGUI(KC_V),         LGUI(KC_U), LGUI(KC_F),         KC_TRNS,    KC_TRNS,
    /*L2*/ LGUI(KC_S),      LGUI(KC_I),         KC_TRNS,    LGUI(KC_T),         KC_TRNS,    KC_TRNS,
    /*L3*/ LGUI(LSFT(KC_S)),KC_TRNS,            KC_TRNS,    LGUI(KC_P),         KC_TRNS,    KC_TRNS,
    /*L4*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*         Down                 Pad                     Up              Nail                    Knuckle         DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS
      ),

    [WSN] = LAYOUT(
            /* Center               North                   East            South                   West*/

    /*R1*/ LGUI(KC_4),      LGUI(KC_7),         KC_TRNS,    LGUI(KC_1),         LGUI(KC_0), KC_TRNS,
    /*R2*/ LGUI(KC_5),      LGUI(KC_8),         KC_TRNS,    LGUI(KC_2),         KC_TRNS,    KC_TRNS,
    /*R3*/ LGUI(KC_6),      LGUI(KC_9),         KC_TRNS,    LGUI(KC_3),         KC_TRNS,    KC_TRNS,
    /*R4*/ LGUI(KC_4),      LGUI(KC_7),         LGUI(KC_0), LGUI(KC_1),         KC_TRNS,    KC_TRNS,
    /*L1*/ LGUI(KC_4),      LGUI(KC_7),         LGUI(KC_0), LGUI(KC_1),         KC_TRNS,    KC_TRNS,
    /*L2*/ LGUI(KC_5),      LGUI(KC_8),         KC_TRNS,    LGUI(KC_2),         KC_TRNS,    KC_TRNS,
    /*L3*/ LGUI(KC_6),      LGUI(KC_9),         KC_TRNS,    LGUI(KC_3),         KC_TRNS,    KC_TRNS,
    /*L4*/ LGUI(KC_4),      LGUI(KC_7),         KC_TRNS,    LGUI(KC_1),         LGUI(KC_0), KC_TRNS,
    /*         Down                 Pad                     Up              Nail                    Knuckle         DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS
      ),
    [WSI] = LAYOUT(
            /* Center               North                   East            South                   West*/

    /*R1*/ WS_YT,           WS_MU,              KC_TRNS,    WS_WO,              KC_TRNS,    KC_TRNS,
    /*R2*/ WS_PG,           WS_FF,              KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*R3*/ WS_CH,           KC_TRNS,            KC_TRNS,    WS_ST,              KC_TRNS,    KC_TRNS,
    /*R4*/ WS_PG,           WS_FF,              KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*L1*/ WS_YT,           WS_MU,              KC_TRNS,    WS_WO,              KC_TRNS,    KC_TRNS,
    /*L2*/ WS_PG,           WS_FF,              KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*L3*/ WS_CH,           KC_TRNS,            KC_TRNS,    WS_ST,              KC_TRNS,    KC_TRNS,
    /*L4*/ WS_PG,           WS_FF,              KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*         Down                 Pad                     Up              Nail                    Knuckle         DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS
      ),
    [MON] = LAYOUT(
            /* Center               North                   East            South                   West*/

    /*R1*/ MON_1,           KC_TRNS,            KC_TRNS,    MON_MOV_1,          KC_TRNS,    KC_TRNS,
    /*R2*/ MON_2,           KC_TRNS,            KC_TRNS,    MON_MOV_2,          KC_TRNS,    KC_TRNS,
    /*R3*/ MON_3,           KC_TRNS,            KC_TRNS,    MON_MOV_3,          KC_TRNS,    KC_TRNS,
    /*R4*/ MON_3,           KC_TRNS,            KC_TRNS,    MON_MOV_3,          KC_TRNS,    KC_TRNS,
    /*L1*/ MON_1,           KC_TRNS,            KC_TRNS,    MON_MOV_1,          KC_TRNS,    KC_TRNS,
    /*L2*/ MON_2,           KC_TRNS,            KC_TRNS,    MON_MOV_2,          KC_TRNS,    KC_TRNS,
    /*L3*/ MON_3,           KC_TRNS,            KC_TRNS,    MON_MOV_3,          KC_TRNS,    KC_TRNS,
    /*L4*/ MON_3,           KC_TRNS,            KC_TRNS,    MON_MOV_3,          KC_TRNS,    KC_TRNS,
    /*         Down                 Pad                     Up              Nail                    Knuckle         DoubleDown*/
    /*RT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,
    /*LT*/ KC_TRNS,         KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS
      ),
    [MBO] = LAYOUT(
        /*Center           North           East            South           West*/
        /*R1*/ KC_BTN1,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*R2*/ KC_BTN3,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*R3*/ KC_BTN2,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*R4*/ SV_RECALIBRATE_POINTER,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*L1*/ KC_BTN1,        KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, XXXXXXX,
        /*L2*/ KC_BTN3,        KC_TRNS,       KC_TRNS,       SV_SNIPER_2,        KC_TRNS, XXXXXXX,
        /*L3*/ KC_BTN2,        KC_TRNS,       KC_TRNS,       SV_SNIPER_3,        KC_TRNS, XXXXXXX,
        /*L4*/ SV_RECALIBRATE_POINTER, KC_TRNS, KC_TRNS,       SV_SNIPER_5,      KC_TRNS, XXXXXXX,
        /*     Down            Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ KC_TRNS,        KC_BTN1,       KC_TRNS,       KC_BTN2,       KC_TRNS,   KC_TRNS,
        /*LT*/ KC_TRNS,        KC_BTN1,       KC_TRNS,       KC_BTN2,       KC_TRNS,   KC_TRNS
        )

};
// clang-format on
#endif

#define NAMED_WS(W) SEND_STRING(SS_LGUI("w") SS_DELAY(50) W SS_DELAY(50) SS_TAP(X_ESC))
#define WM_MON(M) SEND_STRING(SS_LGUI("o") SS_DELAY(50) M SS_DELAY(50) SS_TAP(X_ESC))
#define WM_MON_MOV(M) SEND_STRING(SS_LALT(SS_LGUI("o")) SS_DELAY(50) M SS_DELAY(50) SS_TAP(X_ESC))

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    (void)record;
    switch (keycode) {
        case WS_YT:
            NAMED_WS("y");
            break;
        case WS_MU:
            NAMED_WS("m");
            break;
        case WS_WO:
            NAMED_WS("w");
            break;
        case WS_PG:
            NAMED_WS("p");
            break;
        case WS_FF:
            NAMED_WS("f");
            break;
        case WS_CH:
            NAMED_WS("c");
            break;
        case WS_ST:
            NAMED_WS("s");
            break;
        case MON_1:
            WM_MON("1");
            break;
        case MON_2:
            WM_MON("2");
            break;
        case MON_3:
            WM_MON("3");
            break;
        case MON_MOV_1:
            WM_MON_MOV("1");
            break;
        case MON_MOV_2:
            WM_MON_MOV("2");
            break;
        case MON_MOV_3:
            WM_MON_MOV("3");
            break;
        default:
            break;
    }
    return true;
}

#undef NAMED_WS
#undef WM_MON
#undef WM_MON_MOV

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    if (tap_hold_record->event.key.row == 0 || tap_hold_record->event.key.row == 5 || other_record->event.key.row == 0 || other_record->event.key.row == 5) {
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

void keyboard_post_init_user(void) {
    // Customise these values if you need to debug the matrix
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;

#if __has_include("keymap_all.h")
    if (fresh_install) {
        sval_init_defaults();
    }
#endif
}
