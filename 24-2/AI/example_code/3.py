import numpy as np
import matplotlib.pyplot as plt


def plot_xy(X, Y, a, b, c):
    mkr = {-1: "_", 1: "+"}
    lbl = {-1: "minus", 1: "plus"}
    clr = {-1: "red", 1: "blue"}

    if (b == 0):
        print('no graph')
    else:
        x = np.linspace(-5, 5, 100)
        # ax + by + c = 0
        y = - (a/b) * x - (c/b)
        # plt.plot(x, y, '-r', label='ax + by + c = 0')
        plt.plot(x, y, '-r')
        plt.title('Graph of ax + by + c = 0')
        plt.xlabel('x', color='#1C2833')
        plt.ylabel('y', color='#1C2833')
        # plt.legend(loc='upper left')
        # plt.axis(option='on')
        plt.axhline(y=0, color='k')
        plt.axvline(x=0, color='k')

        for i in category:
            plt.scatter(X[np.where(Y == i), 0], X[np.where(
                Y == i), 1], c=clr[i], marker=mkr[i], label=lbl[i])

        plt.legend(fontsize=12, loc='upper left')  # legend position
        plt.grid()
        plt.show()


def perceptron(X, Y, iter):
    theta = np.array([0, 0])
    theta_0 = 0

    for t in range(iter):
        print("t : ",   t)
        # numbers of row -> .shape[0]
        for i in range((X.shape[0])):
            # print(Y[i])
            # print(X[i])
            # print(np.dot(theta, X[i]))
            if Y[i] * (np.dot(theta, X[i]) + theta_0) <= 0:
                # theta = theta + np.dot(Y[i], X[i]) # np.dot은 스칼라와 벡터를 곱할 때 아래의 곱셈과 같은 결과를 줍니다.
                theta = theta + Y[i] * X[i]  # Y와 X의 곱은 X의 각 원소에 Y를 곱한 값이 됩니다.
                theta_0 = theta_0 + Y[i]
        print("theta, theta_0 : ", theta, theta_0)
        plot_xy(X, Y, theta[0], theta[1], theta_0)

    return theta, theta_0


features = [[1, 2], [2, 1], [3, -1], [2.5, 1.5], [2, 3], [3, 2]]
labels = [-1, -1, -1, 1, 1, 1]

mkr = {-1: "_", 1: "+"}
lbl = {-1: "minus", 1: "plus"}
clr = {-1: "red", 1: "blue"}

X = np.array(features)
Y = np.array(labels)
category = np.unique(Y)
perceptron(X, Y, 50)

plt.xlabel('x')
plt.ylabel('y')
plt.legend(fontsize=12, loc='upper left')  # legend position
plt.axhline(y=0, color='k')
plt.axvline(x=0, color='k')
plt.grid()
plt.show()
