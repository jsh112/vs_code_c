#!/usr/bin/env python
# coding: utf-8

# ## Data Structure

# ### print (기본 입출력)
# 
# - print(value, sep='', end='\n', ...)
# 
#     - value를 출력
#     - sep : 출력되는 value들 사이 분리 기호
#     - end : 출력 문자열 마지막 문자
#         - 기본값('\n')

# In[145]:


print('오늘 파이썬 배우기 좋은 날이네!')
print('오늘은', '일요일', end='+')
print('\n오늘은', '일요일')


# ### 변수
# 
# - 변수란 자료형의 값을 저장하는 공간
# - 변수명 = 변수에 저장할 값
# - 변수의 타입 확인 : type()

# In[146]:


import pandas as pd
import numpy as np

data = {
    '분류' : ['숫자', '', '참, 거짓', '열거형', '집합', '','', '사전'],
    '타입' : ['정수', '실수','불','문자열','리스트', '튜플', '세트', '사전'],
    '타입명' : ['int', 'float', 'bool', 'Str', 'list', 'tuple', 'set', 'dict'],
    '리터럴 예시' : ['1, 4, 10', '3.156', 'True, False', '\"Hello World\"', '[10, 20, 30, 40]', '(1, 2, 3, 4)', '{3, 5, 9, 10}', '{\'a\':1, \'b\':2}']
}

pd.DataFrame(data)


# ### 숫자형 타입 확인과 변경
# 
# - type() 함수를 사용하여 데이터 타입 검사 가능

# In[147]:


print(type(1))
print(type(3.14))
print(type("안녕"))
print(type(True))


# - type 변경

# In[148]:


a = 1
print(type(a))
print(f'type(float(a)) : {type(float(a))}')

b = 3.99
print(f'int(b) = {int(b)}')
print(f'type(int(b)) : {type(int(b))}')


# ## 집합형 자료구조
# 
# - list
#     - 여러 가지 형태의 변수를 하나의 순서가 있는 배열로 묶어놓은 형태
# 
# - tuple
#     - 조회만 가능하고 변경이 불가능한 리스트
# 
# - set
#     - 순서가 없고 중복을 허용하지 않음
# 
# - dictionary
#     - Key와 value 형태로 데이터를 저장함

# - list 규칙
# 
#     - list는 다양한 type의 데이터를 집합으로 가집니다
#     - list 안에 list도 허용합니다.
#     - list는 순서의 개념이 존재합니다

# In[149]:


a = []
a = list()

a = [1, 'hello', 3, 3.14, True]
a = [1, 3.14, 'hi', [6, 7, '8']]
print(a)


# #### list의 성질
# 
# - append() : 값 추가
#     - append(value)  : 리스트의 맨 마지막에 value 추가

# In[150]:


mylist = list()
for i in range(3):
    mylist.append(3)

mylist.append(5)
print(mylist)


# - insert() : 값 추가
#     - insert(index, value) : index에 value 삽입

# In[151]:


mylist.insert(1, 100)
mylist


# - 삭제
#     - remove(value) : 첫번째로 나오는 value 삭제(index 빠른 순서)
# 
#     - pop(index) : index 번째 요소를 반환 및 삭제

# In[152]:


mylist = [1, 100, 7, 7, 7, 7, 3, 5, 2]
mylist.remove(1)
mylist


# - pop(index)는 값을 저장함과 동시에 index에 있는 값을 삭제시킨다

# In[153]:


mylist = [1, 100, 7, 7, 7, 7, 3, 5, 2]
print(mylist.pop(1))
mylist


# - len() : 리스트의 크기
#     - len(list)

# In[154]:


mylist = list(range(10, 60, 10))
print(mylist)
len(mylist)


# - 정렬
#     - *sort()* : 정렬
#     - *sort(reverse=True)* : 내림차순(descending) 정렬

# In[155]:


mylist = list(range(0, 60, 10))
print(mylist)

mylist.sort(reverse=True)
mylist


# - *extend()* : 리스트 확장

# In[156]:


a = [1, 2, 3]
print(a)
a.extend([4, 5])
print(a)


# - 색인(index)
# 
#     - mylist = [1,2,3,4]

# In[157]:


print(mylist[0])
print(mylist[3])
# print(mylist[4])
print(mylist[-1])
print(mylist[-3])
# print(mylist[-5])


# - 리스트 색인하여 값 수정

# In[158]:


print(mylist)
mylist[0] = 100
print(mylist)
mylist[-1] = 300
print(mylist)


# - 중첩 리스트 색인

# In[159]:


mylist = [[1,2,3], [4,5,6], [7,8,9]]
print(mylist)

