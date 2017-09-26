/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:05:25 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/31 16:17:06 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_parse_param(int ac, char **av, int *i, int *j)
{
	char		*param;

	*i = 1;
	if ((param = ft_strnjoin("", "", 1)) == NULL)
		return (NULL);
	while (*i < ac && av[*i][0] == '-' && ft_strlen(av[*i]) > 1)
	{
		*j = 1;
		while (av[*i][*j])
		{
			if (ft_strcmp(av[*i], "--") == 0)
				return (param);
			if (av[*i][*j] != 'l' && av[*i][*j] != 'R'
					&& av[*i][*j] != 'a' && av[*i][*j] != 'r' &&
					av[*i][*j] != 't')
				return (NULL);
			if (ft_strchr(param, av[*i][*j]) == NULL && av[*i][*j] != '-')
				param = ft_strnjoin(param, av[*i] + *j, 1);
			*j = *j + 1;
		}
		*i = *i + 1;
	}
	return (param);
}
