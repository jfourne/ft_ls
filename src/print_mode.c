/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:19:07 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/11 15:52:07 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_mode_oth(mode_t mode)
{
	if (mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_ISVTX && mode & S_IXOTH)
		ft_putchar('t');
	else if (mode & S_ISVTX && mode | S_IXOTH)
		ft_putchar('T');
	else if (mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_putstr("  ");
}

void				print_mode_gr(mode_t mode)
{
	if (mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_ISGID && mode & S_IXGRP)
		ft_putchar('s');
	else if (mode & S_ISGID && mode | S_IXGRP)
		ft_putchar('S');
	else if (mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	print_mode_oth(mode);
}

void				print_mode_usr(mode_t mode)
{
	if (mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_ISUID && mode & S_IXUSR)
		ft_putchar('s');
	else if (mode & S_ISUID && mode | S_IXUSR)
		ft_putchar('S');
	else if (mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	print_mode_gr(mode);
}

void				print_mode(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else if (S_ISREG(mode))
		ft_putchar('-');
	print_mode_usr(mode);
}
