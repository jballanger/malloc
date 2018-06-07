/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:50:12 by jballang          #+#    #+#             */
/*   Updated: 2018/06/07 15:21:33 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			check(void **ptr, int size)
{
	unsigned char	key[2];
	t_key			*ptr_key;

	create_checksum(NULL, key, ptr, size);
	ptr_key = (*ptr + size);
	if (key[0] == ptr_key->value[0] &&\
		key[1] == ptr_key->value[1])
		return ;
	ft_putendl("Invalid checksum, exiting..");
	kill(getpid(), SIGSEGV);
}

unsigned char	get_char_from_add(unsigned char *ptr, int size)
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

unsigned char	get_char_from_multiply(unsigned char *ptr, int size)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		c *= *ptr;
		ptr++;
		i++;
	}
	return (c & 255);
}

void			update_checksum(void **ptr, int size)
{
	t_key	*key;

	key = (*ptr + size);
	create_checksum(&key, NULL, ptr, size);
}

void			create_checksum(t_key **key, unsigned char buff[2],\
					void **ptr, int size)
{
	t_key	*tmp;
	void	*address;

	address = *ptr;
	if (key)
	{
		tmp = *key;
		tmp->value[0] = get_char_from_add((unsigned char*)address, size);
		tmp->value[1] = get_char_from_multiply((unsigned char*)address, size);
	}
	else if (buff)
	{
		buff[0] = get_char_from_add((unsigned char*)address, size);
		buff[1] = get_char_from_multiply((unsigned char*)address, size);
	}
}
