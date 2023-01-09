/*
 * 요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가
주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로
이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될
때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고
한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 1,000)

출력
예제와 같이 요세푸스 순열을 출력한다.


문제접근
요세푸스 문제부터 이해하자.
'순서대로 K번째'라는건 'K번째로 건너간다'는 뉘앙스로 이해해야 한다.
1. K가 3이라고 할 때 3, 6이 제거되고
2. 다음의 줄어든 인원들속에서 6부터 3번째인 2, 7이 제거되고
3. 7부터 3번째인 5
4. 5부터 2번 건넌 1이 제거된다.


리스트와 index, 제거 로직이 있으면 될 듯.
그러나 제거하면서 계속 한칸씩 움직여야 하고, 배열의 길이를 알고 있어야 한다.

큐의 제거에 유리한 방법은 linked list! 그리고 순환되도록!
일단 N만큼 node를 만든 다음, pointer rear가 마지막 node,
마지막 node가 첫번째 node (front)를 가리키도록 구현.

그러면 제거해가면서 index를 3씩 앞으로 나아가도 별다른 데이터 변경이 필요없다.

1. 입력: N
2. loop(N): N만큼 node 생성해서 linked list 완성
3. loop(하나만 남을 때까지):
3-1. 3씩 건너가면서 node 제거
4. 출력: 마지막 노드의 값

데이터:
int 사람수 N
int 양의 정수 K (<=N)
typedef struct Node{
    int number
    Node *link
} 각각의 사람 (노드)
노드 *front, *rear

하나만 남는 조건: front->link = front (자기자신을 포인팅)

제거(int K):
K번째 건너간 다음에 노드를 삭제
K-1번째 노드->link = 삭제될 K번째 노드->link
free(삭제될 노드)
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int n, k, i=1; // 사람 수, k번, index변수는 1부터
	scanf("%d%d", &n, &k);
	bool dead[n+1]; 
    for(int i = 1; i<=n; i++) dead[i]=false; //요소들 false로 초기화


	int count_dead = 0; //N번 다 제거 되면 종료
	int count_k = 0; //k번째마다 수를 제거
	
    printf("<");
	while(1){
        // 아직 제거되지 않은 놈을 거칠때마다 k 카운트 증가
		if(dead[i] == false) count_k++; 
        // 아직 제거되지 않은 k번째 수를 제거
		if(dead[i] == false && count_k == k) {
			count_k = 0;    // k 카운트 초기화
			dead[i] = true; // 제거 표시
			count_dead++;
			if(count_dead == n) { //다 제거시 while 종료
				printf("%d>", i);
				break;
			}
			printf("%d, ", i); //제거된 수 출력
		}
		i++;
		if(i>n) i -= n; // 순환되도록 index 초기화
	}
    return 0;
}
