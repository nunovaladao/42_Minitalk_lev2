/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:34 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/22 23:31:24 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *g_send_message = 0;

void	server_handler(int sig, siginfo_t *siginfo, void *nothing)
{
	static int	bit;
	static unsigned char	i;

	(void)nothing;
	if (sig == SIGUSR1)
		i += (128 >> bit);
	bit++;
	if (bit == 8)
	{
		g_send_message = ft_minitalk_strjoin(g_send_message, i);
		if (i == '\0')
		{
			ft_printf("%s", g_send_message);
			free(g_send_message);
			g_send_message = 0;
			kill(siginfo->si_pid, SIGUSR1);
		}
		bit = 0;
		i = 0;
	}
}

/* void	server_handler(int sig, siginfo_t *siginfo, void *nothing)
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
		kill(siginfo->si_pid, SIGUSR1);
	}
} */

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
