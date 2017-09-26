/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:07:47 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/10 15:17:19 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		first_word(char const *s, char c, char **tab)
{
	int			i;
	int			word;

	i = 0;
	word = 0;
	if (s[0] && s[0] != c)
	{
		while (s[i] && s[i] != c)
			i++;
		if ((tab[0] = (char *)malloc((i + 1) * sizeof(char))) == 0)
			return (-1);
		i = 0;
		word = 1;
		while (s[i] && s[i] != c)
		{
			tab[0][i] = s[i];
			i++;
		}
		tab[0][i] = '\0';
	}
	return (word);
}

static void		cpy_word(char *tab, char const *s, char c, int i)
{
	int			a;

	a = 0;
	while (s[i] && s[i] != c)
	{
		tab[a] = s[i];
		a++;
		i++;
	}
	tab[a] = '\0';
}

static char		**put_word(char const *s, char c, char **tab)
{
	int			i;
	int			j;
	int			save;

	if ((j = first_word(s, c, tab)) == -1)
		return (NULL);
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && (s[i] != c && s[i] != '\0'))
		{
			save = i;
			while (s[i] && s[i] != c)
				i++;
			if ((tab[j] = (char *)malloc((i - save + 1) * sizeof(char))) == 0)
				return (NULL);
			i = save;
			cpy_word(tab[j], s, c, i);
			j++;
		}
		if (s[i])
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

static char		**split_return(char **tab)
{
	if ((tab = (char**)malloc(1 * sizeof(char*))) == 0)
		return (NULL);
	if ((*tab = (char*)malloc(1 * sizeof(char))) == 0)
		return (NULL);
	*tab = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			word;
	char		**tab;

	i = 1;
	word = 0;
	if (!s)
		return (NULL);
	if (s[0] && s[0] != c)
		word++;
	while (s[i])
	{
		if (s[i - 1] == c && (s[i] != c && s[i] != '\0'))
			word++;
		i++;
	}
	tab = NULL;
	if (word == 0)
		return (split_return(tab));
	if ((tab = (char **)malloc((word + 1) * sizeof(char*))) == 0)
		return (NULL);
	if ((tab = put_word(s, c, tab)) == NULL)
		return (NULL);
	i = 0;
	return (tab);
}
