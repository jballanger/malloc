/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:56:02 by jballang          #+#    #+#             */
/*   Updated: 2016/11/09 12:26:27 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	if (s)
	{
		if (!(result = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			result[i] = f(s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
