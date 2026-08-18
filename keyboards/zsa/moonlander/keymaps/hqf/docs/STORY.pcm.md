[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · [Bahasa Indonesia](STORY.id.md) · [Deutsch](STORY.de.md) · [日本語](STORY.ja.md) · **Naijá** · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · [Türkçe](STORY.tr.md) · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

*Dem use AI translate dis page. You see mistake? Pull request wey go improve dis translation, we go welcome am.*

# Everything Wey I Build For This Keyboard

My name na Olivier Pons, I be developer, and I dey type code, French, English, and now voice, whole day. This keymap no be layout wey I download — na years of small small change, commit by commit, wey I do so e go match exactly how I dey work, for Linux, for AZERTY. This page dey tell di full story — why e dey exist, and how e reach here.

## Di problem

Dem design AZERTY for typewriter, no be for programmer. Bracket and operator dey hide behind combination wey no easy, and to dey switch whole day between French and code dey cause wahala. Instead make I dey fight di layout, I build layer around am.

## Wetin di layers dey do

- **L0**: Base AZERTY, wey close to wetin my hand don already sabi.
- **L1**: Every symbol wey programmer need, without to comot for home row.
- **L2**: Numpad and French letter wey get accent.
- **L3**: Copy/paste and OS-specific shortcut, because Linux, Windows and macOS no dey ever agree.
- **L4/L5**: RGB light and sound, so I go sabi which layer I dey without to look.
- **L6**: E dey turn di keyboard to gaming controller.

## Keeping di screen awake

Early early I add mouse-jiggle macro (`M_JIG_ON` / `M_JIGOFF`): di cursor dey shake itself for one small square every 800ms, so di machine no go lock or idle during long call or long reading. One key go turn am on, one go turn am off.

## Turning di keyboard to controller

Layer 6 dey exist just for gaming: tap-dance for one key dey toggle am, and Rapid Fire macro dey repeat one key or mouse button for one timer wey I fit speed up or slow down live, from di keyboard sef, without to recompile di config.

## Feedback without to look down

RGB per layer and one library of QMK sound effect — including one "clicky" typing beep — mean say I go always sabi which mode I dey without to look di board. Small thing, but e save me plenty "wait, which layer I dey".

## Shortcut wey stop to be something I dey think about

Window-manager combo (Ctrl+Alt+bracket, Ctrl+Alt+Z), copy/paste wey dey work di same for Linux, Windows or macOS, HTML tag auto-completion, signature macro for things wey I dey type plenty times every day — one by one, dis ones stop to be things wey I need to think about.

## Staying current with QMK

QMK dey deprecate old keycode as time dey pass. When dem replace `RGB_*` and mouse keycode with `RM_*`/`MS_*`, I migrate di whole keymap instead make I leave am rot for old API.

## Giving am voice

Di newest part: Ctrl+Alt+K dey toggle [opons-voxd](https://github.com/olivierpons/opons-voxd), open source voice-dictation tool wey I sef build separate. Na di first key for dis board wey no just dey move text — e dey start to listen.

## Why I dey share dis one

Nobody suppose copy dis one just like dat — everybody hand and work style dey different. But di idea — layer for symbol, OS shortcut, feedback, macro, and now voice — fit save another person di years wey e take me reach here. Di full keymap and build instructions dey one folder up, for [di keymap README](../README.md).

---

> Dem translate am to di 20 languages wey people dey use pass for di world; correction through pull request, we go welcome am.
