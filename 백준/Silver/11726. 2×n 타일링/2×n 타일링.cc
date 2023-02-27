/*
# 문제 재정의
 DP 문제. 점화식 찾자!
# 계획
 1. 테이블 정의
    D[i] = n값이 i일 때의 직사각형 채우는 방법의 수.
 2. 점화식 찾기
    D[1]=1 D[2]=2 D[3]=D[2]+1 D[4]=D[3]+2 D[5]=D[4]+2=7 D[6]=...
    D[i] = D[i-1] + 첫째칸에 1x2(가로) 두개를 넣고 나머지를 채우는 방법의 수
    = D[i-1] + D[ (i-2) ]
 3. 초기값 정하기
    점화식에서 i-2까지 도니까 2번째까진 넣어줘야함.
    D[1]=1, D[2]=2, D[3]=3

# 복잡도 검증
# 회고
*/
#include <bits/stdc++.h>
using namespace std;

int n;
long D[1002]; // 점화식 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;

    // INITIAL
    D[1] = 1, D[2] = 2;

    for (int i = 3; i <= n ; ++i) {
        D[i] = ( D[i - 1] + D[i - 2] ) % 10007; // 10007 나머지를 넣어줌.
    }

    cout << D[n];
}