/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:34 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/24 15:01:06 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int sig, siginfo_t *siginfo, void *nothing)
{
	static int	bit;
	static unsigned char	c;

	(void)nothing;
	if (sig == SIGUSR1)
		c |= (0b10000000 >> bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
		kill(siginfo->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("PID: %d\n", getpid());
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = &server_handler;
	if ((sigaction(SIGUSR1, &signal, NULL)) == -1)
		solve_errors("Error Signal: SIGUSR1\n");
	if ((sigaction(SIGUSR2, &signal, NULL)) == -1)
		solve_errors("Error Signal: SIGUSR2\n");
	while (1)
		pause();
	return (0);
}
