/*
 # 문제 재정의와 추상화
 내림차순 정렬 문제. 사실 오름차순으로 정렬하고 출력시 반복문을 반대로 돌면 됨.
 입력값을 각 자릿수별로 int값으로 쪼개는 과정이 필요.

 # 문제 접근
sort 함수를 통해 정렬한 다음 반복문을 반대로 실행하자.

 1. 입력 : n (string)
 2. n을 쪼개 ascii 숫자 성질을 사용해 원래 값으로써 배열에 저장
 3. 배열을 sort
 4. 출력

 # 배운 점
 sort와 내림차순 정렬 요령.
 내림차순용 compare 함수를 만드는 방법, greater<> 임시 객체를 호출하는 방법이 있다.
 */

#include <bits/stdc++.h>
using namespace std;
vector<int> v; // 최대 1,000,000,000인 자연수의 각 자릿수가 담길 배열

// 내림차순용 compare 함수
bool compare(int x, int y){
    return x > y;
}
int main(){
    string n;
    cin >> n;
    // ascii 성질 이용한 빼기 연산 (숫자들은 49번째부터 시작)
    for (int i=0; i<n.length(); i++)
        v.push_back((int)(n[i] - 48));

    // sort
    sort(v.begin(), v.end(), compare);
    // print (내림차순)
    for (int element : v)
        cout << element;
}
