/*
# 문제 재정의
 길이 상관없이(1이상 N이하) 모든 부분수열에 대해 합이 S가 되는 경우의 수를 구하는 문제.
 부분집합의 성질을 이용해서 상태공간트리를 떠올려 풀어야 한다.

# 계획
# 계획 검증
# 회고
 - https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0C/solutions/1182.cpp
 - 접근 자체가 틀렸다. visited 혹은 isused 에 매몰됐다. 반복문이 없어도 상태공간트리(순열과 조합)를 만든다면 백트래킹이란 점을 배웠다.
 - 원소가 n개인 집합에서 부분집합의 개수는 2^n. (e.g. {1,2,3} : {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3})
 이 문제조건상 공집합을 빼면 2^n -1개의 조합에 대해 합이 S와 일치하는지를 보면 된다.
 - 함수 내에서 i번째 수를 더할지 말지 정하고, i+1번째 수를 정하러 한 단계 더 들어간다고 생각하자.
 - 상태공간트리를 각 조합의 합으로 생각하자. 그리고 서브트리를 나누는 분기점은 '다음 수를 고르냐 고르지 않냐'이다.
 즉 매순간 수를 더할지, 더하지 않을지 선택하는 방법으로 모든 부분수열의 합을 뽑아낼 수 있다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, s, M;
int cnt=0;
int arr[20]; // 입력될 수열

void func(int cur, int tot){
    if(cur == n){// BASE CONDITION. n만큼 '선택'했다면 종료. 만약 조합의 합(tot)이 S와 같다면 count +1
        if(tot == s) cnt++;
        return;
    }
    // BACKTRACK. tot에다가 arr[cur]을 더하냐, 더하지 않냐의 분기를 나눈다. 상태공간트리를 떠올리자!
    func(cur+1, tot);
    func(cur+1, tot+arr[cur]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    func(0,0);

    if (s==0) // CONDITION.
        cnt --;
    cout << cnt;
}