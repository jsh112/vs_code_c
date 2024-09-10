import numpy as np
import matplotlib.pyplot as plt

# Generate random data points
X_data = np.random.rand(5) * 5
Y_data = np.random.rand(5) * 5

# Define a range for w (slope)
w_range = np.linspace(0, 10, 1000)  # w between 0 and 10
x_range = np.linspace(0, 5, 1000)   # X values for plotting the best-fit line

# Compute the optimal slope (min_w)
min_w = np.sum(X_data * Y_data) / np.sum(X_data**2)

# Compute squared error for each w
squared_errors = np.zeros(w_range.shape)

for idx, w in enumerate(w_range):
    predicted_Y = w * X_data
    squared_errors[idx] = np.sum((Y_data - predicted_Y) ** 2)

# Find the index of the minimum squared error
min_error_idx = np.argmin(squared_errors)

# Create figure and subplots
plt.figure(figsize=(12, 6))

# Plot squared error as a function of w
plt.subplot(1, 2, 1)
plt.plot(w_range, squared_errors, color='b', label='Squared Error')
plt.scatter(w_range[min_error_idx],
            squared_errors[min_error_idx], color='r', label='Min Error')
plt.xlabel('w')
plt.ylabel('Squared Error (e^2)')
plt.title('Squared Error vs. w')
plt.grid(True)  # Add grid
plt.legend()    # Add legend

# Plot data points and the best fit line using min_w
plt.subplot(1, 2, 2)
plt.scatter(X_data, Y_data, color='r', label='Data Points')
plt.plot(x_range, min_w * x_range, color='y',
         label=f'Best Fit: y = {min_w:.2f}x')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Data Points and Best Fit Line')
plt.grid(True)  # Add grid
plt.legend()    # Add legend

# Show plot
plt.tight_layout()
plt.show()
