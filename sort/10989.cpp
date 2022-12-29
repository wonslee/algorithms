/*
# 문제 재정의와 추상화
말 그대로, N개의 수를 오름차순 정렬한 결과를 출력한다. 
같은 타입의 데이터 나열. 그 배열을 정렬

# 첫번째 문제 접근
배열에 저장한 다음 정렬하면 되는 문제.
문제에서 요구한 메모리 제한은 8MB. 
1000000 * 4 byte = 4MB다. 

merge sort를 썼을 때 같은 길이의 배열을 2개 갖고 있어야 하므로 메모리 초과가 나올 수 있겠다. 
quick sort를 써보자.

## 로직
1. 입력 : n
2. loop(n) : 배열 생성
3. 퀵 정렬
4. loop(n) : 각 원소들 출력

## Quick Sort
합병 정렬과 마찬가지로 분할정복 기법을 이용하는 정렬.
pivot을 기준으로 배열을 쪼갠 다음(partition)
pivot보다 작은 원소는 왼쪽, 큰 원소는 오른쪽으로 swap되도록 한다.

## 결과: 메모리 초과
으음? 왜지?
다시 살펴보니 0을 하나 빼먹었다...

# 두번째 문제 접근
- 참고 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=vjhh0712v&logNo=221466898588
10000000 * 4 byte = 40MB다. 
즉, n 사이즈의 배열을 만드는 순간 이 문제는 실패.

입력값의 조건이 특이했다.
입력되는 수의 범위는 10,000보다 작거나 같은 자연수.

그렇다면 값에 범위에 대한 배열을 만들어서, 각 값의 카운터를 증가시켜주고 카운터만큼 출력해주면 되는 아주 간단한 문제가 되었다.
즉 배열의 index를 각 값이라고 치고, 거기에 담긴 count를 저장하는 식.
어차피 오름차순이니까!

1부터 10000이므로, 배열의 특성상 0번째는 안 쓰인다. 그러니 상수 RANGE는 10001로 설정.

# 배운 점
솔직히 quick sort 알고리즘 복습하려고 푼 문제였는데, quick sort에 갇혀서 단순한 걸 못 본 것 같다.
원소의 값 범위가 좁게 한정되어있는 상황, 그리고 메모리가 한정되어있는 상황에선 count라는 놀라운 개념을 쓰도록 하자.
*/
#include <iostream>
#define RANGE 10001

int count[RANGE];

int main(){
    int n, value; 
    scanf("%i", &n);
    for (int i=0; i<n; i++){
        scanf("%i", &value);
        count[value] ++;      // increment count
    } 

    // 각 count만큼 value를 출력
    for (int i=0; i<RANGE; i++)
        while (count[i] --)
            printf("%i\n", i);
}
