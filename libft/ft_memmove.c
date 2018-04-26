/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:04:51 by jballang          #+#    #+#             */
/*   Updated: 2016/11/09 12:47:13 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*result;
	char	*source;
	int		i;

	result = (char*)dst;
	source = (char*)src;
	i = 0;
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			*(result + len) = *(source + len);
		}
	}
	else
	{
		while ((size_t)i < len)
		{
			*(result + i) = *(source + i);
			i++;
		}
	}
	return (dst);
}
