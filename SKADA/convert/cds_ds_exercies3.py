#!/usr/bin/env python
# coding: utf-8

# ### moduel impot
# 

# In[3]:


from IPython.display import Image
import numpy as np
import pandas as pd
import seaborn as sns


# #### 실습에 활용할 데이터셋
# 
# #### 타이타닉 : 탑승객의 사망자 생존자 데이터 분석
# 

# In[4]:


df = sns.load_dataset("titanic")
df.head()


# #### 컬럼(column) 설명
# 

# - survived : 생존여부(1 : 생존, 0 : 사망)
# - plcass : 좌석등급 (1등급, 2등급, 3등급)
# - sex : 성별
# - age : 나이(float)
# - sibsp : 형제 + 배우자 수
# - parch : 부모 + 자녀 수
# - fare : 좌석 요금
# - embarked : 탑승 항구 (S, C, Q)
# - class : pclass와 동일
# - who : 남자(man), 여자(woman), 아이(child)\
# - deck : 데크 번호 (알파벳 + 숫자 혼용)
# - embark_town : 탑승 항구 이름
# - alive : 생존여부 (yes, no)
# - alone : 혼자 탑승 여부
# 

# #### 데이터 분석!
# 
# ##### 주요 목표
# 
# - Pandas를 활용하여 타이타닉호 생존자, 사망자 **데이터를 분석**합니다.
# 
# - 데이터를 토대로 생존율이 높은 승객, 생존율이 낮은 승객은 누구인지 판단합니다.
# 

# ### head() 앞 부분 / tail() 뒷 부분 조회
# 
# - default 옵션으로 **5개의 row가 조회**됩니다.
# 
# - 괄호 안에 숫자를 넣어 명시적으로 조회하고 싶은 행의 개수를 지정할 수 있습니다.
# 

# In[5]:


df.head()


# In[6]:


df.tail()


# In[7]:


df.head(3)


# In[9]:


df.tail(7)


# ### info()
# 

# - column별 정보(information)을 보여줍니다.
# - 데이터의 개수, 그리고 데이터 type을 확인 할 때 사용합니다.
# 

# In[10]:


df.info()


# **object**타입은 쉽게 문자열이라고 생각하면 됩니다.
# 
# 그런데, **category** 타입도 있습니다. category 타입은 문자열이지만, '남자'/'여자' 처럼 카테고리화 할 수 잇는 칼럼을 의미합니다. 나중에 별도로 다루겠습니다.
# 

# ### value_counts()
# 

# column 별 **값의 분포를 확인**할 때 사용합니다.
# 
# **남자, 여자, 아이의 데이터 분호를 확인**하고 싶다면 다음과 같이 실행합니다.
# 

# In[11]:


df['who'].value_counts()


# #### 연습문제
# 

# In[ ]:


df.head()


# `embark_town`은 승객의 탑승 항구를 나타내는 column입니다. 탑승 항구별 승객 데이터 분포를 확인해 주세요.
# 

# In[12]:


# 코드를 입력해 주세요
df['embark_town'].value_counts()


# <p><strong>[출력 결과]</strong></p>
# <pre>Southampton    644
# Cherbourg      168
# Queenstown      77
# Name: embark_town, dtype: int64</pre>
# 

# `who` column에 대한 데이터 분포를 확인해 주세요.
# 

# In[14]:


# 코드를 입력해 주세요
df['who'].value_counts()


# <p><strong>[출력 결과]</strong></p>
# <pre>man      537
# woman    271
# child     83
# Name: who, dtype: int64</pre>
# 

# ## 속성: Attributes
# 
# 속성 값은 **함수형으로 조회하지 않습니다.**
# 
# 자주 활용하는 DataFrame은 **속성 값**들은 다음과 같습니다.
# 
# - ndim
# - shape
# - index
# - columns
# - values
# - T
# 

# **차원**을 나타냅니다. DataFrame은 2가 출력됩니다.
# 

# In[16]:


df.ndim


# **(행, 열)** 순서로 출력됩니다.
# 

# In[15]:


df.shape


# index는 기본 설정된 **RangeIndex**가 **출력**됩니다.
# 

# In[17]:


df.index


# columns는 **열**을 출력 합니다.
# 

# In[18]:


df.columns


# values는 모든 값을 출력하며, **numpy array 형식으로 출력**됩니다.
# 

# In[19]:


df.values


