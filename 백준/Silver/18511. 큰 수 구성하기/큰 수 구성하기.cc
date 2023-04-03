/*
# 문제 재정의
 조합 문제. 백트래킹, DP, 그리디 등이 가능하다.
 순열 알고리즘을 이용한 완전 탐색 문제

 "K <= 3"에 주목하자!!
 K^10가지 조합으로 N보다 작거나 같은 최대값을 만들면 된다. 완전탐색, backtracking.

# 계획
# 복잡도 검증
 O(k^(n의 자릿수)) = 대략 3^10 = 100000 이하
# 회고
 - 전반적으로 더러운 풀이였다. 딱히 유형을 콕 집어 찾은것도 아니고 생각나는대로 풀어버림
 - 반례들을 먼저 더 생각해보고 풀자. 그래야 문제 유형이 더 잘 보인다.
 - 틀렸다. n=10, k=1, {1}일 때 답은 1밖에 없다. 지금 경우에는 11을 만들게 된다.
 - bruteforce문제였다. 3^10 = 54000.. 정도이므로 1초내에 가능함.
 - to_string을 배웠다. 어떤 숫자의 자릿수가 필요할 땐 이걸 쓰자. to_string(n).size()
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
vector<int> k_set, permutation;

void dfs(int depth, int length) {
    if (depth == length) {// BASE CONDITION : n의 자릿수와 동일해졌을 때
        int temp = 0;
        for (int p: permutation) {// 한번에 싹다 더해주기
            temp += p;
            temp *= 10;
        }
        temp /= 10;
        if (n >= temp)// CONDITION : 유효한 값(n보다 작거나 같은)일 경우, 최대값 갱신
            ans = max(ans, temp);
        return;
    }

    for (int i = 0; i < k; ++i) {// LOOP : k만큼 반복
        permutation.push_back(k_set[i]);
        dfs(depth + 1, length); // BACKTRACK : 다음 depth로
        permutation.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    k_set.resize(k);// 크기 맞추기

    for (int i = 0; i < k; ++i)
        cin >> k_set[i];

    for (int i = 1; i <= to_string(n).size(); ++i)
        dfs(0, i);

    cout <<  ans;
}