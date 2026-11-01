# Tez çalışma haritası
## Amaç
Bir serbestlik dereceli master–slave sisteminde hassas konum takibi ve çevre etkileşim torkunun kullanıcıya yansıtılması.
Araştırma katkısı henüz kesinleşmedi. DOB/RFOB eklemek tek başına katkı iddiası değildir.
Önce ölçülebilir temel davranışı kur, sonra bir belirsizlik/temas koşulunda performansı karşılaştır.

## Çalışmanın esas dosyaları
- DOB_Gravity_DcMotor.slx: kullanıcının mevcut motor–link/kontrol modeli; çalışma burada devam edecek.
- DcMotorAndLinkModel.m: motor, link, redüktör ve eşdeğer atalet.
- DcMotorModel.m: akım, hız ve konum kontrolcü kazançları.
- dob.slx: mevcut ayrı model; yapısı henüz incelenmedi.
- horizontal/report/main.tex: korunmuş modüler teknik rapor.
- horizontal/report/archive/: kaldırılan sade modelin geçmiş doğrulama çıktıları; mevcut sistemin doğrulaması değil.

## Dosyadan doğrulanan yapı
Motor alt sistemi: Kt, Ke, Rs, Ls, akım integratörü, kontrolcü ve doygunluk.
HizPozKontrolcu: hız PI ve konum kontrolü.
Disli Ileri / Disli Geri: oran dönüşümleri.
Joint1.J üzerinden mekanik integratörler ve yerçekimi katsayısı.
Simscape Multibody: World Frame, Revolute Joint, Rigid Transform, Cylindrical Solid ve Mechanism Configuration.
Motor/dişli sürtünme alt sistemleri var; etkinlikleri ve parametre bağları henüz doğrulanmadı.
Blok adlarının bulunması bağlantıların veya fiziksel tutarlılığın doğrulandığı anlamına gelmez.

## Birlikte çalışma sırası
1. Mevcut modelde tek sinyal zincirini izle: tork komutu → akım → motor torku → redüktör → link hareketi.
   Her sinyal için birim, pozitif yön ve motor/yük tarafını işaretle.
2. Mevcut Simscape kolunun torkla mı yoksa hareketle mi sürüldüğünü kontrol et.
   Hareketle sürülüyorsa animasyon bağımsız dinamik doğrulama sayılmaz.
3. GP 22 C tam oranını 69255/208 olarak, kontrolcü dönüşümleriyle birlikte uygula.
   Eski parametre dosyasında N=20 var; henüz değiştirilmedi.
4. Yatay/dikey seçimini açık bir parametreyle tanımla; eski dikey davranışı koru.
   Analitik model ile Simscape aynı atalet, eksen, giriş torku ve dış torku kullanmalı.
5. Tek taraflı yay–damper teması ekle. Önce açısal sanal duvarla başla.
   Temas torkunu gerçek referans olarak kaydet; işaret ve ayrılma davranışını doğrula.
6. DOB toplam eşdeğer bozucuyu kestirsin; RFOB temas torkunu ayırmayı hedeflesin.
   Sürtünme ve model hatası ayrımı varsayımlara bağlıdır; doğrudan eşit kabul etme.
7. Doğrulanmış ekseni master/slave olarak bağla; konum farkı ve etkileşim torku dengesini incele.

## Her oturumun çıktısı
Tek soru, tek küçük değişiklik, önce tahmin, sonra grafik, kısa yorum.
Kullanıcı açıklayabilmeden yeni katman ekleme.
Ölçütler: konum hatası, temas tepe torku, yerleşme, RFOB hatası ve kararlılık.
DOB kapalı/açık karşılaştırmalarında aynı giriş ve fiziksel koşulları koru.

## Açık parametreler
Motor tam ürün kodu; gerçek link geometrisi/kütle merkezi/ataleti.
GP 22 C: nominal 333:1, tam 69255/208; 1.8 Nm çıkış taşıma sınırı.
Katalog maksimum verimi %49; gerçek çalışma verimi ve ters sürülebilirlik doğrulanmadı.
Redüktör ataleti, boşluk ve sürtünme bu aşamada doğrulanmadı.

