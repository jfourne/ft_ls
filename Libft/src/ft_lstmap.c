/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:39:33 by jfourne           #+#    #+#             */
/*   Updated: 2016/12/19 13:41:00 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*tmp;
	t_list	*add;

	if (!f || !lst)
		return (NULL);
	if ((first = ft_lstnew(NULL, 0, 0)) == NULL)
		return (NULL);
	first = (f)(lst);
	tmp = lst->next;
	while (tmp != NULL)
	{
		if ((add = ft_lstnew(NULL, 0, 0)) == NULL)
			return (NULL);
		add = (f)(tmp);
		ft_lstback(&first, add);
		tmp = tmp->next;
	}
	return (first);
}
