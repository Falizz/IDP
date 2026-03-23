#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define MAX_ALUNOS 100

int assinaturas = 0;
pid_t vetor_assinaturas[MAX_ALUNOS];
pthread_mutex_t possedalista;

pid_t gettid() {
    return syscall(SYS_gettid);
}

void* aluno(void* arg) {
    pthread_mutex_lock(&possedalista);

    int posicao_atual = assinaturas;
    pid_t meu_id = gettid();

    vetor_assinaturas[posicao_atual] = meu_id;

    assinaturas++;

    sleep(1);
    
    printf("Aluno %d assinou a lista.\n", (int)meu_id);

    pthread_mutex_unlock(&possedalista);

    pthread_exit(NULL);
}

int main() {
    int n;
    pthread_t threads[MAX_ALUNOS];

    printf("Digite o número de alunos (1 a 100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        fprintf(stderr, "Número de alunos inválido.\n");
        return 1;
    }

    pthread_mutex_init(&possedalista, NULL);

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, aluno, NULL);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("A ordem de assinatura da lista foi:");
    for (int i = 0; i < n; i++) {
        printf(" %d", (int)vetor_assinaturas[i]);
    }
    printf("\n");

    pthread_mutex_destroy(&possedalista);

    return 0;
}