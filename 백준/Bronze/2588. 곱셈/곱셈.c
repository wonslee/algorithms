#include <stdio.h>

// 야매 pow 함수. 양의 정수 혹은 0만 연산 가능
int poww(int x,int y ){
    int result =1;
    if (y > 0)
        while (y--)
            result *= x;
    return result;
}

int main(){
    int input1,input2;
    scanf("%i %i", &input1, &input2);
    
    // pow(10, 자릿수-1)로 나눈 다음에 10으로 나눈 나머지.
    for (int i=0; i<3; i++){
        int operand = input2 / poww(10, i) % 10;
        printf("%i\n", input1 * operand);
    }
    
    printf("%i", input1 * input2);
}