/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:18:08 by jballang          #+#    #+#             */
/*   Updated: 2018/05/25 16:15:14 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	push_header(t_page *page, t_header *header)
{
	t_header	*tmp;

	tmp = page->blocks;
  check((void*)&tmp, sizeof(t_header));
  ft_putendl("ok2");
	while (tmp && tmp->next)
  {
		tmp = tmp->next;
    ft_putendl("hahahahaha");
    if (tmp) check((void*)&tmp, sizeof(t_header));
  }
	tmp->next = header;
	ft_putendl("updating checksum in push_header 1");
	update_checksum((void*)&tmp, sizeof(t_header));
	header->prev = tmp;
  ft_putendl("updating checksum in push_header 2");
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
	ft_putendl("Creating checksum in create_header");
	create_checksum(&key, NULL, (void*)&header, sizeof(t_header));
	*root += size;
	if (!page->blocks)
		page->blocks = header;
	else {
    ft_putendl("pushing header");
		push_header(page, header);
  }
	if (free == 0)
		page->available -= (size + sizeof(t_header));
	else
		page->available -= (sizeof(t_header));
  ft_putendl("updating checksum in create_header");
  update_checksum((void*)&page, sizeof(t_page));
	return (header->address);
}
