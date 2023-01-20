/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:16 by nsoares-          #+#    #+#             */
/*   Updated: 2023/01/20 16:19:18 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bits()
{
    
}

int send_mensage()
{
    
}

void client_handler(int sig, siginfo_t *siginfo, void *nothing)
{
    (void)sig;
    (void)siginfo;
    (void)nothing;

    printf("Signal came from Server\n"); //ft_printf
}

int main(int argc, char **argv)
{
    struct sigaction signal1;
    struct sigaction signal2;
    
    sigemptyset(&signal1.sa_mask);
    sigemptyset(&signal2.sa_mask);

    signal1.sa_flags = SA_SIGINFO;
    signal2.sa_flags = SA_SIGINFO;
    
    signal1.sa_sigaction = client_handler;
    signal2.sa_sigaction = client_handler;
    
    if ((sigaction(SIGUSR1, &signal1, 0)) == -1)
        printf("Error Client Signal\n"); //ft_printf
    if ((sigaction(SIGUSR2, &signal2, 0)) == -1)
        printf("Error Client Signal\n"); //ft_printf
    
}