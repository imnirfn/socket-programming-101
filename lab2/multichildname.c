#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const char* childTask() {
  char *namePtr = malloc(20);
  printf("Enter your name : ");
  scanf("%[^\n]%*c", namePtr);
  
  return namePtr;
}

void parentTask() {
  printf("Waiting for child\n");
  wait(NULL);
  printf("Job is done\n");
}

int main(void) {
  for(int i = 0; i < 4; i++) {
    pid_t pid = fork();

    if (pid == 0) {
      printf("Your name is : %s\n", childTask());
      exit(EXIT_SUCCESS);
    } else if (pid > 0) {
      parentTask();
    }
  }
  return 0;
}
