/*
# 문제 재정의
 - DP 문제. 피보나치랑 비슷하게 수열의 패턴을 관찰하는게 주요
# 계획
 - 테이블 정의 : d[i] = P(i)
 - 점화식 : d[i] = d[i-2] + d[i-3]
 - 초기값 : d[1]=d[2]=d[3]=1
# 복잡도 검증
# 회고
*/


#include <bits/stdc++.h>
using namespace std;

int t, n;
long long d[102];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    // INITIAL
    d[1]=1,d[2]=1,d[3]=1;
    // LOOP : 점화식
    for (int i = 4; i <= 100; ++i) {
        d[i] = d[i - 2] + d[i - 3];
    }

    while (t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
}