#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t full,empty;
int buffer=0;

void *producer()
{
    sem_wait(&empty);
    buffer++;
    printf("Producer produced item %d\n",buffer);
    sem_post(&full);
}

void *consumer()
{
    sem_wait(&full);
    printf("Consumer consumed item %d\n",buffer);
    buffer--;
    sem_post(&empty);
}

int main()
{
    pthread_t p,c;

    sem_init(&empty,0,1);
    sem_init(&full,0,0);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    return 0;
}