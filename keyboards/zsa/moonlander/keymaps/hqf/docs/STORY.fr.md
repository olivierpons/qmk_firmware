[English](STORY.md) · **Français** · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md)

*Traduit avec l'aide de l'IA. Une erreur ? Les pull requests pour améliorer cette traduction sont les bienvenues.*

# Tout ce que j'ai construit pour ce clavier

Cette page raconte toute l'histoire : pas seulement ce que fait le keymap aujourd'hui, mais comment il en est arrivé là, commit après commit, au fil de mois de petits changements.

## Partir d'une disposition vierge

Je ne voulais pas d'un Moonlander avec une disposition standard. Je voulais de l'AZERTY — ma disposition native — reconstruite de zéro pour la programmation : les symboles à portée de main, sans gymnastique de couches à mémoriser pour `{`, `[`, `|`. La première version fonctionnelle est la base sur laquelle je construis encore aujourd'hui.

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

## L'écrire noir sur blanc

Ce keymap a dépassé le stade du simple fichier de config depuis un moment. Il a un comportement qui mérite d'être expliqué, et je voulais que cette explication touche plus de monde que les seuls lecteurs anglophones ou francophones — d'où cette page, et la page plus courte [ABOUT](ABOUT.fr.md), toutes deux traduites. Le keymap complet et les instructions de compilation se trouvent un niveau au-dessus, dans [le README du keymap](../README.md).

---

> Traduit dans les 10 langues les plus parlées au monde ; les corrections via pull request sont les bienvenues.
