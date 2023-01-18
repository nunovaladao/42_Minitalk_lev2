/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:34 by nsoares-          #+#    #+#             */
/*   Updated: 2023/01/18 17:07:40 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig)
{
    if (sig == SIGUSR1)
        puts("0");
    else if (sig == SIGUSR2)
        puts("1");
}

int main()
{
    pid_t pid = getpid();
    
    struct sigaction signal;
    
    sigaction(SIGUSR1, &signal, NULL);
    sigaction(SIGUSR2, &signal, NULL);
    
    signal.sa_handler = signal_handler;
    
    kill(getpid(), SIGUSR1);
    kill(getpid(), SIGUSR2);
    
    while (1)
    {
        pause();
    }
    
}