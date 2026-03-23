int main(int argc, char **argv)
{
    int pid;
    int pipefd[2];
    char pipefd0[0x20], pipefd1[0x20];

    pipe(pipefd);
    pid = fork();

    if (pid != 0) {
        close(pipefd[0]);
        puts("Eviando resposta...");
        write(pipefd[1], resposta_secreta, 23);
        close(pipefd[1]);
    } else {
        snprintf(pipefd0, 0x20, "%d", pipefd[0]);
        snprintf(pipefd1, 0x20, "%d", pipefd[1]);
        if (access("/desafio/solucao", X_OK) == 0) {
            execl("/desafio/solucao", "/desafio/solucao", pipefd0, pipefd1, NULL);
        }
        fprintf(stderr, "Erro ao executar solucao\n");
    }

    return 0;
}