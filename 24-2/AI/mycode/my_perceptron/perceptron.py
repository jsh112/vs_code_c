import numpy as np
import matplotlib.pyplot as plt


class Perceptron:
    # init
    def __init__(self, input_size, learning_rate=0.01, epochs=1000):
        self.weights = np.random.randn(input_size)
        self.bias = np.random.randn()
        self.input_size = input_size
        self.learning_rate = learning_rate
        self.epochs = epochs

    # activation function
    def activation_function(self, x):
        return 1 if x >= 0 else -1

    # predict
    def predict(self, x):
        output = np.dot(x, self.weights) + self.bias
        return self.activation_function(output)

    def plot_boundary(self, X, y):
        if self.weights[1] != 0:
            x_values = np.linspace(-1, 2, 100)
            # y = -(a/b)x + -(c/b)
            y_values = -(self.weights[0]/self.weights[1]) * \
                x_values - (self.bias / self.weights[1])
            plt.plot(x_values, y_values, '-r', label='Decision Line')

        for i in range(len(X)):
            if y[i] == 1:
                plt.scatter(X[i][0], X[i][1], color='blue', marker='o')
            else:
                plt.scatter(X[i][0], X[i][1], color='red', marker='x')

        plt.axhline(0, color='black', linewidth=0.4)
        plt.axvline(0, color='black', linewidth=0.4)
        plt.xlim(-1, 2)
        plt.ylim(-1, 2)
        plt.title(
            f'Line : x2 = {-(self.weights[0]/self.weights[1])}*x + {self.bias / self.weights[1]}')
        plt.xlabel('x1')
        plt.ylabel('x2')
        plt.legend()
        plt.grid()
        plt.show()
    # fit

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
            self.plot_boundary(X, y)
