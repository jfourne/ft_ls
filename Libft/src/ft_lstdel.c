/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:21:21 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/11 15:39:21 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		*alst = tmp;
		free(*alst);
		tmp = tmp->next;
	}
	*alst = NULL;
}
