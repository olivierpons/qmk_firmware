/**
 * Copyright 2024 Olivier Pons / HQF Development <olivier.pons@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * HQF: AZERTY Moonlander keymap, Linux first. What it does, at a glance:
 *
 * L0 AZERTY. Right thumbs: &nbsp; (M_NBSP), <tag></tag> around word (tap
 *    TD(TD_ATG); triple tap TD(TD_ATG): Syntax Terror intro theme).
 * L1 (hold MO(L_1)): F1-F12, \ { } ~ | / @ < > [ ] # %, arrows, word jumps,
 *    Home/End/PgUp/PgDn, 2 emails, Ctrl+Alt+K dictation, circle mouse jiggler
 *    (bottom left row: delay +/-, click N/NE/.../NW/off, radius +/-; right
 *    thumb next to Ctrl+Alt+K: on/off).
 * L2 (hold MO(L_2)): numpad, Caps/Num Lock, â ê î ô û ù ``, 2 signatures,
 *    Linux desktop left/right/maximize, Ctrl+[ Ctrl+].
 * L3 (hold MO(L_3)): copy/cut/paste as Ctrl+C/V, Ctrl+Shift+C/V, Ctrl+Ins/
 *    Shift+Ins, 2 sentences, arrows, F1-F12, Ctrl+Alt+W.
 * L4 (tap TD(TD_RF)): RGB on/off/effect/hue/sat/value, audio on/off (U/J),
 *    music mode on/off (I/K), typing beep on/off/pitch (O/L).
 * L5 (Goto L5 key): 40 melodies, one per key.
 * L6 (double tap TD(TD_RF)): gaming, rapid fire mouse 1/2/both and space,
 *    rapid fire speed up/down. Triple tap TD(TD_RF): USSR anthem.
 *
 * Music mode: tap TD(TD_RF) -> L4, press MU_ON (I), tap TD(TD_RF) again -> L0,
 * play the three middle rows (40 notes, low to high). Stop: L4, MU_OFF (K).
 * No sound at all: audio is off -> L4, AU_ON (U).
 * Personal strings (signatures, emails, sentences): config.local.h.
 */

/**
 * MACRO DOCUMENTATION
 * ------------------
 * This keymap supports several types of customizable macros:
 *
 * 1. SIGNATURE MACROS (M_SIGN1, M_SIGN2)
 *    Example structure:
 *    case M_SIGN1:
 *        SEND_STRING(SS_TAP(X_ENT) SS_TAP(X_ENT)   // Two newlines
 *            "Name - Role\n"                        // Basic signature
 *            "Additional Info");                    // Extra information
 *
 *    Advanced example with formatting:
 *    case M_SIGN2:
 *        PLAY_SONG(unicode_windows);               // Optional: play sound
 *        SEND_STRING(
 *            SS_TAP(X_ENT) SS_TAP(X_ENT)          // Two newlines
 *            SS_DOWN(X_LSFT) SS_TAP(X_N) SS_UP(X_LSFT) // Capital letter
 *            "ame - "                              // Continue text
 *            SS_DOWN(X_LSFT) SS_TAP(X_R) SS_UP(X_LSFT) // Another capital
 *            "ole\n"                               // Newline
 *            "https://website.com"                 // URL
 *        );
 *
 * 2. EMAIL MACROS (M_EMAIL1, M_EMAIL2)
 *    Example structure:
 *    case M_EMAIL1:
 *        PLAY_SONG(chromatic_sound); // Optional: play sound
 *        SEND_STRING(
 *            "username" // Email prefix
 *            SS_DOWN(X_RALT) SS_TAP(X_0) SS_UP(X_RALT) // @ symbol
 *            "domain.com" // Domain
 *        );
 *
 * 3. Sentences (M_STCE_1, M_STCE_2)
 *    Like signatures and emails, sends a "sentence" or a "word", it's up to you:
 *    Example structure:
 *    case M_STCE_1:
 *        SEND_STRING("\nsry\n");
 *
 * SPECIAL CHARACTERS REFERENCE
 * --------------------------
 * @ symbol: SS_DOWN(X_RALT) SS_TAP(X_0) SS_UP(X_RALT)
 * # symbol: SS_DOWN(X_RALT) SS_TAP(X_3) SS_UP(X_RALT)
 * { symbol: SS_DOWN(X_RALT) SS_TAP(X_4) SS_UP(X_RALT)
 * [ symbol: SS_DOWN(X_RALT) SS_TAP(X_5) SS_UP(X_RALT)
 * | symbol: SS_DOWN(X_RALT) SS_TAP(X_6) SS_UP(X_RALT)
 * ` symbol: SS_DOWN(X_RALT) SS_TAP(X_7) SS_UP(X_RALT)
 * \ symbol: SS_DOWN(X_RALT) SS_TAP(X_8) SS_UP(X_RALT)
 * ~ symbol: SS_DOWN(X_RALT) SS_TAP(X_2) SS_UP(X_RALT)
 *
 * FORMATTING COMMANDS
 * -----------------
 * Newline:     SS_TAP(X_ENT)
 * Space:       SS_TAP(X_SPC)
 * Tab:         SS_TAP(X_TAB)
 * Shift+Key:   SS_DOWN(X_LSFT) SS_TAP(X_KEY) SS_UP(X_LSFT)
 * Alt+Key:     SS_DOWN(X_LALT) SS_TAP(X_KEY) SS_UP(X_LALT)
 * Ctrl+Key:    SS_DOWN(X_LCTL) SS_TAP(X_KEY) SS_UP(X_LCTL)
 */

#include QMK_KEYBOARD_H
#include "version.h"

// Include local configuration if it exists
#if __has_include("config.local.h")
    #include "config.local.h"
#else
    // Default values if config.local.h doesn't exist
    #define SIGNATURE_1 "Example Name - Role"
    #define SIGNATURE_2 "Example Name - Role\nhttps://example.com"
    #define EMAIL_1 "example@domain.com"
    #define EMAIL_2 "example@company.com"
    #define CUSTOM_SOUND SONG(STARTUP_SOUND)
#endif

/**
 * Tap Dance State Definitions
 * --------------------------
 * Defines the possible states for tap dance actions:
 * - TD_NONE: No tap dance action in progress
 * - TD_UNKNOWN: Unrecognized tap pattern
 * - TD_SINGLE_TAP: Single tap detected
 * - TD_SINGLE_HOLD: Key is being held after single tap
 * - TD_DOUBLE_TAP: Double tap detected
 * - TD_TRIPLE_TAP: Triple tap detected
 */
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_TRIPLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    TD_RF,  // TD_RF = Tap Dance Rapid Fire toggle
    TD_ATG, // TD_ATG = Tap Dance tag helper, triple tap plays the intro theme
};

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);
void atg_finished(tap_dance_state_t *state, void *user_data);
void atg_reset(tap_dance_state_t *state, void *user_data);

// Shared by the M_ATG keycode and by the TD_ATG tap dance
void send_advanced_tag(void);

/**
 * Layer Definitions
 * ----------------
 * L_0: Base AZERTY layout
 * L_1: Symbols and Navigation layer
 * L_2: Numpad and French accents
 * L_3: Gaming/Alternative layout
 * L_4: RGB Controls
 * L_5: Sound Effects
 * L_6: Rapid Fire Gaming mode
 */
enum layers {
    L_0,
    L_1,
    L_2,
    L_3,
    L_4,
    L_5,
    L_6
};

/**
 * Custom Keycodes
 * --------------
 * M_VRSN: Version information
 * M_ATG: Advanced tag helper
 * M_SOUND00-39: Sound effect triggers
 * M_SIGN1-2: Signature templates
 * M_EMAIL1-2: Email templates
 * RF_MOUSE1-3: Rapid fire mouse buttons
 * RF_SPACE: Rapid fire spacebar
 */
enum custom_keycodes {
    M_VRSN = SAFE_RANGE,
    M_ATG,
    // Sound effects (M_SOUND00 through M_SOUND39)
    M_SOUND00,
    M_SOUND01,
    M_SOUND02,
    M_SOUND03,
    M_SOUND04,
    M_SOUND05,
    M_SOUND06,
    M_SOUND07,
    M_SOUND08,
    M_SOUND09,
    M_SOUND10,
    M_SOUND11,
    M_SOUND12,
    M_SOUND13,
    M_SOUND14,
    M_SOUND15,
    M_SOUND16,
    M_SOUND17,
    M_SOUND18,
    M_SOUND19,
    M_SOUND20,
    M_SOUND21,
    M_SOUND22,
    M_SOUND23,
    M_SOUND24,
    M_SOUND25,
    M_SOUND26,
    M_SOUND27,
    M_SOUND28,
    M_SOUND29,
    M_SOUND30,
    M_SOUND31,
    M_SOUND32,
    M_SOUND33,
    M_SOUND34,
    M_SOUND35,
    M_SOUND36,
    M_SOUND37,
    M_SOUND38,
    M_SOUND39,
    // Templates and macros
    M_SIGN1,
    M_SIGN2,
    M_EMAIL1,
    M_EMAIL2,
    M_STCE_1,
    M_STCE_2,
    // Special characters and symbols
    M_NBSP,
    M_PAR,
    M_GT,
    M_PPE,
    M_BKS,
    M_LBK,
    M_RBK,
    M_SLH,
    M_HTG,
    M_OSB, // [ Opening Square bracket
    M_CSB, // ] Closing Square bracket
    M_COSB, // [ Ctrl + Opening Square bracket
    M_CCSB, // ] Ctrl + Closing Square bracket
    M_ARB,
    M_TLD,
    M_BQT,
    // French accented characters
    M_C_A,
    M_C_E,
    M_C_I,
    M_C_O,
    M_C_U,
    // Navigation shortcuts
    M_XLT,
    M_XRT,
    // Layer change sounds
    M_L4_SP,
    M_L5_SP,
    M_L6_SP,
    // Gaming features
    RF_SPD_UP,
    RF_SPD_DN,
    RF_MOUSE1,
    RF_MOUSE2,
    RF_MOUSE3,
    RF_SPACE,
    // Mouse jiggling
    M_JG_TOG,
    M_JG_RUP,
    M_JG_RDN,
    M_JG_CTG,
    M_JG_DUP,
    M_JG_DDN,
};

