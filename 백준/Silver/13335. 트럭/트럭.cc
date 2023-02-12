/*
# 문제 재정의
 L을 넘지 않도록, 최대한 w에 근접하게 배열 원소를 밀어내는 문제.

 실제로 시간을 기다리는게 아니라 COUNT를 써야 할것 같다. 마지막 원소라면 w만큼 더한다던지.
 트럭이 언제 들어갔는지(다리의 어디 위치에 있는지)를 저장해야 할 듯.
 큐를 써야 하나? 트럭이 있지 않으면 0을 넣는식?

# 계획
 truck[n]
 time_count
 current_number

 LOOP(truck 모든 원소):
    time_COUNT ++
    IF Q.size() >0 : dequeue

    sum(Q) : 큐(현재 다리)의 모든 원소 값을 합하기.

    무게 우선, 그 다음 다리 길이와 트럭의 개수.
    if ( current_weight + truck[i] > L ) continue
    if ( current_number + 1 > w ) continue

    Q.push
    current_weight += truck[i]
    current_number ++;

# 복잡도 검증
 O(n^2) --> 1000000
# 회고
*/

// https://aerimforest.tistory.com/205
#include <bits/stdc++.h>
using namespace std;

int n, w, L, cnt, ans, weightSum;
int truck[1001];
queue<int> Q; // 다리위의 트럭들 큐

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> w >> L;
    for (int i = 0; i < n; ++i) cin >> truck[i];

    for(int i = 0; i < n; i++) {
        while(true) {// LOOP: 다리에서 트럭을 빼는 과정
            if(Q.size() == w) {// CONDITION: 다리가 꽉 찬 경우
                weightSum -= Q.front();
                Q.pop();// 맨 앞의 트럭 제거
            }
            // CONDITION: 무게가 정상인 경우 반복문 나감
            if(truck[i] + weightSum <= L) break;

            // 무게가 L을 넘는 경우
            Q.push(0);
            ans++;
        }
        Q.push(truck[i]); // 트럭 추가
        weightSum += truck[i];
        ans++;
    }

    cout << ans + w; // 마지막 트럭이 건너는 시간 w 더하기
}