# **T : 전치(Transpose)** 는 index와 Column의 축을 교환합니다.
# 

# In[20]:


df.T


# ### 타입 변환 (astype)
# 

# In[21]:


df.info()


# `int32`로 변경
# 

# In[22]:


df['pclass'].astype('int32').head()


# `float32`로 변경
# 

# In[23]:


df['pclass'].astype('float32').head()


# `object`로 변경
# 

# In[24]:


df['pclass'].astype('object').head()


# `category`로 변경.
# 
# `category`로 변경 시에는 Categories가 같이 출력 됩니다.
# 

# In[25]:


df['pclass'].astype('category').head()


# ### 정렬 (sort)
# 

# #### sort_index : index 정렬
# 
# - index 기준으로 정렬합니다. (기본 오름차순이 적용되어 있습니다.)-
# - 내림차순 정렬을 적용하려면, `ascending=False`를 옵션 값으로 설정합니다.
# 

# In[26]:


df.sort_index().head()


# In[27]:


df.sort_index(ascending=False).head()


# #### sort_values : 값에 대한 정렬
# 
# - 값을 기준으로 행을 정렬합니다.
# - by에 기준이 되는 행을 설정합니다.
# - by에 2개 이상의 컬럼을 지정하여 정렬할 수 있습니다.
# - 오름차순/내림차순을 컬럼 별로 지정할 수 있습니다.
# 

# In[28]:


df.sort_values(by='age').head()


# 내림차순 정렬 : `ascending=False`
# 

# In[29]:


df.sort_values(by='age', ascending=False).head()


# **문자열 컬럼도 오름차순/내림차순 정렬이 가능**하며 알파벳 순서로 정렬됩니다.
# 

# In[30]:


df.sort_values(by='class', ascending=False).head()


# **2개 이상의 컬럼**을 기준으로 값 정렬 할 수 있습니다.
# 

# In[31]:


df.sort_values(['fare', 'age']).head()


# In[32]:


df.sort_values(by=['fare', 'age']).head()


# 오름차순/내림차순 정렬도 컬럼 **각각에 지정**해 줄 수 있습니다.
# 

# In[33]:


df.sort_values(['fare', 'age'], ascending=[False, True]).head()


# In[34]:


df.sort_values(['age', 'fare'], ascending=[False, True]).head()


# #### df.sort_values(['column1', 'column2', ...], asending = (bool_lists)) 일 때
# 
# #### 항상 column1부터 bool_list의 값대로 정렬한 후 그 다음 column2를 진행하는 방식이다
# 

# In[35]:


bool_list = [False, True]
column_list = ['age', 'fare']
df.sort_values(by=column_list, ascending=bool_list).head()


# ### 연습문제
# 

# `tips` 데이터는 미국 레스토랑의 매출과 웨이터에게 지불한 팁을 나타내는 데이터입니다.
# 

# In[36]:


tips = sns.load_dataset("tips")
tips.head()


# - `total_bill`과 `tip`에 대한 내림차순 정렬을 해주세요
# - 상위 10개만 출력하세요
# 

# In[40]:


# 코드를 입력해 주세요
column_list = ['total_bill', 'tip']
bool_list = [False, False]
tips.sort_values(by=column_list, ascending=bool_list).head(10)


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
# 
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>total_bill</th>
#       <th>tip</th>
#       <th>sex</th>
#       <th>smoker</th>
#       <th>day</th>
#       <th>time</th>
#       <th>size</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>170</th>
#       <td>50.81</td>
#       <td>10.00</td>
#       <td>Male</td>
#       <td>Yes</td>
#       <td>Sat</td>
#       <td>Dinner</td>
#       <td>3</td>
#     </tr>
#     <tr>
#       <th>212</th>
#       <td>48.33</td>
#       <td>9.00</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Sat</td>
#       <td>Dinner</td>
#       <td>4</td>
#     </tr>
#     <tr>
#       <th>59</th>
#       <td>48.27</td>
#       <td>6.73</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Sat</td>
#       <td>Dinner</td>
#       <td>4</td>
#     </tr>
#     <tr>
#       <th>156</th>
#       <td>48.17</td>
#       <td>5.00</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>6</td>
#     </tr>
#     <tr>
#       <th>182</th>
#       <td>45.35</td>
#       <td>3.50</td>
#       <td>Male</td>
#       <td>Yes</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>3</td>
#     </tr>
#     <tr>
#       <th>102</th>
#       <td>44.30</td>
#       <td>2.50</td>
#       <td>Female</td>
#       <td>Yes</td>
#       <td>Sat</td>
#       <td>Dinner</td>
#       <td>3</td>
#     </tr>
#     <tr>
#       <th>197</th>
#       <td>43.11</td>
#       <td>5.00</td>
#       <td>Female</td>
#       <td>Yes</td>
#       <td>Thur</td>
#       <td>Lunch</td>
#       <td>4</td>
#     </tr>
#     <tr>
#       <th>142</th>
#       <td>41.19</td>
#       <td>5.00</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Thur</td>
#       <td>Lunch</td>
#       <td>5</td>
#     </tr>
#     <tr>
#       <th>184</th>
#       <td>40.55</td>
#       <td>3.00</td>
#       <td>Male</td>
#       <td>Yes</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>2</td>
#     </tr>
#     <tr>
#       <th>95</th>
#       <td>40.17</td>
#       <td>4.73</td>
#       <td>Male</td>
#       <td>Yes</td>
#       <td>Fri</td>
#       <td>Dinner</td>
#       <td>4</td>
#     </tr>
#   </tbody>
# </table>
# </div>
# 

