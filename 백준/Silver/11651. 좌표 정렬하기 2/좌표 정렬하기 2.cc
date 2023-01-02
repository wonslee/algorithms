/*
2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬
 # 문제 재정의와 추상화
 변수가 2개인 정렬 문제. 우선순위를 y, x순으로 정렬하면 된다.
 # 문제 접근
 compare 함수에서 y가 큰 경우 혹은 y는 같고 x는 큰 경우를 비교를 하거나
 vector의 원소를 pair<>로 만들어 sort함수를 쓰면 된다.
 # 계획 검증

 ## 입력값 다시보기
 x,y는 절댓값 100000이하로 int범위 충족.

 ## 시간 복잡도
 시간 제한 1초에 입력값 N=100000이므로 O(N^2)로는 불가능하다. O(N log N) 알고리즘으로 풀어야 함.
 merge sort, heap sort 등이 있고, c++ sort로 구현 가능하다.

 ## 공간 복잡도
 int 2개 쌍이 100000개 배열에 담기므로 800000byte = 0.8 MB
 # 배운 점

 */

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main(){
    int n, x, y;
    cin >> n;
    while (n--){
        scanf("%i %i", &x , &y);
        // y에 대해서 먼저 sort 우선순위 갖도록 pair 구성
        v.push_back({y,x});
    }
    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++)
        printf("%i %i\n", v[i].second, v[i].first);
}