/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:41:47 by jballang          #+#    #+#             */
/*   Updated: 2016/11/08 14:50:01 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*result;

	if (!(result = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		result = NULL;
	else
	{
		i = 0;
		while (s1[i] != '\0')
		{
			result[i] = s1[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
