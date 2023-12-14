# DP 기초 문제

N = int(input())
recursion_cnt = 0
dp_cnt = 0


# recursion
def fib(x):
    global recursion_cnt

    if x == 1 or x == 2:
        recursion_cnt += 1
        return 1
    else:
        return fib(x-1) + fib(x-2)


fib(N)

# DP
f = [0 for _ in range(N)]

f[0] = 1
f[1] = 1
for i in range(2, N):
    f[i] = f[i-1] + f[i-2]
    dp_cnt += 1


print(recursion_cnt, dp_cnt)

