import numpy as np
from scipy.io import loadmat
from stl import mesh

# Load lidar data
lidar_data = loadmat('lidar_data_2.mat')
lidar_1 = lidar_data['lidar_1']
lidar_2 = lidar_data['lidar_2']

# Transformation matrices for lidar 1
x_1, y_1, z_1 = 0.94, 0.49, 1.76
roll_1, pitch_1, yaw_1 = 0.0, 0.0, -0.017453

# Transformation matrices for lidar 2
x_2, y_2, z_2 = 0.964921, -0.52463, 1.8305882
roll_2, pitch_2, yaw_2 = 0.0049101, 0.113957, 0.0447597

# Lidar transformation functions
def transformation_matrix(x, y, z, roll, pitch, yaw):
    cos_r = np.cos(roll)
    sin_r = np.sin(roll)
    cos_p = np.cos(pitch)
    sin_p = np.sin(pitch)
    cos_y = np.cos(yaw)
    sin_y = np.sin(yaw)

    r_matrix = np.array([[1, 0, 0, 0],
                         [0, cos_r, -sin_r, 0],
                         [0, sin_r, cos_r, 0],
                         [0, 0, 0, 1]])

    p_matrix = np.array([[cos_p, 0, sin_p, 0],
                         [0, 1, 0, 0],
                         [-sin_p, 0, cos_p, 0],
                         [0, 0, 0, 1]])

    y_matrix = np.array([[cos_y, -sin_y, 0, 0],
                         [sin_y, cos_y, 0, 0],
                         [0, 0, 1, 0],
                         [0, 0, 0, 1]])

    tl_matrix = np.array([[1, 0, 0, x],
                          [0, 1, 0, y],
                          [0, 0, 1, z],
                          [0, 0, 0, 1]])

    tf_matrix = np.dot(np.dot(np.dot(tl_matrix, y_matrix), p_matrix), r_matrix)

    return tf_matrix

# Apply transformation matrices to lidar data
tf_lidar_1 = np.dot(lidar_1, transformation_matrix(x_1, y_1, z_1, roll_1, pitch_1, yaw_1).T)
tf_lidar_2 = np.dot(lidar_2, transformation_matrix(x_2, y_2, z_2, roll_2, pitch_2, yaw_2).T)

# Load car model
car_mesh = mesh.Mesh.from_file('hyundai_i30.stl')
car_vertices = np.concatenate((car_mesh.x, car_mesh.y, car_mesh.z, np.ones_like(car_mesh.x)), axis=1)

# Apply transformation matrix to car model
car_roll = 90/180 * np.pi
car_yaw = 90/180 * np.pi
R_car_roll = np.array([[1, 0, 0, 0],
                       [0, np.cos(car_roll), -np.sin(car_roll), 0],
                       [0, np.sin(car_roll), np.cos(car_roll), 0],
                       [0, 0, 0, 1]])
R_car_yaw = np.array([[np.cos(car_yaw), -np.sin(car_yaw), 0, 0],
                      [np.sin(car_yaw), np.cos(car_yaw), 0, 0],
                      [0, 0, 1, 0],
                      [0, 0, 0, 1]])
car_re = np.dot(np.dot(R_car_yaw, R_car_roll), car_vertices.T)
car_temp = np.sort(car_re[1, :])
car_ydot = -car_temp[len(car_temp) // 2]
car_xdot = -1.8
car_zdot = -np.min(car_re[2, :]) + 0.2
L_car = np.array([[1, 0, 0, car_xdot],
                  [0, 1, 0, car_ydot],
                  [0, 0, 1, car_zdot],
                  [0, 0, 0, 1]])
car_re = np.dot(L_car, car_re)

# Visualization code goes here
# Note: Visualization in Python typically requires additional libraries such as matplotlib or mayavi
