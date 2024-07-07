#!/usr/bin/env python
# coding: utf-8

# ### module import

# In[91]:


import json
import os
from IPython.display import Image
import numpy as np
import pandas as pd
import seaborn as sns
import warnings

warnings.filterwarnings('ignore')


# ### 데이터셋 로드

# In[92]:


df = sns.load_dataset('titanic')
df.head()


# **컬럼(columns) 설명**
#
# - survivied: 생존여부 (1: 생존, 0: 사망)
# - pclass: 좌석 등급 (1등급, 2등급, 3등급)
# - sex: 성별
# - age: 나이
# - sibsp: 형제 + 배우자 수
# - parch: 부모 + 자녀 수
# - fare: 좌석 요금
# - embarked: 탑승 항구 (S, C, Q)
# - class: pclass와 동일
# - who: 남자(man), 여자(woman), 아이(child)
# - adult_male: 성인 남자 여부
# - deck: 데크 번호 (알파벳 + 숫자 혼용)
# - embark_town: 탑승 항구 이름
# - alive: 생존여부 (yes, no)
# - alone: 혼자 탑승 여부

# ### 통계 (statistics)
#
# **통계**는 데이터 분석에서 굉장히 **중요한 요소**입니다.
#
# 데이터에 대한 통계 계산식을 Pandas 함수로 제공하기 때문에 어렵지 않게 통곗값을 산출할 수 있습니다.

# ### describe() - 요약통계
#
# 전반적인 주요 통계를 확인할 수 있습니다.
#
# 기본 값으로 `수치형(Nemerical) 컬럼`에 대한 통계표를 보여줍니다.

# - **count** : 데이터 개수
# - **mean** : 평균
# - **std** : 표준편차(standard deviation)
# - **min** : 최솟값
# - **max** : 최댓값

# In[93]:


df.describe()


# **문자열 컬럼에 대한 통계표**도 확인할 수 있습니다.
#
# - **unique** : 고유 데이터의 값 개수
# - **top** : 가장 많이 출현한 데이터의 개수
# - **freq** : 가장 많이 출현한 데이터의 빈도 수

# In[94]:


df.describe(include='object')


# ### count() - 개수
#
# 데이터의 개수
#
# DataFrame 전체의 개수를 구하는 경우

# In[95]:


df.count()


# 단일 column의 데이터 개수를 구하는 경우

# In[96]:


df['age'].count()


# ### mean() - 평균
#
# 데이터의 **평균**
#
# DataFrame 평균

# In[97]:


# numeric_only=True 조건을 달아줘야 함
df.mean(numeric_only=True)


# `age` 컬럼에 대한 평균

# In[98]:


df['age'].mean()


# #### Mean - 조건별 평균
#
# 성인 남성의 나이의 평균 구하기

# In[99]:


cond = (df['adult_male'] == True)
df.loc[cond, 'age'].mean()


# #### 연습문제
# 다음 조건을 만족하는 승객의 **나이 평균**과 조건을 만족하는 **데이터의 개수**를 구하세요.
#
# - `fare`를 30 이상 40 미만 지불한 승객
# - `pclass`는 1등급

# In[100]:


cond1 = (df['fare'] >= 30) & (df['fare'] < 40)
cond2 = (df['pclass'] == 1)
cond = cond1 & cond2
print(df.loc[cond])
df.loc[cond, 'age']


# `age` 컬럼의 데이터 개수 구하기

# In[101]:


df.loc[cond, 'age'].count()


# **[출력 결과]**
# <pre>
# 21</pre>

# `age` 컬럼의 평균 구하기

# In[102]:


df.loc[cond, 'age'].mean()


# `skipna=True` 옵션
#
# 기술 통계 함수에서는 `skipna=True`가 **기본으로 설정** 되어 있습니다.
#
# 만약, `skipna=False`로 설정하게 된다면, **Nan 값이 있는 column**은 **Nan 값으로 출력**됩니다.

# In[103]:


# skipna = False로 지정한 경우
df.mean(skipna=False, numeric_only=True)


# In[104]:


