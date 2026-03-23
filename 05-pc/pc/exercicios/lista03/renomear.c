#include <stdio.h>
#include <unistd.h>

int main (void)
{

    const char *arquivo = "C052E02EA0F0.txt";
    const char *novo_nome = "renomeado.txt";

    if (rename(arquivo, novo_nome) == 0) {
        printf("Arquivo renomeado com sucesso.\n");
    } else {
        perror("Erro ao renomear arquivo");
    }

    return 0;
}