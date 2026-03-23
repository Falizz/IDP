#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

const char* frase = "Um queijo suico tem buracos. Quanto mais queijo, mais buracos. Quanto mais buracos, menos queijo. Logo, quanto mais queijo, menos queijo!";
volatile int turn = 0;
volatile int indice_atual = 0;
int tamanho_frase;

void* thread_imprime(void* arg) {
    int my_id = *(int*)arg;
    
    int proximo_id = (my_id + 1) % 3;

    while (1) {        
        while (turn != my_id);
        if (indice_atual >= tamanho_frase) {
            turn = proximo_id;
            break;
        }

        putchar(frase[indice_atual]);
        indice_atual++;
        turn = proximo_id;
    }

    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3] = {0, 1, 2};

    tamanho_frase = strlen(frase);

    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_imprime, &ids[i]) != 0) {
            perror("Falha ao criar a thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    return 0;
}