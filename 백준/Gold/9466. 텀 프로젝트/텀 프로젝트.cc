/*
# 문제 재정의
 DFS문제. '사이클'을 이루는 연결그래프의 노드들 개수를 구해야 한다.
# 계획
# 복잡도 검증
 모든 학생에 대해 한번씩만 방문하므로 O(n)..?!
# 회고
 그래프, DFS라는것까지는 얼추 파악했다. 그러나 구현을 못했음..
 DFS 감 잃었네.
 DFS는 백트래킹에만 쓰이는게 아니다. 자꾸 재귀와 base condition에 집착하지 말자

 그래프라고해서 꼭 adj_matrix를 쓰지 않아도 된다.
 이 문제처럼 공간복잡도에 한계가 있을 경우, 1차원 배열로 풀 수 있음.
*/

#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr[100002];        // 그래프 노드들의 배열
int state[100002];      // STATE : 방문 여부 & 사이클 완성한 노드인지 여부

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
    int cur = x;
    while(true){// LOOP : 이어진 노드들을 모두 순회
        state[cur] = x; // 방문 표시. 시작지점 놈의 번호를 먹인다
        cur = arr[cur]; // 다음 놈으로 넘어가는 과정
        if(state[cur] == x){ // 사이클이 완성된 경우
            while(state[cur] != CYCLE_IN){// 사이클 완성 표시(큰 의미는 없다. 나중에 볼라고)
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }else if(state[cur] != NOT_VISITED) {// 이전 방문에서 지나간 학생에 도달했을 경우
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;

    while (t--) {
        cin >> n;
        fill(state + 1, state + n + 1, NOT_VISITED); // state를 모두 초기화

        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        int ans=0;

        // LOOP: 첫번째부터 시작하되, 방문되지 않은 노드들에 대해서만 DFS => O(n)
        for (int i = 1; i <= n; ++i)
            if (state[i] == NOT_VISITED) run(i); // 방문하지 않은 놈들에 대해

        int cnt = 0;
        // 사이클을 만들지 않는 놈들의 개수만 세기
        for (int i = 1; i <= n; ++i)
            if (state[i] != CYCLE_IN) cnt++;

        cout << cnt << '\n';
    }
}