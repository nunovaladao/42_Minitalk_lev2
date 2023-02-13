/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:34 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/11 22:14:03 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void server_handler(int sig, siginfo_t *siginfo, void *nothing)
{
    static int	bit;
	static int	i;

	(void)siginfo;
	(void)nothing;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int main(int argc, char **argv)
{
    struct sigaction signal;
    pid_t pid;
    (void)argv;

    if (argc != 1)
        ft_printf("Error!");
    pid = getpid();
    ft_printf("PID: %d\n", pid);
    
    sigemptyset(&signal.sa_mask);
    signal.sa_flags = SA_SIGINFO;
    signal.sa_sigaction = server_handler;
    
    if ((sigaction(SIGUSR1, &signal, NULL)) == -1)
        ft_printf("Error Signal: SIGUSR1\n");
    if ((sigaction(SIGUSR2, &signal, NULL)) == -1)
        ft_printf("Error Signal: SIGUSR2\n");
    
    while (1)
        pause();
    return (0);
}