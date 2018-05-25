/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:50:12 by jballang          #+#    #+#             */
/*   Updated: 2018/05/25 14:27:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	check(void **ptr, int size)
{
	unsigned char	key[2];
	t_key	*ptr_key;

	create_checksum(NULL, key, ptr, size);
	ptr_key = (*ptr + size);
	ft_putstr("ptr_key[0]: ");
	ft_putnbr(ptr_key->value[0]);
	ft_putstr("\nptr_key[1]: ");
	ft_putnbr(ptr_key->value[1]);
	ft_putstr("\nkey[0]: ");
	ft_putnbr(key[0]);
	ft_putstr("\nkey[1]: ");
	ft_putnbr(key[1]);
	ft_putchar('\n');
	if (key[0] == ptr_key->value[0] &&\
		key[1] == ptr_key->value[1])
		return;
	ft_putendl("Invalid header, exiting..");
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
		//ft_putnbr(c);
		//ft_putchar('\n');
		ptr++;
		i++;
	}
	return (c & 255);
}

void	create_checksum(t_key **key, unsigned char buff[2], void **ptr, int size)
{
	t_key	*tmp;
	void	*address;

	address = *ptr;
	if (key)
	{
		tmp = *key;
		tmp->value[0] = get_char_from_add((unsigned char*)address, size);
		tmp->value[1] = 42;
	}
	else if (buff)
	{
		buff[0] = get_char_from_add((unsigned char*)address, size);
		buff[1] = 42;
	}
	ft_putstr("checksum: ");
	ft_putnbr((unsigned char)get_char_from_add((unsigned char*)address, size));
	ft_putendl("");
}
