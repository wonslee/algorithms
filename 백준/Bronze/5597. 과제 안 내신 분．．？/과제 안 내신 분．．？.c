#include <stdio.h>
#define LENGTH 30

int main() {
  int input, array[LENGTH] = {0}; // count?

  for (int i = 0; i < LENGTH - 2; i++) {
    scanf("%d", &input);
    array[input - 1] = input;
  }

  for (int i = 0; i < LENGTH; i++) {
    if (array[i] == 0) 
        printf("%i\n", i+1);
  }
}