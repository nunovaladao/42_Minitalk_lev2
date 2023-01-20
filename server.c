/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:34 by nsoares-          #+#    #+#             */
/*   Updated: 2023/01/20 16:05:28 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void server_handler(int sig, siginfo_t *siginfo, void *nothing)
{
    if (sig == SIGUSR1)
    {
        kill(getpid(), SIGUSR1);
        puts("0");
    }
    else if (sig == SIGUSR2)
    {    
        kill(getpid(), SIGUSR2);
        puts("1");
    }

}

int main(void)
{
    struct sigaction signal1;
    struct sigaction signal2;
    pid_t pid;
    
    pid = getpid();
    printf("PID: %d\n", pid); //ft_printf
    
    sigemptyset(&signal1.sa_mask);
    sigemptyset(&signal2.sa_mask);

    signal1.sa_flags = SA_SIGINFO;
    signal2.sa_flags = SA_SIGINFO;
    
    signal1.sa_sigaction = server_handler;
    signal2.sa_sigaction = server_handler;
    
    if ((sigaction(SIGUSR1, &signal1, 0)) == -1)
        printf("Error Signal\n"); //ft_printf
    if ((sigaction(SIGUSR2, &signal2, 0)) == -1)
        printf("Error Signal\n"); //ft_printf
    
    while (1)
        pause();
    return (0);
}