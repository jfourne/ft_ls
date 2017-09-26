/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:27:29 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/10 15:05:37 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*my_revstr(char *str, int neg)
{
	int			i;
	int			lenght;
	char		*rev_str;

	i = 0;
	lenght = ft_strlen(str);
	if (neg == 2)
		str[0] += 1;
	if ((rev_str = (char *)malloc((lenght + 1) * sizeof(char))) == 0)
		return (NULL);
	lenght--;
	while (lenght > -1)
	{
		rev_str[i] = str[lenght];
		lenght--;
		i++;
	}
	rev_str[i] = '\0';
	return (rev_str);
}

static char		*my_itoa(int n, char *str, int i, int neg)
{
	if ((n / 10) == 0)
	{
		str[i] = n + '0';
		if (neg > 0)
		{
			str[i + 1] = '-';
			i++;
		}
		str[i + 1] = '\0';
		return (str);
	}
	str[i] = (n % 10) + '0';
	my_itoa(n / 10, str, i + 1, neg);
	return (str);
}

static int		count_mult_ten(int n, int count_nb)
{
	while ((n / 10) > 0)
	{
		n /= 10;
		count_nb++;
	}
	return (count_nb);
}

char			*ft_itoa(int n)
{
	int			count_nb;
	int			neg;
	char		*str;

	neg = 0;
	count_nb = 1;
	if (n < 0)
	{
		neg = 1;
		if (n == -2147483648)
		{
			neg++;
			n++;
		}
		n *= -1;
		count_nb++;
	}
	count_nb = count_mult_ten(n, count_nb);
	if ((str = (char *)malloc((count_nb + 1) * sizeof(char))) == 0)
		return (NULL);
	my_itoa(n, str, 0, neg);
	return (my_revstr(str, neg));
}
