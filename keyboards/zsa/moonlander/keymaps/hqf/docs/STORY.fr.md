[English](STORY.md) · **Français** · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · [Bahasa Indonesia](STORY.id.md) · [Deutsch](STORY.de.md) · [日本語](STORY.ja.md) · [Naijá](STORY.pcm.md) · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · [Türkçe](STORY.tr.md) · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

*Traduit avec l'aide de l'IA. Une erreur ? Les pull requests pour améliorer cette traduction sont les bienvenues.*

# Tout ce que j'ai construit pour ce clavier

Je suis Olivier Pons, développeur, et je tape du code, du français, de l'anglais, et maintenant de la voix, toute la journée. Ce keymap n'est pas une disposition téléchargée — il est né d'années de petits changements, commit après commit, pour coller exactement à ma façon de travailler, sous Linux, en AZERTY. Cette page raconte toute l'histoire : pourquoi il existe, et comment il en est arrivé là.

## Le problème

L'AZERTY a été conçu pour les machines à écrire, pas pour les développeurs. Crochets et opérateurs se cachent derrière des combinaisons peu pratiques, et jongler toute la journée entre français et code crée une friction constante. Plutôt que de lutter contre la disposition, j'ai construit des couches autour d'elle.

## Les couches

- **L0** : AZERTY de base, proche de ce que mes mains connaissent déjà.
- **L1** : tous les symboles dont un développeur a besoin, sans quitter la ligne de base.
- **L2** : pavé numérique et caractères accentués français.
- **L3** : copier/coller et raccourcis spécifiques à l'OS, car Linux, Windows et macOS ne sont jamais d'accord.
- **L4/L5** : éclairage RGB et sons, pour savoir sur quelle couche je suis sans regarder.
- **L6** : transforme le clavier en manette de jeu.

## Garder l'écran éveillé

Très tôt, j'ai ajouté une macro de jiggle de souris (`M_JIG_ON` / `M_JIGOFF`) : le curseur se déplace tout seul dans un petit carré toutes les 800 ms, pour que la machine ne se verrouille pas et ne passe pas en veille pendant un long appel ou une longue lecture. Une touche pour activer, une pour désactiver.

## Transformer le clavier en manette

La couche 6 existe uniquement pour le jeu : un tap-dance sur une touche l'active, et des macros Rapid Fire répètent une touche ou un bouton de souris à intervalle réglable, accélérable ou ralentissable en direct, depuis le clavier lui-même, sans recompiler la config.

## Un retour sans avoir à regarder

Le RGB par couche et une bibliothèque d'effets sonores QMK — dont un bip de frappe façon « clicky » — me permettent de toujours savoir dans quel mode je suis sans jeter un œil au clavier. Un petit détail qui m'a évité pas mal de « attends, je suis sur quelle couche ? ».

## Des raccourcis devenus inconscients

Combinaisons de gestionnaire de fenêtres (Ctrl+Alt+crochet, Ctrl+Alt+Z), copier/coller qui fonctionne pareil que je sois sous Linux, Windows ou macOS, complétion automatique de balises HTML, macros de signature pour tout ce que je tape des dizaines de fois par jour — un par un, ces gestes ont cessé d'être des choses auxquelles je pense.

## Rester à jour avec QMK

QMK déprécie ses keycodes au fil du temps. Quand les keycodes `RGB_*` et souris ont été remplacés par `RM_*`/`MS_*`, j'ai migré tout le keymap plutôt que de le laisser pourrir sur une ancienne API.

## Lui donner une voix

La pièce la plus récente : Ctrl+Alt+K active [opons-voxd](https://github.com/olivierpons/opons-voxd), un outil de dictée vocale open source que j'ai construit séparément. C'est la première touche de ce clavier qui ne déplace pas juste du texte — elle se met à écouter.

## Pourquoi je partage ça

Personne ne devrait copier ça tel quel — chaque main et chaque façon de travailler diffèrent. Mais l'idée — des couches pour les symboles, les raccourcis OS, le retour visuel, les macros, et maintenant la voix — pourrait faire gagner à quelqu'un d'autre les années que ça m'a pris. Le keymap complet et les instructions de compilation se trouvent un niveau au-dessus, dans [le README du keymap](../README.md).

---

> Traduit dans les 20 langues les plus parlées au monde ; les corrections via pull request sont les bienvenues.
