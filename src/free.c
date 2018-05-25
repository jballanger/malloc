/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:32:50 by jballang          #+#    #+#             */
/*   Updated: 2018/05/25 16:03:46 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		free_large(t_page *page, t_header *header)
{
	if (page->prev)
		page->prev->next = page->next;
	if (page->next)
		page->next->prev = page->prev;
	if (!page->prev && page->next)
		g_mem.pages = page->next;
	if (!page->prev && !page->next)
		g_mem.pages = NULL;
	munmap(page, (sizeof(t_header) + sizeof(t_page) + header->size));
	page = NULL;
}

void		free(void *ptr)
{
	t_page		*page;
	t_header	*header;

	if (!ptr || !own_ptr(ptr))
		return ;
	header = (ptr - sizeof(t_header));
	while (header && header->prev)
		header = header->prev;
	page = (void*)(header - 1);
	header = (ptr - sizeof(t_header));
	if (page->type == 3)
		free_large(page, header);
	else
	{
		page->available += header->size;
		header->free = 1;
	}
}
