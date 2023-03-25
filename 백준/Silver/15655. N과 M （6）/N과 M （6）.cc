/*
# 문제 재정의
 모든 경우의 수를 뒤져봐야 한다. 완전탐색 문제
 -> DFS 백트래킹
# 계획
 우선 배열을 정렬한 다음
 depth을 인자로 받는 dfs함수를 호출해 모든 경우의 수를 출력

 DFS(depth, item):
    BASE CONDITION(depth == length):
        permut 원소들 출력, 함수 종료
    LOOP(i in M):
        IF(i > item):
            permut.push_back(i)
            DFS(depth+1, i)
            permut.pop_back()

# 복잡도 검증
 O(nPm) = 대충 M! = 8! = 40320
# 회고
 - 오랜만이라 잘 안 풀렸다. 결국 보고 풀었음..
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, input;
vector<int> inputs; // 입력 배열
vector<int> seq; // 수열
bool is_used[10002]; // 사용되었는지 체크하는 불리언 카운팅 배열

void dfs(int idx) {
    if (idx == m) {// BASE CONDITION : 조합 하나 완성된 경우
        for (int s : seq) cout << s << ' ';
        cout << '\n';
        return;
    }

    for (int num : inputs) {// LOOP : 배열을 idx+1부터 끝까지
        if (seq.empty() || !is_used[num] && num > seq.back()) {// CONDITION : 아직 안 쓰였고 현재 숫자보다 클 경우에만
            seq.push_back(num);
            is_used[num] = true;
            dfs(idx + 1); // BACKTRACK
            seq.pop_back();
            is_used[num] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        inputs.push_back(input);
    }

    // SORT :
    sort(inputs.begin(), inputs.end());

    // 먼저 첫번째 원소를 넣어줘야 하나?
    dfs(0);
}