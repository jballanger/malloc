/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:07:47 by jballang          #+#    #+#             */
/*   Updated: 2018/06/07 08:46:34 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	fill_page(void **root, t_page *page)
{
	t_header	*header;
	t_key		*key;

	header = *root;
	*root += sizeof(t_header);
	key = *root;
	*root += sizeof(t_key);
	header->size = (page->available - (sizeof(t_header) + sizeof(t_key)));
	header->address = *root;
	header->free = 1;
	header->next = NULL;
	header->prev = NULL;
	create_checksum(&key, NULL, (void*)&header, sizeof(t_header));
	*root += page->available;
	check((void*)&header, sizeof(t_header));
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	page->available -= sizeof(t_header) + sizeof(t_key);
	update_checksum((void*)&page, sizeof(t_page));
}

void	push_page(t_page *page)
{
	t_page	*tmp;

	tmp = g_mem.pages;
	check((void*)&tmp, sizeof(t_page));
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp)
			check((void*)&tmp, sizeof(t_page));
	}
	tmp->next = page;
	update_checksum((void*)&tmp, sizeof(t_page));
	page->prev = tmp;
	update_checksum((void*)&page, sizeof(t_page));
}

void	*create_large_page(size_t size)
{
	t_page	*page;
	t_key	*key;
	void	*root;
	void	*ptr;

	root = ft_alloc(sizeof(t_page) + sizeof(t_header) + \
		(sizeof(t_key) * 2) + size);
	page = root;
	root += sizeof(t_page);
	page->type = 3;
	page->available = size;
	page->blocks = NULL;
	page->next = NULL;
	page->prev = NULL;
	key = root;
	root += sizeof(t_key);
	create_checksum(&key, NULL, (void*)&page, sizeof(t_page));
	if (!g_mem.pages)
		g_mem.pages = page;
	else
		push_page(page);
	ptr = create_header(&root, page, size, 0);
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
	page->available = (type_max - (sizeof(t_page) + sizeof(t_key)));
	page->blocks = NULL;
	page->next = NULL;
	page->prev = NULL;
	key = g_mem.root[type - 1];
	g_mem.root[type - 1] += sizeof(t_key);
	create_checksum(&key, NULL, (void*)&page, sizeof(t_page));
	if (!g_mem.pages)
		g_mem.pages = page;
	else
		push_page(page);
	ptr = create_header(&g_mem.root[type - 1], page, size, 0);
	fill_page(&g_mem.root[type - 1], page);
	return (ptr);
}

void	*search_block(char type, size_t size)
{
	t_page	*page;
	void	*addr;

	page = g_mem.pages;
	while (page)
	{
		check((void*)&page, sizeof(t_page));
		if (page->type == type && page->available >= size)
		{
			addr = get_block(page, size);
			if (addr)
				return (addr);
		}
		page = page->next;
	}
	return (NULL);
}
