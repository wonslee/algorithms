/*
# 문제 재정의

나머지 연산의 성질을 이용하는 문제. 정수론.
 곱셈과 덧셈 중간마다 나머지를 취해도 결과의 나머지는 같다는 것입니다.
✓ 따라서 매 연산마다 나머지를 취해 주면 수가 커지지 않고 원하는 O(N log N ) 시간복잡도를 얻습니다.

5 7일때 : 1 -> 1, 2 -> 12 -> 5 , 3 -> 53 -> 4, 4->44->2, 5->25->4
 == 12345 % 7

# 계획

# 복잡도 검증
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, digit;
unsigned long long gyulsu;  // 수의 범위가 최대한 크게 잡기

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;

    gyulsu = 1 % k;  // 초기값 : 1

    for (int num = 2; num <= n; ++num) {
        // 1. N의 자릿수 계산
        digit = (int) log10(num) + 1;

        // 2. 기존의 N-1결수를 10의 N자릿수 승만큼 곱해주고, % k
        gyulsu *= pow(10, digit);

        gyulsu %= k;

        // 3. N % k 을 더해주기
        gyulsu += (num % k);

        // 4. N결수 % k
        gyulsu %= k;
    }

    cout << gyulsu;
}