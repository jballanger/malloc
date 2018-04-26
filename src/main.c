/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/04/26 14:36:15 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	main(int ac, char **av)
{
	void	*ptr;
	void	*ptr2;
	void	*ptr3;

	ac = 777;
	av = NULL;
	ptr = fmalloc(2);
	ptr2 = fmalloc(222);
	//show_pages();
	//ft_putendl("________________________________________");
	ptr3 = (char*)fmalloc(59);
	show_pages();
	//ft_memcpy(ptr3, "super", 5);
	//ft_putendl(ptr3);
}
