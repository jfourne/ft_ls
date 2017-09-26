/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:39:36 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/30 15:48:55 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	replace_next_prev(t_list *save_next, t_list *tmp, int *ret)
{
	tmp->next->next = tmp;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->prev = tmp->next;
	tmp->next = save_next;
	*ret = 1;
}

void		ft_lst_sort(t_list **alst, t_list *tmp)
{
	t_list	*save_next;
	t_list	*save_prev;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = 0;
		while (tmp && tmp->next != NULL)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
			{
				if (tmp == *alst)
					*alst = tmp->next;
				save_next = tmp->next->next;
				save_prev = tmp->prev;
				if (save_next)
					save_next->prev = tmp;
				replace_next_prev(save_next, tmp, &ret);
			}
			tmp = tmp->next;
		}
		tmp = *alst;
	}
}

void		ft_lst_sort_by_type(t_list **alst, t_list *tmp)
{
	t_list	*save_next;
	t_list	*save_prev;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = 0;
		while (tmp && tmp->next != NULL)
		{
			if (tmp->type > tmp->next->type)
			{
				if (tmp == *alst)
					*alst = tmp->next;
				save_next = tmp->next->next;
				save_prev = tmp->prev;
				if (save_next)
					save_next->prev = tmp;
				replace_next_prev(save_next, tmp, &ret);
			}
			tmp = tmp->next;
		}
		tmp = *alst;
	}
}
