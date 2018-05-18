/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:50:12 by jballang          #+#    #+#             */
/*   Updated: 2018/05/18 10:03:25 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	create_checksum(t_key *key, void **ptr, size_t size)
{
	if (!ptr)
		return ;
	key->value[0] = 42;
	key->value[1] = 84;
}
