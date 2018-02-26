/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:41:58 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/06 09:36:11 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_get_coord(t_e *tmp, char **split, int i)
{
	tmp->name = split[0];
	tmp->x = split[1];
	tmp->y = split[2];
	tmp->pos = i;
	tmp->path = 0;
	tmp->next = NULL;
}

int				ft_newsale(t_e **sale, char *buff)
{
	t_e			*tmp;
	char		**split;
	int			j;
	static int	i;

	j = 0;
	if (!*sale)
	{
		split = ft_strsplit(buff, ' ');
		tmp = (t_e*)malloc(sizeof(t_e));
		ft_get_coord(tmp, split, i);
		*sale = tmp;
	}
	else
	{
		split = ft_strsplit(buff, ' ');
		tmp = *sale;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_e*)malloc(sizeof(t_e));
		ft_get_coord(tmp->next, split, i);
	}
	free(split);
	i++;
	return (1);
}
