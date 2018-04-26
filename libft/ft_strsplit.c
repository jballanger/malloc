/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:39:40 by jballang          #+#    #+#             */
/*   Updated: 2017/05/24 12:03:12 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strsplit_return(char **array, int j, char const *s, char c)
{
	s--;
	if (*s == c)
		j--;
	array[j] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	if (!(array = (char**)malloc(sizeof(char*) * ft_strlen(s))))
		return (NULL);
	while (*s != '\0')
	{
		i = -1;
		while (*s == c)
			s++;
		if (!(array[j] = (char*)malloc(sizeof(char) * ft_wordlenc(s, c) + 1)))
			return (NULL);
		while (*s != c && *s != '\0')
		{
			array[j][++i] = *s;
			s++;
		}
		array[j][++i] = '\0';
		j++;
	}
	return (ft_strsplit_return(array, j, s, c));
}
