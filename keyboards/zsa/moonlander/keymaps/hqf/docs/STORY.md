**English** · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md)

# Everything I Built For This Keyboard

This page is the full story: not just what the keymap does today, but how it got here, commit by commit, over months of small changes.

## Starting from a blank layout

I didn't want a Moonlander running a stock layout. I wanted AZERTY — my native layout — rebuilt from scratch for programming: symbols within reach, no memorized layer gymnastics for `{`, `[`, `|`. The first working version was the base I still build on today.

## Keeping the screen awake

Early on I added a mouse-jiggle macro (`M_JIG_ON` / `M_JIGOFF`): the cursor nudges itself in a small square every 800ms, so the machine doesn't lock or go idle during a long call or a long read. One key turns it on, one turns it off.

## Turning the board into a controller

Layer 6 exists purely for gaming: tap-dance on one key toggles it, and Rapid Fire macros repeat a key or mouse button on a timer I can speed up or slow down live, from the keyboard itself, no config recompile needed.

## Feedback without looking down

RGB per layer and a library of QMK sound effects — including a "clicky" typing beep — mean I always know what mode I'm in without glancing at the board. Small thing, saved a lot of "wait, which layer am I on."

## Shortcuts that stopped being conscious

Window-manager combos (Ctrl+Alt+bracket, Ctrl+Alt+Z), copy/paste that works the same whether I'm on Linux, Windows or macOS, HTML tag auto-completion, signature macros for the things I type dozens of times a day — one by one, these stopped being things I think about.

## Staying current with QMK

QMK deprecates keycodes over time. When `RGB_*` and mouse keycodes were replaced by `RM_*`/`MS_*`, I migrated the whole keymap rather than let it bit-rot on an old API.

## Giving it a voice

The newest piece: Ctrl+Alt+K toggles [opons-voxd](https://github.com/olivierpons/opons-voxd), an open-source voice-dictation tool I built separately. It's the first key on this board that doesn't just move text around — it starts listening.

## Writing it down

This keymap outgrew being just a config file a while back. It has behavior worth explaining, and I wanted that explanation to reach more people than just English or French readers — hence this page, and the shorter [ABOUT](ABOUT.md) page, both translated. The full keymap and build instructions are one level up, in [the keymap's README](../README.md).

---

> Translated into the 10 most-used languages in the world; corrections via pull request are welcome.
