/* 10871 X보다 작은 수 
정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.

입력 : 첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10,000)
둘째 줄에 수열 A를 이루는 정수 N개가 주어진다. 주어지는 정수는 모두 1보다 크거나 같고, 10,000보다 작거나 같은 정수이다.
출력 : X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다. X보다 작은 수는 적어도 하나 존재한다.

문제접근
1. 데이터 : array A (길이는 N), 정수 X
2. 반복문 : 길이 N을 모두 순회하도록
3. 조건문 : X와 array[i]의 값 비교, X보다 작을 경우 출력 
*/

#include <stdio.h>

int main(){
    int N, X;
    scanf("%d %d", &N, &X);
    int array[N];
    
    for (int i = 0; i<N; i++)
        scanf("%d", &array[i]);
    
    for (int i = 0; i<N; i++)
        if (array[i] < X)
            printf("%d ", array[i]);

    return 0;
}