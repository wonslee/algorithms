/*
# 문제 재정의
 재귀함수를 이해하고 경우의 수를 찾는 문제. DP 쓰면 될것 같은데?
# 계획

 0 : 1 0
 1 : 0 1
 2 : 1 1
 3 : 1 2
 4 : 2,3  3, 2 -> 2,1 1,0 -> 1,0
 5 : 3,5
 6 : 5,8

 0과 1의 호출개수 패턴이 피보나치와 같다!

 d[i] = d[i-1] + d[i-2]
# 복잡도 검증
 O(n)
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int t, n;
pair<int,int> d[42]; // 0,1을 담을 DP 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;

    d[0] = {1,0}, d[1] = {0,1};

    for (int i = 2; i <= 40; ++i) {
        d[i].first = d[i - 1].first + d[i - 2].first;
        d[i].second = d[i - 1].second + d[i - 2].second;
    }

    while (t--) {
        cin >> n;
        cout << d[n].first << ' ' << d[n].second << '\n';
    }
}