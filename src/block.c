/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:10:09 by jballang          #+#    #+#             */
/*   Updated: 2018/05/18 12:08:30 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	split_block(t_page *page, t_header *header, size_t size)
{
	void	*root;
  size_t  available_size;

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
    //ft_putendl("u");
    check((void*)&header, sizeof(t_header));
    //ft_putendl("/u/");
		if (header->free == 1 && header->size >= size)
		{
      // if 192 > 162 && (192 - 162) old
      // if 43 > 5 && (38 > 42)
      // if 192 > 120 && (72 > 42)
			if (header->size > size && \
        (header->size - size) > (sizeof(t_header) + sizeof(t_key)))
      {
				split_block(page, header, size);
        page->available -= size;
      }
      else if (page->available <= (size + sizeof(t_header) + sizeof(t_key)))
      {
        ft_putendl("xdddd");
        //exit(0);
        page->available = 0;
      }
			header->free = 0;
      update_checksum((void*)&header, sizeof(t_header));
      update_checksum((void*)&page, sizeof(t_page));
			return (header->address);
		}
		header = header->next;
	}
  ft_putnbr(page->available);
  ft_putendl(" available\n");
	ft_putendl("shouldn't happen");
  exit(0);
  //show_pages();
  ft_putendl("oui");
	return (NULL);
}
