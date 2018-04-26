/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:10:09 by jballang          #+#    #+#             */
/*   Updated: 2018/04/26 14:39:37 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*get_block(t_page *page, size_t size)
{
	t_header	*header;

	header = page->blocks;
	while (header)
	{
		if (header->free == 1 && header->size >= size)
		{
			// fragment
			header->size = size;
			header->free = 0;
			page->available -= size;
			return (header->address);
		}
		header = header->next;
	}
	ft_putendl("shouldn't happen");
	return (NULL);
}
