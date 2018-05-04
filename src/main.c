/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/05/04 14:06:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*int	main(void)
{
	void	*ptr;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;

	ptr = fmalloc(32);
	ft_memcpy(ptr, "sdfghjkfopjreiojgiorthjosijhsrt\0", 32);
	ft_putendl(ptr);
	ffree(ptr);
	ptr2 = fmalloc(32);
	ffree(ptr2);
	ptr3 = fmalloc(32);
	ffree(ptr3);
	ptr4 = fmalloc(32);
	ffree(ptr4);
	show_pages();
	return (0);
}*/

// TINY_MAX 32768
// t_page 40
// t_header 40
