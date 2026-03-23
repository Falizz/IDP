#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NUM_CARROS 10

int largada = 3;

void *carro(void *arg) {
    int id = (int)(long)arg;

    while (largada != 0) {
        // Spin-wait (busy-waiting)
    }

    printf("Sou o carro %d e terminei a corrida.\n", id);
    return NULL;
}

void *juizdelargada(void *arg) {
    srand(time(NULL));

    while (largada > 0) {
        int tempo_aleatorio = (rand() % 10) + 1;
        sleep(tempo_aleatorio);
        largada--;
    }

    printf("GO!\n");
    return NULL;
}

int main() {
    pthread_t tid_carros[NUM_CARROS];
    pthread_t tid_juiz;
    long i;

    for (i = 0; i < NUM_CARROS; i++) {
        pthread_create(&tid_carros[i], NULL, carro, (void *)i);
    }

    pthread_create(&tid_juiz, NULL, juizdelargada, NULL);

    for (i = 0; i < NUM_CARROS; i++) {
        pthread_join(tid_carros[i], NULL);
    }
    pthread_join(tid_juiz, NULL);

    return 0;
}