## Düzenleme önerisi
Şimdilik mevcut MATLAB dosyalarını taşımayalım; göreli yolları bozmayalım.
Önce model içinde Motor, Transmission, Link, Contact, Observers, Controllers ve Logging sınırlarını anlaşılır hâle getir.
Derlenmiş exe, *_grt_rtw, slprj ve slxc çıktıları kaynak model değildir.
Mevcut otomatik üretim klasörleri kullanıcıya ait olduğu için silinmedi.

## Bileşen düzeni
Parametreler components/ altında motor, gearbox, link, joint ve controllers olarak ayrıldı.
Tek başlangıç setup_thesis.m; eski iki giriş dosyası uyumluluk için korunuyor.
Bu düzenleme fiziksel parametreleri değiştirmez. N=20 → GP 22 C geçişi hâlâ bekliyor.
Bileşen düzeni sadeleştirildi: alt klasörler kaldırıldı, tüm *_parameters.m dosyaları doğrudan components/ içinde. setup_thesis yolları güncellendi.

## Mevcut Simscape incelemesi
Model.slx içindeki Cylindrical Solid: uzunluk 0.06 m, kütle 0.43 g.
Revolute Joint: NoTorque / ComputedMotion; sensör çıkışları kapalı.
GravityVector [0 -9.81 0], Rigid Transform +Y 0.03 m.
Bu yapı henüz motorun sürdüğü yatay link modeli değildir.
Link parametreleri 150 x 20 x 10 mm homojen PLA varsayımıyla güncellendi.
m=0.0372 kg, lc=0.075 m, Izz,p=0.00028024 kg m^2.
150 mm hedef; diğer boyutlar ve yoğunluk varsayım. Ana SLX henüz değiştirilmedi.
Main adı korunacak. Link değişince Main kontrolcü kazançlarını yeniden hesaplar.

## Simscape bağlantı kararı
Gövde Brick Solid: boyut [L1.length L1.width L1.thickness], m, kg.
Eklemin Z ekseni dünya Z ile aynı; dünya yerçekimi [0 0 -g].
Eklemden gövde merkezine X yönünde L1.lc öteleme.
Eklemde tork Provided by Input, motion Automatically Computed; q ve w sensing.
Simulink-PS Converter tork birimi N*m; PS-Simulink Converter rad, rad/s.
Sadece linkin fiziksel ataleti kullanılırsa motor rotor ataleti eksik kalır.
Karşılaştırma için aynı eksene N^2*(Jr+Jg) rotor/dişli eşdeğer ataleti eklenmeli.
Link ataleti gövde geometrisinden hesaplandığından Joint1.J ayrıca eklenmemeli.
İlk aşama paralel iki plant aynı net yük torkuyla sürülecek.
Mevcut kontrolcü analitik plantte kalacak; Simscape q,w yalnızca karşılaştırma Scope'una gidecek.
Sonraki aşamada doğrulanan Simscape plant geri beslemeye alınabilir.

## GP 22 C artık ana parametrelerde etkin
G1.N=69255/208; G1.Jg=0.4e-7 kg*m^2 (giriş tarafı).
Bu güncelleme önceki N=20 bekliyor kayıtlarını geçersiz kılar.
G1.eta=1 ideal model kabulü; katalog maksimum verimi G1.catalog.maxEfficiency=0.49.
Tork/hız sınırları ve boşluk yalnızca katalog alanlarında, henüz modelde uygulanmıyor.
Main çalışınca Joint1.J ve mevcut kontrolcü kazançları yeni değerlerle hesaplanır.

## Sürtünme yolu doğrulandı
Kaydedilmiş Model.slx: Motor_Hiz -> Motor Surtunme Modeli (P=M1) -> Motor_Surtunme.
Motor_Tork - Motor_Surtunme, sonra Disli Ileri üzerinden N ile çarpılıyor.
Motor_Hiz yük hızından N ile oluşturuluyor; motor viskoz sönümü yükte N^2*M1.Bv.
Dişli sürtünmesi yük hızından G1 ile hesaplanıp mekanik toplamdan çıkarılıyor; G1.Bv=0.
Joint1.B=N^2*M1.Bv+G1.Bv eklendi, hız PI Ki hesabı ve mekanik Bode bitkisi düzeltildi.
SLX değiştirilmedi. Diskte hız kontrolcü girişi hâlâ Motor_Hiz; açık modelde Disli_Hiz değişikliği kaydedilmeli.
Bu kontrolcü formülü Disli_Hiz geri beslemesini varsayar.
