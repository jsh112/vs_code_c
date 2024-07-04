name = "Alice"
age = 30

print(f'나의 이름은 {name}입니다. 나이는 {age} 살입니다.')

d = {'name': 'abc', 'age': 10}
print(f"반가워요. 저는 {d['name']}입니다. 저의 나이는 {d['age']}입니다")

print('-'.join(['010', '1234', '5678']))

# 1 ~ 3(duration 1)
for i in range(1, 4):
    for j in range(1, 4):
        print(f' (i={i}) + (j={j}) = {i*j}')
    print('===')

for i in range(10):
    if i == 5:
        continue
    print(i)

print("\n")

for i in range(10):
    if i == 5:
        break
    print(i)

print("\n")

count = 1

while True:
    print(count)
    count += 1
    if count > 5:
        break


def sample_function():
    print('The function is called!')


sample_function()


def print_function(a, b, c):
    print(f'a: {a}, b: {b},c: {c}')


print_function(1, 2, 3)


def add(a, b, c):
    print(f'a = {a}')
    print(f'b = {b}')
    print(f'c = {c}')
    return a + b + c


print(add(1, 4, 4))
print('\n')
print(add(1, 5, 6.2))
print('\n')
print(add(1.0, 2.5, 3.4))


test_values = [
    (1, 4, 4),
    (1, 5, 6.2),
    (1.0, 2.5, 3.4)
]

for values in test_values:
    result = add(*values)
    print(f'{result}\n')


def Add(a, b=3):
    print(f'a={a}')
    print(f'b={b}')
    return a + b


print(Add(3))
print(Add(3, 4))
print(Add(5, b=4))
print(Add(a=5, b=4))

print('\n')


def ADD(*args):
    for arg in args:
        print(arg)
    print('===' * 5)


print(f'{ADD(1, 2, 3, 4, 5, 6)}\n')


def Add(a, *args):
    print(f'a = {a}')
    for arg in args:
        print(arg)
    print('====' * 5)


def Add(a, b=2, *args):
    print(f'a = {a}')
    print(f'b = {b}')
    for arg in args:
        print(arg)
    print('====' * 5)


Add(1, 3, 5, 7, 9)
Add(1, 2, 3, 4, 5)


def add(**a):
    for k, v in a.items():
        print(k, v)
    print("====" * 5)


add(a=1, b=2, c=3)
b = {'a': 1, 'b': 2, 'c': 3, 'd': 4}
b
add(**b)

a = lambda x:x*2
print(a(4))

# 지시사항 1번을 참고하여 코드를 작성하세요.
sample ='20210101Sunny'

date = sample[:-5] 
weather = sample[-5:]
print(f'date: {date}, weather: {weather}')

# 지시사항 2번을 참고하여 코드를 작성하세요.
license_plate = "13나 5645"
print(license_plate[-4:])

a = 'Python is my life'
# index에 값을 할당하여 변경하려는 경우 에러 발생!
# a[2] = 'Y'

a = '반갑습니다!'
b = '웰컴 투 파이썬'

# 지시시항 1번을 참고하여 코드를 작성하세요.
print(a + b)

# 지시시항 2번을 참고하여 코드를 작성하세요.
print(a * 2)

# 지시시항 3번을 참고하여 코드를 작성하세요.
print("abc" * 5)

# 지시시항 4번을 참고하여 코드를 작성하세요.
print("===" * 7)

a = 'This is a pen'

# 지시사항 1번을 참고하여 코드를 작성하세요.
d = a.split(' ')
print(d)

b = 'This-is-a-pen'
# 지시사항 2번을 참고하여 코드를 작성하세요.
e = b.split('-')
print(e)

c = '한글은 어떻게 될까요?'
# 지시사항 3번을 참고하여 코드를 작성하세요.
f = c.split(' ')
print(f)

sample = 'abc-def.789/100'

# 지시사항 1번을 참고하여 코드를 작성하세요.
print(sample.split('.'))

# 지시사항 2번을 참고하여 코드를 작성하세요.
print(sample.split('-'))

a = ['010',  '1234', '5678']
# 지시사항 1번을 참고하여 코드를 작성하세요.
print('-'.join(a))
b = 'ABCDE'
# 지시사항 2번을 참고하여 코드를 작성하세요.
print('-'.join(b))

# 지시사항 1번을 참고하여 코드를 작성하세요.
sample = ['Python', 'is', 'too', 'interesting']
print('*'.join(sample))

# 지시사항 2번을 참고하여 코드를 작성하세요.
phone_number = ['010', '1234', '5678']
print('-'.join(phone_number))

a = 'My name is Teddy'

# 지시사항 1번을 참고하여 코드를 작성하세요.
print(a.lower())
# 지시사항 2번을 참고하여 코드를 작성하세요.
print(a.upper())

# 한글에는 대소문자 구분이 없습니다.
b = '한글엔 대소문자가 없어요ㅠ'
print(b.lower())
print(b.upper())


c = '01-sample.png'
# 지시사항 3번을 참고하여 코드를 작성하세요.
print(c.replace('png','jpg'))


d = '    01-sample.png                '
print(d)

# 지시사항 4번을 참고하여 코드를 작성하세요.
print(d.strip())

# 지시사항 1번을 참고하여 코드를 작성하세요.
a = 10
b = 3
print(a + b)

# 지시사항 2번을 참고하여 코드를 작성하세요.
c = 10
c += 5
print(c)

# 지시사항 3번을 참고하여 코드를 작성하세요.
d = 10
e = 3
print(d - e)

# 지시사항 4번을 참고하여 코드를 작성하세요.
f = 9
f -= 3
print(f)

# 지시사항 5번을 참고하여 코드를 작성하세요.
g = 10
h = 3
print(g / h)

# 지시사항 6번을 참고하여 코드를 작성하세요.
i = 10
i /= 2
print(i)

# 지시사항 7번을 참고하여 코드를 작성하세요.
j = 10
k = 3
print(j * k)

# 지시사항 8번을 참고하여 코드를 작성하세요.
l = 20
l *= 3
print(l)

a = 10
b = 3

# 지시사항 1번을 참고하여 코드를 작성하세요.
print(a // b)

# 지시사항 2번을 참고하여 코드를 작성하세요.
print(a % b)

# 지시사항 3번을 참고하여 코드를 작성하세요.
print(a ** b)

# 지시사항 4번을 참고하여 코드를 작성하세요.
print((10 + 2) * 5)

# 다음과 같은 경우는 어떻게 될까요?
c = '10'
d = '20'
print(c + d)

'''
e = '10'
f = 20
print(e + f) Error 발생!

'''

age1 = 35
age2 = 20

# 지시사항 1번을 참고하여 코드를 작성하세요.
print('30세 이상입니다' if age1 >= 30 else '30세 이하입니다')


def sample_function1():
    print('함수가 호출 되었습니다!')


# 함수의 이름만 출력시
print(sample_function1)

sample_function1()


# 함수의 이름을 별도의 변수에 대입한 후 변수에 ()를 같이 실행한 경우
a = sample_function1
a()





