/*
# 문제 재정의
 그냥 오름차순으로 정렬하면 되는 문제.

 정렬한 다음에 야무지게 인출시간의 합을 구하는 방법은 없나?
# 계획
 1. 오름차순 정렬
 2. LOOP(n): 인출 시간 합 구하기
# 복잡도 검증
 O(n) : 1000
# 회고
 - 풀고보니 DP랑 비슷.. d[i] = i번째 놈의 인출시간.
*/


#include <bits/stdc++.h>
using namespace std;

int n, summ;
int arr[1002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        summ += arr[i];
    }

    cout << summ;
}