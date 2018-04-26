/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:10:23 by jballang          #+#    #+#             */
/*   Updated: 2016/11/07 09:42:11 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy;

	copy = (unsigned char*)s;
	while (n > 0)
	{
		if (*copy == (unsigned char)c)
			return (copy);
		copy++;
		n--;
	}
	return (0);
}
