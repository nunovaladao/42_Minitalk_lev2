/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:17:47 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/20 19:41:39 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_message_count = 0;

void	send_string(pid_t pid, char *string)
{
	char	c;
	int				bits;

	while (*string)
	{
		c = *string;
		bits = 0;
		while (bits < 8)
		{
			if (c & 1 << (7 - bits))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(40);
			bits++;
		}
		string++;
	}
}

void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		g_message_count++;
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_handler = &client_handler;
	if ((sigaction(SIGUSR1, &signal, 0)) == -1)
		solve_errors("Error Client Signal\n");
	if ((sigaction(SIGUSR2, &signal, 0)) == -1)
		solve_errors("Error Client Signal\n");
	if (!ft_atoi(argv[1]) || ft_atoi(argv[1]) < 0)	
		solve_errors("PID error!\n");
	if (argc == 3)
	{
		send_string(ft_atoi(argv[1]), argv[2]);
		ft_printf("The message has been received [%d] times!\n", g_message_count);
	}
	else
		solve_errors("Wrong args!\n");
}