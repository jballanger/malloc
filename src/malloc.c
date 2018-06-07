/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:51:42 by jballang          #+#    #+#             */
/*   Updated: 2018/06/07 11:50:56 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_alloc(size_t size)
{
	void	*map;

	map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,
		0);
	if (map == MAP_FAILED)
		return (NULL);
	return (map);
}

void	*ft_malloc(size_t size)
{
	void	*addr;

	if (IS_TINY(size))
	{
		addr = search_block(1, size);
		if (addr)
			return (addr);
		else
			return (create_page(1, TINY_MAX, size));
	}
	else if (IS_SMALL(size))
	{
		addr = search_block(2, size);
		if (addr)
			return (addr);
		else
			return (create_page(2, SMALL_MAX, size));
	}
	else if (IS_LARGE(size))
		return (create_large_page(size));
	return (NULL);
}

void	*malloc(size_t size)
{
	void	*ptr;

	if (size < 1)
		return (NULL);
	pthread_mutex_lock(&g_mutex);
	ptr = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
