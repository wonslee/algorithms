/* 8957 OX 퀴즈
문제
OX퀴즈의 결과가 있다. 
문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 
"OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있고, 길이가 0보다 크고 80보다 작은 문자열이 주어진다. 
문자열은 O와 X만으로 이루어져 있다.

출력
각 테스트 케이스마다 점수를 출력한다.

문제접근
특이한 점은 '연속된' O의 개수라는 것.
총합을 저장할 변수도 필요하지만, 이때까지 얼마나 연속되었는지를 저장할 변수도 필요하다.

1. data: int sum, serial, N, char *row
2. loop: for N, 각 serial에 대한 점수를 계산하는 과정..
    3. loop: for length of row(string), 각 알파벳(O,X)에 대한 분기 처리..
    3-1. if O , sum을 serial만큼 더하는 동시에 serial을 1 증가
    3-2. if X , serial을 0으로 초기화
    3-3. if \0 (string의 마지막), 점수인 sum 출력(줄바꿈)

막힌 부분
scanf한 row가 null값?
string에 대한 printf에 대한 개념이 덜 잡혀있었음..
선언할 떄 *보다는 []가 안정적.
*/
#include <stdio.h>

int main(){
    int  n;
    scanf("%i", &n);

    // loop: n번만큼, 각 row의 결과를 계산
    for (int i=0; i<n; i++){
        int sum=0, serial=0;
        // 문제조건 : 80보다 작은 문자열
        char row[80]; 
        scanf("%s", row);
        // loop: row의 length만큼, 각 알파벳의 값에 따라 serial과 sum을 연산
        for (int j=0; row[j] != '\0'; j++){
            if (row[j] == 'O')
                sum += ++serial;
            else
                serial = 0;
        }
        printf("%i\n", sum);
    }
    return 0;
}