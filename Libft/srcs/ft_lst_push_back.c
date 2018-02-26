/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:20:04 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/11 13:20:07 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin_list, void const *content,
		size_t content_size)
{
	t_list *list;

	list = *begin_list;
	while (list->next)
		list = list->next;
	list->next = ft_lstnew(content, content_size);
}
