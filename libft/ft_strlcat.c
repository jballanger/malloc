/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:17:34 by jballang          #+#    #+#             */
/*   Updated: 2016/11/09 12:17:46 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	max;
	size_t	i;

	dst_len = (size_t)ft_strlen(dst);
	src_len = (size_t)ft_strlen(src);
	max = size - dst_len - 1;
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] != '\0' && i < max)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
