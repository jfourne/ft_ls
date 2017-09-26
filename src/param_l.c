/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:55:48 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/31 16:17:54 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_link(char *path, mode_t mode)
{
	int				i;
	char			*buff;

	if (S_ISLNK(mode))
	{
		ft_putstr(" -> ");
		if ((buff = (char *)malloc((128 + 1) * sizeof(char)))
				== NULL)
			return ;
		if ((i = readlink(path, buff, 128)) == -1)
		{
			perror("");
			return ;
		}
		buff[i] = '\0';
		ft_putstr(buff);
	}
	ft_putchar('\n');
}

void				init_all(t_size *all)
{
	all->size = 0;
	all->maj_size = 0;
	all->min_size = 0;
	all->l_size = 0;
	all->n_size = 0;
	all->g_size = 0;
}

void				call_for_l(struct stat buf, t_size all)
{
	print_mode(buf.st_mode);
	print_with_space(all.l_size, buf.st_nlink);
	ft_putchar(' ');
	print_names(buf.st_uid, buf.st_gid, all);
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
	{
		print_with_space(all.maj_size, major(buf.st_rdev));
		ft_putstr(", ");
		print_with_space(all.min_size, minor(buf.st_rdev));
	}
	else
		print_with_space(all.size, buf.st_size);
	ft_putchar(' ');
	print_time_modif(&buf.st_mtime, 0, 0);
}

void				param_l(char *str, t_list *tmp)
{
	char			*path;
	struct stat		buf;
	t_size			all;

	init_all(&all);
	redim(str, tmp, &all, 0);
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
			path = ft_strdup(tmp->content);
		if (lstat(path, &buf) == -1)
			return (perror(""));
		call_for_l(buf, all);
		add_color(buf.st_mode, tmp->content, 0, 0);
		print_link(path, buf.st_mode);
		free(path);
		tmp = tmp->next;
	}
}
