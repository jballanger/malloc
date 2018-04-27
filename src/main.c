/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/04/27 10:16:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	main(int ac, char **av)
{
	void	*ptr;
	/*void	*ptr2;
	void	*ptr3;
	void	*ptr4;*/

	ac = 777;
	av = NULL;
	int i = 0;
	while (i < 196) {
		ptr = fmalloc(128);
		i += 1;
	}
	ptr = fmalloc(57);
	ptr = fmalloc(30);
	/*ptr2 = fmalloc(222);
	ptr3 = (char*)fmalloc(6);
	ptr4 = (char*)fmalloc(15);*/
	show_pages();
	/*ft_memcpy(ptr3, "super\0", 6);
	ft_memcpy(ptr4, "incroyable!__!\0", 15);
	ft_putendl(ptr3);
	ft_putendl(ptr4);
	ft_putendl(ptr3 + (sizeof(t_header) + 6));*/
}

// TINY_MAX 32768
// t_page 40
// t_header 40
