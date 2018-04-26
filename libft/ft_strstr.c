/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:14:07 by jballang          #+#    #+#             */
/*   Updated: 2016/11/08 17:08:04 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*ptr;
	char	*start_little;

	if (little[0] == '\0')
		return ((char*)big);
	start_little = (char*)little;
	while (*big != '\0')
	{
		if (*big == *little)
		{
			ptr = (char*)big;
			while (*big != '\0' && *little != '\0' && \
					*big == *little)
			{
				big++;
				little++;
			}
			if (*little == '\0')
				return (ptr);
			big = ptr;
			little = start_little;
		}
		big++;
	}
	return (NULL);
}
