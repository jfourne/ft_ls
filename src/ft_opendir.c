/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:20:15 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/30 16:12:17 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*open_recursive(char *str, t_list *tmp, char *param)
{
	char			*save;

	if (str[ft_strlen(str) - 1] == '/')
	{
		if ((save = ft_strdup(str)) == NULL)
			return (NULL);
	}
	else
	{
		if ((save = ft_strjoin(str, "/")) == NULL)
			return (NULL);
	}
	if ((save = ft_strjoin(save, tmp->content)) == NULL)
		return (NULL);
	if (ft_opendir(save, 2, param, 2) == -1)
		open_error(save);
	return (save);
}

static void			ft_opendir_r(char *str, t_list *tmp, char *param)
{
	while (tmp != NULL)
	{
		if ((ft_strchr(param, 'R') != NULL) && tmp->type == DT_DIR
			&& ft_strcmp(".", tmp->content) != 0 &&
			ft_strcmp("..", tmp->content) != 0)
		{
			if (ft_strchr(param, 'a') == NULL)
			{
				if (tmp->content[0] != '.')
				{
					if (open_recursive(str, tmp, param) == NULL)
						return ;
				}
			}
			else
			{
				if (open_recursive(str, tmp, param) == NULL)
					return ;
			}
		}
		tmp = tmp->next;
	}
}

int					ft_opendir(char *str, int a, char *param, int mult)
{
	DIR				*dir;
	struct dirent	*ret;
	t_list			*first;

	first = NULL;
	if ((dir = opendir(str)) == NULL)
		return (-1);
	if (mult == 2)
		ft_putchar('\n');
	while ((ret = readdir(dir)) != NULL)
	{
		if (read_to_list(&first, ret, param) == -1)
			return (-1);
	}
	if (ft_strchr(param, 'r') != NULL)
		ft_lstreverse(&first);
	call_print(str, &first, param, a);
	free(ret);
	closedir(dir);
	if (ft_strchr(param, 'R') != NULL)
		ft_opendir_r(str, first, param);
	return (0);
}
