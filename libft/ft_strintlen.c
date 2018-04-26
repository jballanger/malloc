/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:57:26 by jballang          #+#    #+#             */
/*   Updated: 2016/11/18 11:57:27 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strintlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			i++;
		str++;
	}
	return (i);
}
