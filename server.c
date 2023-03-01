/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:17:44 by nsoares-          #+#    #+#             */
/*   Updated: 2023/03/01 17:52:53 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int sig)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c |= (0b10000000 >> bit);
	else if (sig == SIGUSR2)
		c |= 0;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("PID: %d\n", getpid());
	sigemptyset(&signal.sa_mask);
	signal.sa_handler = &server_handler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
