/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:42:21 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/23 14:50:47 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (!(content))
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = (void*)malloc(sizeof(void) * (ft_strlen(content) + 1));
		if (!list->content)
			return (NULL);
		ft_memset(list->content, '\0', ft_strlen(content) + 1);
		ft_memmove(list->content, content, ft_strlen(content));
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