// Key combination defines for better readability
#define LSCTL(kc) (QK_LCTL | QK_LSFT | (kc))
#define KC_SLSH KC_SLASH

// Layer shortcuts
#define L_0 0 // Default layer
#define L_1 1 // Symbols & Navigation
#define L_2 2 // Numpad & Accents
#define L_3 3 // Gaming/Alternative
#define L_4 4 // RGB Controls
#define L_5 5 // Sound Effects
#define L_6 6 // Rapid Fire Gaming

// Copy/Paste shortcuts for different systems
#define C_COPY   LCTL(KC_C)        // Classical Copy (Ctrl + C)
#define C_CUT    LCTL(KC_X)        // Classical Cut (Ctrl + X)
#define C_PASTE  LCTL(KC_V)        // Classical Paste (Ctrl + V)
#define I_COPY   LCTL(KC_INS)      // Alternative Copy (Ctrl + Insert)
#define I_CUT    LSFT(KC_DEL)      // Alternative Cut (Shift + Delete)
#define I_PASTE  LSFT(KC_INS)      // Alternative Paste (Shift + Insert)
#define L_COPY   LSCTL(KC_C)       // Linux Copy
#define L_PASTE  LSCTL(KC_V)       // Linux Paste
#define C_Alt_W  LCTL(LALT(KC_Z))  // Ctrl + Alt + Z (W on AZERTY)
#define C_Alt_K  LCTL(LALT(KC_K))  // Ctrl + Alt + K, toggles opons-voxd voice dictation: https://github.com/olivierpons/opons-voxd

#define I_PCT    LSFT(KC_QUOT) // % Percent

#define C_HTG    RALT(KC_3) // Hashtag '#'

// Navigation shortcuts
#define C_LEFT   LCTL(KC_LEFT)  // Word left
#define C_RIGHT  LCTL(KC_RIGHT) // Word right
#define X_LT     LCA(KC_LEFT)   // Linux: previous desktop
#define X_RT     LCA(KC_RIGHT)  // Linux: next desktop
#define X_MX     LCA(KC_UP)     // Linux: maximize window
#define W_LT     LGUI(KC_LEFT)  // Windows: previous desktop
#define W_RT     LGUI(KC_RIGHT) // Windows: next desktop
#define X_SB     LCA(KC_B)      // Linux: maximize window

/**
 * Note: for some macros like LT() or TG():
 *
 * LT = Momentary Layer Toggle: Switch to the selected layer when held, send
 *      the selected key when tapped QMK limits this macro to switch to layers
 *      under layer 16.
 *
 * TG = Toggle layer: Switch to a given layer.
 *      Tap this key again to return to the current layer.
 */

float ag_norm_sound          [][2] = SONG(AG_NORM_SOUND);
float ag_swap_sound          [][2] = SONG(AG_SWAP_SOUND);
float audio_off_sound        [][2] = SONG(AUDIO_OFF_SOUND);
float audio_on_sound         [][2] = SONG(AUDIO_ON_SOUND);
float campanella             [][2] = SONG(CAMPANELLA);
float caps_lock_off_sound    [][2] = SONG(CAPS_LOCK_OFF_SOUND);
float caps_lock_on_sound     [][2] = SONG(CAPS_LOCK_ON_SOUND);
float chromatic_sound        [][2] = SONG(CHROMATIC_SOUND);
float clueboard_sound        [][2] = SONG(CLUEBOARD_SOUND);
float colemak_sound          [][2] = SONG(COLEMAK_SOUND);
float dvorak_sound           [][2] = SONG(DVORAK_SOUND);
float fantasie_impromptu     [][2] = SONG(FANTASIE_IMPROMPTU);
float goodbye_sound          [][2] = SONG(GOODBYE_SOUND);
float guitar_sound           [][2] = SONG(GUITAR_SOUND);
float major_sound            [][2] = SONG(MAJOR_SOUND);
float minor_sound            [][2] = SONG(MINOR_SOUND);
float music_off_sound        [][2] = SONG(MUSIC_OFF_SOUND);
float music_on_sound         [][2] = SONG(MUSIC_ON_SOUND);
float music_scale_sound      [][2] = SONG(MUSIC_SCALE_SOUND);
float nocturne_op_9_no_1     [][2] = SONG(NOCTURNE_OP_9_NO_1);
float num_lock_off_sound     [][2] = SONG(NUM_LOCK_OFF_SOUND);
float num_lock_on_sound      [][2] = SONG(NUM_LOCK_ON_SOUND);
float ode_to_joy             [][2] = SONG(ODE_TO_JOY);
float planck_sound           [][2] = SONG(PLANCK_SOUND);
float plover_goodbye_sound   [][2] = SONG(PLOVER_GOODBYE_SOUND);
float plover_sound           [][2] = SONG(PLOVER_SOUND);
float preonic_sound          [][2] = SONG(PREONIC_SOUND);
float qwerty_sound           [][2] = SONG(QWERTY_SOUND);
float rock_a_bye_baby        [][2] = SONG(ROCK_A_BYE_BABY);
float scroll_lock_off_sound  [][2] = SONG(SCROLL_LOCK_OFF_SOUND);
float scroll_lock_on_sound   [][2] = SONG(SCROLL_LOCK_ON_SOUND);
float startup_sound          [][2] = SONG(STARTUP_SOUND);
float terminal_sound         [][2] = SONG(TERMINAL_SOUND);
float unicode_linux          [][2] = SONG(UNICODE_LINUX);
float unicode_windows        [][2] = SONG(UNICODE_WINDOWS);
float ussr_anthem            [][2] = SONG(USSR_ANTHEM);
float violin_sound           [][2] = SONG(VIOLIN_SOUND);
float voice_change_sound     [][2] = SONG(VOICE_CHANGE_SOUND);
float workman_sound          [][2] = SONG(WORKMAN_SOUND);
float tos_hymn_risen         [][2] = SONG(TOS_HYMN_RISEN);
float custom_sound           [][2] = SONG(B__NOTE(_G6), B__NOTE(_C7), W__NOTE(_G6), H__NOTE(_A6), B__NOTE(_B6), W__NOTE(_E6), W__NOTE(_E6), B__NOTE(_A6), W__NOTE(_G6), H__NOTE(_F6), B__NOTE(_G6), W__NOTE(_C6), W__NOTE(_C6), B__NOTE(_D6), W__NOTE(_D6), W__NOTE(_E6), B__NOTE(_D6), W__NOTE(_D6), W__NOTE(_G6), B__NOTE(_F6), W__NOTE(_G6), W__NOTE(_A6), B__NOTE(_B6),);

/**
 * Melody voice of the Syntax Terror intro theme, one phrase of 6.40 s.
 *
 * Durations are in QMK's unit of 1/64th of a beat, which audio_duration_to_ms()
 * turns into duration * 1875 / (tempo * 2) ms; at the default tempo of 120 that
 * unit is 7.8125 ms, so the 0.2 s eighth note of this theme is 26 units and the
 * named macros (E__NOTE, Q__NOTE...) cannot land on that grid.
 */
float syntax_terror_intro    [][2] = SONG(
    M__NOTE(_C5, 26), M__NOTE(_C5, 26), M__NOTE(_AS4, 51), M__NOTE(_G4, 51),
    M__NOTE(_AS4, 51), M__NOTE(_C5, 51), M__NOTE(_AS4, 51), M__NOTE(_G4, 102),
    M__NOTE(_C5, 51), M__NOTE(_AS4, 26), M__NOTE(_AS4, 26), M__NOTE(_G4, 51),
    M__NOTE(_AS4, 51), M__NOTE(_C5, 51), M__NOTE(_AS4, 154));

/**
 * Mouse jiggler sounds, all different from each other. On/off: one long note,
 * high (E7, 2637 Hz) when it starts, low (E4, 330 Hz) when it stops. Click
 * point (M_JG_CTG): two short notes, one step higher on the C major scale for
 * each direction, C6 for north up to C7 for north west, and C4 (262 Hz) when
 * the click is turned off. The low notes stay above 250 Hz to remain audible
 * on the keyboard speaker. Radius at its limit: two notes, rising at the
 * maximum, falling at the minimum. Delay at its limit: three notes, same
 * directions.
 */
