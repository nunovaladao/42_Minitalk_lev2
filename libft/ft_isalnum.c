/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:27:40 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/06 21:41:00 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || \
	(c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_isalnum('a'));
	printf("%d", ft_isalnum('2'));
}*/
