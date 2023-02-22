/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_strjoin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:35:31 by nsoares-          #+#    #+#             */
/*   Updated: 2023/02/22 23:40:21 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_minitalk_strjoin(char *str, char c)
{
    char *new;
    int i;

    if (!c)
        return (NULL);
    if (!str)
    {
        new = malloc(sizeof(char) * 2);
        new[0] = c;
        new[1] = '\0';
        return (new);
    }
    new = malloc(sizeof(char) * ft_strlen(str) + 2);
    if (!new)
        return (NULL);
    i = -1;
    while (str[++i])
        new[i] = str[i];
    new[i++] = c;
    new[i] = '\0';
    free(str);
    return (new);
}