print(mylist[1])
print(mylist[1][1])


# - slicing : 추출

# In[160]:


mylist = list(range(100, 600, 100))
print(mylist)

print(mylist[:3])
print(mylist[-3: -1])
print(mylist[2:])
print(mylist[-3:])

print(mylist[::-1])
print(mylist[::2])
print(mylist[1::2])
print(mylist[3:1:-1])


# ### tuple의 성질
# 
# - 데이터 변경이 불가능
# 
# - 튜플은 소괄호로 둘러싸임
# 
# - 튜플의 생성
# 
#     - mytuple = (1, 2, 3) or 1, 2, 3
# 
# - 리스트는 값의 추가, 수정 삭제 가능 튜플은 불가
# 
# - 튜플의 인덱싱과 슬라이싱은 리스트와 동일
# 
# - 값 수정이 필요 없을 경우 튜플을 사용하는 것이 더 효과적 (C언어의 const와 비슷함)

# ### set의 성질
# 
# - set는 중괄호 안에 쉼표들로 값들을 구분
# 
# - **중복을 허용하지 않으며** 순서가 없음

# In[161]:


myset = set()
myset = set([1,1,1,1,2,2,2,3,3,3])
print(myset)


# - add(value) : 값 추가

# In[162]:


myset = set()
print(myset)

myset.add(1)
print(myset)

for i in range(1,5):
    myset.add(7)
print(myset)


# - update(set) : 여러개 값 일괄 추가

# In[163]:


print(myset)
myset.update([1, 3, 5, 7, 9])
print(myset)


# - 값 제거 : remove(value)

# In[164]:


print(myset)
myset.remove(1)
print(myset)


# - 세트는 집합이므로 intersection, union, difference를 모두 가짐

# In[165]:


a = {1,2,3,4,5}
b = {3,4,5,6,7}

print(a&b)
print(a.intersection(b))
print(a|b)
print(a.union(b))
print(a-b)
print(a.difference(b))


# ### Dictionary의 성질
# 
# - 딕셔너리는 key와 value의 쌍 여러개와 {}로 구성되어있음
# 
# - key를 통해 value를 얻음
# 
# - 순서가 없고, key 값은 **고유한 값**이어야 함
# 
# - type은 dict로 표시, 공 딕셔너리도 dict()로 만듦
# 
# - keys() : 모든 키 조회
# 
# - vaues() : 모든 value 조회
# 
# - items() : key, value 모두 조회

# In[166]:


mydict = {'a' : 1, 'b': 2}
print(mydict)

print(mydict.keys())
print(mydict.values())
print(mydict.items())


# - 값 추가

# In[167]:


mydict = dict()
mydict['apple'] = 5
mydict[0] = 2
mydict


# - update(dictionary) : 다중 업데이트

# In[168]:


mydict = { '파인애플' : 1500, '망고' : 3500}
print(mydict)

fruit = {
    '사과' : 500,
    '수박' : 2500
}
mydict.update(fruit)
print(mydict)


# - 값 변경 : key에 새로운 value 대입

# In[169]:


mydict = {'a' : 100, 'b':200, 'c' : 300}
print(mydict)

mydict['a'] = 900
print(mydict)


# - pop() : 요소 제거

# In[170]:


print(mydict)
mydict.pop('a')
print(mydict)


# ### 문자열(str)
# 
# - 데이터 분석에 있어서 문자열 데이터의 중요성
# - 자연어처리 데이터는 대부분 텍스트 데이터
# - 우리가 흔히 접하는 Excel, table 데이터안에도 텍스트 데이터가 많음
# - 한국은 영어와 한국어도 처리할 수 있어야함
# 
# **특성**
# - 문자열은 리스트, 튜플과 마찬가지로 순차형 구조를 가짐
# - 문자열은 불변(immutable) object입니다.

# - 문자열 생성
#     - 큰따옴표
#     - 작은 따옴표

# - 문자열 만들기
#     - 큰 따옴표, 작은따옴표를 연속 3개로 사용
#     - 여러줄 표현할 때

# In[171]:


print("""
      안녕하세요?
      반갑습니다
      웰컴!
      
      """)


# ### 문자열 포맷팅
#     - %

# In[172]:


print('안녕하세요 %s' % ('반갑습니다.'))
print('안녕하세요 %.3f' % (0.1234))
print('안녕하세요 %d' % (1234))
print('안녕하세요 %c' % ('a'))


# - {}와 .format()

# In[173]:


print('welcome to python {}'.format('파이썬.'))
print('welcome to python {}'.format(485))
print('pi is {:.2f}'.format(3.141592))


# - f 문자열 포맷팅(python 3.6 이상)

# In[174]:


