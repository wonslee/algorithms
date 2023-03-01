/*
# 문제 재정의
 - DP...?
# 계획
 1. 테이블 정의
    D[i] = A[1] + A[2] + ... + A[i]

 2. 점화식 구하기
    D[i] = D[i-1] + A[i]
    D[j] = D[j-1] + A[j]
    --> i~j의 값 = D[j] - D[i-1]
 3. 초기값
    D[1] = A[1]
# 복잡도 검증
 - 그냥 A[i] ~ A[j] 를 더해서 출력하는 경우, 100000^2이므로 100억이고 10초 이상이 걸리므로 시간 초과다.
# 회고
*/


#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
int A[100002];
int D[100002]; // DP 배열

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    D[1] = A[1];
    for (int i = 2; i <= n; ++i) {
        // DP : 미리 D[i] 구하기
        D[i] = D[i - 1] + A[i];
    }

    while (m--) {
        cin >> a >> b;
        cout << D[b] - D[a - 1] << '\n';
    }

}