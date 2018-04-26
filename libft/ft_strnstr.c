/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:27:31 by jballang          #+#    #+#             */
/*   Updated: 2016/11/08 17:09:53 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && n > (size_t)i)
	{
		if (big[i] == little[j])
		{
			ptr = (char*)&big[i];
			while (big[i + j] != '\0' && little[j] != '\0' && \
					big[i + j] == little[j] && n > (size_t)(i + j))
				j++;
			if (little[j] == '\0')
				return (ptr);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
