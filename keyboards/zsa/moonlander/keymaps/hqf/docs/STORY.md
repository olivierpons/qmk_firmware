**English** · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · [Bahasa Indonesia](STORY.id.md) · [Deutsch](STORY.de.md) · [日本語](STORY.ja.md) · [Naijá](STORY.pcm.md) · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · [Türkçe](STORY.tr.md) · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

# Everything I Built For This Keyboard

I'm Olivier Pons, a developer who types code, French, English, and now voice, all day. This keymap isn't a layout I downloaded — it grew from years of small changes, commit by commit, to match exactly how I work, on Linux, in AZERTY. This page is the full story: why it exists, and how it got here.

## The problem

AZERTY was built for typewriters, not programmers. Brackets and operators sit behind awkward combos, and switching between French and code all day creates constant friction. Instead of fighting the layout, I built layers around it.

## The layers

- **L0**: base AZERTY, close to what my hands already know.
- **L1**: every symbol a programmer needs, without leaving the home row.
- **L2**: numpad and French accented characters.
- **L3**: copy/paste and OS shortcuts, since Linux, Windows and macOS never agree.
- **L4/L5**: RGB lighting and sound, so I know which layer I'm on without looking.
- **L6**: turns the board into a gaming controller.

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

## Why I share this

Nobody should copy this as-is — everyone's hands and workflow differ. But the idea — layers for symbols, OS shortcuts, feedback, macros, and now voice — might save someone else the years it took me to get here. The full keymap and build instructions are one level up, in [the keymap's README](../README.md).

---

> Translated into the 20 most-used languages in the world; corrections via pull request are welcome.