float jiggle_on_sound         [][2] = SONG(H__NOTE(_E7));
// Length of jiggle_on_sound, an H__NOTE at the default tempo of 120:
// 32 * 1875 / (120 * 2) ms, see audio_duration_to_ms().
#define JIGGLE_ON_SOUND_MS    250
float jiggle_off_sound        [][2] = SONG(H__NOTE(_E4));
// Both notes are set to the direction's pitch before each play.
float jiggle_click_sound      [][2] = SONG(Q__NOTE(_C6), E__NOTE(_REST),
                                           Q__NOTE(_C6));
static const float jiggle_click_notes[8] = {
    NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6, NOTE_C7,
};
float jiggle_click_off_sound  [][2] = SONG(Q__NOTE(_C4), E__NOTE(_REST),
                                           Q__NOTE(_C4));
float jiggle_radius_max_sound [][2] = SONG(E__NOTE(_C6), Q__NOTE(_G6));
float jiggle_radius_min_sound [][2] = SONG(E__NOTE(_G5), Q__NOTE(_C5));
float jiggle_delay_max_sound  [][2] = SONG(E__NOTE(_C6), E__NOTE(_E6),
                                           Q__NOTE(_G6));
float jiggle_delay_min_sound  [][2] = SONG(E__NOTE(_G5), E__NOTE(_E5),
                                           Q__NOTE(_C5));

/**
 * Mouse jiggler: the cursor runs clockwise around a circle, one pixel every
 * jiggle_period, starting from its rightmost point. The center is where the
 * cursor stood when M_JG_TOG first started it. M_JG_TOG stops it and leaves
 * the cursor where it is; started again, it goes on from that point of the
 * circle. Radius, delay, click and position are kept from one run to the next.
 * M_JG_RUP / M_JG_RDN change the radius, also while it runs: the cursor then
 * moves along its radius to the new circle. M_JG_DUP / M_JG_DDN lengthen /
 * shorten the delay. On these four keys, a tap changes the value by 1, a key
 * held past JIGGLE_HOLD_MS changes it by 10 per repeat, repeats coming faster
 * and faster. The unit is the pixel for the radius; for the delay it is the
 * millisecond from 1 ms up, and one pixel per millisecond below: 1 ms, then 2,
 * 3 ... 100 pixels per millisecond.
 *
 * The host reads the mouse every USB_POLLING_INTERVAL_MS (1 ms), so the steps
 * due within a millisecond go out as one report of several pixels: that is how
 * the delay goes below 1 ms. One report per millisecond at most also keeps the
 * mouse endpoint queue from filling up, which would block the keyboard.
 *
 * Each step goes to the neighbour pixel (8-connected) along the tangent that
 * stays closest to x^2 + y^2 = r^2, so the cursor follows every pixel of the
 * circle and a full turn adds up to no move at all. With the default radius of
 * 10, a turn is 56 steps, i.e. 56 s at the default delay of 1 s. The smallest
 * radius, 1, still moves the cursor: 8 one-pixel steps around the center.
 *
 * Distances are mouse counts: they are screen pixels only when the OS pointer
 * acceleration is flat with a speed of 1, otherwise the OS scales the circle. A
 * screen edge that stops the cursor eats part of the move and shifts the
 * center.
 *
 * M_JG_CTG picks where a left click happens each time the cursor crosses it:
 * each press moves on to the next point of the circle, north (top), north east,
 * east, south east, south, south west, west, north west, then no click, then
 * north again.
 */
/**
 * Delay: jiggle_period, the only delay, read by matrix_scan_user() and changed
 * by M_JG_DUP / M_JG_DDN, in units of 10 ns (JIGGLE_MS per millisecond), from
 * 1 s / JIGGLE_PER_MS_MAX to 10 s. Below 1 ms it is JIGGLE_MS / n for n pixels
 * per millisecond; 10 ns units keep n exact once read back, up to 100.
 */
#define JIGGLE_MS             100000UL
#define JIGGLE_PERIOD_DEFAULT (1000 * JIGGLE_MS)
#define JIGGLE_PERIOD_MAX     (10000 * JIGGLE_MS)
#define JIGGLE_PER_MS_MAX     100
// Scan gap counted as 1 ms: the steps it missed are dropped, not made at once.
#define JIGGLE_STALL_MS       10
// Change of the radius or the delay: a tap, each repeat while held.
#define JIGGLE_TAP_STEP       1
#define JIGGLE_HOLD_STEP      10
// A key released within JIGGLE_HOLD_MS is a tap: a quick press, as when typing
// a letter, lasts less.
#define JIGGLE_HOLD_MS        120
// Repeats while held: the first one JIGGLE_HOLD_MS after the press, the next
// ones JIGGLE_REPEAT_FIRST_MS apart, each gap 1/8 shorter, down to
// JIGGLE_REPEAT_LAST_MS.
#define JIGGLE_REPEAT_FIRST_MS 200
#define JIGGLE_REPEAT_LAST_MS  10
#define JIGGLE_RADIUS_DEFAULT 10
#define JIGGLE_RADIUS_MIN     1
#define JIGGLE_RADIUS_MAX     2000

static bool     jiggle_active = false;
static uint8_t  jiggle_click  = 0; // 0: no click, 1-8: N, NE, E ... NW
static int16_t  jiggle_radius = JIGGLE_RADIUS_DEFAULT;
static uint32_t jiggle_period = JIGGLE_PERIOD_DEFAULT; // between two steps
static uint32_t jiggle_budget = 0; // time owed to steps, same unit
static int16_t  jiggle_x      = 0; // cursor offset from the center, y down
static int16_t  jiggle_y      = 0;
static int16_t  jiggle_on     = 0; // radius of (jiggle_x, jiggle_y), 0: never
static int16_t  jiggle_dx     = 0; // steps made, not sent yet
static int16_t  jiggle_dy     = 0;
static uint16_t jiggle_timer  = 0;

// Click points of jiggle_click 1-8, as directions from the center, y down.
static const int8_t jiggle_click_dir[8][2] = {
    {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1},
};

// Radius or delay key pressed (M_JG_RUP/RDN/DUP/DDN), 0 = none.
static uint16_t jiggle_key         = 0;
static bool     jiggle_key_held    = false; // held past JIGGLE_HOLD_MS
static bool     jiggle_key_stopped = false; // limit reached while held
static uint16_t jiggle_key_pressed = 0;
static uint16_t jiggle_repeat_timer  = 0;
static uint16_t jiggle_repeat_ms     = 0;

/**
 * Volume of every sound, in percent of the DAC full scale. jiggle_on_sound
 * plays at AUDIO_QUIET_PERCENT: high notes come out louder than low ones on the
 * keyboard speaker. matrix_scan_user() sets it back to 100 once
 * JIGGLE_ON_SOUND_MS are over.
 */
