#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>

#define try do { jmp_buf ex_buf__; switch( setjmp(ex_buf__) ) { case 0:
#define catch(x) break; case x:
#define etry } } while(0)
#define throw(x) longjmp(ex_buf__, x)

/* constants currently as int, need to cast into signal */
#define SIGNAL_EXCEPTION (1)
#define FGETS_EXCEPTION (2)

void signal_handler(int sig) {
  char *str = malloc(50); // allocate memory space for str
  if (sig == 2) { /* SIGINT catch */
    str = "SIGINT";
  } else if ( sig == 3 ) {
    str = "SIGQUIT";
  } else {
    str = "SIGTSTP";
  }

  printf("This is a special signal handler for %s\n", str);
}

int main(int argc, char** argv) {
  char str[500];
  void signal_handler(int sig); /* user defined signal handler */
  
  try {
    if (signal(SIGTSTP, signal_handler) == SIG_ERR || signal(SIGQUIT, signal_handler) == SIG_ERR || signal(SIGINT, signal_handler) == SIG_ERR) {
      throw( SIGNAL_EXCEPTION );
    }

    printf("Enter string: ");
    if (fgets(str, 200, stdin) == NULL) {
      throw( FGETS_EXCEPTION );
    } else {
      printf("Youve entered: %s\n", str);
    }
  } catch (SIGNAL_EXCEPTION) {
    printf("catch error\n"); 
  } catch (FGETS_EXCEPTION) {
    printf("fgets error\n");
  } etry;

  return 0;
}
