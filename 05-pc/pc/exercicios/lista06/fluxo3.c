#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    fork();
    if(fork() || fork()) {
        putchar('.');
    }
    putchar('!');
    printf("%d filho de %d\n", getpid(), getppid());
    wait(NULL);
    return 0;
}