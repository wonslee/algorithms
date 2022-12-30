#include <stdio.h>

int main(){
    int N, count=0;
    scanf("%i", &N);
    
    while (N--){
        int input;
        scanf("%*c%*c%*c%i", &input);
        if (input <= 90) count++;
    }
    printf("%i", count);
}