#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *minhaThread(void *arg) {
    printf("Olá! Esta é uma mensagem da nova thread criada!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id; // Variável para armazenar o ID da thread
    int status;          // Variável para armazenar o status de retorno das chamadas

    printf("Programa principal: Tentando criar a nova thread...\n");

    // pthread_create(ponteiro para o ID, atributos, função a ser executada, argumentos para a função)
    status = pthread_create(&thread_id, NULL, minhaThread, NULL);
    pthread_join(thread_id, NULL);

    printf("Programa principal: A thread terminou e a execução está completa.\n");

    return 0; // Sucesso
}