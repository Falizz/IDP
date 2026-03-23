#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void bar()
{
    printf("Tentando pegar o lock de novo.\n");
    pthread_mutex_lock(&mutex);
        printf("Estou com duplo acesso? Sim!\n");
    pthread_mutex_unlock(&mutex);
}

void *foo(void *empty)
{
    pthread_mutex_lock(&mutex);
        printf("Acesso a região crítica.\n");
        bar();
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_t t;
    
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);
    pthread_mutexattr_destroy(&attr);

    pthread_create(&t, NULL, foo, NULL);
    pthread_join(t, NULL);
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}