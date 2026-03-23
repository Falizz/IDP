#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/prctl.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Processo filho
        prctl(PR_SET_NAME, "filho", 0, 0, 0);
        while (1) {
            sleep(1);
        }
    } else {
        // Processo pai
        prctl(PR_SET_NAME, "pai", 0, 0, 0);
        while (1) {
            sleep(1);
        }
    }

    return 0;
}