# skipna = True로 지정한 경우
df.mean(skipna=True, numeric_only=True)


# ### median() - 중앙값
#
# 데이터의 중앙값을 출력합니다. 데이터를 **오름차순 정렬하여 중앙에 위치한 값**입니다.
#
# 이상치가(outlier)가 존재하는 경우, `mean()`보다 `median()`을 대푯값으로 더 선호합니다.

# In[105]:


pd.Series([1, 2, 3, 4, 5]).median()


# In[106]:


pd.Series([4, 5, 1, 2, 3]).median()


# 짝수개의 데이터가 있는 경우에는 **가운데 2개 중앙 데이터의 평균 값을 출력** 합니다.

# In[107]:


pd.Series([1, 2, 3, 4, 5, 6]).median()


# 나이의 평균과 중앙값은 약간의 차이가 있음을 확인할 수 있습니다

# In[108]:


print(f'나이 평균 :{df['age'].mean():.5f}\n나이 중앙값 : {df['age'].median()}\n차이 : {
      df['age'].mean() - df['age'].median(): .5f}')


# ### sum() - 합계
#
# 데이터의 **합계**입니다. 문자열 column은 모든 데이터가 붙어서 출력될 수 있습니다.ㅠ

# In[109]:


# loc[row, column slicing]
df.loc[:, ['age', 'fare']].sum()


# 단일 column에 대한 **합계 출력**

# In[110]:


df['fare'].sum()


# ### cumsum() - 누적합, cumprod() - 누적곱
#
# 누적되는 합계를 구할 수 있습니다.

# In[111]:


df['age'].cumsum()


# 누적되는 곱도 구할 수 있으나, 일반적으로 **값이 너무 커지므로 잘 활용하지는 않습니다.**

# In[112]:


df['age'].cumprod()


# ### var() - 분산(variance)

# $\large 분산 = \Huge\frac{\sum_{i=1}^{n}(X_{i} - \bar{x})^{2}}{n-1}$
#
# $\large 평균 = \huge \bar{X}$

# In[113]:


# 평균
fare_mean = df['fare'].values.mean()
print(fare_mean)
# 분산
my_var = ((df['fare'].values - fare_mean)**2).sum() / (df['fare'].count() - 1)
print(my_var)


# In[114]:


df['fare'].var()


# ### std() - 표준편차
#
# 분산의 제곱근

# $\large 표준편차 =\huge\sqrt{분산} = \sqrt{\frac{\sum_{i=1}^{n}(X_{i} - \bar{x})^{2}}{n-1}}$

# In[115]:


np.sqrt(df['fare'].var())


# In[116]:


df['fare'].std()


# ### min() - 최솟값, max() - 최댓값

# In[117]:


# 최솟값
df['age'].min()


# In[118]:


df['age'].max()


# ### agg - aggregation : 통합 통계 적용 (복수의 통계 함수 적용)
#
# 단일 컬럼에 agg 적용

# In[119]:


df['age'].agg(['min', 'max', 'count', 'mean'])


# 복수의 컬럼에 agg 적용

# In[120]:


df[['age', 'fare']].agg(['min', 'max', 'count', 'mean'])


# ### 연습문제
#
# 다이아몬드 데이터를 활용하여 다음의 문제를 풀어주세요

# In[121]:


diamond = sns.load_dataset('diamonds')
diamond


# depth의 **최솟값**을 구하세요

# In[122]:


diamond['depth'].min()


# **[출력 결과]**
#
# 43.0

# `carat`에 대한 **평균과 분산**을 동시에 출력하세요

# In[123]:


# 코드를 입력해 주세요
diamond['carat'].agg(['mean', 'var'])


# <p><strong>[출력 결과]</strong></p>
# <pre>mean    0.797940
# var     0.224687
# Name: carat, dtype: float64</pre>

# x, y에 대한 **합계**와 **표준편차**를 출력하세요

# In[124]:


# 코드를 입력하세요
diamond[['x', 'y']].agg(['sum', 'std'])