#define AUDIO_QUIET_PERCENT 50
static uint8_t  audio_volume       = 100;
static uint16_t audio_volume_timer = 0;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_0] = LAYOUT_moonlander(
  /* ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓   ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓ */
  /* ┃   Esc   │   & 1   │   é 2   │   " 3   │   ' 4   │   ( 5   │ Goto L5 ┃   ┃  Pscr   │   - 6   │   è 7   │   _ 8   │   ç 9   │   à 0   │  Bkspc  ┃ */
       KC_ESC  ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   , M_L5_SP ,     KC_PSCR , KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   ,  KC_BSPC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃   Tab   │   a A   │   z Z   │   e E   │   r R   │   t T   │   Del   ┃   ┃  Bkspc  │   y Y   │   u U   │   i I   │   o O   │   p P   │   ^ ¨   ┃ */
       KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   , KC_DEL  ,     KC_BSPC ,  KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   , KC_LBRC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃  Bkspc  │   q Q   │   s S   │   d D   │   f F   │   g G   │   Del   ┃   ┃ RShft ⇧ │   h H   │   j J   │   k K   │   l L   │   m M   │ Enter ⏎ ┃ */
       KC_BSPC ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   , KC_DEL  ,     KC_RSFT ,  KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , KC_SCLN , KC_ENT  ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛   ┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃ LShft ⇧ │   w W   │   x X   │   c C   │   v V   │   b B   ┃                       ┃   n N   │   , ?   │   ; .   │   : /   │   ! §   │ RShft ⇧ ┃ */
       KC_LSFT ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,                          KC_N   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛┏━━━━━━━━━┓ ┏━━━━━━━━━┓┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃  LCtl   │         │   LAlt  │   Del   │   Del   ┃          ┃ Goto L4 ┃ ┃  <> </> ┃          ┃   Spc   │   RSft  │   RAlt  │   RGui  │   RCtl  ┃ */
       KC_LCTL , KC_MEH  , KC_LALT , KC_DEL  , KC_DEL  ,           TD(TD_RF),  TD(TD_ATG),           KC_SPC  , KC_RSFT , KC_RALT , KC_RGUI , KC_RCTL ,
  /* ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛          ┠─────────┨ ┠─────────┨          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ */
  /*                                          ┏━━━━━━━━━┯━━━━━━━━━╃─────────┨ ┠─────────╄━━━━━━━━━┯━━━━━━━━━┓                                          */
  /*                                          ┃   ~L3   │   ~L2   │  Lgui   ┃ ┃  Nbsp   │   ~L2   │  ~L1    ┃                                          */
                                                MO(L_3) , MO(L_2) , KC_LGUI ,   M_NBSP  , MO(L_2) , MO(L_1)
  /*                                          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛                                          */
    ),

    [L_1] = LAYOUT_moonlander(
  /* ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓   ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓ */
  /* ┃   Esc   │    f①   │    f②   │    f③   │    f④   │    f⑤   │    f⑥   ┃   ┃   f⑦    │    f⑧   │    f⑨   │   f⑩    │   f⑪    │   f⑫    │  Bkspc  ┃ */
       _______ ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,      KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 , KC_BSPC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃    -    │    \    │    *    │    $    │    {    │    }    │    ~    ┃   ┃  Sign.  │  PgUp   │ Ctrl ←  │    ↑    │ Ctrl →  │  PgDn   │   ^ ¨   ┃ */
       _______ ,  M_BKS  , KC_BSLS , KC_RBRC ,  M_LBK  ,  M_RBK  ,  M_TLD  ,     M_EMAIL1, KC_PGUP , C_LEFT  ,  KC_UP  , C_RIGHT , KC_PGDN , KC_LBRC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃    -    │    =    │    |    │    /    │    (    │    )    │         ┃   ┃  Email  │   Home  │    ←    │    ↓    │    →    │   End   │ Enter ⏎ ┃ */
        C_HTG  , KC_EQL  ,  M_PPE  ,  M_SLH  ,  KC_5   , KC_MINS ,  I_PCT  ,     M_EMAIL2, KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_END  , KC_PENT ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛   ┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │    <    │    @    │    >    │    [    │    ]    ┃                       ┃   n N   │   Bspc  │   Del   │  PgDn   │         │ RShft ⇧ ┃ */
       _______ , KC_NUBS ,  M_ARB  ,  M_GT   ,  M_OSB  ,  M_CSB  ,                         _______ , KC_BSPC , KC_DEL  , KC_PGDN , _______ , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛┏━━━━━━━━━┓ ┏━━━━━━━━━┓┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃ Delay + │ Delay - │Click dir│Radius + │Radius - ┃          ┃         ┃ ┃         ┃          ┃   Spc   │         │         │         │         ┃ */
       M_JG_DUP, M_JG_DDN, M_JG_CTG, M_JG_RUP, M_JG_RDN,            _______ ,   _______ ,            KC_SPC  , _______ , _______ , _______ , _______ ,
  /* ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛          ┠─────────┨ ┠─────────┨          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ */
  /*                                          ┏━━━━━━━━━┯━━━━━━━━━╃─────────┨ ┠─────────╄━━━━━━━━━┯━━━━━━━━━┓                                          */
  /*                                          ┃         │         │         ┃ ┃CtlAlt K │ Jig tog │         ┃                                          */
                                                _______ , _______ , _______ ,   C_Alt_K , M_JG_TOG, _______
  /*                                          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛                                          */
    ),

    [L_2] = LAYOUT_moonlander(
  /* ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓   ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓ */
  /* ┃         │         │         │         │         │         │         ┃   ┃  CAPS   │   NUM   │   NUM   │    /    │    *    │   P-    │  Bkspc  ┃ */
       _______ , _______ , _______ , _______ , _______ , _______ , _______ ,     KC_CAPS , KC_NUM  , KC_NUM  , KC_PSLS , KC_PAST , KC_PMNS , KC_BSPC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │ CtAlt↑  │    û    │    ù    │    ~    ┃   ┃ Sign. L │  Copy   │   P7    │   P8    │   P9    │   P+    │   ^ ¨   ┃ */
       _______ , _______ , _______ ,  X_MX   ,  M_C_U  , KC_QUOT ,  M_TLD  ,     M_SIGN1 , _______ ,  KC_P7  ,  KC_P8  ,  KC_P9  , KC_PPLS , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃   ()    │    -    │ CtAlt←  │ CtAltB  │ CtAlt→  │    ù    │    ù    ┃   ┃ Sign. L │  Home   │   P4    │   P5    │   P6    │   P+    │ PEnt  ⏎ ┃ */
        M_PAR  , _______ ,  X_LT   ,  X_SB   ,  X_RT   , KC_QUOT , KC_QUOT ,     M_SIGN2 , KC_HOME ,  KC_P4  ,  KC_P5  ,  KC_P6  , KC_PPLS , KC_PENT ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛   ┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         │         ┃                       ┃         │         │         │         │         │         ┃ */
  /* ┃    -    │    â    │    ê    │    î    │    ô    │   ``    ┃                       ┃    -    │   P1    │   P2    │   P3    │ PEnt  ⏎ │ RShft ⇧ ┃ */
       _______ ,  M_C_A  ,  M_C_E  ,  M_C_I  ,  M_C_O  , M_BQT   ,                         _______ ,  KC_P1  ,  KC_P2  ,  KC_P3  , KC_PENT , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛┏━━━━━━━━━┓ ┏━━━━━━━━━┓┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │ Ctl + [ │ Ctl + ] ┃          ┃         ┃ ┃         ┃          ┃   P0    │    .    │         │         │         ┃ */
       _______ , _______ , _______ , M_COSB  , M_CCSB  ,            _______ ,   _______ ,             KC_P0  , KC_PDOT , _______ , _______ , _______ ,
  /* ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛          ┠─────────┨ ┠─────────┨          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ */
  /*                                          ┏━━━━━━━━━┯━━━━━━━━━┛         ┃ ┃         ┗━━━━━━━━━━━━━━━━━━━┓                                          */
                                                _______ , _______ , _______ ,   _______ , _______ , _______
  /*                                          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛                                          */
    ),

    [L_3] = LAYOUT_moonlander(
  /* Copy/paste + all Linux flavors for my left hand                           Right hand = moving cursor + cut/copy/paste                             */
  /* ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓   ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓ */
  /* ┃   Esc   │    f①   │    f②   │    f③   │    f④   │    f⑤   │    f⑥   ┃   ┃   f⑦    │    f⑧   │    f⑨   │   f⑩    │   f⑪    │   f⑫    │  Bkspc  ┃ */
       _______ ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,      KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 , KC_BSPC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃    -    │    \    │ C-Copy  │ C-Paste │ L-Copy  │ L-Paste │ Sent. 1 ┃   ┃  Bkspc  │  PgUp   │ Ctrl ←  │    ↑    │ Ctrl →  │  PgDn   │   ^ ¨   ┃ */
       _______ ,  M_BKS  , C_COPY  , C_PASTE , L_COPY  , L_PASTE , M_STCE_1,     KC_BSPC , KC_PGUP , C_LEFT  ,  KC_UP  , C_RIGHT , KC_PGDN , KC_LBRC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃    -    │    =    │  C-Cut  │ C-Paste │ I-Copy  │ I-Paste │ Sent. 2 ┃   ┃ RShft ⇧ │   Home  │    ←    │    ↓    │    →    │   End   │ Enter ⏎ ┃ */
        C_HTG  , KC_EQL  ,  C_CUT  , C_PASTE , I_COPY  , I_PASTE , M_STCE_2,     KC_RSFT , KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_END  , KC_PENT ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛   ┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃ LShft ⇧ │    <    │    @    │    >    │  I-Cut  │ I-Paste ┃                       ┃   n N   │   Bspc  │   Del   │  PgDn   │         │ RShft ⇧ ┃ */
       _______ , KC_NUBS ,  M_ARB  ,  M_GT   ,  I_CUT  , I_PASTE ,                         _______ , KC_BSPC , KC_DEL  , KC_PGDN , _______ , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛┏━━━━━━━━━┓ ┏━━━━━━━━━┓┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         ┃          ┃         ┃ ┃         ┃          ┃   Spc   │ I-Copy  │ I-Paste │         │         ┃ */
       _______ , _______ , _______ , _______ , _______ ,            _______ ,   _______ ,            KC_SPC  , I_COPY  , I_PASTE , _______ , _______ ,
  /* ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛          ┠─────────┨ ┠─────────┨          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ */
  /*                                          ┏━━━━━━━━━┯━━━━━━━━━┛         ┃ ┃         ┗━━━━━━━━━━━━━━━━━━━┓                                          */
                                                _______ , _______ , C_Alt_W ,   _______ , _______ , _______
  /*                                          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛                                          */
    ),

    [L_4] = LAYOUT_moonlander(

  /* RM_TOGG  | Toggle RGB Matrix on/off                                       */
  /* RM_NEXT  | Next RGB Matrix effect, RM_PREV for previous                   */
  /* RM_HUEU  | Increase hue, decrease hue when Shift is held                  */
  /* RM_HUED  | Decrease hue, increase hue when Shift is held                  */
  /* RM_SATU  | Increase saturation, decrease saturation when Shift is held    */
  /* RM_SATD  | Decrease saturation, increase saturation when Shift is held    */
  /* RM_VALU  | Increase value (brightness), decrease value when Shift is held */
  /* RM_VALD  | Decrease value (brightness), increase value when Shift is held */

  /* ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓   ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓ */
  /* ┃ A on/off│         │         │         │         │         │         ┃   ┃         │         │         │         │         │         │         ┃ */
       RM_TOGG , _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         │         │         ┃   ┃         │         │         │         │         │         │         ┃ */
       _______ , _______ , _______ , _______ , RM_SATU , RM_SATD , _______ ,     _______ , _______ ,  AU_ON  , MU_ON   , CK_ON   , _______ , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         │         │         ┃   ┃         │         │         │(Audio/J)│(Click/J)│         │         ┃ */
       _______ , _______ , _______ , _______ , RM_VALU , RM_VALD , _______ ,     _______ , _______ ,  AU_OFF , MU_OFF  , CK_OFF  , _______ , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛   ┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         │         ┃                       ┃         │         │         │         │         │         ┃ */
       _______ , _______ , _______ , _______ , RM_HUEU , RM_HUED ,                         _______ , _______ , MU_NEXT , CK_UP   , _______ , _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛┏━━━━━━━━━┓ ┏━━━━━━━━━┓┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         ┃          ┃ Goto L4 ┃ ┃         ┃          ┃         │         │         │         │         ┃ */
       _______ , _______ , _______ , _______ , _______ ,           TD(TD_RF),   _______ ,            _______ , MU_TOGG , CK_DOWN , _______ , _______ ,
  /* ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛          ┠─────────┨ ┠─────────┨          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ */
  /*                                          ┏━━━━━━━━━┯━━━━━━━━━┛         ┃ ┃         ┗━━━━━━━━━━━━━━━━━━━┓                                          */
                                               RM_PREV , RM_NEXT , _______ ,   _______ , _______ , _______
  /*                                          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛                                          */
      ),

    [L_5] = LAYOUT_moonlander(

  /* ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓   ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓ */
  /* ┃         │         │         │         │         │         │ Goto L0 ┃   ┃         │         │         │         │         │         │         ┃ */
       _______ ,M_SOUND00,M_SOUND01,M_SOUND02,M_SOUND03,M_SOUND04, M_L5_SP,      _______ ,M_SOUND20,M_SOUND21,M_SOUND22,M_SOUND23,M_SOUND24, _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         │         │         ┃   ┃         │         │         │         │         │         │         ┃ */
       _______ ,M_SOUND05,M_SOUND06,M_SOUND07,M_SOUND08,M_SOUND09, _______ ,     _______ ,M_SOUND25,M_SOUND26,M_SOUND27,M_SOUND28,M_SOUND29, _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         │         │         ┃   ┃         │         │         │         │         │         │         ┃ */
       _______ ,M_SOUND10,M_SOUND11,M_SOUND12,M_SOUND13,M_SOUND14, _______ ,     _______ ,M_SOUND30,M_SOUND31,M_SOUND32,M_SOUND33,M_SOUND34, _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛   ┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         │         ┃                       ┃         │         │         │         │         │         ┃ */
       _______ ,M_SOUND15,M_SOUND16,M_SOUND17,M_SOUND18,M_SOUND19,                        M_SOUND35,M_SOUND36,M_SOUND37,M_SOUND38,M_SOUND39, _______ ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛┏━━━━━━━━━┓ ┏━━━━━━━━━┓┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │         │         │         │         ┃          ┃         ┃ ┃         ┃          ┃         │         │         │         │         ┃ */
       _______ , _______ , _______ , _______ , _______ ,            _______ ,   _______ ,            _______ , _______ , _______ , _______ , _______ ,
  /* ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛          ┠─────────┨ ┠─────────┨          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ */
  /*                                          ┏━━━━━━━━━┯━━━━━━━━━┛         ┃ ┃         ┗━━━━━━━━━━━━━━━━━━━┓                                          */
                                                _______ , _______ , _______ ,   _______ , _______ , _______
  /*                                          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛                                          */
      ),
    [L_6] = LAYOUT_moonlander(
  /* ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓   ┏━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┯━━━━━━━━━┓ */
  /* ┃   Esc   │   & 1   │   é 2   │   " 3   │   ' 4   │   ( 5   │ Goto L0 ┃   ┃  Pscr   │   - 6   │   è 7   │   _ 8   │   ç 9   │   à 0   │  Bkspc  ┃ */
       KC_ESC  ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   , M_L6_SP ,     KC_PSCR , KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   ,  KC_BSPC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃   Tab   │   a A   │   z Z   │   e E   │   r R   │   t T   │RapidF Up┃   ┃  Bkspc  │   y Y   │   u U   │   i I   │   o O   │   p P   │   ^ ¨   ┃ */
       KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,RF_SPD_UP,     KC_BSPC ,  KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   , KC_LBRC ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨   ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │   q Q   │   s S   │   d D   │   f F   │   g G   │RapidF Dn┃   ┃ RShft ⇧ │   h H   │   j J   │   k K   │   l L   │   m M   │ Enter ⏎ ┃ */
       _______ ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,RF_SPD_DN,     KC_RSFT ,  KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , KC_SCLN , KC_ENT  ,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛   ┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃         │   w W   │   x X   │   c C   │   v V   │   b B   ┃                       ┃   n N   │   , ?   │   ; .   │   : /   │   ! §   │ RShft ⇧ ┃ */
       _______ ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,                          KC_N   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
  /* ┠─────────┼─────────┼─────────┼─────────┼─────────┲━━━━━━━━━┛┏━━━━━━━━━┓ ┏━━━━━━━━━┓┗━━━━━━━━━┱─────────┼─────────┼─────────┼─────────┼─────────┨ */
  /* ┃  LCtl   │         │   LAlt  │   Del   │   Del   ┃          ┃ Goto L4 ┃ ┃  <> </> ┃          ┃   Spc   │   RSft  │   RAlt  │   RGui  │   RCtl  ┃ */
       KC_LCTL , KC_MEH  , KC_LALT , KC_DEL  , KC_DEL  ,           TD(TD_RF),  TD(TD_ATG),           RF_SPACE, KC_RSFT , KC_RALT , KC_RGUI , KC_RCTL ,
  /* ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛          ┠─────────┨ ┠─────────┨          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ */
  /*                                          ┏━━━━━━━━━┯━━━━━━━━━╃─────────┨ ┠─────────╄━━━━━━━━━┯━━━━━━━━━┓                                          */
  /*                                          ┃ RapidF3 │ RapidF1 │ RapidF2 ┃ ┃  Nbsp   │   ~L2   │  ~L1    ┃                                          */
                                               RF_MOUSE3,RF_MOUSE1,RF_MOUSE2,   M_NBSP  , MO(L_2) , MO(L_1)
  /*                                          ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛ ┗━━━━━━━━━┷━━━━━━━━━┷━━━━━━━━━┛                                          */
    ),
};

