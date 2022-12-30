#include <stdio.h>

int main() {
  int input, m = 0, m_index;

  for (int i = 0; i < 9; i++) {
    scanf("%i", &input);
    if (input > m) {
      m = input;
      m_index = i + 1;
    }
  }
  printf("%i\n%i", m, m_index);
}
