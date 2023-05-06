/*
# 문제 재정의

그리디로는 풀 수 없음.
 브루트포스 문제. 모든 경우의 수를 다 뒤져봐야 한다. 상태공간트리

=> 백트래킹 혹은 next_permutation 으로
 100 ^ n

아니면 메모이제이션?
 k=15라고 할 때, [15] 배열에다가 차례대로 최소시도값을 넣으면 되지 않을까?
 ex. 1,2,3,4,1,2,3,4,2,3,1,2,3,3
 [15] = MIN([10] + 1, [3] + 1, [14]+1) = MIN(3,4,4) = 3

 d[i] = MIN( FOR( c in coins : d[i-c] + 1 ) )

 => O(n*k) = 약 1000000

# 계획

# 복잡도 검증
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, coin;
vector<int> coins;
int memo[100002];    // memoization. 최소 시도값을 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(memo, memo + 10002, 987654321);

    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        cin >> coin;
        coins.push_back(coin);
        memo[coin] = 1;  // 해당 동전의 최소시도횟수는 무조건 1
    }

    for (int i = 1; i <= k; ++i) {// 1~k까지
        if (memo[i] == 1) continue;

        for (int c : coins) {// DP
            if (i > c)
                memo[i] = min(memo[i], memo[i - c] + 1);
        }
    }

    if (memo[k] == 987654321)// 도달 못하는 경우
        cout << -1;
    else
        cout << memo[k];
}