#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
* 입력
첫 번째 줄에 정수 a와 b가 공백으로 구분되어 주어집니다.

출력
몬스터에게 대미지를 줄 수 있으면 1, 그렇지 않으면 0을 출력해 주세요.

float a,b;
a / b 가 100보다 크거나 같은지에 대한 boolean값 출력 
*/
int main() {
	float a, b;
	scanf("%f %f", &a, &b);

	double rate = a - a * b / 100 ;
	printf("%i", rate < 100);
	return 0;
}
