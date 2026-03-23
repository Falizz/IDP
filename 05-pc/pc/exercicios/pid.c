#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Sou o filho %d e o meu pai eh %d\n", getpid(), getppid());
    } else {
        printf("Sou o pai %d e o meu filho eh %d\n", getpid(), pid);
    }

    return 0;
}
