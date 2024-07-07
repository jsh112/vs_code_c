#!/usr/bin/env python
# coding: utf-8

# In[14]:


from IPython.display import Image
img = Image(url="https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/Pandas_logo.svg/1280px-Pandas_logo.svg.png", width=250)
img


# # 공지사항
# - ### 셀이 선택되면 **M**은 `MarkDown`, **Y**는 `Python Code`

# # Pandas

# ## 개요

# **관계형** 또는 **레이블이 된** 데이터로 쉽고 직관적 으로 작업할 수 있도록 설계되었고, 빠르고, 유연한 데이터 구조를 제공하는 Python 패키지입니다.
# 
# 또한, 어떤 언어로도 사용할 수 있는 가장 **강력하고 유연한 오픈 소스 데이터 분석 / 조직 도구**입니다.
# 
# Pandas는 다음의 종류의 데이터에 **적합한 분석 패키지**입니다.
# 
# - SQL 테이블 또는 Excel 스프레드 시트에서와 같은 열과 행으로 이루어진 테이블 형식 데이터
# - 정렬되고 정렬되지 않은 시계열 데이터
# - 다른 형태의 관찰 / 통계 데이터 세트

# ## Pandas의 Alias 지정

# pandas는 `pd`의 alias를 사용합니다.

# In[15]:


import pandas


# In[16]:


pandas


# In[17]:


import pandas as pd


# In[18]:


pd


# In[19]:


pd.__version__


# ## Series

# Pandas의 Series는 1차원 배열로서 다음의 특징을 가집니다.
# 
# - 데이터를 담는 **차원 배열 구조**를 가집니다.
# - **인덱스(index)를 사용 가능**합니다.
# - **데이터 타입**을 가집니다. (dtype)

# ### Series의 생성

# numpy array 로 생성한 경우

# In[20]:


# numpy 생성
import numpy as np
arr = np.arange(100, 105)
arr


# In[21]:


s = pd.Series(arr)
s


# `dtype`을 지정하여 생성한 경우

# In[22]:


s = pd.Series(arr, dtype='int32')
s


# ##### list로 생성한 경우

# In[23]:


a = pd.Series(['부장', '차장', '대리', '사원', '인턴'])
# a == print(a)
print(a)


# ##### 다양한 타입(type)의 데이터를 섞은 경우

# Series에 다양한 데이터 타입의 데이터로 생성 시, **object** 타입으로 생성됩니다.

# In[24]:


a = pd.Series([91, 2.5, '스포츠', 4, 5.16])
a


# ### 연습문제

# 다음의 Series를 생성하세요
# - dtype은 `float32`가 되도록 생성하세요

# In[26]:


# 코드를 입력해주세요
a = pd.Series([3, 5, 7, 9, 11], dtype='float32')
a


# In[27]:


_list = [3,5,7,9,11]
pd.Series(_list, dtype='float32')


# <p><strong>[출력 결과]</strong></p>
# <pre>
# 0     3.0
# 1     5.0
# 2     7.0
# 3     9.0
# 4    11.0
# dtype: float32</pre>
# 

# In[28]:


# 코드를 입력해 주세요
pd.Series(['가', '나','다','라','마'])


# In[57]:


# list 로 만드는 방법
_list = list('가나다라마')
pd.Series(_list)


# <p><strong>[출력 결과]</strong></p>
# <pre>
# 0   가
# 1   나
# 2   다
# 3   라
# 4   마
# dtype: object</pre>

# ### 인덱싱 (indexing)

# In[41]:


s = pd.Series(['부장', '차장', '대리', '사원', '인턴'])
s


# Series 생성 시 0부터 순차적으로 부여되는 index를 확인할 수 있습니다.
# 
# 이를 `RangeIndex` 라고 부릅니다.

# In[42]:


s.index


# 인덱싱 사례

# In[43]:


s[0]


# ### Fancy Indexing

# In[44]:


idx = [1, 3]
s[idx]


# In[45]:


np.arange(1, 4, 2)


# In[46]:


idx = np.arange(1, 4, 2)
s[idx]


# ### boolean indexing

# 조건식을 만들어서 특정 조건에 대하여 `True`에 해당하는 값만 필터링 할 수 있습니다.

# In[47]:


np.random.seed(0)
s = pd.Series(np.random.randint(10000, 20000, size=(10,)))
s


# boolean series를 생성 후 index로 활용하여 필터합니다.

# In[48]:


s > 15000


# In[49]:


# 15000 이상인 데이터 필터
s[s > 15000]


# In[50]:


idx = (s > 15000) & (s < 18000)
s[idx]


# 기본 값으로 부여되는 `RangeIndex` 에 사용자 정의의 `index`를 **지정**할 수 있습니다

# In[51]:


s = pd.Series(['마케팅', '경영', '개발', '기획', '인사'], index=['a', 'b', 'c', 'd', 'e'])
s


