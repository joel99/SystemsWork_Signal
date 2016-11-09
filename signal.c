#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

static void sighandler(int signo){
  
  if (signo == SIGINT){
    int fd = open("signalLog", O_CREAT | O_WRONLY | O_APPEND, 0644);
    printf("\nSIGINT intercepted. Exiting...\n");
    write(fd, "exited successfully\n", 20);
    close(fd);
    exit(EXIT_SUCCESS);
  }
  if (signo == SIGUSR1){
    printf("Parent Process ID: %d", getppid());
  }
}

int main(){

    
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("\n");
    kill(getpid(), SIGUSR1);
    printf("\n");
    printf("Process ID: %d\n", getpid());
    sleep(1);
  }


}
