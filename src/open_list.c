/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:47:55 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/30 16:43:18 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				read_to_list(t_list **first, struct dirent *ret, char *param)
{
	t_list		*tmp;
	t_list		*file_name;

	if (*first == NULL)
	{
		if (ret->d_name[0] == '.' && ft_strchr(param, 'a') == NULL)
			return (1);
		if ((*first = ft_lstnew(ret->d_name, ft_strlen(ret->d_name),
						ret->d_type)) == NULL)
			return (-1);
	}
	else
	{
		tmp = *first;
		if (ret->d_name[0] == '.' && ft_strchr(param, 'a') == NULL)
			return (1);
		if ((file_name = ft_lstnew(ret->d_name, ft_strlen(ret->d_name),
						ret->d_type)) == NULL)
			return (-1);
		ft_lstpush_back(first, file_name);
	}
	return (0);
}

void			list_set_type(t_list *first)
{
	t_list		*tmp;
	DIR			*dir;

	tmp = first;
	while (tmp != NULL)
	{
		dir = opendir(tmp->content);
		if (errno == ENOTDIR)
		{
			errno = 0;
			tmp->type = 3;
		}
		if (errno == ENOENT)
		{
			errno = 0;
			tmp->type = 0;
		}
		if (dir)
			closedir(dir);
		tmp = tmp->next;
	}
}

int				if_not_dir(t_list *first, char *param)
{
	DIR			*dir;
	t_list		*tmp;

	tmp = first;
	while (first && first->type < 3)
	{
		if (first->type < 3)
		{
			dir = opendir(first->content);
			print_perror_usage(first->content, 2);
		}
		first = first->next;
	}
	if (first == NULL)
		return (-1);
	call_print(NULL, &first, param, 1);
	ft_lstfree(&tmp);
	return (0);
}

t_list			*open_list(char **av, int i, int ac, char *param)
{
	t_list		*first;
	t_list		*tmp;

	first = NULL;
	if ((first = ft_lstnew(av[i], ft_strlen(av[i]), DT_DIR)) == NULL)
		return (NULL);
	i++;
	while (i < ac)
	{
		if ((tmp = ft_lstnew(av[i], ft_strlen(av[i]), DT_DIR)) == NULL)
			return (NULL);
		ft_lstpush_back(&first, tmp);
		i++;
	}
	list_set_type(first);
	ft_lst_sort(&first, first);
	ft_lst_sort_by_type(&first, first);
	tmp = first;
	while (first && first->type < 4)
		first = first->next;
	if (first && first->prev)
		first->prev->next = NULL;
	if (first != tmp && if_not_dir(tmp, param) == 0 && first)
		ft_putchar('\n');
	return (first);
}
