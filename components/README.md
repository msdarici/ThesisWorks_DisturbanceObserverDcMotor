# Bileşen parametreleri
Tek klasör: bütün parametre dosyaları doğrudan components içindedir.
Depo kökünde setup_thesis çalıştır; bütün parametreler doğru sırayla yüklenir.
Eski DcMotorAndLinkModel komutu da aynı başlangıcı çağırır.

- motor_parameters.m → M1
- gearbox_parameters.m → G1
- link_parameters.m → L1
- joint_parameters.m → g ve türetilen Joint1
- controller_parameters.m → kontrolculer ve mevcut Bode grafikleri

Yay–damper eklendiğinde environment_parameters.m aynı klasöre eklenecek.
Bu düzenleme sayısal değerleri veya SLX bağlantılarını değiştirmez.
G1.N halen 20; GP 22 C oranına geçiş ayrı bir sonraki adımdır.
