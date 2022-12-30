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