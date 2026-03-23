#include <stdio.h>
#include <signal.h>

int main (void)
{

    int pid = 7;

    if (kill(pid, SIGALRM) == 0) {
        printf("Sinal enviado com sucesso\n");
    } else {
        perror("Erro ao enviar o sinal");
    }

    return 0;
}