/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:08:45 by jballang          #+#    #+#             */
/*   Updated: 2018/05/17 15:19:03 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_base(int n, int base)
{
	int len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		len += 1;
		n /= base;
	}
	return (len);
}
