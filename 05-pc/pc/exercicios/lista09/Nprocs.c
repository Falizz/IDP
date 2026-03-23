#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROCESSOS 14

int main() {
    pid_t pid;
    int i;

    for (i = 0; i < NUM_PROCESSOS; i++) {
        pid = fork();

        if (pid == 0) {
            printf("Processo %d criado (PID = %d, Pai = %d)\n", i + 1, getpid(), getppid());
        } else {
            wait(NULL);
            exit(0);
        }
    }

    printf("Processo final (PID = %d, Pai = %d)\n", getpid(), getppid());
    return 0;
}
