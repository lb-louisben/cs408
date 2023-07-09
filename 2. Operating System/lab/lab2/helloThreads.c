#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

int shared_value = 100; // shared data section belongs to process.

void* hello(void* arg)
{
 for (int i = 0; i < 3; ++i){
    printf("hello(%d)\n", shared_value++);
    sleep(1);
  }
}

void* world(void* arg)
{
 for (int i = 0; i < 3; ++i){
    printf("world(%d)\n", shared_value++);
    sleep(2);
  }
}

int main(int argc, char const* argv[])
{
  // srand(time(NULL));
  pthread_t tid, tid2;

  pthread_create(&tid, NULL, hello, NULL);
  pthread_create(&tid2, NULL, world, NULL);

  pthread_join(tid, NULL);
  pthread_join(tid2, NULL);

  printf("this is main thread.\n");

  return 0;
  
}


/*
hello和world函数在调用初期，任存在问题
没有加锁，导致两次并发执行时shared_value都是100
加上sleep函数就会改善
*/
