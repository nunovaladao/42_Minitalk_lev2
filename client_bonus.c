/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:16 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/13 17:09:26 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_mensage(pid_t pid, char *mensage)
{
	unsigned char	c;
	int				nbr_bits;

	while (*mensage)
	{
		c = *mensage;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		mensage++;
	}
}

void	client_handler(int sig, siginfo_t *siginfo, void *nothing)
{
	(void)sig;
	(void)siginfo;
	(void)nothing;
	ft_printf("Signal came from Server\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = client_handler;
	if ((sigaction(SIGUSR1, &signal, 0)) == -1)
		solve_errors("Error Client Signal\n");
	if ((sigaction(SIGUSR2, &signal, 0)) == -1)
		solve_errors("Error Client Signal\n");
	if (ft_atoi(argv[1]) < 0)
		solve_errors("PID error!\n");
	if (argc == 3)
		send_mensage(ft_atoi(argv[1]), argv[2]);
	else
		solve_errors("Wrong args! Put 1 argument and try again!\n");
}
