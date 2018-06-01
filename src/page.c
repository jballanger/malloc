/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:07:47 by jballang          #+#    #+#             */
/*   Updated: 2018/05/25 16:12:11 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	fill_page(void **root, t_page *page)
{
	t_header	*header;
  t_key     *key;

	header = *root;
	*root += sizeof(t_header);
  key = *root;
  *root += sizeof(t_key);
	header->size = (page->available - (sizeof(t_header) + sizeof(t_key)));
	header->address = *root;
	header->free = 1;
	header->next = NULL;
	header->prev = NULL;
  //ft_putendl("Creating header checksum in fill_page");
  create_checksum(&key, NULL, (void*)&header, sizeof(t_header));
	*root += page->available;
  //ft_putendl("check in fill_page");
  check((void*)&header, sizeof(t_header));
  //ft_putendl("ok");
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	page->available -= sizeof(t_header) + sizeof(t_key);
  //ft_putendl("updating checksum in fill_page");
  update_checksum((void*)&page, sizeof(t_page));
}

void	push_page(t_page *page)
{
  //ft_putendl("oui");
	t_page			*tmp;
	//unsigned char	buff[2];

	tmp = g_mem.pages;
	//ft_putendl("1");
	check((void*)&tmp, sizeof(t_page));
	//ft_putendl("/1/");
	while (tmp && tmp->next)
  {
		tmp = tmp->next;
    if (tmp) check((void*)&tmp, sizeof(t_page));
  }
	tmp->next = page;
  //ft_putendl("updating checksum in push_page 1");
	update_checksum((void*)&tmp, sizeof(t_page));
	page->prev = tmp;
  //ft_putendl("updating checksum in push_page 2");
  update_checksum((void*)&page, sizeof(t_page));
}

void	*create_large_page(size_t size)
{
	t_page	*page;
  t_key   *key;
	void	*root;
	void	*ptr;

	root = ft_alloc(sizeof(t_page) + sizeof(t_header) + \
    (sizeof(t_key) * 2) + size);
	page = root;
	root += sizeof(t_page);
	page->type = 3;
  page->available = size;
	page->blocks = NULL;
	page->next = NULL;
	page->prev = NULL;
  key = root;
  root += sizeof(t_key);
  //ft_putendl("creating checksum in create_large_page");
  create_checksum(&key, NULL, (void*)&page, sizeof(t_page));
	if (!g_mem.pages)
		g_mem.pages = page;
	else
		push_page(page);
	ptr = create_header(&root, page, size, 0);
  /*ft_putendl("updating checksum in create_large_page");
  update_checksum((void*)&page, sizeof(t_page));*/
	return (ptr);
}

void	*create_page(char type, size_t type_max, size_t size)
{
	t_page	*page;
	t_key	*key;
	void	*ptr;

	g_mem.root[type - 1] = ft_alloc(type_max);
	page = g_mem.root[type - 1];
	g_mem.root[type - 1] += sizeof(t_page);
	page->type = type;
	page->available = (type_max - (sizeof(t_page) + sizeof(t_key)));
	page->blocks = NULL;
	page->next = NULL;
	page->prev = NULL;
	key = g_mem.root[type - 1];
	g_mem.root[type - 1] += sizeof(t_key);
  create_checksum(&key, NULL, (void*)&page, sizeof(t_page));
  //ft_putendl("xx");
	if (!g_mem.pages) {
    //ft_putendl("d1");
		g_mem.pages = page;
  }
	else {
    //ft_putendl("d2");
		push_page(page);
  }
  //ft_putendl("xx22");
	ptr = create_header(&g_mem.root[type - 1], page, size, 0);
	fill_page(&g_mem.root[type - 1], page);
	//ft_putendl("Creating page checksum in create_page");
	return (ptr);
}

void	*search_block(char type, size_t size)
{
	t_page	*page;
  void    *addr;

	//if (!g_mem.pages) return (NULL);
	page = g_mem.pages;
	while (page)
	{
		check((void*)&page, sizeof(t_page));
		if (page->type == type && page->available >= size)
    {
      addr = get_block(page, size);
      if (addr)
        return (addr);
    }
		page = page->next;
	}
	return (NULL);
}
