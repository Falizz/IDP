#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define NUM_PROCESSOS 10
#define NUM_THREADS 12

void *thread_routine(void *arg) {
    long thread_id = (long)arg;
    
    printf("Sou uma thread. Meu ID (interno) é: %ld\n", thread_id);
    
    pthread_exit(NULL);
}

int main() {
    pid_t pid;
    int i;

    for (i = 0; i < NUM_PROCESSOS; i++) {
        pid = fork();

        if (pid > 0) {
            wait(NULL);
            exit(0);
        }
    }

    pthread_t threads[NUM_THREADS]; 
    int status;
    long i;

    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_create(&threads[i], NULL, thread_routine, (void *)i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}

