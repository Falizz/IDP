#include <stdio.h>
#include <signal.h>

int main (void)
{

    int pid = 7;

    if (kill(pid, SIGCONT) == 0){
        printf("Sinal SIGCONT enviado com sucesso\n");
    } else {
        perror("Erro ao enviar sinal SIGCONT");
    }

    return 0;
}