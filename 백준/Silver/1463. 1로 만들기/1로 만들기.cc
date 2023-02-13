/*
# 문제 재정의
 수학적인 패턴(점화식)을 구해 푸는 DP 문제.

 !! 이건 소인수분해다. 3의 몇승, 2의 몇승이 숫자안에 있는지 찾아내야 최소 횟수를 구할 수 있다.
 3^12, 2^19 부터 해서 구해나간다.
# 계획
 1. 테이블 정의
    D[i] = i를 1로 만들기 위해 필요한 연산 사용횟수의 최소값
 2. 점화식 찾기
    D[i] = ?
    3으로 나눌 경우: D[i] = D[i/3] + 1
    2로 나눌 경우: D[i] = D[i/2] + 1
    1을 뺄 경우: D[i] = D[i-1] + 1
    위 3 경우중에서 최소값 MIN을 구하면 된다.
 3. 초기값 정의하기
    D[1] = 0
# 복잡도 검증
# 회고
 - 얼핏보면 백트래킹을 떠올릴 수도 있다.
*/

// https://aerimforest.tistory.com/205
#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000004];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;

    // DP
    d[1] = 0; // INITIAL
    for (int i = 2; i <= n; ++i) {// LOOP: d[i] 갱신
        d[i] = d[i - 1] + 1;
        if (i%2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if (i%3 == 0) d[i] = min(d[i], d[i / 3] + 1);
    }
    cout << d[n];
}