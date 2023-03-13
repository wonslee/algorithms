/*
# 문제 재정의
 - 경우의 수 문제. 백트래킹이냐 그리디냐.. 100000이면 백트래킹은 어렵겠다.
 - 그리디. 가장 일찍 시작하면서 짧은 회의들을 고르면 되려나?
 혹은 y(끝나는 시간)순으로 정렬하거나 y-x 순으로 정렬하는게 나을 수도.
# 계획
    1. sort : y-x순, x순으로 정렬
    2. 첫번째 원소 방문, pos = 첫번째.y
    3. LOOP():
        IF(pos보다 큰 x값이 없을 경우) 종료
        정렬된 순으로 방문. 단, x값이 pos보다 큰 놈들만

# 복잡도 검증
# 회고
*/


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, pos, cnt;
pair<int,int> arr[100002];

bool comp(pair<int,int> p1, pair<int,int> p2) {
    bool result = p1.Y < p2.Y;
    if (p1.Y == p2.Y) { // 진행시간이 같은 경우, x순으로 정렬
        result = p1.Y - p1.X > p2.Y - p2.X;
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].X >> arr[i].Y;
    }
    sort(arr, arr + n, comp);

    for (int i = 0; i < n; ++i) {
        if (pos > arr[i].X) continue;

        cnt++; // 방문
        pos = arr[i].Y;
    }

    cout << cnt;
}