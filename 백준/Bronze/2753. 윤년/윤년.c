#include <stdio.h>

int isYoon(int year){
    return ( (year % 4 ==0 && year % 100!= 0) || year % 400 ==0 );
}
int main(){
    int n;scanf("%i", &n);
    printf("%i", isYoon(n));
}