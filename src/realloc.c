/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:04:39 by jballang          #+#    #+#             */
/*   Updated: 2018/05/03 12:00:17 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_realloc_tiny_small(void *ptr, size_t size, t_header *header)
{
	void	*new_ptr;
	size_t	new_size;

	new_ptr = fmalloc(size);
	new_size = (header->size > size) ? size : header->size;
	ft_memcpy(new_ptr, ptr, new_size);
	header->free = 1;
	return (new_ptr);
}

void	*ft_realloc_large(void *ptr, size_t size, t_header *header)
{
	void	*new_ptr;
	size_t	new_size;

	new_ptr = fmalloc(size);
	new_size = (header->size > size) ? size : header->size;
	ft_memcpy(new_ptr, ptr, new_size);
	ffree(ptr);
	return (new_ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_page		*page;
	t_header	*header;

	header = (ptr - sizeof(t_header));
	while (header->prev)
		header = header->prev;
	page = (void*)(header - 1);
	header = (ptr - sizeof(t_header));
	if (page->type == 3)
		return (ft_realloc_large(ptr, size, header));
	else
		return (ft_realloc_tiny_small(ptr, size, header));
	return (NULL);
}

void	*frealloc(void *ptr, size_t size)
{
	if (!ptr)
		return fmalloc(size);
	if (size == 0)
	{
		ffree(ptr);
		return (NULL);
	}
	return (ft_realloc(ptr, size));
}