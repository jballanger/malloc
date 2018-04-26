/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:53 by jballang          #+#    #+#             */
/*   Updated: 2016/11/08 17:13:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	nb;

	neg = 0;
	nb = 0;
	if (ft_strintlen(str) > 19)
		return (-1);
	while (*str == 9 || *str == 10 || *str == 11 || *str == 12 || *str == 13\
		|| *str == 32)
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	if (neg == 1)
		nb = -nb;
	return (nb);
}
