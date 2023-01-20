/*
# 문제 재정의
 원형 큐의 구현, 이동 횟수 문제.

# 계획
 원형 큐를 직접 구현?

# 계획 검증


# 회고
 - deque의 push_back, pop_back 메서드로 원형큐를 구현하는 방법을 배웠다.
 - 원형큐를 deque으로 구현할 때, front에 가까운지 rear에 가까운지 판별하는 조건문을 짜는데 미흡했다.
 */

#include <bits/stdc++.h>
using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, index, num, cnt=0;
    // 원형 큐
    deque<int> dq;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        dq.push_back(i);

    while (m--){
        cin >> num;

        for (int i=0; i<dq.size(); i++)
            if (dq[i]==num){
                index=i;
                break;
            }

        // CONDITION : front와 가까울 경우 move left, rear과 가까울 경우 move right. front에 있을 경우 pop_front
        if (index < dq.size() - index) {
            // 숫자 찾을 때까지 왼쪽으로 한칸씩 이동
            while (dq.front() != num) {
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front(); // 찾았으면 dequeue
        }
        else {
            // 숫자 찾을 때까지 오른쪽으로 한칸씩 이동
            while (dq.front() != num){
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.pop_front(); // 찾았으면 dequeue
        }
    }

    cout << cnt;
}