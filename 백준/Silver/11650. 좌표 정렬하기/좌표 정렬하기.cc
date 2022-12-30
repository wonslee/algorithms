/*
 # 문제 재정의와 추상화
숫자 x,y의 쌍 (x,y)를 x순으로, 그 다음으로 y순으로 정렬.
우선 x끼리 정렬을 마친 다음, y에 대해서 한 번 더 정렬한다.

 # 문제 접근
 우선 쌍(x,y)을 하나의 원소로 갖는 배열을 주 데이터로 써야 한다.
 x가 크거나, x가 같고 y가 큰 2가지 경우를 기준으로 sort가 이뤄져야 한다.

 하나의 수로 string처럼 연결하는 방법을 생각해보면 일단 수의 범위가 너무 크고, 음수 때문에 불가능.

 sort함수를 쓰되, compare 함수에서 point의 x,y에 접근해서 비교하는 분기처리 과정이 필요해보인다.

 # 계획 검증
 ## 입력값 다시보기
 x,y는 절댓값 100000이하의 정수이므로 int로 커버 가능.

 ## 시간 복잡도
 c++ sort는 최악의 경우 O(N log(N)) 복잡도를 갖는다.
 그리고 이는 대략 N <= 1000000까지 1초안에 수행 가능하므로
 ## 공간 복잡도
 struct를 제외하고 생각할 때, int 2개씩 100000개 배열에 들어있으니, 800000byte = 0.8MB

 # 배운 점
 - 나중에 더 큰 객체들을 정렬해야할 때가 생기면, 이런 sort와 분기처리가 유용하겠다.
 - 왜 처음에 정렬을 두번 해야한다고 생각했을까? struct로 x,y를 묶는다는 생각과 sort는 무조건 int를 비교해야 한다는생각에 갇혀 있었던 것 같다.
 - pair<>을 쓰는 방법도 있다. compare함수도 필요 없이, sort에서 알아서 pair에 대한 sort를 해주네!
 */

#include <bits/stdc++.h>
using namespace std;

// vector of points
vector<pair<int, int>> v;

int main(){
    int n, x, y; scanf("%i", &n);
    // input
    for (int i=0; i<n; i++){
        scanf ("%i %i", &x , &y);
        v.push_back({x,y});
    }

    // sort
    sort(v.begin(), v.end());

    // output
    for (int i=0; i< n; i++)
        printf("%i %i\n", v[i].first, v[i].second);
}