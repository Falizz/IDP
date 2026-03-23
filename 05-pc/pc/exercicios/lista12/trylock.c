#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

#define NUM_THREADS 6
#define TOTAL_AGUA 36

int bebedouro = TOTAL_AGUA;
pthread_mutex_t mutex;

void* beber_agua(void* arg) {
    while (1) {
        int status = pthread_mutex_trylock(&mutex);

        if (status == 0) {
            if (bebedouro > 0) {
                bebedouro--;
                printf("Thread %lu bebendo agua\n", (unsigned long)pthread_self());
                
                pthread_mutex_unlock(&mutex);
                
                sleep(3);
            } else {
                pthread_mutex_unlock(&mutex);
                break; 
            }
        } else {
            if (bebedouro <= 0) break;

            printf("Thread %lu nao conseguiu beber agua\n", (unsigned long)pthread_self());
            
            sleep(1); 
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    pthread_mutex_init(&mutex, NULL);

    printf("--- Bebedouro Aberto (Capacidade: %d) ---\n", TOTAL_AGUA);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, beber_agua, NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("--- Bebedouro Vazio. Fim da execução. ---\n");

    pthread_mutex_destroy(&mutex);

    return 0;
}