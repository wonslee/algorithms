#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

const char password[11] = "ILOVEYONSEI";

// ASCII 성질 이용해서 빼기 연산. 
int distance(int next, char current){
	int result = abs(password[next] - current);
	return result;
}
int main() {
	char input;
	scanf("%c", &input);
	int sum = 0;

	// 첫번째엔 input 과 0번째를 비교
	sum += distance(0, input);
	for (int i = 1; i < 11; i++) {
		sum += distance(i, password[i-1]);
	}
	
	printf("%i\n", sum);
	return 0;
}