/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:09:31 by jballang          #+#    #+#             */
/*   Updated: 2018/05/25 15:53:12 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	print_addr(void *addr, int lf)
{
	ft_putstr("0x");
	ft_print_itoa_base((size_t)addr, 16);
	if (lf)
		ft_putchar('\n');
}

size_t	print_page(char type)
{
	t_page		*page;
	t_header	*header;
	size_t		total;

	if (!g_mem.pages) return (0);
	page = g_mem.pages;
	total = 0;
	while (page)
	{
		// check((void*)&page, sizeof(t_page));
		if (page->type == type)
		{
			if (page->type == 1)
				ft_putstr("TINY : ");
			else if (page->type == 2)
				ft_putstr("SMALL :");
			else if (page->type == 3)
				ft_putstr("LARGE : ");
			print_addr(page, 1);
			header = page->blocks;
			while (header)
			{
				print_addr(header, 0);
				ft_putstr(" - ");
				print_addr((void*)((size_t)header + header->size), 0);
				ft_putstr(" : ");
				ft_putnbr(header->size);
				ft_putendl(" octets");
				total += (header->free == 0) ? header->size : 0;
				header = header->next;
			}
		}
		page = page->next;
	}
	return (total);
}

void	show_pages()
{
	t_page		*page;
	t_header	*header;

	ft_putendl("!!! show_pages !!!");
	if (!g_mem.pages) return ;
	page = g_mem.pages;
	while (page)
	{
		ft_putendl("x2");
		check((void*)&page, sizeof(t_page));
		ft_putendl("------------------------------");
		ft_putstr("Type: ");
		if (page->type == 1)
			ft_putendl("TINY");
		if (page->type == 2)
			ft_putendl("SMALL");
		if (page->type == 3)
			ft_putendl("LARGE");
		ft_putstr("Address: ");
		ft_putnbr((size_t)page);
		ft_putchar('\n');
		ft_putstr("Available: ");
		ft_putnbr(page->available);
		ft_putchar('\n');
		ft_putstr("Blocks: ");
		ft_putnbr((size_t)page->blocks);
		ft_putchar('\n');
		ft_putstr("Prev: ");
		ft_putnbr((size_t)page->prev);
		ft_putchar('\n');
		ft_putstr("Next: ");
		ft_putnbr((size_t)page->next);
		ft_putchar('\n');
		if (page->blocks)
		{
			header = page->blocks;
			while (header)
			{
				ft_putendl("     ---------------");
				ft_putstr("     Address: ");
				ft_putnbr((size_t)header->address);
				ft_putstr("\n     Size: ");
				ft_putnbr(header->size);
				ft_putstr("\n     Free: ");
				ft_putendl((header->free == 0) ? "No" : "Yes");
				header = header->next;
			}
			ft_putendl("     ---------------");
		}
		page = page->next;
	}
	ft_putendl("------------------------------");
}

void	show_alloc_mem()
{
	size_t	total;

	total = print_page(1);
	total += print_page(2);
	total += print_page(3);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" octets");
}
