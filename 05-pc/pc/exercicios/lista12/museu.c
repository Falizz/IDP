#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_TURISTAS 20

#define CAP_SALA_1 5
#define CAP_SALA_2 7
#define CAP_SALA_3 6

sem_t sem_sala1;
sem_t sem_sala2;
sem_t sem_sala3;

sem_t sem_guia;

int cont_sala1 = 0, total_sala1 = 0;
int cont_sala2 = 0, total_sala2 = 0;
int cont_sala3 = 0, total_sala3 = 0;

void visitar_sala(int id_sala, int capacidade, sem_t *sem_sala, int *contador, int *total_processado) {

    sem_wait(sem_sala);

    sem_wait(&sem_guia);

    (*contador)++;
    (*total_processado)++;

    if (*contador == capacidade || *total_processado == NUM_TURISTAS) {
        printf("Sala %d completa, começando a explicação para %d pessoas.\n", id_sala, *contador);
        *contador = 0; 
    }
    
    sem_post(&sem_guia);
    sleep(2);
    sem_post(sem_sala);
}

void* turista(void* arg) {
    visitar_sala(1, CAP_SALA_1, &sem_sala1, &cont_sala1, &total_sala1);
    visitar_sala(2, CAP_SALA_2, &sem_sala2, &cont_sala2, &total_sala2);
    visitar_sala(3, CAP_SALA_3, &sem_sala3, &cont_sala3, &total_sala3);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_TURISTAS];
    int i;

    sem_init(&sem_sala1, 0, CAP_SALA_1);
    sem_init(&sem_sala2, 0, CAP_SALA_2);
    sem_init(&sem_sala3, 0, CAP_SALA_3);
    
    sem_init(&sem_guia, 0, 1);

    printf(">>> O Museu abriu para %d turistas! <<<\n\n", NUM_TURISTAS);

    for(i = 0; i < NUM_TURISTAS; i++) {
        pthread_create(&threads[i], NULL, turista, NULL);
    }

    for(i = 0; i < NUM_TURISTAS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n>>> Todos os turistas completaram a visita. Museu fechado. <<<\n");

    sem_destroy(&sem_sala1);
    sem_destroy(&sem_sala2);
    sem_destroy(&sem_sala3);
    sem_destroy(&sem_guia);

    return 0;
}