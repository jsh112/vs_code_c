# return 이 존재하는 경우

def sample_function2():

    print('함수가 호출 되었습니다!')

    return 123



# return 값이 존재하는 경우 함수는 결과 값을 반환 하면 반환된 결과를 변수에 대입할 수 있습니다.

result1 = sample_function2()

print(result1)



# 하지만, 함수가 아무런 결과 값을 반환하지 않는다면 함수로부터 반환된 결과는 None입니다.

# return 이 없는 경우

def sample_function3():

    print('함수가 호출 되었습니다!')


result2 = sample_function3()
print(result2)

ddlist = list()
ddlist = [1,2,3]
print(ddlist)


