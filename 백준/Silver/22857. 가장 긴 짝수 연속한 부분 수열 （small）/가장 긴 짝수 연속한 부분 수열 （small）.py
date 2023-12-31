#
# N = 50000, K = 100, 원소 값 = 10^6
# 가장 긴 증가하는 부분 수열 문제와 매우 흡사.
# K번 삭제하는 경우의 수를 어떻게 처리하느냐가 관건.

# K=2일 때
# 1 2 3 4 5 6 7 8 -> 1  2  4  6  7 8 9 가 3으로 최대 길이.

# 입력받을 때 이거 홀수냐 짝수냐만 저장하자. 홀수:False 짝수:True

# d[i] = sequence[i]까지의 최대 연속 짝수 길이. sequence[i]가 짝수라면 d[i-1] + 1
# 이거... 모든 경우의 수를 구할 수는 없다. N=50000인데 그 안에서 K개 빼는 경우를 모두 구하려면 시간 초과될 거임.
# dp를 진행하면서 짝수가 아닐 때 제거해나가면서 지금까지 몇개(혹은 몇번째 원소)를 지웠는지 셀까?

# del[i] = [지금까지 지운 원소 index들]
# K=3일 때
# 2 2 2 1 1 1 2 2 1 2 2 1 2 1 2
# ! 어차피 K개를 넘어가는 홀수들이 있으면 해당 원소는 더 이상 진행 불가.
# for _ in N
#       for _ in K
# d[0] = 1, d[1] = 2, d[2] = 3, ... d[4]=3, d[5]=3  --> 리셋
# d[6] = 1, d[7] = 2, d[8] = 2 (del[8] = [8]), d[9]=3, d[10]=4, d[11]=4 (del[11]
# K=100...

# [2 3 2 3 2 2 1 1]


import sys

read = sys.stdin.readline

# input
N, K = map(int, read().split())
input_list = list(map(int, read().split()))
is_even = [i % 2 == 0 for i in input_list]  # 짝수인지 여부만 저장

# init
d = [0 for i in range(N)]
deleted = [0 for i in range(N)]  # i번째놈이 삭제한 원소 개수

# main
for i in range(N):
    if not is_even[i]:
        continue
    for j in range(i, N):
        if is_even[j]: # 짝수일 경우
            d[i] += 1
        else:
            deleted[i] += 1

        if deleted[i] > K:
            break


print(max(d))

