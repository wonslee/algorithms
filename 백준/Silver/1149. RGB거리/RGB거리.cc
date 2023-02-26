/*
# 문제 재정의
 DP 문제. 점화식 찾자!
# 계획
 1. 테이블 정의
    D[i][j] = i번째 집을 j색으로 칠했을때 그때까지의 총 비용. 0: 빨강  1: 초록  2: 파랑
 2. 점화식 찾기
    조건을 충족시키려면 퐁당퐁당을 해야한다. 가령, 이전 집이 빨강이라면 현재 집이 빨강이어선 안 된다.
    FOR j=0~2 : D[i][j] = MIN( D[i-1][(j+1)%3], D[i-1][(j+2)%3] ) + S[i][j]
 3. 초기값 정하기
    D[1][0] = S[1][0], D[1][1] = S[1][1], D[1][2] = S[1][2]

 MIN을 쓰자.
# 복잡도 검증
# 회고
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int S[1002][3];  // 각 집의 비용 배열
int D[1002][3]; // 점화식 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= 2; ++j)
            cin >> S[i][j];

    if (n == 1) {// CONDITION: n=1일때
        cout << *min_element(begin(S[1]), end(S[1]));
        return 0;
    }

    // 초기값 : 맨 첫번째 집만
    D[1][0] = S[1][0];
    D[1][1] = S[1][1];
    D[1][2] = S[1][2];

    for (int i = 1; i <= n; ++i) {// DP : 계단에 대한 점화식
        for (int color = 0; color <= 2; ++color) {// RGB 3가지에 대해
            D[i][color] = min( D[i-1][(color+1)%3], D[i-1][(color+2)%3] ) + S[i][color];
        }
    }
    cout << *min_element(begin(D[n]), end(D[n]));;
}