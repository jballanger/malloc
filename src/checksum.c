/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:50:12 by jballang          #+#    #+#             */
/*   Updated: 2018/05/18 13:37:30 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char	get_char_from_add(unsigned char *ptr, int size)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		c += *ptr;
		ptr++;
		i++;
	}
	return (c & 255);
}

void	create_checksum(void **ptr, int size)
{
	void	*tmp;

	tmp = *ptr;
	ft_putchar('\n');
	ft_putnbr((size_t)tmp);
	ft_putstr(" | ");
	ft_putnbr(get_char_from_add((unsigned char*)tmp, size));
	ft_putchar('\n');
}
