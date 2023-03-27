/*
# 문제 재정의
2차원 공간의 정사각형 카운트를 DP로 바꾸는 문제.
 '정사각형'이 이어질 수 있는지 보드상에서 인식하는게 중요
# 계획
d[i][j] = MIN(d[i-1][j-1], d[i-1][j], d[i][j-1]) + 1
# 복잡도 검증
 O(n*m)
# 회고
 DP라는걸 감도 못 잡았다. 2차원 공간 문제에 대한 감을 키워야

*/

#include <bits/stdc++.h>
using namespace std;

int n,m, ans;
char board[1005][1005];
int d[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (board[i][j] == '1'){
                d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + 1;
                if (d[i][j] > ans)
                    ans = d[i][j];
            }
    // ASCII..
    cout << ans * ans;
}