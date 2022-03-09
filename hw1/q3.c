/*
  Question #3

  (65 points) The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
    n= {n/2, if n is even   and 3*n+1, if n is odd 
  The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 35, the sequence is
  35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int num = -1;    // Variable holding initial n
  while (num <= 0) { // Keep asking until we get a valid number...
    printf("Enter an Integer: ");  // prompting user for the integer
    scanf("%d", &num);             // actually scanning for user input
  }
  
  pid_t parentID = fork(); // parent ID
  
  if (parentID == 0) {
    printf("%d\n", num);                // print initial value
    while (num > 1) {                   // while num is larger than 1
      if (n % 2 == 0) {         // if num is even
        num /= 2;               // divide it by 2
      } else {                  // else
        num = (3 * (num)) + 1;  // multiply it by 3, then add 1
      }
      printf("%d\n", num);  // print num every step
    }
  } else {
    // parent waits for child process to finish
    wait(NULL);
    printf("Finish");
  }
  return 0;
}
