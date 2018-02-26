/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:03:47 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/05 15:27:43 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_e		**ft_get_tab(t_e *tmp1, t_e *prev)
{
	t_e **tab;

	tab = (t_e**)malloc(sizeof(t_e*) * 2);
	tab[0] = tmp1;
	tab[1] = prev;
	return (tab);
}

int				ft_action(t_e **sale, t_p *info, t_e **tab, int i)
{
	t_e *tmp2;

	tmp2 = *sale;
	while (tmp2->pos != i)
		tmp2 = tmp2->next;
	if ((!tab[1] || (tab[1] && tmp2->pos != tab[1]->pos)) && (tmp2->path == 0
				|| tmp2->path >= tab[0]->path + 1
				|| ft_strcmp(info->start, tmp2->name) == 0))
	{
		info->sales[tab[0]->pos][i] = tab[0]->path + 1;
		info->sales[i][tab[0]->pos] = tab[0]->path + 1;
		tmp2->path = tab[0]->path + 1;
		if (ft_solve2(sale, info, tmp2, tab[0]))
		{
			free(tab);
			return (ft_del_last_path(info, tmp2));
		}
		ft_del_last_path(info, tmp2);
	}
	free(tab);
	return (0);
}

int				ft_solve2(t_e **sale, t_p *info, t_e *next, t_e *prev)
{
	int		i;
	int		j;
	t_e		*tmp1;

	i = 0;
	j = 0;
	tmp1 = *sale;
	while (tmp1 && tmp1->pos != next->pos)
		tmp1 = tmp1->next;
	if (ft_strcmp(next->name, info->end) == 0)
	{
		if (ft_get_path(info, tmp1) == 0)
			return (0);
		return (1);
	}
	if (ft_get_path(info, tmp1) == 0)
		return (0);
	while (i < info->nb_sales)
	{
		if (info->sales[tmp1->pos][i] > 0)
			if (ft_action(sale, info, ft_get_tab(tmp1, prev), i))
				return (0);
		i++;
	}
	return (0);
}
