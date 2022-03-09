/*
  Question: Implement the Collatz conjecture by reading an integer `n` and computing the rest of the numbers in a child process with fork(). 
  And wait for the child.
  
  Algorithm (when this algorithm is continually applied, all positive integers will eventually reach 1):
  f(n) = n/2 if n is even else 3*n+1 if n is odd
  
  For example, if n = 20, the sequence is: 20, 10, 5, 16, 8, 4, 2, 1
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int num = -1;    // Variable holding initial n
  while (num <= 0) { // Keep asking until we get a valid number...
    printf("Enter an integer: ");  // Prompting user for the integer
    scanf("%d", &num);             // Read the input. The amperstand means to get the address pointer to "num", so the variable can be modified.
  }
  
  pid_t parentID = fork();      // parent ID
  
  if (parentID == 0) {
    printf("%d\n", num);        // print initial value
    while (num > 1) {           // while num has not reached 1
      if (num % 2 == 0) {       // if num is even
        num /= 2;               // divide it by 2
      } else {                  // else
        num = (3 * (num)) + 1;  // multiply it by 3, then add 1
      }
      printf("%d\n", num);  // print num every step
    }
  } else {
    // parent waits for child process to finish
    wait(NULL);
    printf("Done\n");
  }
  return 0;
}
