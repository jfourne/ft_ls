/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:51:02 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/30 16:08:12 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(char const *content, size_t content_size, char type)
{
	t_list	*new;

	new = NULL;
	if ((new = (t_list *)malloc(1 * sizeof(t_list))) == 0)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->type = 0;
		new->content_size = 0;
	}
	else
	{
		new->type = type;
		new->content = ft_strdup(content);
		new->content_size = content_size;
	}
	new->time_m = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