# In[52]:


s.index


# 사용자 정의의 index 부여 시 **변경된 index**로 조회 가능합니다.

# In[53]:


s['c']


# In[54]:


s[['a', 'd']]


# 먼저, `Series`를 생성 후 index 속성 값에 새로운 index를 할당하여 인덱스를 지정할 수 있습니다.

# In[55]:


s = pd.Series(['마케팅', '경영', '개발', '기획', '인사'])
s.index


# In[56]:


list('abcde')


# In[58]:


s.index = list('abcde')
s


# ### 연습문제
# 
# 다음의 Series를 생성하고 `sample` 변수에 대입하고 출력하세요

# In[97]:


# 코드를 입력해 주세요
_list = list('가나다라마')
list_number = [10, 20, 30, 40, 50]
sample = pd.Series(list_number, index=_list)
print(sample)
print('\n')

# 다른 방법 s.index

sample = pd.Series(list_number)
sample.index = _list
print(sample)


# <p><strong>[출력 결과]</strong></p>
# <pre>
# 가  10
# 나  20
# 다  30
# 라  40
# 마  50
# dtype: int64</pre>

# `sample` 중 **'나' 와 '라'** 데이터를 조회하세요

# In[64]:


# 코드를 입력하세요
idx = ['나','라']
sample[idx]


# <p><strong>[출력 결과]</p></strong>
# <pre>
# 나  20
# 라  40
# dtype: int64</pre>

# In[65]:


np.random.seed(20)
sample2 = pd.Series(np.random.randint(100, 200, size=(15,)))
sample2


# `sample2` 중 160 이하인 데이터만 필터하세요

# In[66]:


# 코드를 입력해 주세요
sample2[sample2 <= 160]


# <p><strong>[출력 결과]</strong></p>
# <pre>2     115
# 4     128
# 6     109
# 7     120
# 9     122
# 11    134
# 13    140
# dtype: int64</pre>

# `sample2` 중 **130 이상 170 이하**인 데이터만 필터하세요

# In[67]:


# 코드를 입력해주세요
idx = (sample2 >= 130) & (sample2 <= 170)
sample2[idx]


# <p><strong>[출력 결과]</p></strong>
# <pre>
# 11  134
# 13  140
# dtype: int64</pre>

# ## 속성 (attribute)

# ### values

# `values` 는 Series 데이터 값(value)만 **numpy array** 형식으로 가져 옵니다.

# In[68]:


s


# In[69]:


s.values


# ### ndim - 차원

# `Series`는 1차원 자료구조이기 때문에 `ndim` 출력시 **1**이 출력됩니다.

# In[70]:


s.ndim


# ### shape

# shape은 데이터의 모양(shape)을 알아보기 위하여 사용하는데, `Series`의 shape은 **데이터의 개수**를 나타냅니다.
# 
# 
# **튜플(tuple)** 형식으로 출력됩니다.

# In[71]:


s.shape


# ### NaN (Not a Number)
# 
# Pandas에서 **NaN 값**은 비어있는 **결측치 데이터**를 의미합니다.
# 
# 임의로 비어있는 값을 대입하고자 할 때는 **numpy의 nan (np.nan)** 을 입력합니다.
# 

# In[73]:


s = pd.Series([
    '선화', '강호', np.nan, '소정', '우영'
])
print(s)


# ### 연습문제
# 
# 다음과 같은 `Series` 를 생성해 주세요

# In[95]:


# 코드를 입력해 주세요
_list = list('가나다라마')
a = pd.Series(['apple', np.nan, 'banana', 'kiwi', 'gubong'])
a.index = _list
a


# <p><strong>[출력 결과]</strong></p>
# <pre>가     apple
# 나       NaN
# 다    banana
# 라      kiwi
# 마    gubong
# dtype: object</pre>

# ### 결측치 (NaN) 값 처리
# 
# `isnull()` 과 `isna()`은 **NaN** 값을 찾는 함수입니다.
# 
# `isnull()` 과 `isna()`는 결과가 동일합니다

# In[76]:


s


# In[77]:


s.isnull()


# In[78]:


s.isna()


# In[79]:


s[s.isnull()]


# In[80]:


s[s.isna()]


# `notnull()`은 **NaN**값이 아닌, 즉 비어있지 않은 데이터를 찾는 함수입니다.

# In[81]:


s.notnull()


# In[82]:


s.notna()


# In[83]:


s[s.notnull()]


# ### 연습문제

# In[84]:


sample = pd.Series(['IT서비스', np.nan, '반도체', np.nan, '바이오', '자율주행'])
sample


# `sample` 중 결측치 데이터만 필터하세요

# In[88]:


# 코드를 입력하세요
sample[sample.isnull()]


