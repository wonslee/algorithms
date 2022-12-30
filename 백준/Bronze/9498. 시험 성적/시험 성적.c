#include <stdio.h>

int main(){
    int input;
    scanf("%i", &input);

    if (input<101 && input >=90) printf("A");
    else if (input >=80 && input <90) printf("B");
    else if (input <80 && input >=70) printf("C");
    else if (input <70 && input >=60) printf("D");
    else printf("F");
}