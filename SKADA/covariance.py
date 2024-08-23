import numpy as np
import pandas as pd

# 행렬 A 정의
A = np.array([[1, -2],
              [2, -1],
              [1, -3]])

# 공분산 행렬 계산
cov_A = np.cov(A, rowvar=False)

# 공분산 행렬을 DataFrame으로 변환하여 이쁘게 출력
cov_df = pd.DataFrame(cov_A, columns=['Variable 1', 'Variable 2'], index=[
                      'Variable 1', 'Variable 2'])

# 소수점 4자리로 포맷팅하여 출력
print(cov_df.round(4))
