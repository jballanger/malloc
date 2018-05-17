/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:09:31 by jballang          #+#    #+#             */
/*   Updated: 2018/04/26 14:09:49 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	show_pages()
{
	t_page		*page;
	t_header	*header;

	page = g_mem.pages;
	while (page)
	{
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
