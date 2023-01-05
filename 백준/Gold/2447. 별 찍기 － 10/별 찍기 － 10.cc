/*
 N이 3보다 클 경우 (N/3) * (N/3) 정사각형을 둘러싸는 형태.
 N=3^k, 1 <= k <8

 # 문제 재정의와 추상화
 말 그대로 재귀. 둘러싸는 형태가 반복적으로 나타나야 한다.
 기본적으로 단계들을 하나씩 쪼개서 다루자.
 1. 마지막 한 단계를 명시(더 이상 재귀호출하지 않도록)
 2. n에서 한 단계만큼 빼서 인자로 전달, 재귀호출

 # 계획
 기본 단위는 n=3일 때다!
 ***
 * *
 ***

 이 패턴을 만족시키기 위해서, 공백이 어디에 들어가야할지를 알아야 한다.
 결국 n*n사각형의 모든 (i,j) 마다, 얘가 별인지 공백인지를 결정
 일단 n에 비례할거같다는건 알겠는데, 그 식을 바로 짜긴 어려워서 n에다 여러 수를 대입해본다.

 n=3일 때 (1,1)
 규칙을 만족시키기 위한 조건은 i % 3 == 1 && j % 3 == 1.
 n=9일 때 (3,3) (3,4) (3,5)  (4,3) (4,4) (4,5)  (5,3) (5,4) (5,5)
 규칙을 만족시키기 위한 조건은 (i/3) % 3 == 1 && (j/3) % 3 == 1.

 결국 가운데가 비어있다는 같은 규칙을 띈다!

 n=27일 때도 같은 패턴으로 (9,9) ~ (17,17)
 조건은 (i/9) % 3 == 1 && (i/9) % 3 == 1.
 이런 패턴의 반복을 재귀로 짜면 된다.

 # 계획 검증
 ## 시간 제한

 ## 메모리 제한

 # 회고
 - 문제 접근 실패.
 - 재귀의 기본 단위(단계)를 캐치하는 능력이 부족.
 - 접근 자체가 어려울 땐, 실제 값(여기선 3,9, ...)을 대입해보면서 패턴을 찾아보자.
 - 좌표값 표현 i,j과 비어있는 좌표들에 대한 규칙을 세울 생각을 했어야 했다.
 */

#include <bits/stdc++.h>
using namespace std;

// 전제 : n은 3의 배수인 자연수.
void star(int i, int j, int n){
    // 핵심. 중간이 비어있는 패턴을 만들기 위한 조건
    if((i / n)%3 == 1 && (j / n)%3 == 1)
        cout << ' ';
    else{
        // 기저사례 : 기본단위(n=3)에서 재귀호출하여 n=1인 경우 (3/3 =1).
        // 별 출력. 즉 기본단위를 이루는 별들이 찍히는 단계.
        if(n < 3)
            cout << '*';
        // n이 3보다 크거나 같은 (3의 배수인) 경우. n/3을 인자로 한 재귀호출. i와 j는 그대로.
        else
            star(i,j,n/3);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;

    // 2중 loop: n * n 사각형에서 모든 칸에 대해서 함수 호출
    // 비어있거나 별을 출력하는 경우는 재귀 없이 함수가 끝난다.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            star(i,j,n);
        // 한 열(i)이 끝났을 때 줄 바꿈
        cout << '\n';
    }
}
