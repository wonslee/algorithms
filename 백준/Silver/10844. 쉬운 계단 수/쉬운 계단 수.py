# 경우의 수 DP
# 1~9 의 2차원 배열을 만들면 될 것 같다.
# N=1일 때, 1 2 3 4 5 6 7 8 9
# N=2일 때, 10 12  21 23  32 34  43 45  54 56  65 67  76 78  87 89  98
# N=3일 때, 101  121 123  210 212  232 234  321 323  343 345 432 434 454 456 543 545 565 567 ...789 ... 989

# 공식은 따로 없는거같음..
# 하락하는 경우 / 상승하는 경우 2가지.
# 0으로 끝나는 경우, 하락 X
# 9로 끝나는 경우, 상승 X

# i층의 j값에서, 다음 층의 값을 하나씩 올려주는건 어떨까?
# 1층의 2일 때: 2층의 1,3의 값을 +1

# d[i][j] = i번째에서 j(1~9)를 선택했을 때 계단수가 되는 최대 값. = d[i-1]
# 첫 시작이 0인 경우에 대해 분기 처리 필요.


import sys

read = sys.stdin.readline

# input
N = int(input())

# init
MAX_N = 104
STAIR = 10
MOD = 1000000000

d = [[0 for _ in range(STAIR)] for _ in range(MAX_N)]
for i in range(1, STAIR):   # 초기값: N=1
    d[0][i] = 1

# main
for i in range(1, N):   # 2~N
    for j in range(0, STAIR):  # 0~9
        if j != 0:
            d[i][j] += d[i - 1][j - 1]
        if j != 9:
            d[i][j] += d[i - 1][j + 1]
        d[i][j] %= MOD

print(sum(d[N - 1]) % MOD)
