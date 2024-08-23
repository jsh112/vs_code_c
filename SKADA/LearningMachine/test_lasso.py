import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import Lasso
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline

# 예제 데이터 생성
np.random.seed(42)
X = np.random.rand(100, 1) * 10  # 독립 변수
y = 2 * X.squeeze() + 1 + np.random.randn(100) * 2  # 종속 변수 (y = 2X + 1 + 잡음)

# Lasso 회귀 모델 생성 및 훈련
lasso = make_pipeline(StandardScaler(), Lasso(alpha=0.1))
lasso.fit(X, y)

# 가중치 추출
w1, intercept = lasso.named_steps['lasso'].coef_[
    0], lasso.named_steps['lasso'].intercept_

# 오차 함수의 등고선 생성


def error_contour(w1, w2, X, y):
    return np.sum((y - (w1 * X.squeeze() + w2))**2)

# 다이아몬드 모양의 L1 정규화 제약 조건


def l1_norm(w1, w2):
    return np.abs(w1) + np.abs(w2)


# 등고선 그리기
w1_range = np.linspace(-1, 3, 400)
w2_range = np.linspace(-1, 10, 400)
W1, W2 = np.meshgrid(w1_range, w2_range)
Z = np.array([error_contour(w1, w2, X, y)
             for w1, w2 in zip(np.ravel(W1), np.ravel(W2))])
Z = Z.reshape(W1.shape)

plt.figure(figsize=(8, 6))
contour = plt.contour(W1, W2, Z, levels=np.logspace(2, 5, 20), cmap='viridis')
plt.clabel(contour, inline=True, fontsize=8)

# L1 정규화 제약 조건 그리기
l1_levels = [1, 2, 3, 4]
for level in l1_levels:
    plt.plot([0, level], [level, 0], 'k--')
    plt.plot([0, -level], [-level, 0], 'k--')
    plt.plot([0, level], [-level, 0], 'k--')
    plt.plot([0, -level], [level, 0], 'k--')

# 등고선과 L1 규제항이 만나는 점을 찾아서 표시
intersection_points = []
for level in l1_levels:
    for i in range(len(W1)):
        for j in range(len(W2)):
            if np.abs(l1_norm(W1[i, j], W2[i, j]) - level) < 0.1:
                intersection_points.append((W1[i, j], W2[i, j]))

for point in intersection_points:
    plt.plot(point[0], point[1], 'bo', markersize=10)
    plt.annotate('Intersection Point', xy=point,
                 xytext=(point[0] + 0.5, point[1] - 0.5),
                 arrowprops=dict(facecolor='blue', shrink=0.05))

# 축 및 레이블 설정
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.xlim(-1, 3)
plt.ylim(-1, 10)
plt.xlabel('$w_1$')
plt.ylabel('$w_2$')
plt.title('Lasso Regularization and Error Contours with Example Data')

plt.show()
