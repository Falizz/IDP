#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 7
#define NUM_ITERACOES 4

typedef struct {
    int indice_unico;
} thread_data_t;

void *contador(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    pthread_t tid = pthread_self();
    int indice_x = data->indice_unico;
    
    for (int n = 1; n <= NUM_ITERACOES; n++) {
        printf("Sou a thread nr %d, meu identificador eh %lu e estou no numero %d\n", 
                indice_x, 
                (unsigned long)tid,
                n);
    }
    
    free(data);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int status;
    long i;
    
    printf("Main: Iniciando a criação de %d threads...\n", NUM_THREADS);

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = (thread_data_t *)malloc(sizeof(thread_data_t));
        data->indice_unico = (int)i + 1;
        
        status = pthread_create(&threads[i], NULL, contador, (void *)data);
    }
    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nTodas as threads, exceto a main, terminaram\n");

    return 0;
}