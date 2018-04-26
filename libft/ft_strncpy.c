/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:15:17 by jballang          #+#    #+#             */
/*   Updated: 2016/11/07 09:49:49 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	while ((size_t)i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while ((size_t)i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
