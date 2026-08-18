[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · **Bahasa Indonesia** · [Deutsch](STORY.de.md) · [日本語](STORY.ja.md) · [Naijá](STORY.pcm.md) · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · [Türkçe](STORY.tr.md) · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

*Diterjemahkan dengan bantuan AI. Menemukan kesalahan? Pull request untuk memperbaiki terjemahan ini sangat diterima.*

# Semua yang Saya Bangun untuk Keyboard Ini

Saya Olivier Pons, seorang developer, dan saya mengetik kode, bahasa Prancis, bahasa Inggris, dan sekarang suara, sepanjang hari. Keymap ini bukan layout unduhan — ia lahir dari bertahun-tahun perubahan kecil, commit demi commit, agar benar-benar sesuai dengan cara kerja saya, di Linux, dengan AZERTY. Halaman ini menceritakan kisah lengkapnya: mengapa ini ada, dan bagaimana ini sampai di sini.

## Masalahnya

AZERTY dirancang untuk mesin ketik, bukan untuk programmer. Tanda kurung dan operator tersembunyi di balik kombinasi yang tidak nyaman, dan berpindah-pindah sepanjang hari antara bahasa Prancis dan kode menciptakan friksi terus-menerus. Alih-alih melawan layout, saya membangun layer di sekelilingnya.

## Fungsi setiap layer

- **L0**: AZERTY dasar, dekat dengan apa yang sudah dikenal tangan saya.
- **L1**: setiap simbol yang dibutuhkan programmer, tanpa meninggalkan home row.
- **L2**: numpad dan karakter beraksen bahasa Prancis.
- **L3**: copy/paste dan shortcut khusus OS, karena Linux, Windows, dan macOS tidak pernah sepakat.
- **L4/L5**: pencahayaan RGB dan suara, agar saya tahu sedang di layer mana tanpa melihat.
- **L6**: mengubah keyboard menjadi gaming controller.

## Menjaga layar tetap terjaga

Sejak awal saya menambahkan makro mouse-jiggle (`M_JIG_ON` / `M_JIGOFF`): kursor bergerak sendiri dalam kotak kecil setiap 800 md, agar komputer tidak terkunci atau idle selama panggilan panjang atau bacaan panjang. Satu tombol menyalakannya, satu mematikannya.

## Mengubah keyboard menjadi controller

Layer 6 ada murni untuk gaming: tap-dance pada satu tombol mengaktifkannya, dan makro Rapid Fire mengulang sebuah tombol atau tombol mouse dengan jeda yang bisa saya percepat atau perlambat secara langsung, dari keyboard itu sendiri, tanpa perlu mengompilasi ulang konfigurasi.

## Umpan balik tanpa perlu melihat

RGB per layer dan pustaka efek suara QMK — termasuk bunyi ketik "clicky" — membuat saya selalu tahu sedang di mode apa tanpa melihat keyboard. Hal kecil yang menghemat banyak momen "tunggu, saya sedang di layer mana?".

## Shortcut yang tak lagi perlu dipikirkan

Kombinasi window manager (Ctrl+Alt+kurung, Ctrl+Alt+Z), copy/paste yang bekerja sama di Linux, Windows, atau macOS, pelengkapan otomatis tag HTML, makro tanda tangan untuk hal-hal yang saya ketik puluhan kali sehari — satu per satu, semua ini berhenti menjadi hal yang perlu saya pikirkan.

## Tetap mengikuti perkembangan QMK

QMK menghentikan dukungan keycode lama seiring waktu. Ketika keycode `RGB_*` dan mouse digantikan oleh `RM_*`/`MS_*`, saya memigrasikan seluruh keymap alih-alih membiarkannya lapuk di atas API lama.

## Memberinya suara

Bagian terbaru: Ctrl+Alt+K mengaktifkan [opons-voxd](https://github.com/olivierpons/opons-voxd), alat dikte suara open source yang juga saya buat secara terpisah. Ini adalah tombol pertama di keyboard ini yang tidak hanya memindahkan teks — ia mulai mendengarkan.

## Mengapa saya membagikan ini

Tidak ada yang perlu meniru ini persis sama — tangan dan cara kerja setiap orang berbeda. Tapi idenya — layer untuk simbol, shortcut OS, umpan balik, makro, dan kini suara — mungkin bisa menghemat waktu bertahun-tahun bagi orang lain seperti yang saya alami. Keymap lengkap dan instruksi build ada satu folder di atas, di [README keymap](../README.md).

---

> Diterjemahkan ke dalam 20 bahasa paling banyak digunakan di dunia; koreksi melalui pull request sangat diterima.
