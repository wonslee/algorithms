/*
# 문제 재정의
 - n개의 숫자쌍(w,v)들의 조합으로 k에 대해 가능한한 최대 v값을 만드는 문제
 - 그리디로는 불가능. w,v로 정렬을 하는식으로 하더라도 언제나 예외가 있음
 DP. 01 Knapsack 문제

# 계획

 1. 테이블 정의
    d[i][j] = 1번부터 i번 물건까지 j무게만큼 넣어봤을 때 가치합이 가장 큰 값
 2. 점화식
    d[i][j] = MAX( d[i-1][j], d[i-1][j-W[i]] + V[i] )
    배낭의 i번째 물건을 넣어본다고 생각하면 이해가 쉽다. i번째 물건을 넣고 남는 나머지 공간(무게)에 다른
 3. 초기값
    딱히 없음.

 마지막에 d[n][ ] 중에서 v 최소값을 구하자.
# 복잡도 검증
# 회고
 - https://cocoon1787.tistory.com/206
 - 01 Knapsack 유형을 알게 됨.
*/


#include <bits/stdc++.h>
using namespace std;
#define W first
#define V second

int n, k;
pair<int,int> bag[102];
int d[102][100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> bag[i].W >> bag[i].V;
    }

    for (int i = 1; i <= n; ++i) {// LOOP : 1~n 배낭의 모든 물건들에 대해
        for (int j = 1; j <= k; ++j) {// 1~k 모든 무게에 대해
            if (j >= bag[i].W) // j가 i번째 물건의 무게보다 크거나 같을 경우
                d[i][j] = max(d[i - 1][j], d[i - 1][j - bag[i].W] + bag[i].V);
            else
                d[i][j] = d[i - 1][j];
        }
    }

    cout << d[n][k];
}