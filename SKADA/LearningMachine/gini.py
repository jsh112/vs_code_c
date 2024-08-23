import numpy as np
import matplotlib.pyplot as plt


def gini(y_true, y_pred):
    y_true = np.array(y_true)
    y_pred = np.array(y_pred)

    # 실제값과 예측값의 크기가 같은지 확인
    if y_true.shape != y_pred.shape:
        raise Exception('Shape Error : 실제값과 예측값의 개수가 일치하지 않습니다.')

    # 데이터 개수
    n_samples = y_true.shape[0]

    # 대각선 값 (완벽한 평등선)
    L_mid = np.linspace(1 / n_samples, 1, n_samples)

    # 예측값에 대한 Lorenz 곡선
    pred_order = y_true[y_pred.argsort()]  # y_pred 크기순으로 y_true 값 정렬
    L_pred = np.cumsum(pred_order) / np.sum(pred_order)  # Lorenz 곡선
    G_pred = np.sum(L_mid - L_pred)  # 예측 값에 대한 지니계수

    # 실제값에 대한 Lorenz 곡선
    true_order = y_true[y_true.argsort()]  # y_true 크기순으로 y_true 값 정렬
    L_true = np.cumsum(true_order) / np.sum(true_order)  # Lorenz 곡선
    G_true = np.sum(L_mid - L_true)  # 예측이 완벽할 때 지니계수

    # 시각화
    plt.figure(figsize=(10, 10))

    # 완벽한 평등선
    plt.plot(np.arange(1, n_samples + 1) / n_samples,
             L_mid, label='Perfect Equality', color='gray')

    # 예측에 따른 Lorenz 곡선
    plt.plot(np.arange(1, n_samples + 1) / n_samples, L_pred,
             label='Predicted Lorenz Curve', color='blue')

    # 실제 값에 따른 Lorenz 곡선
    plt.plot(np.arange(1, n_samples + 1) / n_samples, L_true,
             label='Actual Lorenz Curve', color='red')

    plt.xlabel('Cumulative Share of Samples')
    plt.ylabel('Cumulative Share of Outcomes')
    plt.title('Lorenz Curve and Gini Coefficient')
    plt.legend()
    plt.grid(True)
    plt.show()

    # 정규화된 지니계수
    return G_pred / G_true, G_pred, G_true
