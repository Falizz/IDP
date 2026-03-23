#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    if(fork() || fork()) {
        fork();
    }
    printf("%d sou filho de %d\n", getpid(), getppid());
    wait(NULL);
    return 0;
}