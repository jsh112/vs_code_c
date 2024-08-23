import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, confusion_matrix, roc_auc_score, auc
import pandas as pd
import numpy as np

# Create a DataFrame
df = pd.DataFrame({
    'true': [0, 1, 0, 1, 1, 0, 1],
    'pred': [0, 1, 0, 1, 0, 0, 0]
})

y_true = df['true'].values
y_scores = df['pred'].values

thresholds = np.sort(np.unique(y_scores))

fpr = []
tpr = []

n = len(y_true)

for threshold in thresholds:
    y_pred = (y_scores >= threshold).astype('int')

    # TP, FP, TN, FN 계산
    TP = np.sum((y_true == 1) & (y_pred == 1))
    FP = np.sum((y_true == 0) & (y_pred == 1))
    TN = np.sum((y_true == 0) & (y_pred == 0))
    FN = np.sum((y_true == 1) & (y_pred == 0))

    # FPR과 TPR 계산
    fpr.append(FP / (FP + TN) if (FP + TN) > 0 else 0)
    tpr.append(TP / (TP + FN) if (TP + FN) > 0 else 0)

# 결과 출력
fpr = np.array(fpr)
tpr = np.array(tpr)
thresholds = np.array(thresholds)

print("False Positive Rate (FPR):", fpr, fpr.shape)
print("True Positive Rate (TPR):", tpr, tpr.shape)
print("Thresholds:", thresholds, threshold.shape)

# fpr, tpr, thresholds = roc_curve(df['true'], df['pred'])
# print(f'fpr : {fpr}')
# print(f'tpr : {tpr}')
# print(f'thresholds : {thresholds}')

# print(confusion_matrix(df['true'], df['pred']))

# print(roc_auc_score(df['true'], df['pred']))

plt.figure(figsize=(6, 6))
plt.plot(fpr, tpr, label=f'Roc Curve (AUC : {auc(fpr, tpr)} )')
plt.plot([0, 1], [0, 1], color='gray', linestyle='--')
plt.legend()
plt.show()
