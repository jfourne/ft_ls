/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_l_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:45:10 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/31 14:01:18 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_with_space(int first_nb, int nb)
{
	int				length;
	int				i;
	char			*str;

	i = 0;
	str = ft_itoa(nb);
	length = ft_strlen(str);
	while (first_nb - (length + i) > 0)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(str);
}

void				print_time_year(char *whole_t, int i)
{
	int				a;

	a = 0;
	while (whole_t[i] && a < 2)
	{
		ft_putchar(whole_t[i]);
		if (whole_t[i] == ' ')
			a++;
		i++;
	}
	while (whole_t[i] && whole_t[i] != ' ')
		i++;
	i++;
	ft_putchar(' ');
	while (whole_t[i] && whole_t[i] != '\n')
	{
		ft_putchar(whole_t[i]);
		i++;
	}
	ft_putchar(' ');
}

void				print_time_modif(time_t *file_t, int i, int a)
{
	time_t			current_t;
	char			*whole_t;

	if ((current_t = time(NULL)) == -1)
		return ;
	if ((whole_t = ctime(file_t)) == NULL)
		return ;
	while (whole_t[i] && whole_t[i] != ' ')
		i++;
	i++;
	if (ABS(current_t - *file_t) > MOUNTH * 6)
	{
		print_time_year(whole_t, i);
		return ;
	}
	while (whole_t[i] && a < 2)
	{
		ft_putchar(whole_t[i]);
		i++;
		if (whole_t[i] == ':')
			a++;
	}
	ft_putchar(' ');
}

void				print_names(uid_t name, gid_t gr_name, t_size all)
{
	struct passwd	*uid;
	struct group	*group;
	int				i;

	i = 0;
	uid = getpwuid(name);
	group = getgrgid(gr_name);
	ft_putstr(uid->pw_name);
	ft_putstr("  ");
	while (ft_strlen(uid->pw_name) + i < (unsigned long)all.n_size)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	ft_putstr(group->gr_name);
	ft_putstr("  ");
	while (ft_strlen(group->gr_name) + i < (unsigned long)all.g_size)
	{
		ft_putchar(' ');
		i++;
	}
}
