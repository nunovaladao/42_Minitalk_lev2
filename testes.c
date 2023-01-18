#include <stdio.h>
#include <unistd.h>
# include <signal.h>
#include <stdlib.h>

/* int main()
{
    printf("%d\n", getpid());

    kill(getpid(), SIGUSR1);
    
    while (1)
    {
        pause();
    }
} */

void sighandler(int);

int main () 
{
   signal(SIGINT, sighandler);

   while(1) 
   {
        printf("Going to sleep for a second...\n");
        sleep(1); 
   }
   return(0);
}

void sighandler(int signum) 
{
    printf("Caught signal %d, coming out...\n", signum);
    exit(1);
}