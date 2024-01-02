# 구현
# 조건문 처리 문제
#


import sys

read = sys.stdin.readline

# init

# input
cash = int(input())
chart = list(map(int, read().split()))

# main
# jun, sung = {"result": 0, "cash":cash, "shares" : 0}, {"result": 0, "cash":cash, "shares" : 0}

cash_jun = cash_sung = cash
jun, sung = 0, 0  # 준현, 성민의 결과
shares_jun = shares_sung = 0  # 각각의 주식 개수

asc_cnt, dsc_cnt = 0, 0

for i, price in enumerate(chart):
    # 준현
    if cash_jun >= price:
        shares_now = cash_jun // price
        cash_jun -= shares_now * price
        shares_jun += shares_now

    # 성민
    if i > 0:
        if chart[i] > chart[i - 1]:
            asc_cnt += 1
            dsc_cnt = 0
        elif chart[i] < chart[i - 1]:
            dsc_cnt += 1
            asc_cnt = 0
        else:
            asc_cnt, dsc_cnt = 0, 0

    if dsc_cnt >= 3 and cash_sung >= price:
        shares_now = cash_sung // price
        cash_sung -= shares_now * price
        shares_sung += shares_now

    if asc_cnt >= 3:
        cash_sung += shares_sung * price
        shares_sung = 0

    # 차트 마지막 가격 추출
    if i == len(chart) - 1:
        jun = cash_jun + shares_jun * price
        sung = cash_sung + shares_sung * price

if jun > sung:
    print("BNP")
elif jun < sung:
    print("TIMING")
else:
    print("SAMESAME")
