#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void myhandler(int mysignal)
{
    printf("Sinal recebido\n");
}

int main()
{
    int pid = fork();
    if(pid==-1){
        printf("Process failure\n");
    } else if(!pid){
        printf("...\n");
        sleep(5);
        kill(getppid(),SIGALRM);
    } else{
        signal(SIGALRM, myhandler);
        pause();
        wait(NULL);
    }

    return 0;
}
