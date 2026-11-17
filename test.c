#include <stdio.h>

int main(void) {
  int x = 10;
  int *p = &x;

  printf("%d\n", x);  // 10
  printf("%p\n", p);  // address of x
  printf("%d\n", *p); // 10, dereference p

  *p = 25;
  printf("%d\n", x);

  return 0;
}
