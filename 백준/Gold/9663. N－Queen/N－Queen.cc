/* 9663. N-Queen
 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 방법의 수를 구하는 프로그램을 작성하시오.

# 문제 재정의
 '조합'문제다. NxN 체스판에 퀸 N개가 서로 공격할 수 없게 놓는 경우의 수.
 백트래킹 (N과M) 문제라는걸 생각해보자.
 모든 체스판 칸을 N개만큼 선택해야 하는데, '퀸의 현재 자리와 중복되지 않고 퀸의 공격범위에 있지 않는다'라는 조건이 붙는다.
 그렇다면 visited 변수를 써야 하고, 공격범위에 대한 조건문을 짜야 한다.
 우선 직선범위에 대해서 퀸의 자리와 같은 x,y 자리는 모두 제외.
 대각선범위에 대해서 퀸의 자리에서 (+1,+1)(-1,-1)(-1,+1)(+1,-1) 자리는 모두 제외.

# 계획(실패)
 count=0
 vector<pair> v
 visited[][]
 func(idx):
    기저사례. idx==n일 경우: 하나의 조합을 모두 선택한 것이므로 count+1 후 종료
    for (x=1 ~ N): x축에 대해서
        for (y=1 ~ N): y축에 대해서
            조건문: 퀸의 현재 자리와 퀸의 공격범위 제외한 경우에 대해서
                v.push(x,y)
                visited[x][y]=true
                func(idx+1)
                v.pop()
                visited[x][y]=false
# 계획 검증
 8Cm. 8*7*6*5 정도.
 push, pop연산은 O(1)이므로 시간 차지 별로 안 함.

# 회고
- 백트래킹이라는 점에서 N과M 문제와 똑같지만, **체스판에 대한 수학적인 접근**(x+y, x-y, y)이 가능해야 풀 수 있었던 문제. 
isused1~3은 한 조합 속에서 퀸들의 공격범위들을 저장하는 배열. x,y 연산 결과 이 값들이 하나라도 true일 경우 반복문 continue.
모두 false일 경우 현재 퀸의 공격범위를 3 배열에 저장하고 재귀호출(다음 row).
- 내가 푼 이전 방법은 모든 칸을 2차원 배열로 다 체크했다. (i,j)가 퀸의 공격범위에 있는지 확인하기 위해 중첩 반복문을 총 4개 쓰게 됐다... 
- https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0C/9663.cpp
- http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html
- https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
 */

#include <bits/stdc++.h>
using namespace std;

bool isused1[40]; // column을 차지하고 있는지
bool isused2[40]; // / 방향 대각선을 차지하고 있는지
bool isused3[40]; // \ 방향 대각선을 차지하고 있는지

int n, cnt = 0;

// x번째 column에 말을 배치할 예정
void func(int x) {
    if (x == n) { // N개를 놓는데 성공했다면 count +1후 종료
        cnt++;
        return;
    }
    // loop(y~n) : 백트래킹 반복문. (x, y)에 퀸을 놓을 예정
    for (int y = 0; y < n; y++) {
        if (isused1[y] || isused2[y+x] || isused3[x-y+n-1]) // column이나 대각선 중에 퀸 공격범위가 하나라도 true일 경우
            continue;
        isused1[y] = true;
        isused2[y+x] = true;
        isused3[x-y + n-1] = true;
        func(x+1);
        isused1[y] = false;
        isused2[y+x] = false;
        isused3[x-y + n-1] = false;
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;
}
