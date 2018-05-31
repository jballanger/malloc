/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:04:39 by jballang          #+#    #+#             */
/*   Updated: 2018/05/04 14:07:33 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_realloc_tiny_small(void *ptr, size_t size, t_header *header)
{
	void	*new_ptr;
	size_t	new_size;

	new_ptr = malloc(size);
	new_size = (header->size > size) ? size : header->size;
	ft_memcpy(new_ptr, ptr, new_size);
	header->free = 1;
  update_checksum((void*)&header, sizeof(t_header));
	return (new_ptr);
}

void	*ft_realloc_large(void *ptr, size_t size, t_header *header)
{
	void	*new_ptr;
	size_t	new_size;

	new_ptr = malloc(size);
	new_size = (header->size > size) ? size : header->size;
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_page		*page;
	t_header	*header;

	header = (ptr - (sizeof(t_header) + sizeof(t_key)));
	while (header->prev)
		header = header->prev;
	page = (void*)(header - 1);
	header = (ptr - (sizeof(t_header) + sizeof(t_key)));
	if (page->type == 3)
		return (ft_realloc_large(ptr, size, header));
	else
		return (ft_realloc_tiny_small(ptr, size, header));
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	if (!ptr)
		return (malloc(size));
	if (!own_ptr(ptr))
		return (NULL);
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
  ft_putendl("[realloc]");
	return (ft_realloc(ptr, size));
}
