#include <stdio.h>

int main(void) {
  int age;
  printf("Hello, how old are you?");
  scanf("%d", &age);

  printf("You are %d years old", age);
  return 0;
}
