#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t wrt;
int data=0;

void *reader()
{
    printf("Reader reads data = %d\n",data);
}

void *writer()
{
    sem_wait(&wrt);
    data++;
    printf("Writer writes data = %d\n",data);
    sem_post(&wrt);
}

int main()
{
    pthread_t r,w;

    sem_init(&wrt,0,1);

    pthread_create(&w,NULL,writer,NULL);
    pthread_create(&r,NULL,reader,NULL);

    pthread_join(w,NULL);
    pthread_join(r,NULL);

    return 0;
}