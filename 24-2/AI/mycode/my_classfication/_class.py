import numpy as np
import matplotlib.pyplot as plt


class _binary:
    def __init__(self, input_size, learning_rate=0.01, epochs=1000):
        self.weights = np.random.randn(input_size)
        self.learning_rate = learning_rate
        self.epochs = epochs

    def activation_function(self, output):
        return 1 if output >= 0 else -1

    def pred(self, x):
        output = np.dot(x, self.weights)
        return self.activation_function(output)

    def plot_boundary(self, X, y):
        if self.weights[1] != 0:
            x_values = np.linspace(-1, 6, 100)
            # y = -(w1/w2)x
            y_values = -(self.weights[0]/self.weights[1])*x_values
            plt.plot(x_values, y_values, '-r', label='Decision Line')

        for i in range(len(X)):
            if y[i] == 1:
                plt.scatter(X[i][0], X[i][1], color='blue', marker='o')
            else:
                plt.scatter(X[i][0], X[i][1], color='red', marker='x')
        plt.axhline(0, color='black', linewidth=0.4)
        plt.axvline(0, color='black', linewidth=0.4)
        plt.xlim(-1, 6)
        plt.ylim(-1, 6)
        plt.title(
            f'Line : y = {-(self.weights[0]/self.weights[1])}*x')
        plt.xlabel('x1')
        plt.ylabel('y1')
        plt.legend()
        plt.grid()
        plt.show()

    def fit(self, X, y):
        for epoch in range(self.epochs):
            errors = 0
            self.plot_boundary(X, y)
            for i in range(len(X)):
                y_pred = self.pred(X[i])
                if y[i] != y_pred:
                    self.weights += self.learning_rate * (y[i]-y_pred)*X[i]
                    errors += 1
            print(f'epoch : {epoch+1}, error : {errors}')
            if errors == 0:
                print(f'Training completed at epoch {epoch+1}')
                break


class _class_and:
    def __init__(self, input_size, learning_rate=0.01, epochs=1000):
        self.weights = np.random.randn(input_size)
        self.bias = np.random.randn()
        self.learning_rate = learning_rate
        self.epochs = epochs

    def activation_function(self, output):
        return 1 if output >= 0 else -1

    def predict(self, x):
        output = np.dot(self.weights, x.T) + self.bias
        return self.activation_function(output)

    def plot_cartesian(self, X, y):
        # line
        # y = -(w1/w2)*x + (-b/w2)
        if self.weights[1] != 0:
            x_values = np.linspace(-1, 2, 100)
            y_values = (-self.weights[0]/self.weights[1]
                        )*x_values + (-self.bias/self.weights[1])
            plt.plot(x_values, y_values, '-r', label='Boundary Line')

        # points
        for i in range(len(X)):
            if y[i] == 1:
                plt.scatter(X[i][0], X[i][1], color='blue')
            else:
                plt.scatter(X[i][0], X[i][1], color='red')

        # figure
        plt.axhline(0, color='black', linewidth=0.4)
        plt.axvline(0, color='black', linewidth=0.4)
        plt.xlabel('x1')
        plt.ylabel('x2')
        plt.xlim(-1, 2)
        plt.ylim(-1, 2)
        plt.title(
            f'Line : y = {-(self.weights[0]/self.weights[1])}*x + {-(self.bias/self.weights[1])}')
        plt.legend()
        plt.grid()
        plt.draw()
        plt.pause(0.2)
        plt.clf()

    def fit(self, X, y):
        for epoch in range(self.epochs):
            errors = 0
            self.plot_cartesian(X, y)
            for i in range(len(X)):
                y_pred = self.predict(X[i])
                print('{:<7} : {:>2}, prediction of y : {:>2}'.format(
                    str((X[i][0], X[i][1])), y[i], y_pred))

                if y[i] != y_pred:
                    self.weights += self.learning_rate * (y[i] - y_pred) * X[i]
                    self.bias += self.learning_rate * (y[i] - y_pred)
                    errors += 1

            print(f'epoch : {epoch+1}, numbers of error : {errors}')
            if errors == 0:
                print(f'Training completed at epoch {epoch + 1}')
                input("Training complete")
                for i in range(len(X)):
                    print(f'{(X[i][0], X[i][1])} : {1 if y[i] == 1 else 0}')
                break
            input("사용자가 원할때까지 대기")
