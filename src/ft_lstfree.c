/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:36:57 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/13 15:29:02 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstfree(t_list **first)
{
	t_list	*tmp;

	tmp = *first;
	while (*first)
	{
		tmp = (*first)->next;
		free((*first)->content);
		free(*first);
		*first = tmp;
	}
}
