import numpy as np
import plotly.graph_objects as go
import matplotlib.pyplot as plt
from sklearn.linear_model import Lasso
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline

# 데이터 생성
N = 50
num_alpha = N
num_beta = N
x = np.random.normal(0, 1, N)
u = np.random.normal(0, 1, N)
alpha = 10
beta = 15
y = alpha + x * beta + u

# 알파와 베타 값의 범위 설정
alphas = np.linspace(0, num_alpha, num_alpha)
betas = np.linspace(0, num_beta, num_beta)

# RSS 계산
RSS = np.zeros((num_alpha, num_beta))

for i in range(num_alpha):
    for j in range(num_beta):
        y_hat = alphas[i] + betas[j] * x
        u_hat = y - y_hat
        RSS[i, j] = np.sum(u_hat ** 2)

# 3차원 그래프 생성
fig = go.Figure(data=[go.Surface(z=RSS, x=betas, y=alphas)])
fig.update_layout(scene=dict(
    xaxis_title='beta',
    yaxis_title='alpha',
    zaxis_title='RSS'),
    title='3D Surface Plot of RSS')
fig.show()

# 2차원 등고선과 L1 제약 조건 시각화
plt.figure(figsize=(8, 6))
contour = plt.contour(betas, alphas, RSS,
                      levels=np.logspace(2, 5, 20), cmap='viridis')
plt.clabel(contour, inline=True, fontsize=8)

# L1 정규화 제약 조건 그리기
l1_levels = [1, 2, 3, 4]
for level in l1_levels:
    plt.plot([0, level], [level, 0], 'k--')
    plt.plot([0, -level], [-level, 0], 'k--')
    plt.plot([0, level], [-level, 0], 'k--')
    plt.plot([0, -level], [level, 0], 'k--')

# 축 및 레이블 설정
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.xlim(0, num_beta)
plt.ylim(0, num_alpha)
plt.xlabel('beta')
plt.ylabel('alpha')
plt.title('2D Contour Plot of RSS with L1 Constraint')

plt.show()
