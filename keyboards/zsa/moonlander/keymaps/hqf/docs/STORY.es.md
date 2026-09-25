[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · **Español** · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · [Bahasa Indonesia](STORY.id.md) · [Deutsch](STORY.de.md) · [日本語](STORY.ja.md) · [Naijá](STORY.pcm.md) · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · [Türkçe](STORY.tr.md) · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

*Traducido con ayuda de IA. ¿Encontraste un error? Los pull requests para mejorar esta traducción son bienvenidos.*

# Todo lo que construí para este teclado

Soy Olivier Pons, desarrollador, y escribo código, francés, inglés y ahora voz, todo el día. Este keymap no es una disposición descargada: nació de años de pequeños cambios, commit a commit, para adaptarse exactamente a mi forma de trabajar, en Linux, con AZERTY. Esta página cuenta la historia completa: por qué existe y cómo llegó hasta aquí.

## El problema

AZERTY fue diseñado para máquinas de escribir, no para programadores. Los corchetes y operadores están detrás de combinaciones incómodas, y alternar todo el día entre francés y código crea fricción constante. En lugar de luchar contra la disposición, construí capas alrededor de ella.

## Las capas

- **L0**: AZERTY base, cercano a lo que mis manos ya conocen.
- **L1**: todos los símbolos que necesita un programador, sin salir de la fila base.
- **L2**: teclado numérico y caracteres acentuados del francés.
- **L3**: copiar/pegar y atajos específicos del sistema operativo, porque Linux, Windows y macOS nunca se ponen de acuerdo.
- **L4/L5**: iluminación RGB y sonido, para saber en qué capa estoy sin mirar.
- **L6**: convierte el teclado en un mando de videojuegos.

## Mantener la pantalla despierta

Muy pronto añadí una macro de jiggle de ratón, para que la máquina no se bloquee ni entre en reposo durante una llamada larga o una lectura larga. Al principio el cursor solo se movía un poco cada 800 ms; ahora recorre un círculo píxel a píxel. `M_JG_TOG` lo inicia y lo detiene dejando el cursor donde está: al volver a iniciarlo, sigue desde el mismo punto, con los mismos ajustes. `M_JG_RUP` / `M_JG_RDN` agrandan y reducen el radio (10 píxeles por defecto, hasta un solo píxel, que aún mueve el ratón), y `M_JG_DUP` / `M_JG_DDN` alargan y acortan la pausa entre dos píxeles (1 segundo por defecto, hasta 1 ms, y luego aún más rápido, hasta 100 píxeles por milisegundo). En estas cuatro teclas, una pulsación breve, como al escribir una letra, cambia el valor en 1, y mantener la tecla lo cambia de 10 en 10, cada vez más rápido. `M_JG_CTG` elige dónde se hace un clic izquierdo en cada vuelta: cada pulsación pasa a la siguiente de las ocho direcciones, norte, noreste, este, sureste, sur, suroeste, oeste, noroeste, con un doble pitido un poco más agudo cada vez, y luego desactiva el clic con un pitido grave.

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

## Por qué comparto esto

Nadie debería copiar esto tal cual: cada mano y cada forma de trabajar son diferentes. Pero la idea —capas para símbolos, atajos del sistema, retroalimentación, macros y ahora voz— podría ahorrarle a alguien los años que a mí me costó llegar aquí. El keymap completo y las instrucciones de compilación están un nivel más arriba, en [el README del keymap](../README.md).

---

> Traducido a los 20 idiomas más usados del mundo; las correcciones mediante pull request son bienvenidas.
