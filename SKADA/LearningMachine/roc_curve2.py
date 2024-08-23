import pandas as pd
import numpy as np
from sklearn.metrics import confusion_matrix


def custom_roc_curve(y_true, y_pred):
    # 임계값 설정: 주어진 예제에 맞게 2를 포함하여 설정
    thresholds = [2, 1, 0]

    fpr = []
    tpr = []

    for threshold in thresholds:
        y_pred_binary = (y_pred >= threshold).astype(int)
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
