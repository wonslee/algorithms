# 음... 반복문 문제?

# A짜리 배열 필요.
# 주의: 의미적으로 인덱스 0부터 시작!
# 원형 리스트 느낌이네.  A로 나눈 나머지값을 배열 인덱스로 써야 함
# 뻔 count , 데기 count 가 필요할 듯. 반복문이 한번 돌 때마다 count += 1
# N = 10000
# O(N) 혹은 O(N log N)

# 배열은 0 1 0 1 0 0 1 1   0 1 0 1 0 0 0 1 1 1  0 1 0 1 0 0 0 0 1 1 1 1 ... 식으로 흘러감. 규칙성이 있다.
# 우선 짝수에, 2씩 증가.
# 라운드마다 앞에서부터 4명은 0 1 0 1 확정.
# index_in_round: 라운드 내에서 한 명 진행할 때마다 += 1. 값은 % 2 로 구하자. 0번째 % 2 = 0, ...

# total_in_round: 4 + remain
# 이미 round = 2로 두고 시작.
# 그 후의 남는 사람을 remain이라고 할 때, remain = rount_cnt * 2
# 4 이상이 되면 그 후부터는 4,6,8,10, ... 4/2 = 2, 6/2 = 3, 8/2=4.
# (remain / 2)번째 사람까지 0값 할당.

# index: 01234567 / 8 9 10 11 12 13 14 15 16 17 / 18 19 20 ...

import sys

read = sys.stdin.readline

# input
A, T, target = int(input()), int(input()), bool(int(input()))

# init
people = [False for _ in range(A)]  # 뻔: False 데기: True

DEFAULT = 4  # 뻔 데기 뻔 데기
MAX_T = 10000
MAX_ROUND = 100
INITIAL_ROUND = 2

rnd = INITIAL_ROUND  # 라운드는 2부터 시작한다고 가정.
people_per_round = [DEFAULT + i * INITIAL_ROUND for i in range(MAX_ROUND)]  # 라운드당 사람 수. 10300명 수용 가능
round_capacity = people_per_round.copy()  # 현재 라운드에서 몇명 남았는지.

remain = people_per_round[rnd]
index_in_round = 0  # 현재 라운드상 몇번째인지
bun_cnt, degy_cnt = 0, 0    # 번 카운트, 데기 카운트

# main
for i in range(MAX_T):
    # 0~3번째 => % 2 (뻔 데기 뻔 데기)
    if index_in_round < DEFAULT:
        people[i % A] = index_in_round % 2 == 1
    else:  # (뻔 뻔 .. 데기 데기 ..)
        people[i % A] = (remain <= (people_per_round[rnd] - DEFAULT) // 2)

    if people[i % A]:
        degy_cnt += 1
    else:
        bun_cnt += 1

    if (target and degy_cnt == T) or (not target and bun_cnt == T):
        print(i % A)  # 원탁에서 몇번째에 있는지 출력
        break

    if index_in_round == people_per_round[rnd] - 1:
        rnd += 1
        remain = people_per_round[rnd]
        index_in_round = 0
    else:
        index_in_round += 1
        remain -= 1
