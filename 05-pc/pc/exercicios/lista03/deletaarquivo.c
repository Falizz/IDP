#include <stdio.h>
#include <unistd.h>

int main (void)
{

    const char *arquivo = "1B9F22CC4638.txt";

    if (unlink(arquivo) == 0) {
        printf("Arquivo deletado com sucesso.\n");
    } else {
        perror("Erro ao deletar arquivo");
    }

    return 0;
}