#include <stdio.h>

#define MAX 6

int main(){
    int original[MAX] = {1,1,2,2,2,8};
    int input[MAX];
    
    for (int i=0; i < MAX; i++){
        scanf("%d", &input[i]);
    }
      for (int i=0; i < MAX; i++){
        printf("%d ", original[i] - input[i]);
    }
}