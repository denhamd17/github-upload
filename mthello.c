#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h>

#define NUMBER_OF_THREADS 5

// Function prototype
void *print_hello_world(void *);

// The main program creates 10 threads and then exits.
int main(int argc, char *argv[]) 
{ 
  pthread_t threads[NUMBER_OF_THREADS]; 
  int status, i;
 
 for(i=0; i < NUMBER_OF_THREADS; i++) 
  { 
    printf("Main. Creating thread %d\n", i); 
    status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i); 
    if (status != 0) 
    { 
      printf("Oops. pthread create error code %d\n", status); 
      exit(EXIT_FAILURE); 
    } 
  } 
  exit(EXIT_SUCCESS);
}

// Function definition

void *print_hello_world(void *t) 
{ 
  /* This function prints the thread's identifier and then exits. */ 
  printf("Hello World. Greetings from thread %d\n", t); 
  pthread_exit(NULL); 
}