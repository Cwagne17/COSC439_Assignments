#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// -----------------------
void *fib_thread(void *ptr);  // Prototype for the thread “fib_thread”.

// -----------------------
int fib(int n) 
{
  if(n==0)
    return 0;
  if(n<3)
    return 1;

  // initialize the first three terms
  int i = 1, j = 1, term = i+j;
  // calculate
  int ctr = 3;
  while(ctr<n) {
    i = j;
    j = term;
    term = i+j;
    ctr++;
  }
  return term;
}

// The struct below is used as the parameter for threads created.
struct msg_struct{
   int n;  // The parameter n (≤ 100). for the Fibonacci sequence.
   char *s; // A string with your self-defined message. 
   char *name; // A string for the thread name, such as Thread 1, Thread 2, …., Thread4.
   int result[100]; // An integer array to hold the Fibonacci results.
};

void fib_print(struct msg_struct *msg)
{
  // This function prints the content of a “msg_struct” instance.
  printf("%s\n", msg -> name);
  printf("%s\n", msg -> s);
  for(int i=0; i< msg -> n; i++) {
    printf("%d ", msg -> result[i]);
  }
  printf("\n\n");
}

int main() {
  // Sets up the thread params array
  struct msg_struct thread_params[4];
  thread_params[0] = (struct msg_struct){ .n=6, .s="Chris", .name="Thread_1" };
  thread_params[1] = (struct msg_struct){ .n=7, .s="Wagner", .name="Thread_2" };
  thread_params[2] = (struct msg_struct){ .n=8, .s="Towson University", .name="Thread_3" };
  thread_params[3] = (struct msg_struct){ .n=9, .s="Computer Science", .name="Thread_4" };

  // 1). Create four (4) threads and 2). Pass initialized parameters into it.  
  for(int i=0; i<4; i++) {
    pthread_t tid; pthread_attr_t attr;
    
    // Inits/creates/joins thread
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, fib_thread, &thread_params[i]);
    pthread_join(tid, NULL);

    // Prints out the struct when thread finishes
    fib_print(&thread_params[i]);
  }

  return 0;
}

// -----------------------
// Execution for the thread.
void *fib_thread(void *ptr)
{
  struct msg_struct *struct_ptr = (struct msg_struct*) ptr;
  for(int i=0; i<struct_ptr->n; i++) {
    struct_ptr -> result[i] = fib(i);
  }
  pthread_exit(0);
}