# - `size`를 기준으로 내림차순, `tip`을 기준으로는 오름차순 정렬을 해주세요
# - 상위 10개의 데이터를 출력하세요
# 

# In[42]:


# 코드를 입력해 주세요
column_list = ['size', 'tip']
bool_list = [False, True]
tips.sort_values(by=column_list, ascending=bool_list).head(10)


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
# 
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>total_bill</th>
#       <th>tip</th>
#       <th>sex</th>
#       <th>smoker</th>
#       <th>day</th>
#       <th>time</th>
#       <th>size</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>125</th>
#       <td>29.80</td>
#       <td>4.20</td>
#       <td>Female</td>
#       <td>No</td>
#       <td>Thur</td>
#       <td>Lunch</td>
#       <td>6</td>
#     </tr>
#     <tr>
#       <th>143</th>
#       <td>27.05</td>
#       <td>5.00</td>
#       <td>Female</td>
#       <td>No</td>
#       <td>Thur</td>
#       <td>Lunch</td>
#       <td>6</td>
#     </tr>
#     <tr>
#       <th>156</th>
#       <td>48.17</td>
#       <td>5.00</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>6</td>
#     </tr>
#     <tr>
#       <th>141</th>
#       <td>34.30</td>
#       <td>6.70</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Thur</td>
#       <td>Lunch</td>
#       <td>6</td>
#     </tr>
#     <tr>
#       <th>187</th>
#       <td>30.46</td>
#       <td>2.00</td>
#       <td>Male</td>
#       <td>Yes</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>5</td>
#     </tr>
#     <tr>
#       <th>216</th>
#       <td>28.15</td>
#       <td>3.00</td>
#       <td>Male</td>
#       <td>Yes</td>
#       <td>Sat</td>
#       <td>Dinner</td>
#       <td>5</td>
#     </tr>
#     <tr>
#       <th>142</th>
#       <td>41.19</td>
#       <td>5.00</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Thur</td>
#       <td>Lunch</td>
#       <td>5</td>
#     </tr>
#     <tr>
#       <th>185</th>
#       <td>20.69</td>
#       <td>5.00</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>5</td>
#     </tr>
#     <tr>
#       <th>155</th>
#       <td>29.85</td>
#       <td>5.14</td>
#       <td>Female</td>
#       <td>No</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>5</td>
#     </tr>
#     <tr>
#       <th>153</th>
#       <td>24.55</td>
#       <td>2.00</td>
#       <td>Male</td>
#       <td>No</td>
#       <td>Sun</td>
#       <td>Dinner</td>
#       <td>4</td>
#     </tr>
#   </tbody>
# </table>
# </div>
# 

# ### Indexing, Slicing, 조건 필터링
# 

# In[43]:


df.head()


# #### loc - indexing / slicing
# 
# - Indexing과 slicing을 할 수 있습니다.
# - slicing은 **[시작(포함): 끝(포함)]** 규칙에 유의합니다. 둘 다 포함합니다
# 

# **indexing 예시**
# 

# In[44]:


df.loc[5, 'class']


# **fancy indexing 예시**
# 

# In[46]:


