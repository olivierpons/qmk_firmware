[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · [Bahasa Indonesia](STORY.id.md) · **Deutsch** · [日本語](STORY.ja.md) · [Naijá](STORY.pcm.md) · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · [Türkçe](STORY.tr.md) · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

*Mit KI-Unterstützung übersetzt. Fehler gefunden? Pull Requests zur Verbesserung dieser Übersetzung sind willkommen.*

# Alles, was ich für diese Tastatur gebaut habe

Ich bin Olivier Pons, Entwickler, und tippe den ganzen Tag Code, Französisch, Englisch und jetzt auch Sprache. Dieses Keymap ist kein heruntergeladenes Layout — es ist über Jahre aus kleinen Änderungen entstanden, Commit für Commit, um genau zu meiner Arbeitsweise zu passen, unter Linux, mit AZERTY. Diese Seite erzählt die ganze Geschichte: warum es existiert und wie es dazu kam.

## Das Problem

AZERTY wurde für Schreibmaschinen entworfen, nicht für Programmierer. Klammern und Operatoren verstecken sich hinter unbequemen Kombinationen, und der ständige Wechsel zwischen Französisch und Code erzeugt dauernde Reibung. Statt gegen das Layout anzukämpfen, habe ich Ebenen darum herum gebaut.

## Die Ebenen

- **L0**: Basis-AZERTY, nah an dem, was meine Hände schon kennen.
- **L1**: jedes Symbol, das ein Programmierer braucht, ohne die Grundreihe zu verlassen.
- **L2**: Nummernblock und französische Akzentzeichen.
- **L3**: Kopieren/Einfügen und betriebssystemspezifische Kürzel, weil Linux, Windows und macOS sich nie einig sind.
- **L4/L5**: RGB-Beleuchtung und Sound, damit ich weiß, auf welcher Ebene ich bin, ohne hinzusehen.
- **L6**: verwandelt die Tastatur in einen Gaming-Controller.

## Den Bildschirm wach halten

Früh habe ich ein Mausbewegungs-Makro hinzugefügt (`M_JIG_ON` / `M_JIGOFF`): Der Cursor bewegt sich alle 800 ms selbstständig in einem kleinen Quadrat, damit der Rechner während eines langen Anrufs oder einer langen Lektüre nicht sperrt oder in den Ruhezustand geht. Eine Taste schaltet es ein, eine aus.

## Die Tastatur in einen Controller verwandeln

Ebene 6 existiert nur fürs Gaming: Ein Tap-Dance auf einer Taste schaltet sie um, und Rapid-Fire-Makros wiederholen eine Taste oder Maustaste in einem Takt, den ich live, direkt von der Tastatur aus, beschleunigen oder verlangsamen kann — ohne die Konfiguration neu zu kompilieren.

## Feedback, ohne hinzusehen

RGB pro Ebene und eine Bibliothek von QMK-Soundeffekten — darunter ein "clicky" Tipp-Piepton — sorgen dafür, dass ich immer weiß, in welchem Modus ich bin, ohne auf die Tastatur zu schauen. Eine Kleinigkeit, die mir viele "Moment, auf welcher Ebene bin ich?" erspart hat.

## Kürzel, über die ich nicht mehr nachdenke

Fenstermanager-Kombinationen (Strg+Alt+Klammer, Strg+Alt+Z), Kopieren/Einfügen, das unter Linux, Windows und macOS gleich funktioniert, automatische HTML-Tag-Vervollständigung, Signatur-Makros für Dinge, die ich täglich Dutzende Male tippe — nach und nach wurden das Dinge, über die ich nicht mehr nachdenken muss.

## Mit QMK aktuell bleiben

QMK deprecatet mit der Zeit alte Keycodes. Als `RGB_*`- und Maus-Keycodes durch `RM_*`/`MS_*` ersetzt wurden, habe ich das gesamte Keymap migriert, statt es auf einer veralteten API verrotten zu lassen.

## Ihr eine Stimme geben

Das Neueste: Strg+Alt+K schaltet [opons-voxd](https://github.com/olivierpons/opons-voxd) um, ein separat von mir gebautes Open-Source-Sprachdiktat-Tool. Es ist die erste Taste auf dieser Tastatur, die nicht nur Text verschiebt — sie fängt an zuzuhören.

## Warum ich das teile

Niemand sollte das eins zu eins kopieren — jede Hand und jede Arbeitsweise ist anders. Aber die Idee — Ebenen für Symbole, OS-Kürzel, Feedback, Makros und jetzt Sprache — könnte jemand anderem die Jahre ersparen, die ich dafür gebraucht habe. Das vollständige Keymap und die Build-Anleitung liegen eine Ebene höher, im [README des Keymaps](../README.md).

---

> Übersetzt in die 20 meistgenutzten Sprachen der Welt; Korrekturen per Pull Request sind willkommen.
