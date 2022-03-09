/*
  Question #1

  (15 points) Using the program shown below, explain what the output will be at LINE A. (Please enter the answer to this question in your solution to question 3 as a comment)
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main() {
  pid_t pid;

  pid = fork();

  if (pid == 0) { /* child process */
    value += 15;
    return 0;
  } else if (pid > 0) { /* parent process */
    wait(NULL);
    printf("PARENT: value = %d", value); /* LINE A */
    return 0;
  }
}
