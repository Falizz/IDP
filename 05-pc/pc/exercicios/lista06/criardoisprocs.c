#define _GNU_SOURCE
#include <unistd.h>
#include <sys/prctl.h>

int main (void)
{
    pid_t pid = getpid();

    fork();

    if (pid == getpid()){
        fork();
        prctl(PR_SET_NAME, "0D151D23031D", 0, 0, 0);
        while (1)
        {
            sleep(1);
        }
        
    } else {
        prctl(PR_SET_NAME, "0D151D23031D", 0, 0, 0);
        while (1)
        {
            sleep(1);
        }
        
    }

    return 0;
}