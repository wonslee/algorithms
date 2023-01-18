/* 9663. N-Queen
 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 방법의 수를 구하는 프로그램을 작성하시오.

# 문제 재정의
 '조합'문제다. NxN 체스판에 퀸 N개가 서로 공격할 수 없게 놓는 경우의 수.
 백트래킹 (N과M) 문제라는걸 생각해보자.
 모든 체스판 칸을 N개만큼 선택해야 하는데, '퀸의 현재 자리와 중복되지 않고 퀸의 공격범위에 있지 않는다'라는 조건이 붙는다.
 그렇다면 visited 변수를 써야 하고, 공격범위에 대한 조건문을 짜야 한다.
 우선 직선범위에 대해서 퀸의 자리와 같은 x,y 자리는 모두 제외.
 대각선범위에 대해서 퀸의 자리에서 (+1,+1)(-1,-1)(-1,+1)(+1,-1) 자리는 모두 제외.

# 계획
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

## 시간 복잡도
 8Cm. 8*7*6*5 정도.
 push, pop연산은 O(1)이므로 시간 차지 별로 안 함.

## 공간 복잡도
# 회고
 - 맨 첫번째 퀸만 생각해선 안 된다. 지금까지 있던 모든(idx-1개) 퀸의 공격범위를 고려해야 한다.
 - Queen에 대한 visited가 있어야 한다. 하나의 조합을 싹다 중복해서 계산하고 있었다. (e.g. n=4일 때 2개의 조합을 24개씩 중복 계산해서 48)
 오름차순(N과M 2)이다!! 조합자체가 '집합'처럼 되어야 한다.
 - 대각선 범위를 한칸씩만 재고 있었다.. 계속 나아가도록 해야 함.
 https://oeis.org/A000170

 */

#include <bits/stdc++.h>
using namespace std;

int n, cnt=0;
vector<pair<int,int>> v;
bool visited[15][15];
// 대각선 자리
int dx[4]={1,-1,-1,1};
int dy[4]={1,-1,1,-1};

// check(i, j): 지금까지 퀸들의 공격범위내에 (i,j)가 없는지 여부를 반환
bool check(int i,int j){
    for (int k=0; k<v.size(); k++)
        // 직선범위가 아닌 경우
        if (i != v[k].first && j != v[k].second)
            // 대각선 범위 체크
            // 대각선 4방면으로 쭉, n-1번씩
            for (int distance = 0; distance < 4; distance++){
                int x = v[k].first, y = v[k].second;
                for (int d=0; d<n-1; d++){
                    x += dx[distance], y += dy[distance];
                    if (i == x && j == y)
                        return false;
                }
            }
         else
            return false;

    return true;
}
// 백트래킹 함수
void func(int idx){
    // 기저사례. idx==n일 경우 count+1 후 종료
    if(idx==n){
        cnt++;
        return;
    }

    // 핵심 반복문
    for (int i=1; i<=n; i++)
        for (int j=1;j<=n; j++){
            pair<int,int> p; p.first=i; p.second=j;
            // 핵심 조건문. 첫방문이거나 퀸의 공격범위가 아닌 경우, 그리고 오름차순
            if (v.empty() || ( p > v.back() && !visited[i][j] && check(i,j) )){
                v.push_back(p);
                visited[i][j]=true;
                func(idx+1);
                v.pop_back();
                visited[i][j]=false;
            }
        }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;
}
