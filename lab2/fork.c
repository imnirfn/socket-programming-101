#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
  fork();
  printf("Hello world\n");

  return 0;
}
