/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:32:50 by jballang          #+#    #+#             */
/*   Updated: 2018/04/27 12:48:10 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ffree(void *ptr)
{
	t_page		*page;
	t_header	*header;
	t_header	*tmp;

	header = (ptr - sizeof(t_header));
	tmp = header;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	page = (void*)(tmp - 1);
	page->available += header->size;
	header->free = 1;
	//munmap(header->address, header->size);
}
