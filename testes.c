#include <stdio.h>
#include <unistd.h>
# include <signal.h>

int main()
{
    //struct sigaction abc;
    
    
    
    printf("%d\n", getpid());

    kill(getpid(), SIGUSR1);
    
    while (1)
    {
        pause();
    }
}