df.loc[2:5, ['age', 'fare', 'who']]


# **slcing 예시**
# 

# In[48]:


df.loc[2:5, 'class':'deck'].head()


# In[51]:


df.loc[2:5, 'class':'deck']


# In[50]:


df.loc[:6, 'class':'deck']


# #### 연습문제
# 

# In[52]:


df


# 다음과 같은 결과를 가지도록 인덱싱 혹은 슬라이싱 하세요
# 

# In[57]:


# 코드를 입력해 주세요
df.loc[3:7, :'alone']


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
# 
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>survived</th>
#       <th>pclass</th>
#       <th>sex</th>
#       <th>age</th>
#       <th>sibsp</th>
#       <th>parch</th>
#       <th>fare</th>
#       <th>embarked</th>
#       <th>class</th>
#       <th>who</th>
#       <th>adult_male</th>
#       <th>deck</th>
#       <th>embark_town</th>
#       <th>alive</th>
#       <th>alone</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>3</th>
#       <td>1</td>
#       <td>1</td>
#       <td>female</td>
#       <td>35.0</td>
#       <td>1</td>
#       <td>0</td>
#       <td>53.1000</td>
#       <td>S</td>
#       <td>First</td>
#       <td>woman</td>
#       <td>False</td>
#       <td>C</td>
#       <td>Southampton</td>
#       <td>yes</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>4</th>
#       <td>0</td>
#       <td>3</td>
#       <td>male</td>
#       <td>35.0</td>
#       <td>0</td>
#       <td>0</td>
#       <td>8.0500</td>
#       <td>S</td>
#       <td>Third</td>
#       <td>man</td>
#       <td>True</td>
#       <td>NaN</td>
#       <td>Southampton</td>
#       <td>no</td>
#       <td>True</td>
#     </tr>
#     <tr>
#       <th>5</th>
#       <td>0</td>
#       <td>3</td>
#       <td>male</td>
#       <td>NaN</td>
#       <td>0</td>
#       <td>0</td>
#       <td>8.4583</td>
#       <td>Q</td>
#       <td>Third</td>
#       <td>man</td>
#       <td>True</td>
#       <td>NaN</td>
#       <td>Queenstown</td>
#       <td>no</td>
#       <td>True</td>
#     </tr>
#     <tr>
#       <th>6</th>
#       <td>0</td>
#       <td>1</td>
#       <td>male</td>
#       <td>54.0</td>
#       <td>0</td>
#       <td>0</td>
#       <td>51.8625</td>
#       <td>S</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>E</td>
#       <td>Southampton</td>
#       <td>no</td>
#       <td>True</td>
#     </tr>
#     <tr>
#       <th>7</th>
#       <td>0</td>
#       <td>3</td>
#       <td>male</td>
#       <td>2.0</td>
#       <td>3</td>
#       <td>1</td>
#       <td>21.0750</td>
#       <td>S</td>
#       <td>Third</td>
#       <td>child</td>
#       <td>False</td>
#       <td>NaN</td>
#       <td>Southampton</td>
#       <td>no</td>
#       <td>False</td>
#     </tr>
#   </tbody>
# </table>
# </div>
# 

# In[58]:


# 코드를 입력해 주세요
df.loc[:4, 'pclass':'fare']


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
# 
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>pclass</th>
#       <th>sex</th>
#       <th>age</th>
#       <th>sibsp</th>
#       <th>parch</th>
#       <th>fare</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>0</th>
#       <td>3</td>
#       <td>male</td>
#       <td>22.0</td>
#       <td>1</td>
#       <td>0</td>
#       <td>7.2500</td>
#     </tr>
#     <tr>
#       <th>1</th>
#       <td>1</td>
#       <td>female</td>
#       <td>38.0</td>
#       <td>1</td>
#       <td>0</td>
#       <td>71.2833</td>
#     </tr>
#     <tr>
#       <th>2</th>
#       <td>3</td>
#       <td>female</td>
#       <td>26.0</td>
#       <td>0</td>
#       <td>0</td>
#       <td>7.9250</td>
#     </tr>
#     <tr>
#       <th>3</th>
#       <td>1</td>
#       <td>female</td>
#       <td>35.0</td>
#       <td>1</td>
#       <td>0</td>
#       <td>53.1000</td>
#     </tr>
#     <tr>
#       <th>4</th>
#       <td>3</td>
#       <td>male</td>
#       <td>35.0</td>
#       <td>0</td>
#       <td>0</td>
#       <td>8.0500</td>
#     </tr>
#   </tbody>
# </table>
# </div>
# 

