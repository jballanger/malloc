/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:14:46 by jballang          #+#    #+#             */
/*   Updated: 2016/11/08 13:08:56 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*result;
	char	*source;

	result = (char*)dst;
	source = (char*)src;
	while (n > 0)
	{
		*result = *source;
		result++;
		source++;
		n--;
	}
	return (dst);
}
