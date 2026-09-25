[English](STORY.md) · [Français](STORY.fr.md) · [中文](STORY.zh.md) · [हिन्दी](STORY.hi.md) · [Español](STORY.es.md) · [العربية](STORY.ar.md) · [বাংলা](STORY.bn.md) · [Português](STORY.pt.md) · [Русский](STORY.ru.md) · [اردو](STORY.ur.md) · [Bahasa Indonesia](STORY.id.md) · [Deutsch](STORY.de.md) · [日本語](STORY.ja.md) · [Naijá](STORY.pcm.md) · [मराठी](STORY.mr.md) · [తెలుగు](STORY.te.md) · **Türkçe** · [粵語](STORY.yue.md) · [தமிழ்](STORY.ta.md) · [ਪੰਜਾਬੀ](STORY.pa.md)

*Bu çeviri yapay zeka yardımıyla yapılmıştır. Bir hata mı buldunuz? Bu çeviriyi iyileştirmek için pull request'ler memnuniyetle karşılanır.*

# Bu Klavye İçin İnşa Ettiğim Her Şey

Ben Olivier Pons, bir geliştiriciyim ve gün boyu kod, Fransızca, İngilizce ve artık ses de yazıyorum. Bu keymap indirilmiş bir düzen değil — yıllar süren küçük değişikliklerden, commit commit, çalışma şekline tam olarak uysun diye, Linux üzerinde, AZERTY ile doğdu. Bu sayfa tüm hikâyeyi anlatıyor: neden var, ve buraya nasıl geldi.

## Sorun

AZERTY daktilolar için tasarlanmıştı, programcılar için değil. Parantezler ve operatörler rahatsız edici kombinasyonların arkasına gizlenir, gün boyu Fransızca ile kod arasında geçiş yapmak sürekli sürtünme yaratır. Düzenle savaşmak yerine, onun etrafına katmanlar inşa ettim.

## Katmanlar ne yapar

- **L0**: temel AZERTY, ellerimin zaten bildiğine yakın.
- **L1**: bir programcının ihtiyaç duyduğu her sembol, ana sıradan ayrılmadan.
- **L2**: numara tuş takımı ve Fransızca aksanlı karakterler.
- **L3**: kopyala/yapıştır ve işletim sistemine özgü kısayollar, çünkü Linux, Windows ve macOS asla anlaşmaz.
- **L4/L5**: RGB aydınlatma ve ses, bakmadan hangi katmanda olduğumu bilmem için.
- **L6**: klavyeyi bir oyun kumandasına dönüştürür.

## Ekranı uyanık tutmak

Erken bir dönemde bir fare titretme makrosu ekledim, böylece uzun bir görüşme veya uzun bir okuma sırasında makine kilitlenmez veya boşta kalmaz. Başta imleç her 800 ms'de yalnızca biraz kıpırdıyordu; şimdi bir çemberi piksel piksel izliyor. `M_JG_TOG` onu başlatır ve durdurur, imleci olduğu yerde bırakır: bir sonraki başlatmada aynı noktadan, aynı ayarlarla devam eder. `M_JG_RUP` / `M_JG_RDN` yarıçapı büyütür ve küçültür (varsayılan 10 piksel, fareyi hâlâ hareket ettiren tek bir piksele kadar), `M_JG_DUP` / `M_JG_DDN` ise iki piksel arasındaki duraklamayı uzatır ve kısaltır (varsayılan 1 saniye, 1 ms'ye kadar, sonra daha da hızlı, milisaniyede 100 piksele kadar). Bu dört tuşta, bir harf yazar gibi kısa bir basış değeri 1 değiştirir, tuşu basılı tutmak ise onu her seferinde 10 değiştirir, giderek hızlanarak. `M_JG_CTG` her turda sol tıklamanın nerede yapılacağını seçer: her basış sekiz yönden bir sonrakine geçer, kuzey, kuzeydoğu, doğu, güneydoğu, güney, güneybatı, batı, kuzeybatı, her seferinde biraz daha tiz bir çift bip ile, ardından tıklamayı pes bir bip ile kapatır.

## Klavyeyi bir kumandaya dönüştürmek

Katman 6 sadece oyun için var: bir tuştaki tap-dance onu açıp kapatır, ve Rapid Fire makroları bir tuşu veya fare düğmesini, klavyenin kendisinden, yapılandırmayı yeniden derlemeden, canlı olarak hızlandırıp yavaşlatabildiğim bir ritimle tekrarlar.

## Bakmadan gelen geri bildirim

Katman başına RGB ve bir QMK ses efekti kütüphanesi — "clicky" bir yazma sesi dahil — klavyeye bakmadan her zaman hangi modda olduğumu bilmemi sağlıyor. Küçük bir ayrıntı, ama "dur, hangi katmandayım" anlarından çok kurtardı.

## Artık düşünmediğim kısayollar

Pencere yöneticisi kombinasyonları (Ctrl+Alt+parantez, Ctrl+Alt+Z), Linux, Windows veya macOS'ta aynı şekilde çalışan kopyala/yapıştır, HTML etiketi otomatik tamamlama, günde onlarca kez yazdığım şeyler için imza makroları — birer birer, bunlar artık düşünmem gereken şeyler olmaktan çıktı.

## QMK ile güncel kalmak

QMK zamanla eski keycode'ları kullanımdan kaldırıyor. `RGB_*` ve fare keycode'ları `RM_*`/`MS_*` ile değiştirildiğinde, onu eski bir API üzerinde çürümeye bırakmak yerine tüm keymap'i taşıdım.

## Ona bir ses vermek

En yeni parça: Ctrl+Alt+K, ayrı olarak geliştirdiğim açık kaynaklı bir sesli yazdırma aracı olan [opons-voxd](https://github.com/olivierpons/opons-voxd)'yi açıp kapatıyor. Bu, bu klavyedeki sadece metni hareket ettirmekle kalmayıp dinlemeye başlayan ilk tuş.

## Bunu neden paylaşıyorum

Kimse bunu olduğu gibi kopyalamamalı — herkesin elleri ve çalışma şekli farklı. Ama fikir — semboller için katmanlar, işletim sistemi kısayolları, geri bildirim, makrolar ve şimdi de ses — başka birinin buraya gelmek için harcadığım yılları kazanmasını sağlayabilir. Tam keymap ve derleme talimatları bir klasör yukarıda, [keymap'in README'sinde](../README.md).

---

> Dünyanın en çok kullanılan 20 diline çevrilmiştir; pull request ile düzeltmeler memnuniyetle karşılanır.
