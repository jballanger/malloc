/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:40:33 by jballang          #+#    #+#             */
/*   Updated: 2018/05/18 10:52:18 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	check_page(t_page *page)
{
	if (sizeof(*page) != sizeof(t_page))
	{
		ft_putendl("\nInvalid page, exiting..");
		kill(getpid(), SIGSEGV);
	}
}

void	check_header(t_header *header)
{
	if (sizeof(*header) != sizeof(t_header))
	{
		ft_putendl("\nInvalid header, exiting..");
		kill(getpid(), SIGSEGV);
	}
}
