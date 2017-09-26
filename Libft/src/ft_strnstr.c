/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:44:14 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/07 18:03:27 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *litlle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	save;

	i = 0;
	j = 0;
	save = 0;
	if (litlle[j] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		save = i;
		while (big[i] == litlle[j] && big[i] && i < len)
		{
			i++;
			j++;
			if (litlle[j] == '\0')
				return ((char *)big + save);
		}
		if (j > 0)
			i = save;
		i++;
	}
	return (NULL);
}
