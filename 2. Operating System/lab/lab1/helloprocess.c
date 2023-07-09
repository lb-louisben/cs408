#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

// practice: how to create a child process

int main(int argc, char const *argv[])
{
    // pid_t 是一种数据类型，其本质是一个整型
    // 用 typedef 重新定义了一个名字，用来存储 pid
    pid_t cid;
    int integer = 100;
    printf("Before Fork Process, id: %d\n", getpid());
    
    cid = fork();

    if (cid == 0){
        // execute the child process
        printf("This is the child process: id = %d\n", getpid());
        printf("my parent process: id = %d\n", getppid());
        for (int i = 0; i < 3; i++){
            printf("hello - %d\n", integer++);
        }
        sleep(3);
    } else if(cid == -1) {
        printf("创建子进程失败\n");
    } else {
        printf("This is the parent process: id = %d\n", getpid());
        for (int i = 0; i < 3; i++){
            printf("world - %d\n", integer--);
        }
        
        // 等待子进程结束
        wait(NULL);
    }

    return 0;
}
