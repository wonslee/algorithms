/*
# 문제 재정의
 배열에서 숫자찾는 문제.
 COUNTING 배열을 써도 될거같고 그냥 반복문을 돌아도 될 것 같다.
# 계획
 카운팅 배열을 쓴다고 할 때, 배열의 길이는 20000001 이상이어야 한다. 그리고 접근할 때는 10000000을 더한 수를 찾아야 함.
# 복잡도 검증
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int n,m,input;
int arr[20000005]; // COUNTING 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        arr[input+10000000]++;
    }

    cin >> m;
    while (m--) {
        cin >> input;
        cout << arr[input+10000000] << ' ';
    }
}