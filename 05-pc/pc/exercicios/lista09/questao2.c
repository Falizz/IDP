#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 3

void *thread_routine(void *arg) {
    long id = (long)arg;

    printf("Sou uma thread (ID: %ld)\n", id);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int status;
    long i;

    printf("Programa principal: Criando %d threads...\n", NUM_THREADS);

    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_create(&threads[i], NULL, thread_routine, (void *)i);
    }

    printf("Sou a main\n");

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}