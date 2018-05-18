/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:51:42 by jballang          #+#    #+#             */
/*   Updated: 2018/05/18 10:03:33 by jballang         ###   ########.fr       */
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
	t_page	*page;

	if (IS_TINY(size))
	{
		page = search_page(1, size);
		if (page)
			return (get_block(page, size));
		else
			return (create_page(1, TINY_MAX, size));
	}
	else if (IS_SMALL(size))
	{
		page = search_page(2, size);
		if (page)
			return (get_block(page, size));
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
	ptr = ft_malloc(size);
	return (ptr);
}
