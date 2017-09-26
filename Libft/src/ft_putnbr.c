/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:08:31 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/10 15:06:40 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		my_putnbr(int n, int count_ten, int neg)
{
	if ((n / 10) == 0)
	{
		while (count_ten > 1)
		{
			ft_putchar('0');
			count_ten /= 10;
		}
		if (neg == 1)
			n++;
		ft_putchar(n + '0');
		return ;
	}
	ft_putchar((n / count_ten) + '0');
	my_putnbr(n % count_ten, count_ten / 10, neg);
}

void			ft_putnbr(int n)
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
		ft_putchar('-');
	}
	count_ten = 1;
	save = n;
	while (save / 10 != 0)
	{
		save = save / 10;
		count_ten = count_ten * 10;
	}
	my_putnbr(n, count_ten, neg);
}
