/*
# 문제 재정의
 뭔가 DP같은 문제. 미리 채워둘까? 14층 14호까지만 채워주면 됨

 1층 3호 -> 0층 1호 + 2호 + 3호 = 1+2+3 = 6

 2층
 6을 빼고, 12를 빼고, ...
# 계획

# 복잡도 검증
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int t,n,k;
int apart[15][15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i <= 14; ++i) {
        for (int j = 1; j <= 14; ++j) {
            if (i == 0)
                apart[i][j] = j;
            else {
                for (int l = 1; l <= j; ++l) {
                    apart[i][j] += apart[i - 1][l];
                }
            }
        }
    }

    cin >> t;
    while (t--) {
        cin >> k >> n;
        cout << apart[k][n] << '\n';
    }
}