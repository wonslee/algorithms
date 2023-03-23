/*
# 문제 재정의
# 계획
# 복잡도 검증
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int t, h, w, n;
string ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> h >> w >> n;

        int cnt = 0;
        for (int i = 1; i <= w; ++i) {
            for (int j = 1; j <= h; ++j) {
                cnt++;
                if (cnt == n) {
                    cout << j;
                    if (i < 10)
                        cout << 0;
                    cout << i;
                }
            }
        }

        cout << '\n';
    }
}