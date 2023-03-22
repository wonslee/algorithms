/*
# 문제 재정의
 N개를 만들 수 있는 최대 길이(정수).
 K = 10000, N = 1000000
 처음 K개중에서 최대값과 최소값을 구해야 하나?

 만약 N으로 나눈 값부터 시작해서 K를 순차적으로 돌면.. 잘못하면 2^31이어서 불가능

 조건을 만족하는 랜선 길이중에서 최대값을 구하자!

# 계획
# 복잡도 검증
# 회고
 - 이분탐색만큼은 다른 정렬 등 STL로 구현되어있는것과 달리 직접 구현하는 실력이 있어야겠다.
 - parametric search... 시야가 넓어진 느낌이다
*/

#include <bits/stdc++.h>
using namespace std;

int k, n;
int arr[10005];

bool decide(long long x){// 결정 함수 : 길이가 X일 때 랜선이 N개 이상일 수 있는지 여부
    long long cur = 0;
    for(int i = 0; i < k; i++)// 모든 k랜선을 나눈 몫을 더해줌 -> 랜선 개수
        cur += arr[i] / x;
    return cur >= n; // n개보다 크거나 같은지 결정!
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;

    for(int i = 0; i < k; i++)
        cin >> arr[i];

    long long st = 1;
    long long en = 0x7fffffff; // 2^31 - 1

    while(st < en){// binary search
        // 가장 끝에서부터 시작. 계속해서 mid쪽으로 땡겨옴
        long long mid = (st+en+1)/2; // (st+en+1)/2로 계산할 때 st+en이 int 범위를 넘어갈 수 있습니다. 그래서 그냥 마음 편하게 st, en, mid 모두 long long으로 뒀습니다.

        if(decide(mid))
            st = mid;
        else en = mid-1;
    }
    cout << st;
}