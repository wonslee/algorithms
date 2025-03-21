import sys

read = sys.stdin.readline

# input
input = int(input())

# init
def check_is_yoon(num):
    return int(num % 4 == 0 and num % 100 != 0 or num % 400 == 0)

# main
print(check_is_yoon(input))