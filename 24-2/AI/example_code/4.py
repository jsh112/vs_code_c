import numpy as np
import matplotlib.pyplot as plt


np.random.seed(seed=1)

X_min = 4

X_max = 30

X_n = 16

X = 5 + 25 * np.random.rand(X_n)

Prm_c = [170, 108, 0.2]

T = Prm_c[0] - Prm_c[1] * np.exp(-Prm_c[2] * X) + 4 * np.random.randn(X_n)


print(np.round(X, 2))

print(np.round(T, 2))
