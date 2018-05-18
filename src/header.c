/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:18:08 by jballang          #+#    #+#             */
/*   Updated: 2018/05/18 10:10:42 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	push_header(t_page *page, t_header *header)
{
	t_header	*tmp;

	tmp = page->blocks;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = header;
	header->prev = tmp;
}

void	*create_header(void **root, t_page *page, size_t size, char free)
{
	t_header	*header;
	t_key		*key;

	header = *root;
	*root += sizeof(t_header);
	header->size = size;
	header->address = *root;
	header->free = free;
	header->next = NULL;
	header->prev = NULL;
	key = *root;
	*root += sizeof(t_key);
	create_checksum(key, (void*)(header), sizeof(t_header));
	*root += size;
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	if (free == 0)
		page->available -= (size + sizeof(t_header) + sizeof(t_key));
	else
		page->available -= (sizeof(t_header) + sizeof(t_key));
	return (header->address);
}
