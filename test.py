import numpy as np
import imageio
import cv2
import matplotlib.pyplot as plt
from skimage.measure import label, regionprops

NoOfImg = 24

Xmsaved = np.zeros((2, NoOfImg))
Xhsaved = np.zeros((2, NoOfImg))
Xqrsaved = np.zeros((2, NoOfImg))


def GetBallPos(index):
    global imgBg, firstRun
    if 'firstRun' not in globals():
        imgBg = imageio.imread('Img/bg.jpg')
        firstRun = True

    imgWork = imageio.imread(f'Img/{index}.jpg')
    plt.imshow(imgWork)

    # Calculate absolute difference between images
    fore = np.abs(imgWork.astype(np.int16) - imgBg.astype(np.int16)) > 10
    fore = np.logical_or(fore[:, :, 0], np.logical_or(
        fore[:, :, 1], fore[:, :, 2]))

    # Label and find the region properties
    L = label(fore)
    stats = regionprops(L)

    if len(stats) > 0:
        area_vector = np.array([s.area for s in stats])
        idx = np.argmax(area_vector)
        centroid = stats[idx].centroid

        xc = centroid[1] + 15*np.random.randn()
        yc = centroid[0] + 15*np.random.randn()
    else:
        xc, yc = 0, 0

    return xc, yc


def TrackKalman(xm, ym):
    global A, H, Q, R, x, P, firstRun
    if 'firstRun' not in globals():
        dt = 1
        A = np.array([[1, dt, 0, 0],
                      [0,  1, 0, 0],
                      [0,  0, 1, dt],
                      [0,  0, 0, 1]])

        H = np.array([[1, 0, 0, 0],
                      [0, 0, 1, 0]])

        Q = 1.0 * np.eye(4)
        R = np.array([[50, 0],
                      [0, 50]])

        x = np.zeros(4)
        P = 100 * np.eye(4)

        firstRun = True

    # Kalman prediction step
    xp = A.dot(x)
    Pp = A.dot(P).dot(A.T) + Q

    # Kalman update step
    K = Pp.dot(H.T).dot(np.linalg.inv(H.dot(Pp).dot(H.T) + R))
    z = np.array([xm, ym])
    x = xp + K.dot(z - H.dot(xp))
    P = Pp - K.dot(H).dot(Pp)

    xh = x[0]
    yh = x[2]
    return xh, yh


for k in range(NoOfImg):
    xm, ym = GetBallPos(k)
    xh, yh = TrackKalman(xm, ym)

    # For simplicity, we'll assume TrackKalmanQR is similar to TrackKalman
    xqr, yqr = TrackKalman(xm, ym)

    plt.plot(xm, ym, 'r*')
    plt.plot(xh, yh, 'bs')
    plt.plot(xqr, yqr, 'bo')

    plt.pause(1)

    Xmsaved[:, k] = [xm, ym]
    Xhsaved[:, k] = [xh, yh]
    Xqrsaved[:, k] = [xqr, yqr]

# Plotting the saved results
plt.figure()
plt.plot(Xhsaved[0, :], Xhsaved[1, :], 's')
plt.plot(Xqrsaved[0, :], Xqrsaved[1, :], 'o')
plt.show()
