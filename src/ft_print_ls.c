/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:56:26 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/30 15:59:16 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_print_and_count(t_list *list, int i)
{
	int				a;
	t_list			*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if ((a = ft_strlen(tmp->content)) > i)
			i = a;
		tmp = tmp->next;
	}
	while (!(a = 0) && list != NULL)
	{
		if (list->type == DT_DIR)
		{
			ft_putstr("\x1b[36m");
			a = 1;
		}
		ft_putendl(list->content);
		if (a == 1)
			ft_putstr("\x1b[0m");
		list = list->next;
	}
}

void				call_print(char *str, t_list **first, char *param, int a)
{
	if (a == 2)
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	if (*first == NULL)
		return ;
	ft_lst_sort(first, *first);
	if (ft_strchr(param, 'r') != NULL)
		ft_lstreverse(first);
	if (ft_strchr(param, 't') != NULL)
		param_t(str, first, param);
	if (ft_strchr(param, 'l') != NULL)
		param_l(str, *first);
	else
		ft_print_and_count(*first, ft_strlen((*first)->content));
}
