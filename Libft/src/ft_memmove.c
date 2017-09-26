/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:46:25 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/10 14:55:50 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	save[len];
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (len >= (128 * 1024 * 1024))
		return (NULL);
	while (i < len)
	{
		save[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		s1[i] = save[i];
		i++;
	}
	return (dst);
}
