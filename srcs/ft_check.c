/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:20:52 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/08 13:06:36 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_del_last_list(t_e **sale)
{
	t_e *tmp1;
	t_e *tmp2;

	tmp1 = *sale;
	if (!(tmp1))
		return (0);
	while (tmp1 && tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	if (tmp1->name)
		free(tmp1->name);
	tmp1->name = NULL;
	if (tmp1->x)
		free(tmp1->x);
	tmp1->x = NULL;
	if (tmp1->y)
		free(tmp1->x);
	tmp1->y = NULL;
	if (tmp1->y)
		free(tmp1);
	tmp1 = NULL;
	return (1);
}

int		ft_invalide_sale_info(t_e **sale)
{
	int	i;
	t_e *tmp;

	i = 0;
	tmp = *sale;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->x && tmp->x[i])
	{
		if (ft_isdigit(tmp->x[i]) == 1 || ((ft_isdigit(tmp->x[1]) == 1)
				&& (tmp->x[0] == '+' || tmp->x[0] == '-')))
			i++;
		else
			return (0);
	}
	i = 0;
	while (tmp->y && tmp->y[i])
	{
		if (ft_isdigit(tmp->y[i]) == 1 || ((ft_isdigit(tmp->y[1]) == 1)
				&& (tmp->y[0] == '+' || tmp->y[0] == '-')))
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_invalide_name(t_e *tmp1, t_e *tmp2)
{
	if (tmp2->name[0] == 'L' || ft_strchr(tmp2->name, '-') != NULL)
		return (0);
	if (tmp1->name[0] == 'L' || ft_strchr(tmp1->name, '-') != NULL)
		return (0);
	if (ft_strcmp(tmp2->name, tmp1->name) == 0)
		return (0);
	return (1);
}

int		ft_invalide_sale(t_e **sale)
{
	int	i;
	t_e *tmp1;
	t_e *tmp2;

	i = 0;
	tmp1 = *sale;
	tmp2 = *sale;
	if (tmp1->name[0] == 'L' || ft_invalide_sale_info(sale) == 0)
		return (0);
	while (tmp1 && tmp1->next)
	{
		tmp1 = tmp1->next;
		i++;
	}
	while (tmp2 && tmp2->next && i > 0)
	{
		if (ft_invalide_name(tmp1, tmp2) == 0)
			return (0);
		else if (tmp2->x && tmp1->x && ft_strcmp(tmp2->x, tmp1->x) == 0
				&& tmp2->y && tmp1->y && ft_strcmp(tmp2->y, tmp1->y) == 0)
			return (0);
		tmp2 = tmp2->next;
		i--;
	}
	return (1);
}

int		ft_valide_line(char *buff, t_e **sale, t_p *info)
{
	if (ft_strcmp(buff, "##start") == 0 && info->start)
		return (0);
	else if (ft_strcmp(buff, "##end") == 0 && info->end)
		return (0);
	else if (buff && buff[0] == '#')
		return (1);
	else if (ft_strchr(buff, '-') && ft_invalide_tube(buff, sale) == 1)
		return (1);
	else if (ft_strchr(buff, ' ') != ft_strrchr(buff, ' ')
			&& (ft_isdigit(*(ft_strrchr(buff, ' ') + 1)) == 1
				|| *(ft_strrchr(buff, ' ') + 1) == '-'
				|| *(ft_strrchr(buff, ' ') + 1) == '+')
				&& (ft_isdigit(*(ft_strchr(buff, ' ') + 1)) == 1
				|| *(ft_strchr(buff, ' ') + 1) == '-'
				|| *(ft_strchr(buff, ' ') + 1) == '+'))
		return (1);
	return (0);
}
