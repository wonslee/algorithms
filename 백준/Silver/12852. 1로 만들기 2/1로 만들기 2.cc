/*
# 문제 재정의
# 계획
 1. 테이블 정의
    D[i] = i를 1로 만들기 위한 연산횟수의 최소값
 2. 점화식 구하기
    D[i] = MIN( D[i/3] + 1, D[i/2] + 1, D[i-1] -1 )
    나누어떨어질때만 나눗셈을 한다.
 3. 초기값
    D[1] = 0

 이건 최소값을 출력하는게 아니라 최소값을 구하는동안 거쳐온 모든 숫자를 출력해야 한다.
 가렴 10일 때는 1,3,9,10. D[1]=0, D[3]=1, D[9]=2, D[10]=3
 반복문을 돌면서 i를 따로 저장해야 하나?

# 복잡도 검증
# 회고
 - 경로 복원용 테이블(pre)을 배웠다. 각 index마다 이전에 어디(index)에서 왔다고 체크를 하고 나중에 이 값이 어디서 온건지 추적이 가능
 - `&& D[i] > D[i/2] + 1` 이 부분은 생각하지도 못했다.
 - 똑같은 원리로 BFS에서도 경로복원이 가능하다.
*/


#include <bits/stdc++.h>
using namespace std;

int n;
int D[1000002]; // 점화식 배열
int pre[1000002]; // 경로 복원용 테이블

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    D[1] = 0; // INITIAL
    for (int i = 2; i <= n; ++i) {// LOOP: 점화식
        D[i] = D[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && D[i] > D[i/2] + 1){
            D[i] = min(D[i], D[i / 2] + 1);
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && D[i] > D[i/3] + 1) {
            D[i] = min(D[i], D[i / 3] + 1);
            pre[i] = i / 3;
        }
    }

    cout << D[n] << '\n';

    int cur = n;
    while (true) {
        cout << cur << ' ';
        if (cur == 1) break;
        else cur = pre[cur];
    }
}