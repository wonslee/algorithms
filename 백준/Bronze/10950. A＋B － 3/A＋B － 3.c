#include <stdio.h>

int main(){
    int n; scanf("%i", &n);
    while (n--){
        int a, b; scanf("%i %i",&a, &b);
        printf("%i\n", a+b);
    }
}