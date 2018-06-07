/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:18:08 by jballang          #+#    #+#             */
/*   Updated: 2018/06/07 08:39:23 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	push_header(t_page *page, t_header *header)
{
	t_header	*tmp;

	check((void*)&page, sizeof(t_page));
	tmp = page->blocks;
	check((void*)&tmp, sizeof(t_header));
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp)
			check((void*)&tmp, sizeof(t_header));
	}
	tmp->next = header;
	update_checksum((void*)&tmp, sizeof(t_header));
	header->prev = tmp;
	update_checksum((void*)&header, sizeof(t_header));
}

void	*create_header(void **root, t_page *page, size_t size, char free)
{
	t_header	*header;
	t_key		*key;

	header = *root;
	*root += sizeof(t_header);
	key = *root;
	*root += sizeof(t_key);
	header->size = size;
	header->address = *root;
	header->free = free;
	header->next = NULL;
	header->prev = NULL;
	create_checksum(&key, NULL, (void*)&header, sizeof(t_header));
	*root += size;
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	if (free == 0)
		page->available -= (size + sizeof(t_header) + sizeof(t_key));
	else
		page->available -= (sizeof(t_header) + sizeof(t_key));
	update_checksum((void*)&page, sizeof(t_page));
	return (header->address);
}
