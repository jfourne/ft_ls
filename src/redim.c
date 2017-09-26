/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:28:33 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/31 16:21:58 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				length_major_minor(dev_t rdev, t_size *all)
{
	int				maj_min;

	maj_min = ft_strlen(ft_itoa(major(rdev)));
	if (all->maj_size < maj_min)
		all->maj_size = maj_min;
	maj_min = ft_strlen(ft_itoa(minor(rdev)));
	if (all->min_size < maj_min)
		all->min_size = maj_min;
}

void				complete_all(t_size *all, struct stat buf, int maj_min)
{
	int				nb;
	struct passwd	*uid;
	struct group	*group;

	nb = ft_strlen(ft_itoa(buf.st_nlink));
	if (all->l_size < nb)
		all->l_size = nb;
	if (maj_min == 1)
		nb = ft_strlen(ft_itoa(buf.st_size));
	else
		length_major_minor(buf.st_rdev, all);
	if (all->size < nb)
		all->size = nb;
	uid = getpwuid(buf.st_uid);
	nb = ft_strlen(uid->pw_name);
	if (all->n_size < nb)
		all->n_size = nb;
	group = getgrgid(buf.st_gid);
	nb = ft_strlen(group->gr_name);
	if (all->g_size < nb)
		all->g_size = nb;
	if (all->maj_size || all->min_size)
		all->size = all->maj_size + all->min_size + 2;
}

void				print_total(int total)
{
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

void				redim(char *str, t_list *tmp, t_size *all, int total)
{
	char			*path;
	struct stat		buf;

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
		total = total + buf.st_blocks;
		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
			complete_all(all, buf, 2);
		else
			complete_all(all, buf, 1);
		free(path);
		tmp = tmp->next;
	}
	print_total(total);
}
