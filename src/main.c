/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/05/03 16:47:22 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	main(void)
{
	//void	*ptr;
	//void	*ptr2;
	void	*ptr3;
	void	*ptr4;

	//int i = 0;
	/*while (i < 196) {
		ptr = fmalloc(128);
		i += 1;
	}
	ptr = fmalloc(57);
	ptr = fmalloc(77);
	ptr2 = fmalloc(222);
	ptr3 = (char*)fmalloc(6);
	ptr4 = (char*)fmalloc(15);
	ptr = malloc(33);
	ptr3 = malloc(9000);
	ptr2 = malloc(777);*/
	ptr4 = fmalloc(9000);
	ft_memcpy(ptr4, "incroyable!__!\0", 15);
	ft_putendl(ptr4);
	show_pages();
	ptr3 = fmalloc(4);
	ptr4 = frealloc(ptr4, 444);
	show_pages();
	//ft_putendl(ptr4);
	//ft_putendl(ptr3 + (sizeof(t_header) + 6));
	return (0);
}

// TINY_MAX 32768
// t_page 40
// t_header 40
