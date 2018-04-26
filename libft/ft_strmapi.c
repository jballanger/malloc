/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:02:09 by jballang          #+#    #+#             */
/*   Updated: 2016/11/09 12:27:02 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	if (s)
	{
		if (!(result = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			result[i] = f(i, s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
