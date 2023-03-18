/*
# 문제 재정의
 - 특정 공간안에 가능한 적은 개체수를, 특정 기간동안 한 가지 이상 존재하도록 한다.
 - 회의 문제가 떠오른다. 그땐 회의 종료시간에 대해 정렬한 다음 종료 시간이 같다면 시작시간에 대해 정렬했음.
    그리고 현재 시각을 저장하는 변수와 비교해가면서 그때 이후의 회의를 선택했다.
    이 문제에서는 중간에 비는 시간이 있어선 안 되므로, '현재 시각'에서 얼마나 일찍이든지간에 일단 겹치는 놈을 고르고 봐야함. 늦게 끝날수록 좋고
 - 3월~11월의 날짜들을 선형적으로 나열하고 싶은데 배열을 쓰면 되려나?
 - 두 조건을 만족할 수 없는 경우를 체크해야만 한다. 가장 일찍 피는 꽃의 시작시간과 가장 마지막에 피는 꽃의 종료시간.

# 계획
 날짜에 대해선 pair을 쓰자.

 1. 빨리 피는 순으로 꽃을 정렬
 2. 조건을 만족하지 않을 경우 0 출력


# 복잡도 검증
# 회고
 - https://codingnotes.tistory.com/168
 - 회의 문제 풀이 생각이 맞았따!
*/


#include <bits/stdc++.h>
using namespace std;
#define s first
#define e second

typedef pair<int, int> flower;
flower flowers[100005];
int n;
int sm, sd, em, ed; // 시작 날짜와 종료 날짜
int t = 301; // 현재 시간

int ans = 0; // 선택한 꽃의 개수

bool cmp1(flower f1, flower f2){// 꽃이 빨리 피는 순으로 정렬
    if(f1.s == f2.s) return f1.e < f2.e;
    return f1.s < f2.s;
}
bool cmp2(flower f1, flower f2){return f1.e > f2.e;} // 꽃이 늦게 지는 순으로 정렬

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sm >> sd >> em >> ed;
        flowers[i] = {sm * 100 + sd, em * 100 + ed};// 날짜는 대충 파싱해도 됨
    }

    sort(flowers, flowers + n, cmp2);   // 꽃이 늦게 지는 순으로 정렬
    if(1201 > flowers[0].e) {cout << 0 << "\n"; return 0;}    // 11월 30일 이후에 지는 꽃이 없으면 0 출력
    sort(flowers, flowers + n, cmp1);
    if(301 < flowers[0].e) {cout << 0 << "\n"; return 0;}    // 3월 2일 이전에 피는 꽃이 없으면 0 출력

    while (t < 1201) {// LOOP : 3월1일부터 11월 30일까지
        int nxt_t = t; // 이번에 추가할 꽃으로 인해 변경된 시간

        for(int i = 0; i < n; i++){// 배열 안에서 모두 탐색
            if(flower[i].X <= t && flower[i].Y > nxt_t) // CONDITION : 현재시간을 포함하되 가장 길게 유지되는 꽃
                nxt_t = flower[i].Y;
        }

        if(nxt_t == t){ // CONDITION : 시간 t에서 더 전진이 불가능한 경우.
            cout << 0;
            return 0;
        }

        ans++;
        t = nxt_t;
    }
    cout << ans;
}