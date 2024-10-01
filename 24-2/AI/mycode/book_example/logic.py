import numpy as np
import matplotlib.pyplot as plt

# AND Gate


def AND(x1, x2):
    # w1, w2, theta = 0.5, 0.5, 0.7
    # tmp = x1*w1 + x2*w2
    # if tmp <= theta:
    #     return 0
    # elif tmp > theta:
    #     return 1

    x = np.array([x1, x2])
    w = np.array([0.5, 0.5])
    b = -0.7
    tmp = np.sum(w * x) + b
    if tmp <= 0:
        return 0
    else:
        return 1

# NAND Gate


def NAND(x1, x2):
    x = np.array([x1, x2])
    w = np.array([-0.5, -0.5])
    b = 0.7
    tmp = np.sum(x * w) + b
    if tmp <= 0:
        return 0
    else:
        return 1

# OR Gate


def OR(x1, x2):
    x = np.array([x1, x2])
    w = np.array([1.0, 1.0])
    b = -0.5
    tmp = np.sum(x * w) + b
    if tmp <= 0:
        return 0
    else:
        return 1

# XOR Gate


def XOR(x1, x2):
    s1 = NAND(x1, x2)
    s2 = OR(x1, x2)
    y = AND(s1, s2)
    return y


for x1 in [0, 1]:
    for x2 in [0, 1]:
        print(f"XOR({x1}, {x2}) = {XOR(x1, x2)}")
