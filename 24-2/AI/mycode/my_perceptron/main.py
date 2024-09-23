import numpy as np
from perceptron import Perceptron

# X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
# y = np.array([-1, -1, -1, 1])

X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([1, 1, 1, -1])

# define the value my_perceptron to Perceptron class
# fit X, y
my_perceptron = Perceptron(input_size=2, learning_rate=0.4, epochs=30)
my_perceptron.fit(X, y)