/**
 * Music mode (MU_ON): 40 consecutive semitones on the three middle rows.
 *
 * Neither music_map nor music_on_user() is referenced in this file: QMK uses
 * them itself.
 * - music_map: read by process_music() in
 *   quantum/process_keycode/process_music.c on every key event while music mode
 *   is on, to pick the note of the key. It overrides the weak default of
 *   keyboards/zsa/moonlander/moonlander.c.
 * - music_on_user(): called by music_on() in the same file, i.e. when MU_ON is
 *   pressed, or MU_TOGG while music mode is off.
 *
 * Value = semitones above C3 (130.8 Hz): bottom row 0-11, home row 12-25, top
 * letter row 26-39 (D#6, 1244.5 Hz). Each row rises from the left hand to the
 * right hand. Every other key plays C3 (value 0). Rows 0-5 = left half, rows
 * 6-11 = right half; columns run left to right.
 *
 * Usage: tap TD(TD_RF) -> L4, press MU_ON (I), tap TD(TD_RF) again -> back to
 * L0, play. Stop: L4, MU_OFF (K). Silence everywhere: audio is off -> L4, AU_ON
 * (U).
 */
const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = {
    { 0,  0,  0,  0,  0,  0,  0},
    {26, 27, 28, 29, 30, 31, 32},
    {12, 13, 14, 15, 16, 17, 18},
    { 0,  1,  2,  3,  4,  5,  0},
    { 0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0},
    {33, 34, 35, 36, 37, 38, 39},
    {19, 20, 21, 22, 23, 24, 25},
    { 0,  6,  7,  8,  9, 10, 11},
    { 0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0}
};

extern uint8_t music_mode;
extern int     music_offset;

// Chromatic mode with a zero offset: note = 48 (C3) + music_map value.
void music_on_user(void) {
    music_mode   = MUSIC_MODE_CHROMATIC;
    music_offset = 0;
}

uint16_t rapid_fire_1 = 0;
uint16_t rapid_fire_2 = 0;
uint16_t rapid_fire_wait_counter = 0;
uint16_t rapid_fire_wait_limit = 120;

/**
 * Sends one mouse report. The buttons held through mouse keys (MS_BTN1...) stay
 * down, so the jiggler does not release them.
 */
static void jiggle_report(int8_t dx, int8_t dy, uint8_t buttons) {
    report_mouse_t report = {0};
    report.buttons = mousekey_get_report().buttons | buttons;
    report.x       = dx;
    report.y       = dy;
    host_mouse_send(&report);
}

// Sends a move of (dx, dy), split in reports of at most 127 per axis.
static void jiggle_send(int16_t dx, int16_t dy) {
    while (dx || dy) {
        int8_t sx = dx > 127 ? 127 : (dx < -127 ? -127 : dx);
        int8_t sy = dy > 127 ? 127 : (dy < -127 ? -127 : dy);
        jiggle_report(sx, sy, 0);
        dx -= sx;
        dy -= sy;
    }
}

