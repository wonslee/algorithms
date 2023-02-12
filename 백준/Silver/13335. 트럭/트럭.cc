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
    if ( current_number + 1 > W ) continue

    Q.push
    current_weight += truck[i]
    current_number ++;

# 복잡도 검증
 O(n^2) --> 1000000
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int n,W,L;
int truck[1001];
deque<int> Q; // 다리위의 트럭들 큐
int cnt, time_count;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> W >> L;
    for (int i = 0; i < n; ++i) cin >> truck[i];

    Q.resize(W);

    while (cnt < n) {// LOOP: 들어간 트럭수가 n이 될때까지
        time_count++;
        Q.pop_front();

        int weight=0, number=0; // 현재 다리위에 있는 모든 트럭의 무게, 개수
        for (int j = 0; j < Q.size(); ++j) {
            weight += Q[j];
            if (Q[j] > 0)
                number ++;
        }

        // CONDITION: 무게, 다리길이를 초과한다면 패스.
        if (weight + truck[cnt] > L || number + 1 > W){
            Q.push_back(0); // 트럭이 없음을 표시
            continue;
        }

        Q.push_back(truck[cnt++]);

    }
    cout << time_count + W;
}