/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:32:50 by jballang          #+#    #+#             */
/*   Updated: 2018/04/27 14:26:46 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ffree(void *ptr)
{
	t_page		*page;
	t_page		*tmp_page;
	t_header	*header;
	t_header	*tmp_header;

	header = (ptr - sizeof(t_header));
	tmp_header = header;
	while (tmp_header && tmp_header->prev)
		tmp_header = tmp_header->prev;
	page = (void*)(tmp_header - 1);
	page->available += header->size;
	header->free = 1;
	if (page->type == 3)
	{
		tmp_page = g_mem.pages;
		while (tmp_page && tmp_page != page)
			tmp_page = tmp_page->next;
		if (tmp_page && tmp_page->prev)
			tmp_page->prev->next = tmp_page->next;
		if (tmp_page && tmp_page->next)
			tmp_page->next->prev = tmp_page->prev;
		munmap(page, (sizeof(t_header) + sizeof(t_page) + header->size));
	}
}
