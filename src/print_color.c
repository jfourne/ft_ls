/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:24:37 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/31 16:18:22 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				init_tab(int *tab, mode_t mode)
{
	tab[0] = 0;
	if (mode & S_IXUSR)
		tab[0] = 1;
	tab[1] = S_ISDIR(mode);
	tab[2] = S_ISLNK(mode);
	tab[3] = S_ISBLK(mode);
	tab[4] = S_ISCHR(mode);
}

void				init_color(char **color)
{
	color[0] = ft_strdup("\x1b[31m");
	color[1] = ft_strdup("\x1b[36m");
	color[2] = ft_strdup("\x1b[35m");
	color[3] = ft_strdup("\x1b[32m");
	color[4] = ft_strdup("\x1b[33m");
	color[5] = NULL;
}

void				tab_del(char ***tab)
{
	int				i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

void				add_color(mode_t mode, char *name, int i, int a)
{
	int				*tab;
	char			**color;

	if ((tab = (int *)malloc(5 * sizeof(int))) != NULL)
		init_tab(tab, mode);
	if ((color = (char **)malloc(6 * sizeof(char *))) != NULL)
		init_color(color);
	while (i < 5)
	{
		if (tab && tab[i] == 1)
		{
			a = 1;
			ft_putstr(color[i]);
		}
		i++;
	}
	ft_putstr(name);
	if (a == 1)
		ft_putstr("\x1b[0m");
	free(tab);
	tab_del(&color);
}