// Moves the cursor by (dx, dy) right away.
static void jiggle_move(int16_t dx, int16_t dy) {
    jiggle_x += dx;
    jiggle_y += dy;
    jiggle_send(dx, dy);
}

// Sends the steps made since the last report.
static void jiggle_flush(void) {
    jiggle_send(jiggle_dx, jiggle_dy);
    jiggle_dx = 0;
    jiggle_dy = 0;
}

// Distance of (x, y) to the circle, as |x^2 + y^2 - r^2|.
static int32_t jiggle_error(int32_t x, int32_t y) {
    int32_t e = x * x + y * y - (int32_t)jiggle_radius * jiggle_radius;
    return e < 0 ? -e : e;
}

/**
 * Makes one pixel step clockwise (on screen, y pointing down) along the circle,
 * sent by the next jiggle_flush(). Crossing the click point of jiggle_click,
 * the half line from the center along (cx, cy), it sends the steps so far, then
 * a left click: the cross product cx * y - cy * x turns from negative to zero
 * or positive while the dot product cx * x + cy * y stays positive.
 */
static void jiggle_step(void) {
    // Clockwise tangent at (x, y) with y pointing down: (-y, x).
    int8_t sx = jiggle_y > 0 ? -1 : (jiggle_y < 0 ? 1 : 0);
    int8_t sy = jiggle_x > 0 ? 1 : (jiggle_x < 0 ? -1 : 0);
    if (!sx && !sy) {
        sy = 1;
    }
    int8_t  best_x = sx;
    int8_t  best_y = sx ? 0 : sy;
    int32_t best_e = jiggle_error(jiggle_x + best_x, jiggle_y + best_y);
    if (sx && sy) {
        int32_t e = jiggle_error(jiggle_x, jiggle_y + sy);
        if (e < best_e) {
            best_x = 0;
            best_y = sy;
            best_e = e;
        }
        e = jiggle_error(jiggle_x + sx, jiggle_y + sy);
        if (e < best_e) {
            best_x = sx;
            best_y = sy;
        }
    }
    int8_t  cx     = 0;
    int8_t  cy     = 0;
    int32_t before = 0;
    if (jiggle_click) {
        cx     = jiggle_click_dir[jiggle_click - 1][0];
        cy     = jiggle_click_dir[jiggle_click - 1][1];
        before = (int32_t)cx * jiggle_y - (int32_t)cy * jiggle_x;
    }
    jiggle_x += best_x;
    jiggle_y += best_y;
    jiggle_dx += best_x;
    jiggle_dy += best_y;
    if (jiggle_click && before < 0 &&
        (int32_t)cx * jiggle_y - (int32_t)cy * jiggle_x >= 0 &&
        (int32_t)cx * jiggle_x + (int32_t)cy * jiggle_y > 0) {
        jiggle_flush();
        jiggle_report(0, 0, MOUSE_BTN1);
        jiggle_report(0, 0, 0);
    }
}

/**
 * Moves the cursor along its radius from the circle of radius jiggle_on to the
 * one of radius jiggle_radius. The first time, jiggle_on is 0 and the cursor
 * goes from the center to the rightmost point of the circle.
 */
static void jiggle_fit(void) {
    if (!jiggle_on) {
        jiggle_move(jiggle_radius, 0);
    } else if (jiggle_on != jiggle_radius) {
        int16_t x = (int32_t)jiggle_x * jiggle_radius / jiggle_on;
        int16_t y = (int32_t)jiggle_y * jiggle_radius / jiggle_on;
        jiggle_move(x - jiggle_x, y - jiggle_y);
    }
    jiggle_on = jiggle_radius;
}

/**
 * Adds step pixels (removes if negative) to jiggle_radius, kept within
 * JIGGLE_RADIUS_MIN and JIGGLE_RADIUS_MAX; while the jiggler runs, the cursor
 * moves to the new circle. Already at that limit: plays its sound and returns
 * false.
 */
static bool jiggle_radius_add(int16_t step) {
    if (step > 0 && jiggle_radius >= JIGGLE_RADIUS_MAX) {
        PLAY_SONG(jiggle_radius_max_sound);
        return false;
    }
    if (step < 0 && jiggle_radius <= JIGGLE_RADIUS_MIN) {
        PLAY_SONG(jiggle_radius_min_sound);
        return false;
    }
    int32_t radius = (int32_t)jiggle_radius + step;
    if (radius > JIGGLE_RADIUS_MAX) {
        radius = JIGGLE_RADIUS_MAX;
    } else if (radius < JIGGLE_RADIUS_MIN) {
        radius = JIGGLE_RADIUS_MIN;
    }
    jiggle_radius = radius;
    if (jiggle_active) {
        jiggle_fit();
    }
    return true;
}

// Pixels per millisecond of a jiggle_period of 1 ms or less, rounded.
static uint32_t jiggle_per_ms(void) {
    return (JIGGLE_MS + jiggle_period / 2) / jiggle_period;
}

/**
 * Lengthens (step > 0) or shortens (step < 0) jiggle_period by |step| ms from
 * 1 ms up, by |step| pixels per millisecond below, kept within
 * JIGGLE_PER_MS_MAX pixels per millisecond and JIGGLE_PERIOD_MAX; it stops at
 * 1 ms on the way across. Already at that limit: plays its sound and returns
 * false.
 */
static bool jiggle_delay_add(int16_t step) {
    if (step > 0) {
        if (jiggle_period >= JIGGLE_PERIOD_MAX) {
            PLAY_SONG(jiggle_delay_max_sound);
            return false;
        }
        if (jiggle_period < JIGGLE_MS) {
            int32_t n     = (int32_t)jiggle_per_ms() - step;
            jiggle_period = n > 1 ? JIGGLE_MS / n : JIGGLE_MS;
        } else {
            jiggle_period += (uint32_t)step * JIGGLE_MS;
            if (jiggle_period > JIGGLE_PERIOD_MAX) {
                jiggle_period = JIGGLE_PERIOD_MAX;
            }
        }
    } else {
        uint32_t less = (uint32_t)(-step) * JIGGLE_MS;
        if (jiggle_period > JIGGLE_MS) {
            jiggle_period = jiggle_period - JIGGLE_MS > less ?
                jiggle_period - less : JIGGLE_MS;
        } else {
            uint32_t n = jiggle_per_ms();
            if (n >= JIGGLE_PER_MS_MAX) {
                PLAY_SONG(jiggle_delay_min_sound);
                return false;
            }
            n += -step;
            if (n > JIGGLE_PER_MS_MAX) {
                n = JIGGLE_PER_MS_MAX;
            }
            jiggle_period = JIGGLE_MS / n;
        }
    }
    return true;
}

/**
 * Changes by amount the value of a radius or delay key: up for M_JG_RUP /
 * M_JG_DUP, down for M_JG_RDN / M_JG_DDN. Returns false at the limit.
 */
static bool jiggle_key_add(uint16_t keycode, int16_t amount) {
    switch (keycode) {
        case M_JG_RUP:
            return jiggle_radius_add(amount);
        case M_JG_RDN:
            return jiggle_radius_add(-amount);
        case M_JG_DUP:
            return jiggle_delay_add(amount);
        case M_JG_DDN:
            return jiggle_delay_add(-amount);
    }
    return false;
}

// Key repeat of a held radius or delay key, called on every matrix scan.
static void jiggle_key_repeat(void) {
    if (!jiggle_key || jiggle_key_stopped) {
        return;
    }
    if (!jiggle_key_held) {
        if (timer_elapsed(jiggle_key_pressed) < JIGGLE_HOLD_MS) {
            return;
        }
        jiggle_key_held  = true;
        jiggle_repeat_ms = JIGGLE_REPEAT_FIRST_MS;
    } else if (timer_elapsed(jiggle_repeat_timer) < jiggle_repeat_ms) {
        return;
    } else if (jiggle_repeat_ms > JIGGLE_REPEAT_LAST_MS) {
        jiggle_repeat_ms -= jiggle_repeat_ms / 8;
        if (jiggle_repeat_ms < JIGGLE_REPEAT_LAST_MS) {
            jiggle_repeat_ms = JIGGLE_REPEAT_LAST_MS;
        }
    }
    jiggle_repeat_timer = timer_read();
    if (!jiggle_key_add(jiggle_key, JIGGLE_HOLD_STEP)) {
        jiggle_key_stopped = true;
    }
}

#if AUDIO_MAX_SIMULTANEOUS_TONES != 1
#    error "dac_value_generate() below plays a single tone"
#endif

/**
 * Sine wave of the dac_additive audio driver, from 0 to 4095 with its middle
 * AUDIO_DAC_OFF_VALUE as silence: one period over 256 samples, starting at 0.
 */
