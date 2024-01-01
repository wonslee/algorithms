#
# 진수 변환 문제.
# 컴공 수업 시간에 들었던 것 같다.
# 100 = 64 + 32 + 4 = 1100100 (2) = 64 + 16*2 + 1*4 = 124 (8)

# 단순하게 생각했을 때, 자리마다 하나하나 값을 바꿔주면 될 것 같긴 하다.

import sys

read = sys.stdin.readline

# input
N = input()

# init

# main
converted = bin(int(N, 8))  # bin: binary 변환 함수. 8진수는 oct
print(converted[2:])    # 8진수 앞의 '0b' 제거
