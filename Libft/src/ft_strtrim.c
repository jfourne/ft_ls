/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:45:16 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/11 15:47:34 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_begin(char const *s, int i)
{
	if (!s)
		return (-1);
	while (s[i] && ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i++;
	return (i);
}

static char	*ret_malloc(char *str)
{
	if ((str = (char *)malloc(1 * sizeof(char))) == 0)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		end;
	int		j;

	j = 0;
	str = NULL;
	if ((i = check_begin(s, 0)) == -1)
		return (ret_malloc(str));
	if (s[i] == '\0')
		return (ret_malloc(str));
	end = ft_strlen(s) - 1;
	while (end > 0 && ((s[end] == ' ') || (s[end] == '\n') ||
				(s[end] == '\t')))
		end--;
	if ((str = (char *)malloc((end - i + 2) * sizeof(char))) == 0)
		return (NULL);
	while (i <= end)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
