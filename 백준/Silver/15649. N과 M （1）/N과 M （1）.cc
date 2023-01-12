/* 15649. N과 M
 
 # 문제 재정의
 조합과 관련된 문제. nCk. n! / k!(n-k)! 개의 경우가 나온다. 그러나 이건 모든 경우의수를 출력하는게 조건.
 무식하게 풀기와 연관이 있는 것 같다.
 --> back tracking 문제다.

 # 계획
 반복문 여러개 안에서, i와 j를 M개만큼 고르도록 하면 될 것 같다.
 반복문을 M개만큼 실행해야 하나?

 뭔가, 중복되는 부분수열들이 뒤에 남은 숫자의 개수만큼 나온다. 재귀함수?

 # 계획 검증
 ## 시간 복잡도
 ## 공간 복잡도
 # 회고
 - 백트래킹에 대해 배웠다. 백트래킹이란 현재 상태에서 가능한 모든 후보군들을 따라 들어가며 탐색하는 알고리즘. https://www.youtube.com/watch?v=Enz2csssTCs&list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY&index=13&t=8s
 - 반복문 속에서 재귀호출을 하니 정신을 못 차리겠다. 계속 틀려가면서 배워야겠다.
 */

#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10]; // 매 줄 출력될 수열을 담을 배열
bool is_used[10]; // 특정 수(1~9)가 쓰였는지 여부의 배열

// func(k) : k 직전까지의 수를 택한 상태에서 arr[k]를 정함.
void func(int k){
//    cout << "k = " << k << ' ';
//    cout << "arr : ";
//    for (int i=0; i<10; i++)
//        cout << arr[i] << ' ';
//    cout << "\tis_used : ";
//    for (int i=1; i<=10; i++)
//        cout << is_used[i] << ' ';
//    cout << '\n';

    if(k == m){ // 기저사례. m개를 모두 택했으면 출력 후 종료
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
        cout << '\n';
        return;
    }

    // 핵심. 1부터 n까지의 수에 대해 재귀호출하고, 재귀함수 내에서 또 반복문 실행. --> 상태공간트리 대로 순서 만들게 됨.
    for(int i = 1; i <= n; i++)
        if(!is_used[i]){ // 아직 i가 사용되지 않았으면
            arr[k] = i; // 핵심. k번째 수를 i로 정함
            is_used[i] = true; // i를 사용되었다고 표시
            func(k+1); // 재귀호출. 다음 수를 정하러 한 단계 더 들어감
            is_used[i] = false; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
            // arr[k]는 초기화할 필요 없음.
        }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}