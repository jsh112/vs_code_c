# main.py

import calculator

result = calculator.add(4, 5)
print('result of add : {}' .format(result))

result = calculator.subtract(4, 5)
print(f'result of subtract : {result}')

result = calculator.multiply(4, 5)
print('result of multiply : {}'.format(result))

result = calculator.divide(4, 5)
print('result of divide : {}'.format(result))

from calculator import add

result = add(4, 5)
print('result of add : {}'.format(result))

import calculator as calc

result = calc.subtract(5, 4)
print(f'result of subtract : {result}')

print("\"오늘 파이썬 배우기 좋은 날이네!\"")

# print(f'a = {a}\n')
# print(f'A = {A}\n')
# print(f'안녕 = {안녕}\n')
# print(f'a_1 = {a_1}\n')
# print(f'a_ = {a_}\n')
# print(f'_a = {_a}\n')
# print(f'_1a = {_1a}\n')

print('오늘은', '일요일')
print("오늘은","일요일",sep=" a ")
