#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask() {
  printf("Child process\n");
}

void parentTask() {
  printf("Parent process\n");
}

int main(void) {
  pid_t pid = fork();
  
  if (pid == 0) {
    childTask();
    exit(EXIT_SUCCESS);
  } else if (pid > 0) {
    wait(NULL);
    parentTask();
  } else {
    perror("Creating child process failed\n");
  }
  return 0;
}

