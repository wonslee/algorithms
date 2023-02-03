/*
# 문제 재정의
 1~N 수열에서 수를 N/2개 선택하는 조합을 구하는 문제.
 중복은 없고, 조합이 완성되면 반대편 팀의 조합도 자동적으로 완성되기 때문에 사실상 가능한 조합의 수 /2 만 구하면 된다.

# 계획
 상태공간트리를 따져보자!
 N개, N-1개, ... 중의 하나씩을 선택해나가는 팩토리얼 선택 방식.

 문제는 반대편 팀의 조합까지 구하는 비효율성을 어떻게 제거하느냐이다.

 FUNCTION(idx):
    BASE CONDITION(idx==n/2):
        현재 조합의 능력치 값을 구하고, 경우에 따라 최소값 갱신

    LOOP(i=1 ~ N):
        CONDITION(v.empty() OR i > v.back()): ?? 조합의 절반만 구하는 방법?
            v.push(i)
            FUNCTION(idx+1)
            v.pop()

# 계획 검증
# 회고
 - https://cocoon1787.tistory.com/170
 - 상태공간트리에서부터 꼬였다.
 - visited[]를 쓸 생각을 못했고 N과M 형태에 매몰되어 있었다..
 - 'pos' 변수를 쓸 수 있다는걸 기억해두자.

 */


#include <bits/stdc++.h>
using namespace std;

int n;
int stat[21][21];
bool visited[22];
int ans=987654321;

void func(int idx, int pos){
    if (idx == n/2){// BASE CONDITION. 조합 완성
        int start=0, link=0;
        for (int i=1; i<=n; i++)// LOOP. 능력치 구하기
            for (int j=1; j<=n; j++){
                if(visited[i] && visited[j]) start += stat[i][j];
                if(!visited[i] && !visited[j]) link += stat[i][j];
            }

        int temp = abs(start - link);
        if (temp < ans)
            ans = temp; // 최소값 갱신
    }

    for (int i = pos; i < n; ++i) {// LOOP. 
        visited[i]=true;
        func(idx+1, i+1); // BACKTRACK
        visited[i]=false;
    }

}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> stat[i][j];

     func(0,1);
     cout << ans;
}
