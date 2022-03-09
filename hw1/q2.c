/*
  Question #2

  (20 points) Using the program in the figure below, identify the values of pid
at lines A, B, C, and D. (Assume that the actual pids of the parent and child
are 2600 and 2603, respectively.)
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid, pid1;

  /* fork a child process */
  pid = fork();

  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork Failed");
    return 1;
  } else if (pid == 0) { /* child process */
    pid1 = getpid();
    printf("child: pid = %d", pid);   /* A */
    printf("child: pid1 = %d", pid1); /* B */
  } else {                            /* parent process */
    pid1 = getpid();
    printf("parent: pid = %d", pid);   /* C */
    printf("parent: pid1 = %d", pid1); /* D */
    wait(NULL);
  }
  return 0;
}
