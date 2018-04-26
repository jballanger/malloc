/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 10:43:41 by jballang          #+#    #+#             */
/*   Updated: 2017/02/07 11:06:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
