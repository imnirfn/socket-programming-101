#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(int sig) {
  printf("Caught signal %d\n", sig);
}

int main(void) {
  char str[500];
  void sigint_handler(int sig); /* user defined signal handler */

  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    perror("Signal");
    exit(1);
  }

  printf("Enter string: ");
  if (fgets(str, 200, stdin) == NULL) {
    perror("Fgets");
  } else {
    printf("Youve entered: %s\n", str);
  }

  return 0;
}
