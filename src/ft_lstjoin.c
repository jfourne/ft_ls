/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:34:39 by jfourne           #+#    #+#             */
/*   Updated: 2016/12/19 14:41:05 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ft_lstjoin(t_list *first, t_list *second)
{
	t_list		*tmp;

	tmp = first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = second;
	return (first);
}
