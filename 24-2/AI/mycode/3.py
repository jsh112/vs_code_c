import numpy as np
import matplotlib.pyplot as plt


class Perceptron:
    def __init__(self, input_size, learning_rate=0.01, epochs=1000):
        self.weights = np.random.randn(input_size)
        self.bias = np.random.randn()
        self.learning_rate = learning_rate
        self.epochs = epochs

    def activation_function(self, x):
        return 1 if x >= 0 else -1

    def predict(self, x):
        linear_output = np.dot(x, self.weights) + self.bias
        return self.activation_function(linear_output)

    def fit(self, X, y):
        for epoch in range(self.epochs):
            errors = 0  # 매 epoch마다 오류를 기록하는 변수
            for i in range(len(X)):
                y_pred = self.predict(X[i])
                if y[i] != y_pred:
                    self.weights += self.learning_rate * (y[i] - y_pred) * X[i]
                    self.bias += self.learning_rate * (y[i] - y_pred)
                    errors += 1
            print(f'epoch is {epoch}')
            if errors == 0:
                print(f"Training completed at epoch {epoch+1}")
                break
            self.plot_decision_boundary(X, y)

    def plot_decision_boundary(self, X, y):
        if self.weights[1] != 0:
            x_values = np.linspace(-1, 2, 100)
            y_values = -(self.weights[0] / self.weights[1]) * \
                x_values - (self.bias / self.weights[1])
            plt.plot(x_values, y_values, '-r', label='Decision Boundary')

        for i in range(len(X)):
            if y[i] == 1:
                plt.scatter(X[i][0], X[i][1], color='blue',
                            marker='o', label='Class 1' if i == 0 else "")
            else:
                plt.scatter(X[i][0], X[i][1], color='red',
                            marker='x', label='Class -1' if i == 0 else "")

        plt.axhline(0, color='black', linewidth=0.5)
        plt.axvline(0, color='black', linewidth=0.5)
        plt.xlim(-1, 2)
        plt.ylim(-1, 2)
        plt.title(
            f'Decision Boundary: y = {-self.weights[0]/self.weights[1]} * x + {-self.bias/self.weights[1]}')
        plt.xlabel('Feature 1')
        plt.ylabel('Feature 2')
        plt.legend(loc='upper right')
        plt.grid(True)
        plt.show()


# Training data (AND gate)
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([-1, -1, -1, 1])  # AND gate labels

perceptron = Perceptron(input_size=2, learning_rate=0.5, epochs=1000)
perceptron.fit(X, y)
