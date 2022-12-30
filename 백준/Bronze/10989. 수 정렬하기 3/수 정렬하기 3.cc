#include <iostream>
#define RANGE 10001

int count[RANGE];

int main(){
    int n, value; 
    scanf("%i", &n);
    for (int i=0; i<n; i++){
        scanf("%i", &value);
        count[value] ++;      // increment count
    } 

    // 각 count만큼 value를 출력
    for (int i=0; i<RANGE; i++)
        while (count[i] --)
            printf("%i\n", i);
}