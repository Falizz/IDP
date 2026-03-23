#include <stdio.h>
#include <unistd.h>

int main (void)
{

    const char *dir = "/desafio/me_deleta-FB578FB6218B";

    if (rmdir(dir) == 0) {
        printf("Diretório deletado com sucesso\n");
    } else {
        perror("Erro ao deletar diretório\n");
    }

    return 0;
}