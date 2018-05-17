/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:32:50 by jballang          #+#    #+#             */
/*   Updated: 2018/05/11 13:10:06 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page		*search_ptr_page(void *ptr, t_page *pages)
{
	size_t	page_max_addr;

	while (pages)
	{
		if (pages->type == 3)
		{
			if ((size_t)pages->blocks->address == (size_t)ptr)
				return (pages);
		}
		else
		{
			if (pages->type == 1)
				page_max_addr = ((size_t)pages + (TINY_MAX - 1));
			else if (pages->type == 2)
				page_max_addr = ((size_t)pages + (SMALL_MAX - 1));
			if ((size_t)ptr > (size_t)pages && (size_t)ptr < page_max_addr)
				return (pages);
		}
		pages = pages->next;
	}
	return (NULL);
}

t_header	*search_ptr_header(void *ptr, t_page *page)
{
	t_header	*header;

	header = page->blocks;
	while (header)
	{
		if ((size_t)ptr == (size_t)header->address)
			return (header);
		header = header->next;
	}
	return (NULL);
}

int			own_ptr(void *ptr)
{
	t_page		*pages;
	t_page		*ptr_page;
	t_header	*header;

	pages = g_mem.pages;
	ptr_page = search_ptr_page(ptr, pages);
	if (ptr_page)
	{
		header = search_ptr_header(ptr, ptr_page);
		return (header ? 1 : 0);
	}
	return (0);
}
