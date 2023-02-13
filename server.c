/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:34 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/13 15:00:56 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int sig, siginfo_t *siginfo, void *nothing)
{
	static int	bit;
	static int	i;

	(void)nothing;
	if (sig == SIGUSR1)
		i += (128 >> bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	if (siginfo->si_pid == 0)
		solve_errors("Error in PID'S client!");
	if (kill(siginfo->si_pid, SIGUSR1))
		solve_errors("Error in signal!");
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;
	pid_t				pid;

	(void)argv;
	if (argc != 1)
		solve_errors("Error!");
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = server_handler;
	if ((sigaction(SIGUSR1, &signal, NULL)) == -1)
		solve_errors("Error Signal: SIGUSR1\n");
	if ((sigaction(SIGUSR2, &signal, NULL)) == -1)
		solve_errors("Error Signal: SIGUSR2\n");
	while (1)
		pause();
	return (0);
}
