/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:20:51 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/07 17:59:30 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		save;

	i = 0;
	j = 0;
	save = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		save = i;
		while (big[i] == little[j] && big[i])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char *)big + save);
		}
		if (j > 0)
			i = save;
		i++;
	}
	return (NULL);
}
