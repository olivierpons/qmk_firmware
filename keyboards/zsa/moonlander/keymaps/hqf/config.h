/**
 * Copyright 2026 Olivier Pons / HQF Development <olivier.pons@gmail.com>
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

#pragma once

/**
 * Audio: one tone at a time, the newest key wins, the others stay silent.
 *
 * The additive DAC driver can sum several tones, each divided by their count,
 * but on this speaker two tones buzz, at 16384 Hz as well as at 11025 Hz.
 *
 * The sample rate is spelled out because defining the tone count alone turns
 * off the AUDIO_DAC_QUALITY_SANE_MINIMUM preset that audio_dac.h picks when
 * nothing is set, which would raise the rate to 44100 Hz. 16384 Hz keeps a
 * 64 sample buffer and covers every note played here (highest: 3520 Hz).
 *
 * Not to be confused with config.local.h, the gitignored personal strings
 * included by keymap.c.
 */
#define AUDIO_DAC_SAMPLE_RATE 16384U
#define AUDIO_MAX_SIMULTANEOUS_TONES 1
