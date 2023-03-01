/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:17:47 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/24 16:49:37 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string(pid_t pid, char *string)
{
	unsigned char	c;
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

int	main(int ac, char **av)
{
	pid_t	pid;

	pid = ft_atoi(av[1]);
	if (ac == 3)
		send_string(pid, av[2]);
	else
		solve_errors("Wrong args!\n");
}
