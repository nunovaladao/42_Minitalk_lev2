#include <stdio.h>
#include <unistd.h>
# include <signal.h>
#include <stdlib.h>

/* void handle_signal(int sig)
{   
    printf("\nsig = %d\n", sig);
	printf("cmd = cntrl + c\n");
	printf("handle interrupt\n");
    exit(1);
}

int main()
{
    pid_t pid = getpid();
    printf("PID: %d\n", pid);

    struct sigaction signal;

    sigemptyset(&signal.sa_mask);
    signal.sa_handler = &handle_signal;
    signal.sa_flags = 0;
    

    sigaction(SIGUSR1, &signal, NULL);

    for (int i = 1; i <= 5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }

    kill(pid, SIGUSR1);

    return 0;
} */

void handle_usr1(int sig)
{
	if (sig == SIGUSR1)
        printf("handle usr1\n");
}

void handle_usr2(int sig)
{
    if (sig == SIGUSR2)
		printf("handle usr2\n");
}

int main()
{
	pid_t pid = getpid();
	printf("pid = %d\n", pid);

	struct sigaction sa_usr1;
	sa_usr1.sa_handler = &handle_usr1;
	sigemptyset(&sa_usr1.sa_mask);
	sa_usr1.sa_flags = 0;

	struct sigaction sa_usr2;
	sa_usr2.sa_handler = &handle_usr2;
	sigemptyset(&sa_usr2.sa_mask);
	sa_usr2.sa_flags = 0;

	sigaction(SIGUSR1, &sa_usr1, NULL);
	sigaction(SIGUSR2, &sa_usr2, NULL);

	while(1)
	{
		sleep(1);
		kill(pid, SIGUSR1);
		sleep(1);
		kill(pid, SIGUSR2);
	}

	return (0);
}