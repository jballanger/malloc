/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:07:47 by jballang          #+#    #+#             */
/*   Updated: 2018/04/26 15:01:43 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	fill_page(void **root, t_page *page)
{
	t_header	*header;

	header = *root;
	*root += sizeof(t_header);
	header->size = page->available;
	header->address = *root;
	header->free = 1;
	header->next = NULL;
	header->prev = NULL;
	*root += page->available;
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
}

void	push_page(t_page *page)
{
	t_page	*tmp;

	tmp = g_mem.pages;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = page;
	page->prev = tmp;
}

void	*create_page(char type, size_t type_max, size_t size)
{
	t_page	*page;
	void	*ptr;

	g_mem.root[type - 1] = ft_alloc(type_max);
	page = g_mem.root[type - 1];
	g_mem.root[type - 1] += sizeof(t_page);
	page->type = type;
	page->available = (type_max - sizeof(t_page));
	page->blocks = NULL;
	page->next = NULL;
	page->prev = NULL;
	if (!g_mem.pages)
		g_mem.pages = page;
	else
		push_page(page);
	ptr = create_header(&g_mem.root[type - 1], page, size, 0);
	fill_page(&g_mem.root[type - 1], page);
	return (ptr);
}

t_page	*search_page(char type, size_t size)
{
	t_page	*page;

	page = g_mem.pages;
	while (page)
	{
		if (page->type == type && page->available >= (size + sizeof(t_header)))
			return (page);
		page = page->next;
	}
	return (NULL);
}
