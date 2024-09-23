import numpy as np
from _class import _binary, _class_and

X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([-1, -1, -1, 1])

# _c = _Class(input_size=2, learning_rate=0.3, epochs=30)
# _c.fit(X, y)

X_nand = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y_nand = np.array([1, 1, 1, -1])

_and = _class_and(2, 0.2, 30)
_and.fit(X, y)
