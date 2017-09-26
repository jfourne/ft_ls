/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:01:05 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/31 15:53:57 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					print_perror_usage(char *str, int error)
{
	if (error == 1)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(*str, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("usage: ls [-lRart] [file ...]\n", 2);
	}
	else
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
	return (1);
}

void				open_error(char *str)
{
	DIR				*dir;
	struct dirent	*ret;
	t_list			*first;

	if (errno != ENOTDIR)
		print_perror_usage(str, 2);
	else
	{
		first = NULL;
		if ((dir = opendir(".")) == NULL)
			return ;
		while ((ret = readdir(dir)) != NULL)
		{
			if (read_to_list(&first, ret, "") == -1)
				return ;
		}
		while (first != NULL)
		{
			if (ft_strcmp(str, first->content) == 0)
				ft_putendl(str);
			first = first->next;
		}
		closedir(dir);
	}
}

void				multi_param(t_list *first, int i, char *param)
{
	int				a;

	a = 1;
	if (first && first->prev)
		a = 2;
	while (first != NULL)
	{
		if (a != 2 && first->next == NULL && first->prev == NULL)
			a = 1;
		else
			a = 2;
		if ((i = ft_opendir(first->content, a, param, 1)) == -1)
			open_error(first->content);
		first = first->next;
		if (i != -1 && first != NULL)
			ft_putchar('\n');
		a = 1;
	}
}

void				clean_quit(char **param, t_list **first)
{
	if (*param)
		free(*param);
	ft_lstfree(first);
}

int					main(int ac, char **av)
{
	int				i;
	int				j;
	char			*param;
	t_list			*first;

	i = 1;
	j = 1;
	if ((param = ft_parse_param(ac, av, &i, &j)) == NULL)
		return (print_perror_usage(&av[i][j], 1));
	if (av[i] && ft_strcmp(av[i], "--") == 0)
		i++;
	if (ac == 1 || i == ac)
	{
		if ((ft_opendir(".", 1, param, 1)) == -1)
			open_error(".");
	}
	else
	{
		if ((first = open_list(av, i, ac, param)) == NULL)
			return (1);
		multi_param(first, i, param);
	}
	clean_quit(&param, &first);
	return (0);
}