static const uint16_t dac_sine[256] = {
       0,    1,    2,    6,   10,   15,   22,   30,   39,   50,   61,   74,
      88,  103,  120,  137,  156,  176,  197,  219,  242,  266,  291,  318,
     345,  373,  403,  433,  465,  497,  530,  565,  600,  636,  672,  710,
     749,  788,  828,  869,  910,  952,  995, 1038, 1082, 1127, 1172, 1218,
    1264, 1311, 1358, 1405, 1453, 1501, 1550, 1599, 1648, 1697, 1747, 1797,
    1847, 1897, 1947, 1997, 2048, 2098, 2148, 2198, 2248, 2298, 2348, 2398,
    2447, 2496, 2545, 2594, 2642, 2690, 2737, 2784, 2831, 2877, 2923, 2968,
    3013, 3057, 3100, 3143, 3185, 3226, 3267, 3307, 3346, 3385, 3423, 3459,
    3495, 3530, 3565, 3598, 3630, 3662, 3692, 3722, 3750, 3777, 3804, 3829,
    3853, 3876, 3898, 3919, 3939, 3958, 3975, 3992, 4007, 4021, 4034, 4045,
    4056, 4065, 4073, 4080, 4085, 4089, 4093, 4094, 4095, 4094, 4093, 4089,
    4085, 4080, 4073, 4065, 4056, 4045, 4034, 4021, 4007, 3992, 3975, 3958,
    3939, 3919, 3898, 3876, 3853, 3829, 3804, 3777, 3750, 3722, 3692, 3662,
    3630, 3598, 3565, 3530, 3495, 3459, 3423, 3385, 3346, 3307, 3267, 3226,
    3185, 3143, 3100, 3057, 3013, 2968, 2923, 2877, 2831, 2784, 2737, 2690,
    2642, 2594, 2545, 2496, 2447, 2398, 2348, 2298, 2248, 2198, 2148, 2098,
    2048, 1997, 1947, 1897, 1847, 1797, 1747, 1697, 1648, 1599, 1550, 1501,
    1453, 1405, 1358, 1311, 1264, 1218, 1172, 1127, 1082, 1038,  995,  952,
     910,  869,  828,  788,  749,  710,  672,  636,  600,  565,  530,  497,
     465,  433,  403,  373,  345,  318,  291,  266,  242,  219,  197,  176,
     156,  137,  120,  103,   88,   74,   61,   50,   39,   30,   22,   15,
      10,    6,    2,    1,
};

/**
 * Next DAC sample of the tone being played, at audio_volume percent of the full
 * scale. Overrides the weak dac_value_generate() of
 * platforms/chibios/drivers/audio_dac_additive.c, which calls it from its DAC
 * callback dac_end() for every sample while a sound plays, and waits for a
 * sample close to AUDIO_DAC_OFF_VALUE before it changes or stops the tone.
 *
 * The phase step is the driver's, frequency * 256 / AUDIO_DAC_SAMPLE_RATE *
 * 2/3: its timer runs at 3 * AUDIO_DAC_SAMPLE_RATE and the callback fires twice
 * per conversion. A rest (frequency 0) or the end of the sound lets the current
 * wave run on until it reaches silence, so the speaker does not click.
 */
uint16_t dac_value_generate(void) {
    static float phase     = 0.0f;
    static float frequency = 0.0f;
    const int32_t off      = AUDIO_DAC_OFF_VALUE;
    float playing = audio_get_number_of_active_tones() ?
        audio_get_processed_frequency(0) : 0.0f;
    if (playing > 0.0f) {
        frequency = playing;
    } else if (frequency <= 0.0f) {
        return off;
    }
    phase += frequency * (256.0f / AUDIO_DAC_SAMPLE_RATE * 2.0f / 3.0f);
    while (phase >= 256.0f) {
        phase -= 256.0f;
    }
    int32_t wave = ((int32_t)dac_sine[(uint8_t)phase] - off) * audio_volume;
    wave /= 100;
    if (playing <= 0.0f && wave < (int32_t)(AUDIO_DAC_SAMPLE_MAX / 100) &&
        wave > -(int32_t)(AUDIO_DAC_SAMPLE_MAX / 100)) {
        frequency = 0.0f;
        return off;
    }
    return off + wave;
}

/**
 * QMK calls matrix_scan_user() on every matrix scan: matrix_scan() in
 * quantum/matrix_common.c (CUSTOM_MATRIX = lite) calls the weak
 * matrix_scan_kb() of the same file, which calls it.
 */
void matrix_scan_user(void) {
    // Once per millisecond: makes the steps the elapsed time pays for, then
    // sends them as a single report.
    if (jiggle_active && timer_elapsed(jiggle_timer)) {
        uint16_t ms  = timer_elapsed(jiggle_timer);
        jiggle_timer = timer_read();
        if (ms > JIGGLE_STALL_MS) {
            ms = 1;
        }
        jiggle_budget += ms * JIGGLE_MS;
        while (jiggle_budget >= jiggle_period) {
            jiggle_budget -= jiggle_period;
            jiggle_step();
        }
        jiggle_flush();
    }
    jiggle_key_repeat();
    if (audio_volume != 100 &&
        timer_elapsed(audio_volume_timer) >= JIGGLE_ON_SOUND_MS) {
        audio_volume = 100;
    }
    if (rapid_fire_1 || rapid_fire_2) {
        rapid_fire_wait_counter++;
        rapid_fire_wait_counter = rapid_fire_wait_counter % rapid_fire_wait_limit;
        if (rapid_fire_wait_counter) {
            return;
        }
        if (rapid_fire_1) {
            tap_code16(rapid_fire_1);
        }
        if (rapid_fire_2) {
            tap_code16(rapid_fire_2);
        }
    }
}

/**
 * Wraps the word left of the caret in an HTML tag and leaves the caret between
 * the opening and the closing tag: cuts the word, types <word></word>, then
 * walks back over the closing tag. Called by the M_ATG keycode and by the tag
 * tap dance, which both send the same keystrokes.
 */