# In[60]:


# 코드를 입력해주세요
df.loc[2:10:2, ['age', 'who']]


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
# 
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>age</th>
#       <th>who</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>2</th>
#       <td>26.0</td>
#       <td>woman</td>
#     </tr>
#     <tr>
#       <th>4</th>
#       <td>35.0</td>
#       <td>man</td>
#     </tr>
#     <tr>
#       <th>6</th>
#       <td>54.0</td>
#       <td>man</td>
#     </tr>
#     <tr>
#       <th>8</th>
#       <td>27.0</td>
#       <td>woman</td>
#     </tr>
#     <tr>
#       <th>10</th>
#       <td>4.0</td>
#       <td>child</td>
#     </tr>
#   </tbody>
# </table>
# </div>
# 

# #### loc - 조건 필터
# 

# boolean index를 만들어 조건에 맞는 데이터만 추출해 낼 수 있습니다.
# 

# In[61]:


cond = (df['age'] >= 70)
cond


# In[62]:


df.loc[cond]


# In[65]:


df.loc[cond]


# In[70]:


df.loc[cond].sort_values('age', ascending=False)


# #### loc - 다중 조건
# 
# 다중 조건은 먼저 condition을 정의하고 & 와 | 연산자로 **복합 조건을 생성**합니다.
# 

# In[72]:


# 조건 1 정의
cond1 = (df['fare'] > 30)

# 조건 2 정의
cond2 = (df['who'] == 'woman')


# In[73]:


df.loc[cond1 & cond2]


# In[74]:


df.loc[cond1 | cond2]


# 조건 필터 후 데이터 대입
# 

# In[75]:


cond = (df['age'] >= 70)
cond


# In[76]:


# 조건 필터
df.loc[cond]


# 나이 칼럼만 가져옵니다.
# 

# In[77]:


df.loc[cond, 'age']


# 조건 필터 후 원하는 값을 대입할 수 있습니다. (단일 컬럼 선택에 유의)
# 

# In[78]:


df.loc[cond, 'age'] = -1


# In[79]:


df.loc[cond]


# #### 연습문제
# 

# 데이터를 다시 로드합니다
# 

# In[80]:


df = sns.load_dataset('titanic')
df.head()


# 다음 조건을 만족하는 코드를 입력하세요.
# 
# - 나이가 30살 이상 남자 승객 조건 필터링
# - `fare`를 많이 낸 순서로 내림차순 정렬
# - 상위 10개를 출력
# 

# In[87]:


