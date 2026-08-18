[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · **Español** · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md)

*Traducido con ayuda de IA. ¿Encontraste un error? Los pull requests para mejorar esta traducción son bienvenidos.*

# Todo lo que construí para este teclado

Esta página cuenta la historia completa: no solo lo que hace el keymap hoy, sino cómo llegó hasta aquí, commit a commit, a lo largo de meses de pequeños cambios.

## Partir de una disposición en blanco

No quería un Moonlander con una disposición estándar. Quería AZERTY —mi disposición nativa— reconstruida desde cero para programar: símbolos al alcance de la mano, sin gimnasia de capas que memorizar para `{`, `[`, `|`. La primera versión funcional es la base sobre la que sigo construyendo hoy.

## Mantener la pantalla despierta

Al principio añadí una macro de jiggle de ratón (`M_JIG_ON` / `M_JIGOFF`): el cursor se mueve solo en un pequeño cuadrado cada 800 ms, para que la máquina no se bloquee ni entre en reposo durante una llamada larga o una lectura larga. Una tecla la activa, otra la desactiva.

## Convertir el teclado en un mando

La capa 6 existe solo para jugar: un tap-dance en una tecla la activa, y las macros Rapid Fire repiten una tecla o un botón del ratón a un ritmo que puedo acelerar o ralentizar en vivo, desde el propio teclado, sin recompilar la configuración.

## Retroalimentación sin mirar hacia abajo

El RGB por capa y una biblioteca de efectos de sonido de QMK —incluido un pitido de tecleo tipo "clicky"— hacen que siempre sepa en qué modo estoy sin mirar el teclado. Un detalle pequeño que me ahorró muchos "espera, ¿en qué capa estoy?".

## Atajos que dejaron de ser conscientes

Combinaciones del gestor de ventanas (Ctrl+Alt+corchete, Ctrl+Alt+Z), copiar/pegar que funciona igual en Linux, Windows o macOS, autocompletado de etiquetas HTML, macros de firma para lo que escribo decenas de veces al día —uno a uno, dejaron de ser cosas en las que tengo que pensar.

## Mantenerse al día con QMK

QMK va dejando obsoletos sus keycodes con el tiempo. Cuando los keycodes `RGB_*` y de ratón fueron reemplazados por `RM_*`/`MS_*`, migré todo el keymap en lugar de dejarlo pudrirse sobre una API antigua.

## Darle una voz

Lo más reciente: Ctrl+Alt+K activa [opons-voxd](https://github.com/olivierpons/opons-voxd), una herramienta de dictado por voz de código abierto que construí por separado. Es la primera tecla de este teclado que no solo mueve texto, sino que empieza a escuchar.

## Ponerlo por escrito

Este keymap hace tiempo que dejó de ser solo un archivo de configuración. Tiene un comportamiento que merece explicación, y quería que esa explicación llegara a más gente que solo a lectores de inglés o francés —de ahí esta página, y la más corta [ABOUT](ABOUT.es.md), ambas traducidas. El keymap completo y las instrucciones de compilación están un nivel más arriba, en [el README del keymap](../README.md).

---

> Traducido a los 10 idiomas más usados del mundo; las correcciones mediante pull request son bienvenidas.
