import numpy as np
import matplotlib.pyplot as plt

# Perceptron class definition

# Hide panel : Ctrl+J


class Perceptron:
    def __init__(self, input_size, learning_rate=0.01, epochs=1000):
        self.weights = np.zeros(input_size)
        self.bias = 0
        self.learning_rate = learning_rate
        self.epochs = epochs

    def activation_function(self, x):
        return 1 if x >= 0 else -1

    def predict(self, x):
        linear_output = np.dot(x, self.weights) + self.bias
        return self.activation_function(linear_output)

    def fit(self, X, y):
        # iterate by epochs
        for _ in range(self.epochs):
            for i in range(len(X)):
                y_pred = self.predict(X[i])
                if y[i] * (np.dot(self.weights, X[i]) + self.bias) <= 0:
                    self.weights += self.learning_rate * y[i] * X[i]
                    self.bias += self.learning_rate * y[i]
            self.plot_decision_boundary(X, y)

    def plot_decision_boundary(self, X, y):
        # Plot the decision boundary (only if weight[1] != 0)
        if self.weights[1] != 0:
            x_values = np.linspace(-1, 2, 100)
            y_values = -(self.weights[0] / self.weights[1]) * \
                x_values - (self.bias / self.weights[1])
            plt.plot(x_values, y_values, '-r', label='Decision Boundary')

        # Plot the data points
        for i in range(len(X)):
            if y[i] == 1:
                plt.scatter(X[i][0], X[i][1], color='blue',
                            marker='o', label='1' if i == 0 else "")
            else:
                plt.scatter(X[i][0], X[i][1], color='red',
                            marker='x', label='-1' if i == 0 else "")

        plt.axhline(0, color='black', linewidth=0.5)
        plt.axvline(0, color='black', linewidth=0.5)
        plt.xlim(-1, 2)
        plt.ylim(-1, 2)
        plt.title(f' y = -{self.weights[0]/self.weights[1]}*x + {-self.bias}')
        plt.xlabel('Feature 1')
        plt.ylabel('Feature 2')
        plt.legend(loc='upper right')
        plt.grid(True)
        plt.show()


# Example usage with 2-bit inputs (AND gate)
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])  # Input
y = np.array([-1, 1, 1, 1])

perceptron = Perceptron(input_size=2, learning_rate=0.6, epochs=30)
perceptron.fit(X, y)
print(f"Weights: {perceptron.weights}")
print(f"Bias: {perceptron.bias}")
