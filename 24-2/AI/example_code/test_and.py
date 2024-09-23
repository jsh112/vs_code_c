import numpy as np
import matplotlib.pyplot as plt

# Define the dataset: 2-bit inputs and their corresponding labels
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([0, 0, 0, 1])  # Corresponding labels

# Initialize random weights and bias
np.random.seed(0)  # For reproducibility
w = np.random.randn(2)  # Weight for each feature
b = np.random.randn()   # Bias

# Learning rate and number of iterations
learning_rate = 0.4
num_iterations = 1000

# Sigmoid function


def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# Compute predictions


def predict(X, w, b):
    return sigmoid(np.dot(X, w) + b)

# Compute binary cross-entropy loss


def compute_loss(predictions, y):
    m = len(y)
    return -1/m * (np.dot(y, np.log(predictions)) + np.dot(1 - y, np.log(1 - predictions)))


# Gradient descent
for _ in range(num_iterations):
    # Forward pass
    predictions = predict(X, w, b)

    # Compute loss
    loss = compute_loss(predictions, y)

    # Compute gradients
    m = len(y)
    dw = 1/m * np.dot(X.T, (predictions - y))
    db = 1/m * np.sum(predictions - y)

    # Update weights and bias
    w -= learning_rate * dw
    b -= learning_rate * db

    # Optionally print the loss every 100 iterations
    if _ % 100 == 0:
        print(f"Iteration {_}: Loss {loss}")

# Final weights and bias
print(f"Final weights: {w}")
print(f"Final bias: {b}")

# Compute final predictions
final_predictions = predict(X, w, b)

# Plotting
plt.figure(figsize=(8, 6))

# Plot data points
plt.scatter(X[:, 0], X[:, 1], c=y, s=100, edgecolor='k',
            cmap=plt.cm.RdYlBu, label='Data points')

# Plot decision boundary
x_values = np.linspace(-0.5, 1.5, 100)
y_values = -(w[0] * x_values + b) / w[1]
plt.plot(x_values, y_values,
         label=f'Decision Boundary: y = {-w[0]:.2f}x + {b:.2f}', color='black')

# Labeling
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.title('Classification with Logistic Regression')
plt.legend()
plt.grid(True)
plt.show()

# import numpy as np
# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D

# # Define the dataset: 3-bit inputs and their corresponding labels
# X = np.array([[0, 0, 0], [0, 0, 1], [0, 1, 0], [0, 1, 1],
#               [1, 0, 0], [1, 0, 1], [1, 1, 0], [1, 1, 1]])
# y = np.array([0, 0, 0, 0, 0, 0, 0, 1])  # Corresponding labels

# # Initialize random weights and bias
# np.random.seed(0)  # For reproducibility
# w = np.random.randn(3)  # Weight for each feature
# b = np.random.randn()   # Bias

# # Learning rate and number of iterations
# learning_rate = 0.3
# num_iterations = 1000

# # Sigmoid function


# def sigmoid(z):
#     return 1 / (1 + np.exp(-z))

# # Compute predictions


# def predict(X, w, b):
#     return sigmoid(np.dot(X, w) + b)

# # Compute binary cross-entropy loss


# def compute_loss(predictions, y):
#     m = len(y)
#     return -1/m * (np.dot(y, np.log(predictions)) + np.dot(1 - y, np.log(1 - predictions)))


# # Gradient descent
# for _ in range(num_iterations):
#     # Forward pass
#     predictions = predict(X, w, b)

#     # Compute loss
#     loss = compute_loss(predictions, y)

#     # Compute gradients
#     m = len(y)
#     dw = 1/m * np.dot(X.T, (predictions - y))
#     db = 1/m * np.sum(predictions - y)

#     # Update weights and bias
#     w -= learning_rate * dw
#     b -= learning_rate * db

#     # Optionally print the loss every 100 iterations
#     if _ % 100 == 0:
#         print(f"Iteration {_}: Loss {loss}")

# # Final weights and bias
# print(f"Final weights: {w}")
# print(f"Final bias: {b}")

# # Compute final predictions
# final_predictions = predict(X, w, b)

# # Plotting
# fig = plt.figure(figsize=(12, 8))
# ax = fig.add_subplot(111, projection='3d')

# # Plot data points
# scatter = ax.scatter(X[:, 0], X[:, 1], X[:, 2], c=y, s=100,
#                      edgecolor='k', cmap=plt.cm.RdYlBu, label='Data points')

# # Add labels
# ax.set_xlabel('Feature 1')
# ax.set_ylabel('Feature 2')
# ax.set_zlabel('Feature 3')
# ax.set_title('Classification with Logistic Regression')

# # Create a grid for plotting the decision boundary
# x1_range = np.linspace(-0.5, 1.5, 10)
# x2_range = np.linspace(-0.5, 1.5, 10)
# x1, x2 = np.meshgrid(x1_range, x2_range)
# x3 = - (w[0] * x1 + w[1] * x2 + b) / w[2]

# # Plot decision boundary
# ax.plot_surface(x1, x2, x3, color='black', alpha=0.3, rstride=100, cstride=100)

# plt.legend()
# plt.show()