name = '펭수'
age = 10
print(f'나의 이름은 {name}이고 나이는 {age}입니다')
print(f'내년에는 {age+1}살입니다')

# 딕셔너리 꼴로 사용
d = {'name' : 'peng', 'age':10}
print(f'나의 이름은 {d['name']}이고, 나이는 {d['age']}입니다')


# - 길이

# 

# In[ ]:


len('bananan')


# - 색인 & 슬라이싱 

# In[ ]:


a = 'Python is my life'
print(a[0])
print(a[:6])
print(a[3:6])


# - 결합과 반복

# In[ ]:


a = '반갑습니다'
b = '웰컴 투 파이썬 '
print(a + b)
print(a + '???')
print(a * 2)
print(' === ' * 10)


# - 분리

# In[ ]:


a = 'This is a pen'
print(a.split(' '))
print(a.split())
b = 'This-is-a-pen'
print(b.split('-'))


# - 합치기 : join()

# In[ ]:


print('-'.join(['010','1234','5678']))
print('-'.join('ABCDE'))


# - 대문자, 소문자 (upper(), lower())
# - 바꾸기 : replace('str')
# - 공백제거 : strip()

# - 조건문
# 
# 모두 참인 조건인 경우 가장 첫번째 `참`인 구문을 실행

# In[ ]:


if 3 < 5:
    print('if 구문')
elif 3 < 4:
    print('elif 1')
elif 3 < 5:
    print('elif 2')
elif 3 < 6:
    print('elif 3')
else:
    print('아무것도 아님')


# #### 삼항연산자
# 
# - (참인 값) if 조건 else (거짓인 경우 값)

# In[ ]:


age = 35
print("30세 이상입니다." if age>=30 else "30세 이하입니다.")


# In[ ]:


age = 25
print("30세 이상입니다." if age>=30 else "30세 이하입니다.")


# ### 반복문
# 
# - 반복문이란
#     - 반복문은 프로그램 내에서 똑같은 명령을 일정 회수만큼 반복 수행하도록 제어하는 명령문
#     - 프로그램이 처리하는 대부분 코드는 반복적인 형태가 많으므로, 가장 많이 사용하는 제어 문 중 하나입니다.
#     - list, set, dict 등 집합에 대한 순회를 돌며 일을 처리할 때 많이 쓰임
# 
#     - while과 for ~ in 문법을 가장 많이 씀

# - 기본구조
# 
#     for <변수> in <iterable(list,tuple,str,...)>

# In[ ]:


for i in (1,2,3,4,5):
    print(i)


# - dictionary 반복문

# In[ ]:


mydict = {'a':1, 'b':2, 'c':3}
for key in mydict.keys():
    print(key)
print('\n')    
for value in mydict.values():
    print(value)
print('\n')
for key, value in mydict.items():
    print(key, value)


# - range()
#     - 특정 범위의 정수를 표현할 때 사용
#     - 수정이 불가
#     - 생성방법
#         - range(start,stop,step)

# In[ ]:


for i in range(1,10,2):
    print(i)


# - for in 구문을 중첩 사용할 시
# 
#     - for ~ in 문의 중첩

# In[ ]:


for i in range(1, 4):
    for j in range(1, 4):
        print(f' (i = {i}) + (j = {j}) = {i * j}')
    print('===')


# - continue
# 
#     - 현재 반복에 대해서 루프 내부의 나머지 코드를 건너뛰는 데 사용
# 
# - break
#     - 현재 속한 반복문 종료

# In[ ]:


for i in range(10):
    if i==5:
        continue
    print(i)


# In[ ]:


for i in range(10):
    if i==5:
        break
    print(i)


# - while문
# 
#     - 특정 조건을 만족하는 동안 실행되는 반복문
#     
#     while <조건>:
#         # statement
#         # stetement

# In[ ]:


count = 1

while True:
    print(count)
    count += 1
    if count > 5:
        break


# ### 함수
# 
#     - 기능 단위로 모듈을 구성
# 
#     - 코드의 체계화
# 
#     - 코드의 반복을 피할 수 있고 코드의 재사용이 가능

# def function_name(parameters):
# (statement)
# (statement)
# (statement)
# 
# 1. 키워드 def는 함수의 시작을 표시
# 2. 함수명은 고유하게 식별 가능해야 하고, 식별자 작성 규칙을 따름
# 3. 함수에 값을 전달하는 매개변수는 선택사항
# 4. 함수 헤더의 끝은 세미콜론
# 5. 동일한 범위 내 **들여쓰기**가 적용되어야 함
# 6. 함수에서 값을 반환하는 return문은 선택사항

