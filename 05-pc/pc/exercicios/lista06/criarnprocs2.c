#define _GNU_SOURCE
#include <unistd.h>
#include <sys/prctl.h>

int main (void)
{
    const char *nome = "D713037F0812";

    prctl(PR_SET_NAME, "pai", 0, 0, 0);

    for (int i = 0; i < 11; i++) { // i < 11 cria 11 processos filhos iguais
        pid_t pid = fork();

        if (pid == 0) {
            prctl(PR_SET_NAME, nome, 0, 0, 0);
            while (1) {
                sleep(1);
            }
            exit(0);
        }

    }

    while (1) {
        sleep(1);
    }

    return 0;
}