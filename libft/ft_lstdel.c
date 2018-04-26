/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:16:32 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 12:04:39 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *str, size_t len)
{
	len = 0;
	str = NULL;
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_alst;
	t_list	*tmp;

	tmp_alst = *alst;
	tmp = tmp_alst;
	while (tmp)
	{
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp_alst = tmp_alst->next;
		tmp = tmp_alst;
	}
	*alst = NULL;
}
