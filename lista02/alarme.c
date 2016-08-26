#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
  int pid = fork();
  if(pid==-1){
    printf("Process failure\n");
  } else if(!pid){
    printf("Child process\n");
    sleep(5);
    /* signal(SIGALRM, handler); */
    kill(pid,SIGALRM);
  } else{
    pause();
  }

  return 0;
}
