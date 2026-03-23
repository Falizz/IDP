#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        char *const argv[] = {
            "cp",           // Nome do programa (argv[0])
            "-s",           // Opção 1: criar um link simbólico (symbolic link)
            "-v",           // Opção 2: modo verboso (mostra o que está sendo feito)
            "/usr/bin/yes", // Arquivo de origem
            "/tmp/notnt",   // Arquivo de destino
            NULL            // O array de argumentos DEVE terminar com NULL
        };
        execvp("cp", argv);
    } 
    
    else {

        if (waitpid(pid, &status, 0) == -1) {
            perror("Erro ao aguardar o filho");
            return 1;
        }

        printf("Termino da execucao\n");
    }

    return 0;
}