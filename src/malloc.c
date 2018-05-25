/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:51:42 by jballang          #+#    #+#             */
/*   Updated: 2018/05/25 15:39:53 by jballang         ###   ########.fr       */
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
		else {
			void *p = create_page(1, TINY_MAX, size);
			/*ft_putendl("-------------");
			ft_putnbr((size_t)*g_mem.pages);
			ft_putchar('\n');*/
			page = g_mem.pages;
			ft_putendl("5-------------");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			//page = *g_mem.pages;
			ft_putendl("6-------------");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			//page = *g_mem.pages;
			ft_putendl("7-------------");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			//page = *g_mem.pages;
			ft_putendl("8-------------");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			ft_putendl("d");
			check((void*)&page, sizeof(t_page));
			ft_putendl("/d/");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			ft_putendl("1++++++");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			//page = *g_mem.pages;
			ft_putendl("2++++++");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			//page = *g_mem.pages;
			ft_putendl("3++++++");
			ft_putnbr((size_t)page);
			ft_putchar('\n');
			ft_putendl("######");
			ft_putnbr((size_t)g_mem.pages);
			ft_putchar('\n');
			ft_putnbr((size_t)g_mem.pages);
			ft_putchar('\n');
			return (p);
		}
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
	t_page	*page;

	if (size < 1)
		return (NULL);
	ptr = ft_malloc(size);
	ft_putendl("^^^^^^^^^^^");
	ft_putnbr((size_t)g_mem.pages);
	ft_putchar('\n');
	ft_putnbr((size_t)g_mem.pages);
	ft_putchar('\n');
	page = g_mem.pages;
	ft_putendl("*****");
	ft_putnbr((size_t)page);
	ft_putchar('\n');
	ft_putendl("*****");
	return (ptr);
}
