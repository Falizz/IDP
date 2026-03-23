#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main(void) {

    const char *pipe_name = "FBLBVUZNLEDNNKVW";
    mkfifo(pipe_name, 0666);

    return 0;
}