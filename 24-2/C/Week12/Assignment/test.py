import numpy as np
from numpy.fft import fft, fftshift
import matplotlib.pyplot as plt

# 시간 도메인 신호
x = np.array([1, 2, 3, 4, 5, 6, 7, 8])
for i in range(-10, 0, 1):
    pass

# 1D FFT
X = fft(x)

# 시프팅 전후
X_shifted = fftshift(X)


# 시각화
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.plot(np.abs(X), label="Before shift")
plt.title("Before fftshift")
plt.legend()

plt.subplot(1, 2, 2)
plt.plot(np.abs(X_shifted), label="After shift")
plt.title("After fftshift")
plt.legend()

plt.show()
