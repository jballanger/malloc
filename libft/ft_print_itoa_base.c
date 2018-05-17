/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:56:03 by jballang          #+#    #+#             */
/*   Updated: 2018/05/17 15:17:15 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_itoa_base(int n, int base)
{
	char	str[64];
	int		size;
	int		negative;

	if (!n || base < 2 || base > 16)
		return (ft_putstr("0"));
	negative = 0;
	size = ft_intlen_base(n, base);
	ft_memset(str, '\0', 64);
	if (base == 10 && n < 0)
	{
		n = (-n);
		size += 1;
		negative = 1;
		str[0] = '-';
	}
	while (n)
	{
		size -= 1;
		str[size] = "0123456789ABCDEF"[n % base];
		n /= base;
	}
	ft_putstr(str);
}
