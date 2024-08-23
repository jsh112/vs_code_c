from sklearn.metrics import roc_curve, confusion_matrix, auc
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


def custom_roc_curve(y_true, y_scores):
    # 예측값을 내림차순으로 정렬하고 고유한 값을 선택
    desc_score_indices = np.argsort(y_scores)[::-1]
    y_scores = y_scores[desc_score_indices]
    y_true = y_true[desc_score_indices]

    # 고유한 예측값 추출
    distinct_value_indices = np.where(np.diff(y_scores))[0]
    threshold_idxs = np.r_[distinct_value_indices, y_true.size - 1]

    # 임계값 배열 확장
    thresholds = y_scores[threshold_idxs]
    thresholds = np.concatenate(
        ([thresholds[0] + 1], thresholds, [thresholds[-1] - 1]))

    fpr = []
    tpr = []

    for threshold in thresholds:
        y_pred_binary = (y_scores >= threshold).astype(int)
        tn, fp, fn, tp = confusion_matrix(y_true, y_pred_binary).ravel()
        fpr.append(fp / (fp + tn) if (fp + tn) > 0 else 0)
        tpr.append(tp / (tp + fn) if (tp + fn) > 0 else 0)

    return np.array(fpr), np.array(tpr), np.array(thresholds)


# 데이터프레임 생성
df = pd.DataFrame({
    'true': [0, 1, 0, 1, 1, 0, 1],
    'pred': [0, 1, 0, 1, 0, 0, 0]
})

# 함수 호출
fpr, tpr, thresholds = custom_roc_curve(df['true'].values, df['pred'].values)

# 결과 출력
print(f'False Positive Rate (FPR): {fpr}')
print(f'True Positive Rate (TPR): {tpr}')
print(f'Thresholds: {thresholds}')

# sklearn의 roc_curve와 비교

fpr_sklearn, tpr_sklearn, thresholds_sklearn = roc_curve(
    df['true'], df['pred'])
print(f'\n[sklearn] False Positive Rate (FPR): {fpr_sklearn}')
print(f'[sklearn] True Positive Rate (TPR): {tpr_sklearn}')
print(f'[sklearn] Thresholds: {thresholds_sklearn}')

plt.figure(figsize=(6, 6))
plt.plot(fpr, tpr, label=f'Roc curve (AUC : {auc(fpr, tpr)})')
plt.plot([0, 1], [0, 1], color='gray', linestyle='--')
plt.legend()
plt.show()
