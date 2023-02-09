/*
# 문제 재정의
 배열안에 특정 정수가 존재하는지 탐색하는 문제
 binary search를 이용해서 log n 복잡도로 풀어보자.

# 계획
 c++ STL binary_search 함수를 써보자.

 1과 0이니 boolean값을 출력하면 되겠다.

# 복잡도 검증
# 회고
*/


#include <bits/stdc++.h>
using namespace std;

int n,m,input;
int arr[100001];

bool bs(int target){// BINARY SEARCH: 배열이 이미 정렬되어있음을 가정
    int low=0, high=n;

    while (low != high) {
        int mid = (low + high) / 2; // index 중간값을 계속 구함

        if (target == arr[mid])
            return true;
        else if (target > arr[mid]) // 중간놈보다 클 경우, low index를 mid보다 위로
            low = mid + 1;
        else // 중간놈보다 작을 경우, high index를 mid보다 밑으로
            high = mid - 1;
    }

    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n); // SORT

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> input;
        cout << binary_search(arr, arr + n, input) << '\n';
    }

}