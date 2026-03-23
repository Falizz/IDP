#define _GNU_SOURCE
#include <unistd.h>
#include <sys/prctl.h>

int main (void)
{
    const char *nome = "FD0824B13D28";

    prctl(PR_SET_NAME, nome, 0, 0, 0);

    for (int i = 0; i < 8; i++) { // i < 8 cria 8 processos filhos + o processo pai = 9 processos
        pid_t pid = fork();

        if (pid == 0) {
            prctl(PR_SET_NAME, nome, 0, 0, 0);
            while (1) {
                sleep(1);
            }
        }

    }

    while (1) {
        sleep(1);
    }

    return 0;
}