# <p><strong>[출력 결과]</p></strong>
# <pre>
# 1   NaN
# 3   NaN
# dytpe: object

# `sample` 중 결측치가 아닌 데이터만 필터하세요

# In[89]:


# 코드를 입력해 주세요
sample[sample.notna()]


# <p><strong>[출력 결과]</strong></p>
# <pre>0    IT서비스
# 2      반도체
# 4      바이오
# 5     자율주행
# dtype: object</pre>

# ## 슬라이싱

# **(주의)** 숫자형 index로 접근할 때는 뒷 index가 포함되지 않습니다

# In[90]:


s = pd.Series(np.arange(100, 150, 10))
s


# In[91]:


s[1:3]


# In[92]:


s[1:]


# In[93]:


s[::2]


# 새롭게 지정한 인덱스(문자열)는 시작 index와 끝 index **모두 포함**합니다.

# In[94]:


s.index = list('가나다라마')
s


# In[98]:


s1 = pd.Series(np.arange(100, 250, 10))
s1


# In[99]:


s1[1::2]


# In[100]:


s1[::2]


# In[101]:


s1[1::3]


# In[102]:


s['나':'라']


# ### 연습문제

# In[107]:


np.random.seed(0)
sample = pd.Series(np.random.randint(100, 200, size=(10,)))
sample


# `sample`에서 다음과 같은 결과를 가지도록 **슬라이싱** 하세요

# In[108]:


# 코드를 입력해 주세요
sample[2:7]


# <p><strong>[출력 결과]</p></strong>
# <pre>
# 2   164
# 3   167
# 4   167
# 5   109
# 6   183
# dtype: int64</pre>

# In[109]:


np.random.seed(0)
sample2 = pd.Series(np.random.randint(100, 200, size=(10,)), index=list('가나다라마바사아자차'))
sample2


# `sample2`에서 다음과 같은 결과를 가지도록 **슬라이싱**하세요

# In[114]:


# 코드를 입력해 주세요
sample2['바':'차']


# <p><strong>[출력 결과]</strong></p>
# <pre>바    109
# 사    183
# 아    121
# 자    136
# 차    187
# dtype: int64</pre>

# In[113]:


# 코드를 입력해 주세요
sample2['가':'다']


# <p><strong>[출력 결과]</strong></p>
# <pre>가    144
# 나    147
# 다    164
# dtype: int64</pre>

# In[115]:


# 코드를 입력해 주세요
sample2['나':'바']


# <p><strong>[출력 결과]</strong></p>
# <pre>나    147
# 다    164
# 라    167
# 마    167
# 바    109
# dtype: int64</pre>

# ### DataFrame

# [도큐먼트](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.html)

# `pd.DataFrame`
# 
# - 2차원 데이터 구조 (Excel 데이터 시트를 생각하시면 됩니다)
# - 행(row), 열(column)으로 구성되어 있습니다.
# - 각 열(column)은 각각의 데이터 타입 (dtype)을 가집니다.

# ### 생성

# **list 를 통한 생성**할 수 있습니다. DataFrame을 만들 때는 **2차원 list를 대입**합니다.

# In[116]:


pd.DataFrame([[1, 2, 3], 
              [4, 5, 6], 
              [7, 8, 9]])


# 아래 예제와 같이 **columns를 지정**하면, DataFrame의 각 열에 대한 컬럼명이 붙습니다.

# In[117]:


pd.DataFrame([[1, 2, 3], 
              [4, 5, 6], 
              [7, 8, 9]], columns=['가', '나', '다'])


# **dictionary를 통한 생성**도 가능합니다.
# 
# 편리한 점은 dictionary의 **key 값이 자동으로 column 명으로 지정**됩니다.

# In[118]:


data = {
    'name': ['Kim', 'Lee', 'Park'], 
    'age': [24, 27, 34], 
    'children': [2, 1, 3]
}


# In[122]:


pd.DataFrame(data, index = [1,2,3])


# ### 속성

# DataFrame은 다음의 **속성**을 가집니다.
# 
# - **index**: index (기본 값으로 RangeIndex)
# - **columns**: column 명
# - **values**: numpy array형식의 데이터 값
# - **dtypes**: column 별 데이터 타입
# - **T**: DataFrame을 전치(Transpose)

# In[126]:


data = {
    'name': ['Kim', 'Lee', 'Park'], 
    'age': [24, 27, 34], 
    'children': [2, 1, 3]
}

df = pd.DataFrame(data)
df


# In[127]:


df.index


# In[128]:


df.columns


# In[129]:


df.values


# 데이터프레임에서의 `dtypes` 속성은 칼럼별 `dtype`을 출력합니다

# In[130]:


df.dtypes


# `df.T`는 `DataFrame`을 **Transpose** 시켜줍니다.

# In[132]:


df.index=[1,2,3]
df.T


# ### index 지정

# In[133]:


