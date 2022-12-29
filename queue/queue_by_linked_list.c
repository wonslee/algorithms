#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* linked list queue ADT
 *
 * 생성             : struct of linked list (struct of pointers to node)
 *                  node 구조는 linked list와 완전히 같다.
                    queue 구조를 반영하기 위해 stack과 달리 top이 아닌 front, rear을 쓴다.
 * 공백 조건        : front = rear = NULL (pointer)
 * enqueue(q,item)  :   1. node 생성 (dynamic allocation, item, link = NULL)
 *                      결국 큐이므로, 새 노드는 마지막 자리가 되어야 하므로 link는 NULL
 *                      2. 공백 검사
 *                      공백일 경우, 유일한 노드가 되므로 front = rear = new
 *                      일반적인 경우, 마지막 노드의 link = new, rear = new
 *                          front에는 변화 없고, 항상 rear을 통해 link를 바꾸고 rear만 바꿈.
 * dequeue(q)       :   1. 메모리 해제 목적의 새로운 pointer old로 첫번째 노드 지정 (front)
 *                      front 포인터는 queue개념상 절대 삭제되선 안되니까.
 *                      2. 공백 검사. 공백일 경우 exit
                        3. pointer front를 한칸 뒷 노드로 설정
 *                      4. 마지막 노드였던 경우, pointer rear을 NULL로 설정
 *                      5. old가 가리키는 노드 메모리 해제 (free)
 *
 * 특이사항         : linked list이므로 포화상태는 없다. link에 집중하면 된다. */

typedef char element;
/* create queue */
typedef struct QueueNode{
    element data;
    struct QueueNode *link; 
}QNode;

typedef struct {
    QNode *front, *rear;
}LinkedListQueue;

LinkedListQueue *createQueue(){
    // ?? malloc 안 하면 에러난다.
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool isEmpty(LinkedListQueue *LQ){
    return (LQ->front == NULL);
}

void enqueue(LinkedListQueue *LQ, element item){
    // dynamic allocation
    QNode *newNode = (QNode *)malloc(sizeof(QNode));

    // initialize
    newNode->data = item;
    newNode->link = NULL;
    // 조건 : 공백일 경우와 아닌 경우
    if (isEmpty(LQ)){
               LQ->front = newNode;
               LQ->rear = newNode;
    }else{
        // 순서 중요
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

element dequeue(LinkedListQueue *LQ){
    // pointer old 생성
    QNode *oldNode=LQ->front;

     // 조건 : 공백일 경우와 아닐 경우
    if (isEmpty(LQ)){
        printf("empty!");
        exit(1);
    }
        element item=LQ->front->data;

    // front가 뒷 노드를 가리키도록
    LQ->front= LQ->front->link;
    // 큐가 공백이 된 경우 rear=NULL  --> front=rear=NULL (공백상태)
    if (LQ->front == NULL){
        LQ->rear = NULL;
    }

    free(oldNode);
    return item;
}

void printQueue(LinkedListQueue *LQ){
    printf("\n front ");
    for (QNode *p=LQ->front; p!=NULL ; p=p->link){
     printf(" ---> [ %c | %p ]", p->data, p->link);
     if (p==LQ->rear)
         printf(" <-- rear");
    }
}

int main(){
    LinkedListQueue *myQ = createQueue();

    enqueue(myQ, 'A');
    printQueue(myQ);
     enqueue(myQ, 'B');
    printQueue(myQ);
 enqueue(myQ, 'C');
    printQueue(myQ);

 dequeue(myQ);
    printQueue(myQ);
        enqueue(myQ, 'D');
    printQueue(myQ);
     enqueue(myQ, 'E');
    printQueue(myQ);
 enqueue(myQ, 'F');
    printQueue(myQ);

 dequeue(myQ);
    printQueue(myQ);
 dequeue(myQ);
    printQueue(myQ);
 dequeue(myQ);
    printQueue(myQ);
 dequeue(myQ);
    printQueue(myQ);
     dequeue(myQ);
    printQueue(myQ);
         dequeue(myQ);
    printQueue(myQ);
}
