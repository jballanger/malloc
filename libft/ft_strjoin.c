/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:17:06 by jballang          #+#    #+#             */
/*   Updated: 2016/11/09 12:27:44 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	if (s1 && s2)
	{
		if (!(result = (char*)malloc(sizeof(char) * \
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		while (*s1 != '\0')
		{
			result[i] = *s1;
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			result[i] = *s2;
			i++;
			s2++;
		}
		result[i] = '\0';
	}
	return (result);
}
