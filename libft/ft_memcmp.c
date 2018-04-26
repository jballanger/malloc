/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:16:23 by jballang          #+#    #+#             */
/*   Updated: 2016/11/08 14:43:20 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && n > 0)
	{
		n--;
		if (n > 0)
		{
			str1++;
			str2++;
		}
	}
	return (*str1 - *str2);
}
