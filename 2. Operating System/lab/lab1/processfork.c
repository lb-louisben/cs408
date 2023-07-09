#include<stdio.h>
#include<unistd.h>
#include<sys/unistd.h>
#include<sys/wait.h>

int main(int args, char const *argv[])
{
  for (int i=0; i < 2; i++)
  {
    int ret = fork();
    if (ret == 0){
      printf("child %d, pid = %d, parent = %d\n", i, getpid(), getppid());
      wait(NULL);
    }
  }
}
