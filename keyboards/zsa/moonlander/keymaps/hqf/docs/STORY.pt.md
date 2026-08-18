[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · **Português** · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · [Bahasa Indonesia](STORY.id.md) · [Deutsch](STORY.de.md) · [日本語](STORY.ja.md) · [Naijá](STORY.pcm.md) · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · [Türkçe](STORY.tr.md) · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

*Traduzido com apoio de IA. Encontrou um erro? Pull requests para melhorar esta tradução são bem-vindos.*

# Tudo o que construí para este teclado

Sou Olivier Pons, desenvolvedor, e digito código, francês, inglês e agora voz, o dia todo. Este keymap não é um layout baixado — nasceu de anos de pequenas mudanças, commit a commit, para se encaixar exatamente no meu jeito de trabalhar, no Linux, em AZERTY. Esta página conta a história completa: por que ele existe, e como chegou até aqui.

## O problema

O AZERTY foi feito para máquinas de escrever, não para programadores. Colchetes e operadores ficam atrás de combinações incômodas, e alternar o dia todo entre francês e código cria atrito constante. Em vez de lutar contra o layout, construí camadas ao redor dele.

## As camadas

- **L0**: AZERTY base, perto do que minhas mãos já conhecem.
- **L1**: todos os símbolos que um programador precisa, sem sair da linha base.
- **L2**: teclado numérico e caracteres acentuados do francês.
- **L3**: copiar/colar e atalhos específicos do sistema operacional, já que Linux, Windows e macOS nunca concordam.
- **L4/L5**: iluminação RGB e som, para saber em que camada estou sem olhar.
- **L6**: transforma o teclado em um controle de jogos.

## Mantendo a tela acordada

No início, adicionei uma macro de jiggle de mouse (`M_JIG_ON` / `M_JIGOFF`): o cursor se move sozinho num pequeno quadrado a cada 800 ms, para que a máquina não trave nem entre em repouso durante uma ligação longa ou uma leitura longa. Uma tecla liga, outra desliga.

## Transformando o teclado em um controle

A camada 6 existe só para jogos: um tap-dance numa tecla a alterna, e as macros Rapid Fire repetem uma tecla ou botão do mouse num ritmo que posso acelerar ou desacelerar ao vivo, direto do teclado, sem recompilar a configuração.

## Feedback sem precisar olhar

RGB por camada e uma biblioteca de efeitos sonoros do QMK — incluindo um beep de digitação tipo "clicky" — fazem eu sempre saber em que modo estou sem olhar para o teclado. Um detalhe pequeno que evitou muito "espera, em que camada eu tô?".

## Atalhos que deixaram de ser conscientes

Combinações de gerenciador de janelas (Ctrl+Alt+colchete, Ctrl+Alt+Z), copiar/colar que funciona igual no Linux, Windows ou macOS, autocompletar de tags HTML, macros de assinatura para o que digito dezenas de vezes por dia — um a um, deixaram de ser coisas em que preciso pensar.

## Mantendo-se atualizado com o QMK

O QMK vai depreciando keycodes com o tempo. Quando os keycodes `RGB_*` e de mouse foram substituídos por `RM_*`/`MS_*`, migrei o keymap inteiro em vez de deixá-lo apodrecer numa API antiga.

## Dando-lhe uma voz

A peça mais recente: Ctrl+Alt+K ativa o [opons-voxd](https://github.com/olivierpons/opons-voxd), uma ferramenta de ditado por voz de código aberto que construí separadamente. É a primeira tecla neste teclado que não só move texto — ela começa a escutar.

## Por que eu compartilho isso

Ninguém deveria copiar isso do jeito que está — cada mão e cada jeito de trabalhar é diferente. Mas a ideia — camadas para símbolos, atalhos do sistema, feedback, macros e agora voz — pode economizar para alguém os anos que levei para chegar aqui. O keymap completo e as instruções de build estão um nível acima, no [README do keymap](../README.md).

---

> Traduzido para os 20 idiomas mais usados do mundo; correções via pull request são bem-vindas.
