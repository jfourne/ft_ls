/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:57:37 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/30 16:30:39 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ft_lstreverse(t_list **alst)
{
	t_list		*tmp;
	t_list		*save;

	if ((*alst)->next == NULL)
		return (*alst);
	tmp = *alst;
	while (tmp != NULL)
	{
		save = tmp->next;
		tmp->next = tmp->prev;
		tmp->prev = save;
		if (save == NULL)
			*alst = tmp;
		tmp = save;
	}
	return (*alst);
}