# 코드를 입력해 주세요
cond_age = (df['age'] >= 30)
cond_sex = (df['sex'] == 'male')
df.loc[cond_age & cond_sex].sort_values(by='fare', ascending=False).head(10)


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
# 
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>survived</th>
#       <th>pclass</th>
#       <th>sex</th>
#       <th>age</th>
#       <th>sibsp</th>
#       <th>parch</th>
#       <th>fare</th>
#       <th>embarked</th>
#       <th>class</th>
#       <th>who</th>
#       <th>adult_male</th>
#       <th>deck</th>
#       <th>embark_town</th>
#       <th>alive</th>
#       <th>alone</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>679</th>
#       <td>1</td>
#       <td>1</td>
#       <td>male</td>
#       <td>36.0</td>
#       <td>0</td>
#       <td>1</td>
#       <td>512.3292</td>
#       <td>C</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>B</td>
#       <td>Cherbourg</td>
#       <td>yes</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>737</th>
#       <td>1</td>
#       <td>1</td>
#       <td>male</td>
#       <td>35.0</td>
#       <td>0</td>
#       <td>0</td>
#       <td>512.3292</td>
#       <td>C</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>B</td>
#       <td>Cherbourg</td>
#       <td>yes</td>
#       <td>True</td>
#     </tr>
#     <tr>
#       <th>438</th>
#       <td>0</td>
#       <td>1</td>
#       <td>male</td>
#       <td>64.0</td>
#       <td>1</td>
#       <td>4</td>
#       <td>263.0000</td>
#       <td>S</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>C</td>
#       <td>Southampton</td>
#       <td>no</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>332</th>
#       <td>0</td>
#       <td>1</td>
#       <td>male</td>
#       <td>38.0</td>
#       <td>0</td>
#       <td>1</td>
#       <td>153.4625</td>
#       <td>S</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>C</td>
#       <td>Southampton</td>
#       <td>no</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>660</th>
#       <td>1</td>
#       <td>1</td>
#       <td>male</td>
#       <td>50.0</td>
#       <td>2</td>
#       <td>0</td>
#       <td>133.6500</td>
#       <td>S</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>NaN</td>
#       <td>Southampton</td>
#       <td>yes</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>390</th>
#       <td>1</td>
#       <td>1</td>
#       <td>male</td>
#       <td>36.0</td>
#       <td>1</td>
#       <td>2</td>
#       <td>120.0000</td>
#       <td>S</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>B</td>
#       <td>Southampton</td>
#       <td>yes</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>659</th>
#       <td>0</td>
#       <td>1</td>
#       <td>male</td>
#       <td>58.0</td>
#       <td>0</td>
#       <td>2</td>
#       <td>113.2750</td>
#       <td>C</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>D</td>
#       <td>Cherbourg</td>
#       <td>no</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>698</th>
#       <td>0</td>
#       <td>1</td>
#       <td>male</td>
#       <td>49.0</td>
#       <td>1</td>
#       <td>1</td>
#       <td>110.8833</td>
#       <td>C</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>C</td>
#       <td>Cherbourg</td>
#       <td>no</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>544</th>
#       <td>0</td>
#       <td>1</td>
#       <td>male</td>
#       <td>50.0</td>
#       <td>1</td>
#       <td>0</td>
#       <td>106.4250</td>
#       <td>C</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>C</td>
#       <td>Cherbourg</td>
#       <td>no</td>
#       <td>False</td>
#     </tr>
#     <tr>
#       <th>224</th>
#       <td>1</td>
#       <td>1</td>
#       <td>male</td>
#       <td>38.0</td>
#       <td>1</td>
#       <td>0</td>
#       <td>90.0000</td>
#       <td>S</td>
#       <td>First</td>
#       <td>man</td>
#       <td>True</td>
#       <td>C</td>
#       <td>Southampton</td>
#       <td>yes</td>
#       <td>False</td>
#     </tr>
#   </tbody>
# </table>
# </div>
# 

# 다음 조건을 만족하는 코드를 입력하세요.
# 
# - 나이가 20살 이상 40살 미만인 승객
# - `pclass`가 1등급 혹은 2등급인 승객
# - 열(column)은 `survived`, `pclass`, `age`, `fare` 만 나오게 출력
# - 10개만 출력
# 

# In[88]:


df['pclass'].value_counts()


# In[91]:


cond1 = (df['age'] >= 20) & (df['age'] < 40)
cond2 = (df['pclass'] < 3)

df.loc[cond1 & cond2, ['survived', 'pclass', 'age', 'fare']].head(10)


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
# 
# </style>
# <table border="1" class="dataframe">
#   <thead>
#     <tr style="text-align: right;">
#       <th></th>
#       <th>survived</th>
#       <th>pclass</th>
#       <th>age</th>
#       <th>fare</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>1</th>
#       <td>1</td>
#       <td>1</td>
#       <td>38.0</td>
#       <td>71.2833</td>
#     </tr>
#     <tr>
#       <th>3</th>
#       <td>1</td>
#       <td>1</td>
#       <td>35.0</td>
#       <td>53.1000</td>
#     </tr>
#     <tr>
#       <th>20</th>
#       <td>0</td>
#       <td>2</td>
#       <td>35.0</td>
#       <td>26.0000</td>
#     </tr>
#     <tr>
#       <th>21</th>
#       <td>1</td>
#       <td>2</td>
#       <td>34.0</td>
#       <td>13.0000</td>
#     </tr>
#     <tr>
#       <th>23</th>
#       <td>1</td>
#       <td>1</td>
#       <td>28.0</td>
#       <td>35.5000</td>
#     </tr>
#     <tr>
#       <th>34</th>
#       <td>0</td>
#       <td>1</td>
#       <td>28.0</td>
#       <td>82.1708</td>
#     </tr>
#     <tr>
#       <th>41</th>
#       <td>0</td>
#       <td>2</td>
#       <td>27.0</td>
#       <td>21.0000</td>
#     </tr>
#     <tr>
#       <th>53</th>
#       <td>1</td>
#       <td>2</td>
#       <td>29.0</td>
#       <td>26.0000</td>
#     </tr>
#     <tr>
#       <th>56</th>
#       <td>1</td>
#       <td>2</td>
#       <td>21.0</td>
#       <td>10.5000</td>
#     </tr>
#     <tr>
#       <th>61</th>
#       <td>1</td>
#       <td>1</td>
#       <td>38.0</td>
#       <td>80.0000</td>
#     </tr>
#   </tbody>
# </table>
# </div>
# 

