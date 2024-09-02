import sympy as sp
import matplotlib.pyplot as plt
import numpy as np

# Define the symbolic variables
x, n, i = sp.symbols('x n i')

# Define the function f(x)
f = sp.Function('f')(x)
f = 1

# Define the coefficient function b

def b(n, l):
    coeff = 2 / l * sp.integrate(f * sp.sin(n * sp.pi * x / l), (x, 0, 1))
    return coeff

# Define the Fourier Series function FS


def FS(n, l):
    series_sum = sum(b(i, l) * sp.sin(i * sp.pi * x / l)
                     for i in range(1, n+1))
    return series_sum


# Define the plot range
x_vals = np.linspace(0, 1, 400)

# Plot the original function f(x)
plt.figure(figsize=(10, 6))
plt.plot(x_vals, [f for _ in x_vals], color='black', label='f(x)')

# Plot the Fourier Series for different values of n
for n in range(1, 9, 2):
    fs_n = FS(n, 1)
    f_lambdified = sp.lambdify(x, fs_n, modules=['numpy'])
    y_vals = f_lambdified(x_vals)

    plt.plot(x_vals, y_vals, label=f'n={n}')

# Set axis limits
plt.xlim(0, 1)  # Set x-axis range
plt.ylim(0, 1.5)  # Set y-axis range, adjust based on expected FS(x) range

# Add labels, legend, and show the plot
plt.xlabel('x')
plt.ylabel('f(x) and FS(x)')
plt.title('Fourier Series Approximation')
plt.legend()
plt.show()
