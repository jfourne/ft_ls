/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:26:08 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/30 17:00:37 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		replace_next_prev(t_list *save_next, t_list *tmp, int *ret)
{
	tmp->next->next = tmp;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->prev = tmp->next;
	tmp->next = save_next;
	*ret = 1;
}

void			ft_lst_sort_by_time(t_list **alst, t_list *tmp)
{
	t_list		*save_next;
	t_list		*save_prev;
	int			ret;

	ret = 1;
	while (ret > 0)
	{
		ret = 0;
		while (tmp && tmp->next != NULL)
		{
			if (tmp->time_m < tmp->next->time_m)
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

void			ft_lst_sort_by_revtime(t_list **alst, t_list *tmp)
{
	t_list		*save_next;
	t_list		*save_prev;
	int			ret;

	ret = 1;
	while (ret > 0)
	{
		ret = 0;
		while (tmp && tmp->next != NULL)
		{
			if (tmp->time_m > tmp->next->time_m)
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

void			param_t(char *str, t_list **first, char *param)
{
	char		*path;
	t_list		*tmp;
	struct stat	buf;

	tmp = *first;
	while (tmp != NULL)
	{
		if (str != NULL)
		{
			if ((path = ft_strjoin(str, "/")) == NULL)
				return ;
			if ((path = ft_strjoin_and_clean(path, tmp->content)) == NULL)
				return ;
		}
		else
			path = tmp->content;
		if (lstat(path, &buf) == -1)
			perror("");
		tmp->time_m = buf.st_mtime;
		tmp = tmp->next;
	}
	if (ft_strchr(param, 'r') != NULL)
		ft_lst_sort_by_revtime(first, *first);
	else
		ft_lst_sort_by_time(first, *first);
}