# - 함수의 형태
# 
#     - return 문은 평가되는 표현식이나, 값을 리턴
#     - return 문에 표현식이 없거나 return 문 자체가 없으면 함수는 None object를 return
# - 함수 호출()
#     - 함수를 정의한 후에는 다른 함수, 프로그램 등에서 호출
#     - 함수를 호출하기 위해서는 적절한 인수를 사용하여 호출

# In[ ]:


def sample_function():
    print('function is called!')
    
print(sample_function)
print(sample_function())


# - 위치 인수 (positional argument)
# 
#     - 매개변수 위치에 맞게 값이 전달되는 방식
#     - 가장 기본적인 매개변수 전달방식
# 

# In[ ]:


def print_function(a,b,c):
    print(f'a :{a}, b:{b}, c:{c}')
    
print_function(1,2,3)


# - keyword argument
#     - 함수 호출 시 매개변수의 이름을 명시하여 값을 전달
#     - 매개변수 이름을 알고 있어야 함
#     - 순서에 상관없음

# In[ ]:


def add(a, b, c):
    print(f'a:{a}')
    print(f'b:{b}')
    print(f'c:{c}')
    return a+b+c

print(add(1,4,4))
print(add(1,c=6,b=4))
print(add(a=1,c=6,b=5))


# - 기본 매개변수 default parameter
# 
#     - 함수 정의시 할당 연산자 = 를 사용하여 매개변수에 기본값 설정
#     - 함수 호출시 기본 매개변수의 값을 전달하지 않아도 된다.
#     - 값 전달 시 기본값을 덮어 씀
#     - 함수 정의시 기본값이 없는 매개변수는 기본값 매개변수 뒤에 있을 수가 없음

# In[ ]:


def Add(a, b=3):
    print(f'a:{a}')
    print(f'b:{b}')
    return a + b

print(Add(3))
print(Add(3,4))
print(Add(5, b=4))
print(Add(a=5,b=4))
print(Add(b=4,a=5))
# print(Add(b=3, a))


# - 기본 매개변수 tuple
# 
#     - 매개변수 앞에 *를 붙이면 tuple형태로 값 전달
#     - 매개변수의 길이가 가변

# In[ ]:


def add(*args):
    for arg in args:
        print(arg)
    print('---' * 5)
    
print(add(1))
print(add(1,2,3))

def add(a, *args):
    print(f'a={a}')
    for arg in args:
        print(arg)
    print('===' * 2)
    
add(1,2,3,4)

def add(a, b=2,*args):
    print(f'a={a}')
    print(f'b={b}')
    for arg in args:
        print(arg)
    print('===' * 2)
    
add(1,2,3,4)


# - 기본 매개변수 - dict
# 
#     - 매개변수 앞에 **를 붙이면 dict형태로 전달
#     - 매개변수 길이 가변

# In[ ]:


def add(**a):
    for k, v in a.items():
        print(k, v)
    print('---')
    
add(a=1,b=2,c=3)

b = {'a':1,'b':2,'c':3}
print(b)
add(**b)

def add(a, b=2, **kvargs):
    print(f'a={a}')
    print(f'b={b}')
    print('====' * 5)
    for k, v in kvargs.items():
        print(k, v)
    print('------')

add(a=1,b=2,z=3,x=4,y=5)


# - lambda 함수 
# 
#     - 이름없이 정의된 함수
#     - lambda 키워드를 사용하여 정의
#     - 여러개의 인자를 가질 수 있지만 표현식은 단 하나
#     - 람다함수는 filter(), map()같은 내장함수와 함께 사용

# In[ ]:


a = lambda x: x*2
print(a(4))
a = lambda x,y: x*y
print(a(4,5))


# ### 패키지와 모듈
# 
# - 함수와 모듈 패키지는 함수가 여러개 모여 모듈, 모듈이 여러개 모여 패키지를 이룬다
# 
# - c언어의 .c 파일과 .h 파일이 모여 하나의 프로그램이 되는것과 유사
# 
# #### 모듈
# 
# - 재사용 하고자 하는 변수, 함수등을 별도의 파일에 저장하여 다른 Python 파일에서 호출하여 사용
# - 파일명이 calculator.py는 모듈명은 calculator
# - 큰 프로그램을 작게 쪼개서 재사용성이 높음
# - 자주쓰는 함수를 정의, 이를 다른 파일에서 import해서 사용
# 
# #### 모듈 사용
# - import 모듈명으로 사용할 수 있음
# - 함수 단위의 import도 가능
# 
# #### alias
# 
# - 모듈의 이름이 긴 경우 줄여 사용
# - alias는 흔히 사용되고, 이를 암묵적으로 따름
# - pd, np, plt, sns 등등

# 
