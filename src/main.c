/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/04/26 15:14:49 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	main(int ac, char **av)
{
	void	*ptr;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;

	ac = 777;
	av = NULL;
	ptr = fmalloc(2);
	ptr2 = fmalloc(222);
	ptr3 = (char*)fmalloc(6);
	ptr4 = (char*)fmalloc(15);
	show_pages();
	ft_memcpy(ptr3, "super\0", 6);
	ft_memcpy(ptr4, "incroyable!__!\0", 15);
	ft_putendl(ptr3);
	ft_putendl(ptr4);
	ft_putendl(ptr3 + (sizeof(t_header) + 6));
}
