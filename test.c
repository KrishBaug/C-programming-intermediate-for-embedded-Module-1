#include <stdio.h>

int main(void) {
  float temperature[5] = {25.2, 25.5, 25.1, 26.0, 25.8};

  for (int i = 0; i < 5; i++) {
    printf("%.1f\n", temperature[i]);
  }

  return 0;
}
