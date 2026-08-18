[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · **Português** · [Русский](STORY.ru.md) · [اردو](STORY.ur.md)

*Traduzido com apoio de IA. Encontrou um erro? Pull requests para melhorar esta tradução são bem-vindos.*

# Tudo o que construí para este teclado

Esta página conta a história completa: não só o que o keymap faz hoje, mas como ele chegou até aqui, commit a commit, ao longo de meses de pequenas mudanças.

## Partindo de um layout em branco

Eu não queria um Moonlander com layout padrão. Eu queria AZERTY — meu layout nativo — reconstruído do zero para programação: símbolos ao alcance da mão, sem ginástica de camadas para decorar para `{`, `[`, `|`. A primeira versão funcional é a base sobre a qual ainda construo hoje.

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

## Colocando no papel

Esse keymap faz tempo que deixou de ser só um arquivo de configuração. Ele tem um comportamento que merece explicação, e eu queria que essa explicação chegasse a mais gente do que só leitores de inglês ou francês — daí esta página, e a mais curta [ABOUT](ABOUT.pt.md), ambas traduzidas. O keymap completo e as instruções de build estão um nível acima, no [README do keymap](../README.md).

---

> Traduzido para os 10 idiomas mais usados do mundo; correções via pull request são bem-vindas.
