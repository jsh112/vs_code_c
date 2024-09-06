import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 1, 100)
y = np.sin(x) + 1/3 * np.sin(3*x)
plt.plot(x, y)
