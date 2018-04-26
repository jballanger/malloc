/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:31:20 by jballang          #+#    #+#             */
/*   Updated: 2016/11/09 11:59:17 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	str[ft_intlen(n)] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i = ft_intlen(n);
	}
	else
		i = ft_intlen(n) - 1;
	while (n > 0)
	{
		str[i] = (n % 10 + '0');
		i--;
		n /= 10;
	}
	return (str);
}