df


# In[134]:


df.index = list('abc')
df


# (참고) DataFrame의 indexing / slcing은 나중에 세부적으로 다루도록 하겠습니다.

# ### column 다루기

# DataFrame에 key 값으로 column의 이름을 지정하여 column을 선택할 수 있습니다.
# 
# 1개의 column을 가져올 수 있으며, **1개의 cloumn 선택시 Series**가 됩니다.

# In[135]:


df['name']


# In[136]:


type(df['name'])


# 2개 이상의 column 선택은 **fancy indexing으로 가능**합니다.

# In[137]:


df[['name', 'children']]


# (참고) column에 대한 slicing도 가능하지만 이 부분도 나중에 다루도록 하겠습니다.
# 
# **rename**으로 column명 변경 가능합니다.
# 
# DataFrame.rename(columns={**'바꾸고자 하는 column명'** : **'바꿀 컬럼명'**})

# In[138]:


df.rename(columns={'name': '이름'})


# In[140]:


df.rename(columns={'age': '나이'})


# `inplace=True` 옵션으로 변경사항을 바로 적용할 수 있습니다.

# In[141]:


df.rename(columns={'name': '이름'}, inplace=True)
df


# ### 연습문제
# 
# 다음의 DataFrame을 생성하세요
# 
# - 생성된 DataFrame은 df 변수에 할당합니다.

# In[145]:


# 코드를 입력해 주세요
df = pd.DataFrame({
    'food' : ['KFC', 'McDonald','SchoolFood'],
    'price' : [1000, 2000, 2500],
    'rating' : [4.5, 3.9, 4.2]
})
df


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
#       <th>food</th>
#       <th>price</th>
#       <th>rating</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>0</th>
#       <td>KFC</td>
#       <td>1000</td>
#       <td>4.5</td>
#     </tr>
#     <tr>
#       <th>1</th>
#       <td>McDonald</td>
#       <td>2000</td>
#       <td>3.9</td>
#     </tr>
#     <tr>
#       <th>2</th>
#       <td>SchoolFood</td>
#       <td>2500</td>
#       <td>4.2</td>
#     </tr>
#   </tbody>
# </table>
# </div>

# food column과 rating column만 선택하여 출력하세요

# In[147]:


# 코드를 입력해 주세요
df[['food', 'rating']]


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
#       <th>food</th>
#       <th>rating</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>0</th>
#       <td>KFC</td>
#       <td>4.5</td>
#     </tr>
#     <tr>
#       <th>1</th>
#       <td>McDonald</td>
#       <td>3.9</td>
#     </tr>
#     <tr>
#       <th>2</th>
#       <td>SchoolFood</td>
#       <td>4.2</td>
#     </tr>
#   </tbody>
# </table>
# </div>

# In[148]:


type(df[['food', 'rating']])


# food column명을 place로 변경해 주세요

# In[150]:


# 코드를 입력해 주세요
df.rename(columns={'food': 'place'}, inplace=True)


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
#       <th>place</th>
#       <th>price</th>
#       <th>rating</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>0</th>
#       <td>KFC</td>
#       <td>1000</td>
#       <td>4.5</td>
#     </tr>
#     <tr>
#       <th>1</th>
#       <td>McDonald</td>
#       <td>2000</td>
#       <td>3.9</td>
#     </tr>
#     <tr>
#       <th>2</th>
#       <td>SchoolFood</td>
#       <td>2500</td>
#       <td>4.2</td>
#     </tr>
#   </tbody>
# </table>
# </div>

# ## 제출
# 
# 제출을 위해 아래와 같은 DataFrame을 생성하여 `result_df`에 저장하세요.
# 
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
#       <th>name</th>
#       <th>age</th>
#       <th>children</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>0</th>
#       <td>Kim</td>
#       <td>24</td>
#       <td>2</td>
#     </tr>
#     <tr>
#       <th>1</th>
#       <td>Lee</td>
#       <td>27</td>
#       <td>1</td>
#     </tr>
#     <tr>
#       <th>2</th>
#       <td>Park</td>
#       <td>34</td>
#       <td>3</td>
#     </tr>
#   </tbody>
# </table>
# </div>

# In[151]:


result_df = pd.DataFrame({
    'name' : ['Kim', 'Lee', 'Park'],
    'age' : [24, 27, 34],
    'children' : [2, 1, 3]
})
result_df


# ## 채점 수행
# 
# 아래 코드는 채점 수행을 위한 코드입니다.
# 
# 따라서 이를 수정했을시 **채점이 제대로 이루어지지 않습니다.**
# 
# **주의**: 채점 코드를 실행하기 전에 반드시 코드 파일을 한번 저장하시길 바랍니다.

# In[152]:


import os

result_df.to_json('result.json')

os.system('elice_grade result.json cds_ds_exercise.ipynb')

