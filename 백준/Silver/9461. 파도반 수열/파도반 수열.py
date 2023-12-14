# DP
# 점화식 : f(n) = f(n-2) + f(n-3)
def wave(x):
    d = [1 for _ in range(x)]
    for i in range(3, x):
        d[i] = d[i-2] + d[i-3]
    print(d[x-1])


# input
T = int(input())

for _ in range(T):
    N = int(input())
    wave(N)