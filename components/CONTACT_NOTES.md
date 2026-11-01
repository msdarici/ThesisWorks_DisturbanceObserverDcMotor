# Açısal duvar: blok bağlantısı
Main Wall parametrelerini yükler.
Constant pi/2 yerine Wall.theta yaz.
Giriş 1: sarılmamış yük açısı [rad]. Giriş 2: yük hızı [rad/s].
delta = theta_load - Wall.theta.
Mevcut Ke*delta + De*omega toplamından sonra:
1. Saturation: Lower limit=0, Upper limit=inf.
2. delta>0 koşuluyla Switch: temas varsa sınırlanmış toplam, yoksa Constant 0.
Çıkış pozitif direnç büyüklüğüdür: yük tarafı mekanik toplamının EKSİ girişine bağla.
Alternatif: Gain=-1 ekleyip ARTI girişine bağla; iki kere işaret değiştirme.
Duvarı motor tork toplamına bağlama; bu yük tarafı torkudur.
Duvar öncesi tork tam sıfır olmalı. Ayrılmada çekme torku üretmemeli.

İlk deney: 0 rad'den uzun stair yerine duvarın 0.05 rad gerisinden,
duvarın 0.05 rad ilerisine tek küçük hareket iste.
İlk/son açılar: Wall.theta-0.05 ve Wall.theta+0.05.
Başlangıç açısı ve model yerçekimi konvansiyonu aynı kalmalı.
Açı, hız, direnç torku ve motor gerilimini izle.
Konum PI/P hız döngüsü duvarı itmeye devam edebilir; penetrasyon Ke ile tek başına belirlenmez.
De formülü yalnızca temasın pasif J-K yaklaşımıdır; tam sistem için sönüm garantisi değildir.
