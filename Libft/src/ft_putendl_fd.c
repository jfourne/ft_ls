/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:37:48 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/10 15:03:21 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putendl_fd(const char *s, int fd)
{
	char	c;

	c = '\n';
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
}
