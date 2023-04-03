/*
# 문제 재정의
그냥... 반복문 돌면서 COUNT하거나 DP를 쓰면 되는 문제

반례.
    10,20,1,2,3,4,5,6,7,8,9,30,40  ... 일 경우에는?
이거 경우의 수 문제다. 완전탐색. DP 쓰자.
# 계획
 dp 배열[n][n]

 1. 테이블 정의 : d[i][j] = i번째 놈이 j (i보다는 작은 값) 다음에 왔을 때의 COUNT
 2. 점화식 : d[i][j] = MAX(d[j]) + 1
 3. 초기값 : d[1][] = 1,  mx[1] = 1

 LOOP(i ~ N):
    LOOP(j ~ i-1):
        IF (a[i] > a[j]):
            d[i][j] = mx[j] + 1
            IF (mx[i] < d[i][j]):
                mx[i] = d[i][j]

# 복잡도 검증
 O(n^2)
# 회고
 2차원 배열 필요없었다. 바킹독 참고
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005], d[1005]; // DP 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    fill(d, d + n, 1); // 모든 수는 최소 1부터 시작. 자기 자신이 있기 때문

    // DP LOOP
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (a[i] > a[j]) // 값이 더 큰 경우 : 부분 수열 조건 만족. 최대값 갱신
                d[i] = max(d[i], d[j] + 1);
    cout << *max_element(d, d + n);
}