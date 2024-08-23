# Create Data sets of numpy array
import matplotlib.pyplot as plt
import numpy as np
x1 = np.array([10, 9, 3, 2])
y1 = np.array([90, 80, 50, 30])

x2 = np.array([10, 9, 3, 2, 11])
y2 = np.array([90, 80, 50, 30, 40])

# Visualization of data
plt.figure(1, figsize=(10, 5))

plt.subplot(121)
plt.scatter(x1, y1)
plt.title('Without Outlier')

plt.subplot(122)
plt.scatter(x2, y2)
plt.title('With Outlier')

# Make OLS Function


def OLS(x, y):
    w = np.sum((x - x.mean())*(y - y.mean())) / np.sum((x - x.mean())**2)
    b = y.mean() - w * x.mean()
    return w, b

# compute weight and bias


w1, b1 = OLS(x1, y1)
w2, b2 = OLS(x2, y2)

# predict the values
x1_pred = w1 * x1 + b1
x2_pred = w2 * x2 + b2

plt.figure(2, figsize=(10, 5))
plt.subplot(121)
plt.scatter(x1, y1)
plt.plot(x1, x1_pred, c='red', label=f'Y={w1:.2f}x + {b1:.2f}')
plt.legend()
plt.title('Without Outlier')

plt.subplot(122)
plt.scatter(x2, y2)
plt.plot(x2, x2_pred, c='red', label=f'Y={w2:.2f}x + {b2:.2f}')
plt.legend()
plt.title('With Outlier')

plt.show()
