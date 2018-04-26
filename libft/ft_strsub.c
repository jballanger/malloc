/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:12:26 by jballang          #+#    #+#             */
/*   Updated: 2017/03/06 12:09:17 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s)
	{
		while (len > 0)
		{
			result[i] = s[start + i];
			i++;
			len--;
		}
		result[i] = '\0';
	}
	return (result);
}
