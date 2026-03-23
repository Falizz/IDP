#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main() {
    const char *fifo_path = "/desafio/YJDZASFVAKEINAVH";
    mkfifo(fifo_path, 0666);

    return 0;
}