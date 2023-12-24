# DP
# 수열을 순회하면서 이어지는 스트릭 횟수를 경우의 수 메모이제이션하면서 구하는 문제

# N=1000, 시간 제한 = 1초 => O(N^2) 가능
# d[i] = 숫자 i가 가질 수 있는 가장 최대 스트릭 = MAX(d[1 ~ i-1]) + 1

import sys
read = sys.stdin.readline
MAX_NUMBER = 1005

# input
N = int(input())

sequence = list(map(int, read().split()))

# init
d = [0 for _ in range(MAX_NUMBER)]
for num in sequence:
    if num == 1:
        max_previous = 0
    else:
        max_previous = max(d[1:num])
    d[num] = max_previous + 1

print(max(d))
# main