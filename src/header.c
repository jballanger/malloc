/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:18:08 by jballang          #+#    #+#             */
/*   Updated: 2018/04/26 14:29:23 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	push_header(t_page *page, t_header *header)
{
	t_header	*tmp;

	tmp = page->blocks;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = header;
	header->prev = tmp;
}

void	*create_header(void **root, t_page *page, size_t size)
{
	t_header	*header;

	header = *root;
	*root += sizeof(t_header);
	header->size = size;
	header->address = *root;
	header->free = 0;
	header->next = NULL;
	header->prev = NULL;
	*root += size;
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	return (header->address);
}
