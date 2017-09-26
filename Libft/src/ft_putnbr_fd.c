/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:39:33 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/10 15:06:57 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		my_putnbr_fd(int n, int count_ten, int fd, int neg)
{
	if ((n / 10) == 0)
	{
		while (count_ten > 1)
		{
			ft_putchar_fd('0', fd);
			count_ten /= 10;
		}
		if (neg == 1)
			n++;
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	ft_putchar_fd((n / count_ten) + '0', fd);
	my_putnbr_fd(n % count_ten, count_ten / 10, fd, neg);
}

void			ft_putnbr_fd(int n, int fd)
{
	int			neg;
	int			count_ten;
	int			save;

	neg = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			neg++;
			n++;
		}
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	count_ten = 1;
	save = n;
	while (save / 10 != 0)
	{
		save = save / 10;
		count_ten = count_ten * 10;
	}
	my_putnbr_fd(n, count_ten, fd, neg);
}
