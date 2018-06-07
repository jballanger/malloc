/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:10:09 by jballang          #+#    #+#             */
/*   Updated: 2018/06/07 08:50:06 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	update_available(t_page **page)
{
	t_page		*tmp;
	t_header	*header;
	size_t		total;

	tmp = *page;
	header = tmp->blocks;
	total = 0;
	while (header)
	{
		if (header->free == 1)
			total += header->size;
		header = header->next;
	}
	tmp->available = total;
}

void	split_block(t_page *page, t_header *header, size_t size)
{
	void	*root;
	size_t	available_size;

	root = header->address;
	root += size;
	available_size = (header->size - (size + sizeof(t_header) + sizeof(t_key)));
	if (create_header(&root, page, available_size, 1) != NULL)
		header->size = size;
}

void	*get_block(t_page *page, size_t size)
{
	t_header	*header;

	header = page->blocks;
	while (header)
	{
		check((void*)&header, sizeof(t_header));
		if (header->free == 1 && header->size >= size)
		{
			if (header->size > size && \
				(header->size - size) > (sizeof(t_header) + sizeof(t_key)))
				split_block(page, header, size);
			header->free = 0;
			update_available(&page);
			update_checksum((void*)&header, sizeof(t_header));
			update_checksum((void*)&page, sizeof(t_page));
			return (header->address);
		}
		header = header->next;
	}
	return (NULL);
}
