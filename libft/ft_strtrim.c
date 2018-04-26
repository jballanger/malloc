/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:30:36 by jballang          #+#    #+#             */
/*   Updated: 2016/11/09 12:28:11 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_trim(char const *s)
{
	int	i;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	s--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		i--;
		s--;
	}
	if (i < 0)
		i = 0;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(result = (char*)malloc(sizeof(char) * ft_strlen_trim(s) + 1)))
		return (NULL);
	if (ft_strchr(s, ' ') || ft_strchr(s, '\n') || ft_strchr(s, '\t'))
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		while (*s != '\0')
		{
			result[i] = *s;
			i++;
			s++;
		}
		i--;
		while (result[i] == ' ' || result[i] == '\n' || result[i] == '\t')
			i--;
		result[i + 1] = '\0';
		return (result);
	}
	return (ft_strcpy(result, s));
}
