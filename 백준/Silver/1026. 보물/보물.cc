/*
# 문제 재정의
 A는 작은값 순으로, B는 큰 값 순으로 정렬한 뒤에 각 index마다 곱해주면 될 듯?
 B를 재배열하지 말라고 했지만 얘네가 어떻게 알아

 명제 : 큰 수와 큰 수끼리 곱해질수록 총합이 커진다. 따라서 수가 클 수록 작은수와 곱해줘야 총합이 가장 작아진다.
# 계획
 - A,B sort
 - LOOP : 각 자릿수 곱한 값을 더해나가기
# 복잡도 검증
 모든 조합을 다 구하는 브루트포스는 50!이라 불가능.
 
  O(n)
# 회고
 - n <= 50 이라서 굳이 그리디를 안 써도 될듯? DP를 쓰면 어떨까..?
*/


#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[52], b[52];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    // SORT: A는 작은 순으로, B는 큰 순으로
    sort(a, a + n);
    sort(b, b + n, greater<>());

    for (int i = 0; i < n; ++i) {
        ans += a[i] * b[i];
    }

    cout << ans;
}