# Bant genişliği incelemesi
Main; inspect_bandwidth
Bu komutlar nominal öneri kazançlarını bandwidth_design.m üzerinden hesaplar.
inspect_bandwidth aktif kontrolculer değişkenini değiştirmez.
Grafikler report/figures/cascade_bode.png, sayısal sonuçlar bandwidth_summary.csv içindedir.
Akım/hız hedefleri eski değerlerdir; fiziksel uygunluk onayı değildir.
Öneri hız kazançları: Kp=J*wv/N, Ki=Bload*wv/N.
Bload=N^2*M1.Bv+G1.Bv; mevcut modeldeki viskoz terimlerin etkin olduğu varsayılır.
Gravity, saturation, residual back EMF and sampled implementation are excluded.
