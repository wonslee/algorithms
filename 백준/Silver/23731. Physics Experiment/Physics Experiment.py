# 숫자의 자릿수를 순회하면서 반올림 최대값을 찾는 문제
# e.g. 454 -> 450 -> 500 -> 1000

# 10^0, 10^1, ... 거듭제곱을 이용해야 할듯
# for i in range(N의 자릿수):
#   if i번째 >= 5: N += (10 - STR_N[i]) * 10^i
#   else: N -= STR_N[i] * 10^i

import sys

read = sys.stdin.readline

MAX_INT = sys.maxsize  # 2^63 -1
# input
N = int(input())

# init
result = N  # 최대값 갱신 변수

# main
for i in range(len(str(N))):
    d_index = -(i+1)    # 인덱스 거꾸로
    digit = int(str(N)[d_index])    # 가장 최신의 N에서 구해야 함
    # 반올림
    if digit >= 5:
        N += (10 - digit) * (10 ** i)
    else:
        N -= digit * (10 ** i)

    # 최대값 갱신
    result = max(result, N)

print(result)


