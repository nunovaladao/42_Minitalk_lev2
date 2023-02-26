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

/* void sighandler(int);

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
} */

void handle_sig(int signal)
{
    printf("\nsig = %d\n", signal);
    printf("cmd = cntrl + c\n");
    printf("handle interrupt\n");
    exit(1);
}

int main()
{
    pid_t pid = getpid();
    printf("PID: %d\n\n", pid);

    signal(SIGUSR1, handle_sig);
    for(int i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

    kill(pid, SIGUSR1);

    return 0;
}