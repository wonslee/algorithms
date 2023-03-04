/*
# 문제 재정의
 - DP 문제. 그러나 삼각형의 각 줄을 구현하는 과정도 어려운 문제.

# 계획
 우선 삼각형과 선택 경우의 수를 저장할 2차원 배열이 필요하다.

 대각선 왼쪽은 +1, 오른쪽은+2.

 결국 2차원 배열 방법이 최고다..
 (1,1)
 (1,2) (2,2)
 (1,3) (2,3) (3,3)
 (1,4) (2,4) (3,4) (4,4)
 ...

 (x,y)라고 할 때, (x-1,y-1) (x,y-1) 두 값만 보면 된다.
 범위를 초과하는 경우가 있는데, 0으로 초기화될 것이고 MAX로 거르기 때문에 상관 없어 보인다.

 1. 테이블 정의
    D[i] = i개를 선택했을 때까지 경로의 최대값
 2. 점화식 구하기
    D[y][x] = MAX( D[y-1][x-1], D[y][x-1] ) + t[y][x]
 3. 초기값
    D[1][1] = t[1][1]

# 복잡도 검증
 O(N)
# 회고
 - 삼각형 형태의 숫자들을 2차원 배열으로 단순화시켜봤다.
*/


#include <bits/stdc++.h>
using namespace std;

int n;
int t[505][505];
int D[505][505];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int floor;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> t[i][j];
        }
    }

    // INITIAL
    D[1][1] = t[1][1];

    // 점화식 : D[y][x] = MAX( D[y-1][x-1], D[y-1][x] ) + t[y][x]
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            D[i][j] = max(D[i - 1][j - 1], D[i-1][j]) + t[i][j];
        }
    }

    // 마지막 줄에서 최대값 출력
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (D[n][i] > ans) ans = D[n][i];
    }
    cout << ans;
}