// written by WONSEOK LEE 17007149, USW C LANGUAGE CLASS
// ON 04TH OCTOBER 2022 22:18

#include <stdio.h>
int count = 0;
int fibonacci(int n) {
    count ++;
    if (n<=1)
        return n;
    else 
        return (fibonacci(n-1) + fibonacci(n-2));

}

int main() {
  fibonacci(12);
    printf("count=%i\n", count);

}
