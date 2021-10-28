#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// -----------------------
void fib_thread(void *ptr);  // Prototype for the thread “fib_thread”.

// -----------------------
int fib(int n) 
{
// Write your code for the Fibonacci sequence.
// Input parameter: an integer n (≤ 100).
// Return value: the nth Fibonacci number as the integer data type.
}

// -----------------------
void fib_print(struct msg_struct *msg)
{
    // This function prints the content of a “msg_struct” instance.
}

// -----------------------
// The struct below is used as the parameter for threads created.
struct msg_struct{
   int n;  // The parameter n (≤ 100). for the Fibonacci sequence.
   char *s; // A string with your self-defined message. 
   char *name; // A string for the thread name, such as Thread 1, Thread 2, …., Thread4.
   int result[100]; // An integer array to hold the Fibonacci results.
};

int main() {
// Declare four (4) thread identifiers here.

// 1). Declare four (4) “msg_struct” instances used for thread parameters and 2). assign them initial values.
// 1). Create four (4) threads and 2). Pass initialized parameters into it.  

// Synchronization system calls to control the execution sequence. 

// Calls to the “fib_print()” function for the output.

    return 0;
}

// -----------------------
// Execution for the thread.
void fib_thread(void *ptr)
{
// Extract the sequence parameter, n from the thread parameter, a “struct msg_struct” instance in this case, for the Fibonacci sequence calculation.
// Call the “fib(int n)” function to calculate the values for the Fib sequence and store them in the “result” array in order.
}
