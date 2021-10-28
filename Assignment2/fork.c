#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
  pid_t pid;

  //Prints init statment with main pid
  printf("Hello, the parent process has been created. The process ID is %d.\n", getpid());
  
  // Creates a child process
  pid = fork();
  
  // Prints statement if a child
  if (pid == 0)
    printf("Hi, I am the child process and my process ID is %d\n", getpid());
  
  // Waits for any children processes to finish
  wait(0);

  // Prints a final statement before each process exits w/ the pid
  printf("The last output for the process: %d\n", getpid());
  return 0;
}
