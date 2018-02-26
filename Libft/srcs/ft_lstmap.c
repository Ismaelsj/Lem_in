/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:42:04 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/11 11:11:10 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *begin_list;

	list = NULL;
	begin_list = NULL;
	if (lst)
	{
		list = f(lst);
		begin_list = list;
		lst = lst->next;
	}
	while (lst)
	{
		list->next = f(lst);
		lst = lst->next;
		list = list->next;
	}
	list = NULL;
	return (begin_list);
}
