# Tork Saturation alanları
Main çalıştır.
Motor tork komutu [Nm]: Upper limit M1.tauMax, Lower limit -M1.tauMax.
Redüktör yük tarafı [Nm]: Upper limit G1.tauMax, Lower limit -G1.tauMax.

M1.tauContinuous ve M1.tauPeak gerçek motor varyantı bilinmediği için NaN.
M1.tauMax şimdilik ideal redüktörün sürekli çıkış sınırından türetilir.
Motor sürekli torku doğrulanınca Main iki sınırın küçüğünü kullanır.
G1.tauMax=G1.tauContinuous=1.8 Nm.
G1.tauPeak=2.7 Nm yalnızca aralıklı katalog sınırı; sürekli kullanım onayı değil.

Önce motor komut sınırını kullan. İleri besleme varsa toplam komuttan sonra uygula.
İdeal kayıpsız modelde motor sınırı 1.8/N yaklaşık 0.005406 Nm.
Bu sınır motorun gerçek akım/termal yeterliliğini doğrulamaz.
Komut sınırlaması gerçek geçici torku garanti etmez; gerçek torku da izle.
Gerçek bir dişli aşırı torku otomatik kırpan aktüatör değildir:
çıkışa Saturation eklemek, fiziksel aşırı yük davranışı değil model idealizasyonudur.
PI anti-windup ayrıca kurulmalı; bloklar bu düzenlemeyle değiştirilmedi.