# <p><strong>[출력 결과]</strong></p>
# <div>
# <style scoped>
#     .dataframe tbody tr th:only-of-type {
#         vertical-align: middle;
#     }
#
#     .dataframe tbody tr th {
#         vertical-align: top;
#     }
#
#     .dataframe thead th {
#         text-align: right;
#     }
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>x</th>
#       <th>y</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>sum</th>
#       <td>309138.620000</td>
#       <td>309320.330000</td>
#     </tr>
#     <tr>
#       <th>std</th>
#       <td>1.121761</td>
#       <td>1.142135</td>
#     </tr>
#   </tbody>
# </table>
# </div>

# #### quantile() - 분위
#
# **Quantile이란 주어진 데이터를 동등한 크기로 분할하는 지점**을 말합니다.
#
# 10%의 경우 0.1, 80%의 경우 0.8을 대입하여 갑을 구합니다.

# In[125]:


# 10% quantile
df['age'].quantile(0.1)


# In[126]:


# 10% quantile
df['age'].quantile(0.8)


# ### unique() - 고윳값, nunique() - 고윳값 개수
#
# 고윳값과 고윳값의 개수를 구하고자 할 때 사용합니다.
#
# **unique()**

# In[127]:


df['who'].unique()


# **nunique()** : 고윳값의 개수를 출력합니다.

# In[128]:


df['who'].nunique()


# ### mode() - 최빈값
#
# 최빈값은 **가장 많이 출현한 데이터**를 의미합니다.

# In[129]:


df['who'].mode()


# 카테고리형 데이터에도 적용 가능합니다.

# In[130]:


df['deck'].mode()


# #### 연습문제
# 펭귄 데이터를 활용하여 다음의 문제를 풀어주세요

# In[131]:


penguin = sns.load_dataset('penguins')
penguin


# `species` 컬럼의 **고윳값**을 출력해 주세요

# In[132]:


# 코드를 입력해 주세요
penguin['species'].unique()


# <p><strong>[출력 결과]</strong></p>
# <pre>array(['Adelie', 'Chinstrap', 'Gentoo'], dtype=object)</pre>

# `island` 컬럼의 **최빈값**을 출력해 주세요

# In[133]:


# 코드를 입력해 주세요
penguin['island'].mode()


# <p><strong>[출력 결과]</strong></p>
# <pre>0    Biscoe
# dtype: object</pre>

# `body_mass_g` 컬럼의 10% 분위수 값(하위 10%)을 출력해주세요

# In[134]:


# 코드를 입력해 주세요
penguin['body_mass_g'].quantile(0.1)


# <p><strong>[출력 결과]</strong></p>
# <pre>3300.0</pre>

# `body_mass_g` 컬럼의 80% 분위수 값(상위 20%)을 출력해주세요

# In[135]:


# 코드를 입력해 주세요
penguin['body_mass_g'].quantile(0.8)


# <p><strong>[출력 결과]</strong></p>
# <pre>4950.0</pre>

# ### corr() - 상관관계
#
# `corr()`로 컬럼별 **상관관계**를 확인할 수 있습니다.
#
# - **-1 ~ 1사이의 범위**를 가집니다.
# - **-1에 가까울 수록 반비례**관계, **1에 가까울수록 정비례 관계**를 의미합니다.

# In[136]:


df.corr(numeric_only=True)


# In[137]:


df.corr(numeric_only=True)['survived']


# ## 제출
#
# 제출을 위해 새로 로드된 타이타닉 데이터셋에서 `fare` 컬럼의 분산값을 `result`에 저장하세요.

# In[139]:


df = sns.load_dataset("titanic")
result = df['fare'].var()
result


# ## 채점 수행
#
# 아래 코드는 채점 수행을 위한 코드입니다.
#
# 따라서 이를 수정했을시 **채점이 제대로 이루어지지 않습니다.**
#
# **주의**: 채점 코드를 실행하기 전에 반드시 코드 파일을 한번 저장하시길 바랍니다.

# In[138]:


with open('result.json', 'w') as f:
    json.dump(result, f)

os.system('elice_grade result.json cds_ds_exercise.ipynb')
