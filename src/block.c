/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:10:09 by jballang          #+#    #+#             */
/*   Updated: 2018/04/27 08:43:31 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	split_block(t_page *page, t_header *header, size_t size)
{
	void	*root;

	root = header->address;
	root += size;
	if (create_header(&root, page, (header->size - size), 1) != NULL)
		header->size = size;
}

void	*get_block(t_page *page, size_t size)
{
	t_header	*header;

	header = page->blocks;
	while (header)
	{
		if (header->free == 1 && header->size >= size)
		{
			split_block(page, header, size);
			header->free = 0;
			page->available -= size;
			return (header->address);
		}
		header = header->next;
	}
	ft_putendl("shouldn't happen");
	return (NULL);
}
