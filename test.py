import numpy as np
import matplotlib.pyplot as plt

# n의 값 범위 설정
n = np.linspace(1, 50, 1000)

# 함수 계산
sqrt_n = np.sqrt(n)
f_n = n - sqrt_n

# 서브플롯 생성
fig, axs = plt.subplots(3, 1, figsize=(10, 10), sharex=True)

# 첫 번째 서브플롯: n
axs[0].plot(n, 'r-o')
axs[0].set_ylabel('$n$')
axs[0].grid(True)

# 두 번째 서브플롯: sqrt(n)
axs[1].plot(sqrt_n, 'g-s')
axs[1].set_ylabel('$\sqrt{n}$')
axs[1].grid(True)

# 세 번째 서브플롯: f(n) = n - sqrt(n)
axs[2].plot(f_n, 'b-x')
axs[2].set_xlabel('$n$')
axs[2].set_ylabel('$f(n)$')
axs[2].grid(True)

# 그래프 표시
plt.tight_layout()
plt.show()
