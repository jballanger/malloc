/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:07:47 by jballang          #+#    #+#             */
/*   Updated: 2018/05/25 15:49:27 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	fill_page(void **root, t_page *page)
{
	t_header	*header;

	header = *root;
	*root += sizeof(t_header);
	header->size = (page->available - sizeof(t_header));
	header->address = *root;
	header->free = 1;
	header->next = NULL;
	header->prev = NULL;
	*root += page->available;
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	page->available -= sizeof(t_header);
}

void	push_page(t_page *page)
{
	t_page			*tmp;
	//unsigned char	buff[2];

	tmp = g_mem.pages;
	ft_putendl("1");
	check((void*)&tmp, sizeof(t_page));
	ft_putendl("/1/");
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = page;
	page->prev = tmp;
}

void	*create_large_page(size_t size)
{
	t_page	*page;
	void	*root;
	void	*ptr;

	root = ft_alloc(sizeof(t_page) + sizeof(t_header) + size);
	page = root;
	root += sizeof(t_page);
	page->type = 3;
	page->blocks = NULL;
	page->next = NULL;
	page->prev = NULL;
	if (!g_mem.pages)
		g_mem.pages = page;
	else
		push_page(page);
	ptr = create_header(&root, page, size, 0);
	page->available = size;
	return (ptr);
}

void	*create_page(char type, size_t type_max, size_t size)
{
	t_page	*page;
	t_key	*key;
	void	*ptr;

	g_mem.root[type - 1] = ft_alloc(type_max);
	page = g_mem.root[type - 1];
	g_mem.root[type - 1] += sizeof(t_page);
	page->type = type;
	page->available = (type_max - sizeof(t_page));
	page->blocks = NULL;
	page->next = NULL;
	page->prev = NULL;
	key = g_mem.root[type - 1];
	g_mem.root[type - 1] += sizeof(t_key);
	if (!g_mem.pages)
		g_mem.pages = page;
	else
		push_page(page);
	/*ft_putendl("a");
	check((void*)&page, sizeof(t_page));
	ft_putendl("/a/");*/
	ptr = create_header(&g_mem.root[type - 1], page, size, 0);
	/*ft_putendl("b");
	check((void*)&page, sizeof(t_page));
	ft_putendl("/b/");*/
	fill_page(&g_mem.root[type - 1], page);
	t_page *p = g_mem.pages;
	ft_putendl("a-------------");
	ft_putnbr((size_t)p);
	ft_putchar('\n');
	p = g_mem.pages;
	ft_putendl("b-------------");
	ft_putnbr((size_t)p);
	ft_putchar('\n');
	/*ft_putendl("c");
	check((void*)&page, sizeof(t_page));
	ft_putendl("/c/");*/
	ft_putendl("Creating page checksum");
	create_checksum(&key, NULL, (void*)&page, sizeof(t_page));
	ft_putendl("__abc__");
	check((void*)&page, sizeof(t_page));
	return (ptr);
}

t_page	*search_page(char type, size_t size)
{
	t_page	*page;

	if (!g_mem.pages) return (NULL);
	page = g_mem.pages;
	ft_putnbr((size_t)page);
	ft_putchar('\n');
	ft_putnbr((size_t)g_mem.pages);
	ft_putchar('\n');
	t_page *xd = g_mem.pages;
	ft_putendl("__ghi2__");
	check((void*)&xd, sizeof(t_page));
	while (page)
	{
		//show_pages();
		ft_putendl("x");
		check((void*)&page, sizeof(t_page));
		ft_putendl("/x/");
		if (page->type == type && page->available >= \
			(size + sizeof(t_header)))
			return (page);
		page = page->next;
	}
	return (NULL);
}
