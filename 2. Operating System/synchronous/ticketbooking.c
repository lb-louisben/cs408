#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int ticketAmount = 100;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *ticketAgent(void *arg)
{
    pthread_mutex_lock(&lock);
    int t = ticketAmount;
    // sleep(1);

    if (t > 0)
    {
        printf("One ticket sold...\n");
        t--;
    }
    else
    {
        printf("Tickets are sold out...\n");
    }

    ticketAmount = t;
    pthread_mutex_unlock(&lock);
    pthread_exit(0);
}

int main(int argc, const char* argv[])
{
    int peopleAmount = atoi(argv[1]);
    printf("The input argument is %d\n", peopleAmount);
    pthread_t ticketAgent_tid[2];

    for (int i = 0; i < peopleAmount; i++)
    {
        pthread_create(ticketAgent_tid + i, NULL, ticketAgent, NULL);
    }

    for (int i = 0; i < peopleAmount; i++)
    {
        pthread_join(ticketAgent_tid[i], NULL);
    }

    printf("The left ticket is %d\n", ticketAmount);
    return 0;
}