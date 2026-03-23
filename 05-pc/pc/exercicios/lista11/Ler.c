#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erro: Este programa deve ser executado pelo 'exercicio'\n");
        return 1;
    }

    int fd_leitura = atoi(argv[1]);    
    char buffer[100]; 
    ssize_t bytes_lidos = read(fd_leitura, buffer, sizeof(buffer) - 1);

    if (bytes_lidos > 0) {
        buffer[bytes_lidos] = '\0'; // Garante que é uma string válida
        printf("%s\n", buffer);
    } else {
        perror("Erro ao ler do pipe");
    }

    return 0;
}

/*
    Compilalção:
    gcc prog.c -o solucao

    Execução:
    ./exercicio
*/