# ### iloc
# 
# - `loc`와 유서하지만, index만 허용합니다.
# - loc와 마찬가지고, indexing / slicing 모두 가능합니다.
# 

# In[92]:


df.head()


# **indexing**
# 

# In[93]:


df.iloc[1, 3]


# **Fancy Indexing**
# 

# In[94]:


df.iloc[[0, 3, 4], [0, 1, 5, 6]]


# **Slicing**

# In[95]:


df.iloc[:3, :5]


# **isin**
# 
# 특정 값의 포함 여부는 isin function을 통해 비교가 가능합니다. (파이썬의 in 키워드는 사용 불가합니다.)

# In[96]:


sample = pd.DataFrame({
    'name' : ['Kim', 'Lee', 'park', 'choi'],
    'age': [24, 27, 34, 19]
})
sample


# In[99]:


sample['name'].isin(['Kim', 'Lee'])


# In[100]:


sample.isin(['Kim', 'Lee'])


# `loc`를 활용한 **조건 필터링**으로도 찰떡궁합입니다.

# In[101]:


condition = sample['name'].isin(['Kim', 'Lee'])


# In[102]:


sample.loc[condition]


# ### 연습문제

# In[103]:


tipes = sns.load_dataset('tips')
tips.head()


# - `tips` 데이터셋 중 `day`가 **금요일, 토요일**만 필터링 합니다.
# - `tip`이 $10보다 적게 낸 데이터만 필터링 합니다.
# - 칼럼은 `total_bill`, `tip`, `smoker`, `time`만 출력합니다.
# - 상위 10개 행만 출력합니다

# In[110]:


tips['day'].value_counts()


# In[116]:


cond1 = tips['day'].isin(['Fri', 'Sat'])
cond2 = (tips['tip'] < 10)
tips.loc[cond1 & cond2, ['total_bill', 'tip', 'smoker', 'time']].head(10)


# In[113]:


# 코드를 입력해 주세요
cond_day = (tips['day'] == 'Fri') | (tips['day'] == 'Sat')
cond_tip = (tips['tip'] < 10)
tips.loc[cond_day & cond_tip, ['total_bill', 'tip', 'smoker', 'time']].head(10)


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
#       <th>total_bill</th>
#       <th>tip</th>
#       <th>smoker</th>
#       <th>time</th>
#     </tr>
#   </thead>
#   <tbody>
#     <tr>
#       <th>19</th>
#       <td>20.65</td>
#       <td>3.35</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>20</th>
#       <td>17.92</td>
#       <td>4.08</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>21</th>
#       <td>20.29</td>
#       <td>2.75</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>22</th>
#       <td>15.77</td>
#       <td>2.23</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>23</th>
#       <td>39.42</td>
#       <td>7.58</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>24</th>
#       <td>19.82</td>
#       <td>3.18</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>25</th>
#       <td>17.81</td>
#       <td>2.34</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>26</th>
#       <td>13.37</td>
#       <td>2.00</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>27</th>
#       <td>12.69</td>
#       <td>2.00</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#     <tr>
#       <th>28</th>
#       <td>21.70</td>
#       <td>4.30</td>
#       <td>No</td>
#       <td>Dinner</td>
#     </tr>
#   </tbody>
# </table>
# </div>

# ### 제출
# 
# 제출을 위해 새로 로드된 타이타닉 데이터셋에서 아래 조건을 만족하는 결과를 `result_df`에 저장하세요.
# 
# - 나이가 30살 이상 남자 승객 조건 필터링
# - `fare`를 많이 낸 순서로 내림차순 정렬, 상위 10개

# In[124]:


df = sns.load_dataset('titanic')
df.head()


# In[121]:


df.info()


# In[122]:


cond1 = (df['age'] >= 30) & (df['sex'] == 'male')
df.loc[cond1].sort_values('fare', ascending=False).head(10)


# In[ ]:




