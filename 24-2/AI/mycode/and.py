import numpy as np
import matplotlib.pyplot as plt

features = [[0, 0], [0, 1], [1, 0], [1, 1]]
labels = [-1, -1, -1, 1]


def plot_xy(X, Y, a, b, c):
    lbl = {-1: "0", 1: "1"}
    clr = {-1: "red", 1: "blue"}

    if (b == 0):
        raise ('cannot divided by zero')
    else:
        x = np.linspace(-1, 2, 100)
        y = -(a/b)*x - (c/b)
        plt.plot(x, y, '-r')
        plt.title(f'Graph of {a} * x + {b} * y + {c} = 0')
        plt.xlabel('x')
        plt.ylabel('y')
        plt.axhline(y=0, color='k')
        plt.axvline(x=0, color='k')

        for i in category:
            plt.scatter(X[np.where(Y == i), 0],
                        X[np.where(Y == i), 1], label=lbl[i], c=clr[i])
        plt.legend(fontsize=12)
        plt.grid()
        plt.show()


def perceptron(X, Y, iter, learning_rate):
    theta = np.array([0, 0])
    theta_0 = 0

    for t in range(iter):
        print("t : ", t)
        for i in range(X.shape[0]):
            if Y[i] * (np.dot(theta, X[i]) + theta_0) <= 0:
                # theta_1*x1 + theta_2*x2 + theta_0
                # 이쯤에다가 learning rate를 첨가해보자
                theta = theta + Y[i]*X[i] * learning_rate
                theta_0 = theta_0 + Y[i] * learning_rate
        print(f"theta, theta_0 : {theta}, {theta_0}")
        plot_xy(X, Y, theta[0], theta[1], theta_0)
    return theta, theta_0


X = np.array(features)
Y = np.array(labels)
category = np.unique(Y)
learning_rate = 0.6
perceptron(X, Y, 30, learning_rate)
