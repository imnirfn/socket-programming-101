#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  int pid; /* process id */
  
  switch(pid = fork()) {
    case 0:
      printf("[Case 0 block]Child process with a pid of : %d\n", getpid());
      break;

    default:
      wait(NULL);
      printf("[Default block]Parent process with a pid of : %d\nChild pid of : %d\n", getpid(), pid);
      break;

    case -1:
      perror("Fork error");
      exit(1);
  } 

  return 0;
}
