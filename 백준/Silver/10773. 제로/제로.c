/*
입력
첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)
이후 K개의 줄에 정수가 1개씩 주어진다. 
정수는 0에서 1,000,000 사이의 값을 가지며, 
정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.

출력
재민이가 최종적으로 적어 낸 수의 합을 출력한다. 2^31-1보다 작거나 같은 정수이다.


문제접근
stack을 써야 하는 이유는, 가장 최근에 쓴 수를 지우는 LIFO 방식이기 때문.
array나 linked list 모두 가능.
여기선 linked list로 구현해봄

logic.
1. data: int K, input, sum, struct StackNode {int value, struct StackNode *link}, StackNode *head
2. operations: push, pop (, isEmpty)
3. loop: K만큼, 각 줄에 주어지는 input에 대한 분기처리
    3-1. input값이 0일 경우, pop
    3-2. input값이 0이 아닐 경우, push(input)
4. loop: Stack의 끝까지, 합을 연산
5. 합을 출력
*/
#include <stdio.h>
#include <stdlib.h>

// type definition
typedef struct StackNode{
    int value;
    struct StackNode*link;
}SNode;

SNode *head;

// operations
void push( int value){
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->value = value;
    newNode->link= head;
    head = newNode;
}

void pop(){
    if (head==NULL)
        exit(1);

    SNode *temp = head;
    head = head->link;
    free(temp);
}

int sumAll(){
    int result=0;
    SNode *copy = head;
    
    while(copy !=NULL){
        result+= copy->value;
        copy = copy->link;
    }
    return result; 
}

int main(){
    int K, sum;
    scanf("%i", &K);
    // K만큼 반복. 재민이가 적어내는 수들을 스택에 저장
    for (;K>0; K--){
        int input;
        scanf("%i", &input);
        // input이 0일 경우 pop, 0이 아닐 경우 push 
        if (input == 0)
            pop();
        else 
            push(input);
    }
    // 결과 출력
    printf("%i", sumAll());
}