/*
# 문제 재정의
 C개 중에서 L개를, 정렬되는 식으로 중복없이 선택하는 모든 경우의 수를 구하는 문제.
 브루트포스 문제. N과 M문제와 매우 흡사하다.
 백트래킹으로 풀어보자.

# 계획
 FUNCTION(depth, idx):
    BASE CONDITION(depth == L):
        선택된 조합들 출력, 종료

    LOOP(i=idx+1 ~ 다른 원소들에 대해서):
        CONDITION(이미 방문된 경우) continue

        v.push(i번째 원소)
        BACKTRACK(depth+1, i)
        v.pop()


 FUNCTION(0, 0)

# 복잡도 검증
 TODO. 이거 시간복잡도 구하기.
 15^15인가?흠... 아니다.
 순열과 조합으로 봐야할듯한데
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int l, c;
char alphabet[16];
int m_count, j_count;
bool vis[16];   // 방문 여부

bool is_vowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void dfs(int depth, int idx) {
    // BASE CONDITION : 지금까지의 조합을 출력 후 종료
    if (depth == l) {
        // CONTION :  최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성
        if (m_count >= 1 && j_count >= 2) {
            for (int i = 0; i < c; ++i)
                if (vis[i]) cout << alphabet[i];
            cout << '\n';
        }
        return;
    }

    // LOOP : 나머지 원소들에 대해 오름차순으로 방문
    for (int i = idx; i < c; ++i) {
        // CONDITION : 이미 방문된 경우
        if (vis[i]) continue;

        vis[i] = true;  // 방문 표시
        // 모음, 자음 여부에 따라 count
        if (is_vowel(alphabet[i])) m_count++;
        else j_count++;

        // BACKTRACK
        dfs(depth + 1, i);

        vis[i] = false;
        if (is_vowel(alphabet[i])) m_count--;
        else j_count--;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> c;
    for (int i = 0; i < c; ++i)
        cin >> alphabet[i];

    // SORT
    sort(alphabet, alphabet + c);

    dfs(0, 0);
}