void send_advanced_tag(void) {
    SEND_STRING( \
        SS_DOWN(X_RCTL) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_UP(X_LSFT) \
        SS_TAP(X_X) SS_UP(X_RCTL) \
        SS_TAP(X_NUBS) \
        SS_DOWN(X_RCTL) SS_TAP(X_V) SS_UP(X_RCTL) \
        SS_DOWN(X_RSFT) SS_TAP(X_NUBS) SS_UP(X_RSFT) \
        SS_TAP(X_NUBS) \
        SS_DOWN(X_RSFT) SS_TAP(X_DOT) SS_UP(X_RSFT) \
        SS_DOWN(X_RCTL) SS_TAP(X_V) SS_UP(X_RCTL) \
        SS_DOWN(X_RSFT) SS_TAP(X_NUBS) SS_UP(X_RSFT) \
        SS_TAP(X_LEFT)SS_DOWN(X_RCTL) SS_TAP(X_LEFT) SS_UP(X_RCTL) \
        SS_TAP(X_LEFT) SS_TAP(X_LEFT));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        switch (keycode) {
        case RF_SPD_UP:
            if (rapid_fire_wait_limit > 1) {
                rapid_fire_wait_limit -= 5;
            } else {
                PLAY_SONG(dvorak_sound);
            }
            return false;
        case RF_SPD_DN:
            if (rapid_fire_wait_limit < 50) {
                rapid_fire_wait_limit += 5;
            } else {
                PLAY_SONG(colemak_sound);
            }
            return false;
        case RF_MOUSE1:
            rapid_fire_1 = MS_BTN1;
            rapid_fire_wait_counter = 0;
            return false;
        case RF_MOUSE2:
            rapid_fire_1 = MS_BTN2;
            rapid_fire_wait_counter = 0;
            return false;
        case RF_MOUSE3:
            rapid_fire_1 = MS_BTN1;
            rapid_fire_2 = MS_BTN2;
            rapid_fire_wait_counter = 0;
            return false;
        case RF_SPACE:
            rapid_fire_1 = KC_SPACE;
            return false;
        case M_L4_SP:
            PLAY_SONG(dvorak_sound);
            layer_invert(L_4);
            return false;
        case M_L5_SP:
            PLAY_SONG(colemak_sound);
            layer_invert(L_5);
            return false;
        case M_L6_SP:
            PLAY_SONG(goodbye_sound);
            layer_invert(L_6);
            return false;
        case M_VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case M_ATG: // Advanced tag <></>
             send_advanced_tag();
             return false;
        case M_SOUND00:
            PLAY_SONG(ode_to_joy);
            return false;
        case M_SOUND01:
            PLAY_SONG(rock_a_bye_baby);
            return false;
        case M_SOUND02:
            PLAY_SONG(clueboard_sound);
            return false;
        case M_SOUND03:
            PLAY_SONG(startup_sound);
            return false;
        case M_SOUND04:
            PLAY_SONG(goodbye_sound);
            return false;
        case M_SOUND05:
            PLAY_SONG(planck_sound);
            return false;
        case M_SOUND06:
            PLAY_SONG(preonic_sound);
            return false;
        case M_SOUND07:
            PLAY_SONG(qwerty_sound);
            return false;
        case M_SOUND08:
            PLAY_SONG(colemak_sound);
            return false;
        case M_SOUND09:
            PLAY_SONG(dvorak_sound);
            return false;
        case M_SOUND10:
            PLAY_SONG(workman_sound);
            return false;
        case M_SOUND11:
            PLAY_SONG(plover_sound);
            return false;
        case M_SOUND12:
            PLAY_SONG(plover_goodbye_sound);
            return false;
        case M_SOUND13:
            PLAY_SONG(music_on_sound);
            return false;
        case M_SOUND14:
            PLAY_SONG(audio_on_sound);
            return false;
        case M_SOUND15:
            PLAY_SONG(audio_off_sound);
            return false;
        case M_SOUND16:
            PLAY_SONG(music_scale_sound);
            return false;
        case M_SOUND17:
            PLAY_SONG(music_off_sound);
            return false;
        case M_SOUND18:
            PLAY_SONG(voice_change_sound);
            return false;
        case M_SOUND19:
            PLAY_SONG(chromatic_sound);
            return false;
        case M_SOUND20:
            PLAY_SONG(major_sound);
            return false;
        case M_SOUND21:
            PLAY_SONG(minor_sound);
            return false;
        case M_SOUND22:
            PLAY_SONG(guitar_sound);
            return false;
        case M_SOUND23:
            PLAY_SONG(violin_sound);
            return false;
        case M_SOUND24:
            PLAY_SONG(caps_lock_on_sound);
            return false;
        case M_SOUND25:
            PLAY_SONG(caps_lock_off_sound);
            return false;
        case M_SOUND26:
            PLAY_SONG(scroll_lock_on_sound);
            return false;
        case M_SOUND27:
            PLAY_SONG(scroll_lock_off_sound);
            return false;
        case M_SOUND28:
            PLAY_SONG(num_lock_on_sound);
            return false;
        case M_SOUND29:
            PLAY_SONG(num_lock_off_sound);
            return false;
        case M_SOUND30:
            PLAY_SONG(ag_norm_sound);
            return false;
        case M_SOUND31:
            PLAY_SONG(ag_swap_sound);
            return false;
        case M_SOUND32:
            PLAY_SONG(unicode_windows);
            return false;
        case M_SOUND33:
            PLAY_SONG(unicode_linux);
            return false;
        case M_SOUND34:
            PLAY_SONG(terminal_sound);
            return false;
        case M_SOUND35:
            PLAY_SONG(campanella);
            return false;
        case M_SOUND36:
            PLAY_SONG(fantasie_impromptu);
            return false;
        case M_SOUND37:
            PLAY_SONG(nocturne_op_9_no_1);
            return false;
        case M_SOUND38:
            PLAY_SONG(ussr_anthem);
            return false;
        case M_SOUND39:
            PLAY_SONG(tos_hymn_risen);
            return false;

        case M_SIGN1:
            SEND_STRING(SIGNATURE_1);
            return false;
        case M_SIGN2:
            PLAY_SONG(unicode_windows);
            SEND_STRING(SIGNATURE_2);
            return false;
        case M_STCE_1:
            SEND_STRING(SENTENCE_1);
            return false;
        case M_STCE_2:
            SEND_STRING(SENTENCE_2);
            return false;
        case M_EMAIL1:
            //PLAY_SONG(chromatic_sound);
            SEND_STRING(EMAIL_1);
            return false;
        case M_EMAIL2:
            //PLAY_SONG(planck_sound);
            SEND_STRING(EMAIL_2);
            return false;
        case M_NBSP: // &nbsp;
            SEND_STRING( \
                SS_TAP(X_1) SS_TAP(X_N) SS_TAP(X_B) SS_TAP(X_S) SS_TAP(X_P) \
                SS_TAP(X_COMM));
            return false;
        case M_PAR: // ()
            SEND_STRING(SS_TAP(X_5) SS_TAP(X_MINS) SS_TAP(X_LEFT));
            return false;
        case M_GT: // > Greater than
            SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_NUBS) SS_UP(X_RSFT));
            return false;
        case M_PPE: // | Pipe
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_6) SS_UP(X_RALT));
            return false;
        case M_BKS: // \ Backslash
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_8) SS_UP(X_RALT));
            return false;
        case M_LBK: // { Left bracket
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_4) SS_UP(X_RALT));
            return false;
        case M_RBK: // } Right bracket
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_EQL) SS_UP(X_RALT));
            return false;
        case M_SLH: // / Slash
            SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_DOT) SS_UP(X_RSFT));
            return false;
        case M_HTG: // # Hashtag
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_3) SS_UP(X_RALT));
            return false;
        case M_OSB: // [ Opening Square bracket
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_5) SS_UP(X_RALT));
            return false;
        case M_CSB: // ] Closing Square bracket
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_MINS) SS_UP(X_RALT));
            return false;
        case M_COSB: // [ Ctrl + Opening Square bracket
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RALT) \
                SS_TAP(X_5) SS_UP(X_RALT) SS_UP(X_LCTL));
            return false;
        case M_CCSB: // ] Ctrl + Closing Square bracket
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RALT) \
                SS_TAP(X_MINS) SS_UP(X_RALT) SS_UP(X_LCTL));
            return false;
        case M_ARB: // @ Arobase
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_0) SS_UP(X_RALT));
            return false;
        case M_TLD: // ~ Tilde
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_2) SS_UP(X_RALT) SS_TAP(X_SPC));
            return false;
        case M_BQT: // ` Backquote
            SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_7) SS_UP(X_RALT) SS_TAP(X_SPC) \
                SS_DOWN(X_RALT) SS_TAP(X_7) SS_UP(X_RALT) SS_TAP(X_SPC) \
                SS_TAP(X_LEFT));
            return false;
        case M_C_A: // â
            SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_Q));
            return false;
        case M_C_E: // ê
            SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_E));
            return false;
        case M_C_I: // î
            SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_I));
            return false;
        case M_C_O: // ô
            SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_O));
            return false;
        case M_C_U: // û
            SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_U));
            return false;
        case M_XLT: // LCtrl - LAlt - ←
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_LEFT) \
                SS_UP(X_LALT) SS_UP(X_LCTL));
            return false;
        case M_XRT: // LCtrl - LAlt - →
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_RIGHT) \
                SS_UP(X_LALT) SS_UP(X_LCTL));
            return false;
        case M_JG_TOG:
            if (!jiggle_active) {
                audio_volume       = AUDIO_QUIET_PERCENT;
                audio_volume_timer = timer_read();
                PLAY_SONG(jiggle_on_sound);
                jiggle_fit();
                jiggle_active = true;
                jiggle_timer  = timer_read();
                jiggle_budget = 0;
            } else {
                PLAY_SONG(jiggle_off_sound);
                jiggle_active = false;
            }
            return false;
        case M_JG_CTG:
            jiggle_click = (jiggle_click + 1) % 9;
            if (jiggle_click) {
                jiggle_click_sound[0][0] = jiggle_click_notes[jiggle_click - 1];
                jiggle_click_sound[2][0] = jiggle_click_notes[jiggle_click - 1];
                PLAY_SONG(jiggle_click_sound);
            } else {
                PLAY_SONG(jiggle_click_off_sound);
            }
            return false;
        case M_JG_RUP:
        case M_JG_RDN:
        case M_JG_DUP:
        case M_JG_DDN:
            jiggle_key         = keycode;
            jiggle_key_held    = false;
            jiggle_key_stopped = false;
            jiggle_key_pressed = timer_read();
            return false;
        }
    } else { // key released
        switch (keycode) {
        case M_JG_RUP:
        case M_JG_RDN:
        case M_JG_DUP:
        case M_JG_DDN:
            if (jiggle_key == keycode && !jiggle_key_held) {
                jiggle_key_add(keycode, JIGGLE_TAP_STEP);
            }
            if (jiggle_key == keycode) {
                jiggle_key = 0;
            }
            return false;
        case RF_MOUSE1:
        case RF_MOUSE2:
        case RF_MOUSE3:
        case RF_SPACE:
            rapid_fire_1 = 0;
            rapid_fire_2 = 0;
            return false;
        }
    }
    return true;
}

/* -------------------------------------------------------------------------- */
/* Tap Dance: footer: */
// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        return TD_TRIPLE_TAP;
    }
    return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // only change if not on layer 6:
            if (!layer_state_is(L_6)) {
                PLAY_SONG(dvorak_sound);
                layer_invert(L_4);
            }
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            PLAY_SONG(guitar_sound);
            if (layer_state_is(L_6)) {
                // already set: switch it off:
                layer_off(L_6);
            } else {
                // not already set: switch it on:
                layer_on(L_6);
            }
            break;
        case TD_TRIPLE_TAP:
            PLAY_SONG(ussr_anthem);
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    // if (ql_tap_state.state == TD_SINGLE_HOLD) {
    //     layer_off(L_3);
    // }
    ql_tap_state.state = TD_NONE;
}

// Initialize tap structure associated with the tag tap dance key
static td_tap_t atg_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

/**
 * Right thumb red key, mirror of the TD_RF key on the left: one tap wraps the
 * word in a tag, two taps wrap two words in a row, three taps play the Syntax
 * Terror intro theme. QMK calls this from the tap dance engine once the tap
 * count is settled, that is TAPPING_TERM after the last tap, so the tag now
 * waits 200 ms instead of firing on the key press.
 */
void atg_finished(tap_dance_state_t *state, void *user_data) {
    atg_tap_state.state = cur_dance(state);
    switch (atg_tap_state.state) {
        case TD_SINGLE_TAP:
            send_advanced_tag();
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            send_advanced_tag();
            send_advanced_tag();
            break;
        case TD_TRIPLE_TAP:
            PLAY_SONG(syntax_terror_intro);
            break;
        default:
            break;
    }
}

void atg_reset(tap_dance_state_t *state, void *user_data) {
    atg_tap_state.state = TD_NONE;
}

// Associate our tap dance keys with their functionality
tap_dance_action_t tap_dance_actions[] = {
    [TD_RF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
    [TD_ATG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, atg_finished, atg_reset)
};

