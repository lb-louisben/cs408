#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunc(void* arg){ // thread function
  printf("In New Thread.\n");
}


int main(){
  pthread_t tid;

  // create thread.
  /* the folloeing arguments:
  thread id address
  thread attribute address
  thread function address
  thread parameters address
  */
  pthread_create(&tid, NULL, threadFunc, NULL);

  // wait for specified thread to finish.
  pthread_join(tid, NULL);

  printf("In main thread.\n");

  return 0;
}
