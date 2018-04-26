/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:35 by jballang          #+#    #+#             */
/*   Updated: 2016/11/08 13:08:42 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,\
		size_t n)
{
	char	*result;
	char	*source;

	result = (char*)dst;
	source = (char*)src;
	while (n > 0)
	{
		*result = *source;
		if (*result == c)
		{
			result++;
			return (result);
		}
		result++;
		source++;
		n--;
	}
	return (NULL);
}
