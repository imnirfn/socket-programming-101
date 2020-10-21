#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  for(int i = 0; i < 12; i++) {
    pid_t pid = fork();

    if (pid == 0) {
      printf("Child process => { PPID : %d, PID : %d }\n", getppid(), getpid());
      exit(0);
    } else if (pid > 0) {
      printf("Parent pricess => { PID : %d }\n", getpid());
      printf("Waiting for child\n");
      wait(NULL);
      printf("Child [%d] finished\n", i+1); 
    }
  }
}
