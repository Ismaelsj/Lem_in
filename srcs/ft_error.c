/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:44:47 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/06 09:40:47 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(t_e **sale, t_p *info)
{
	if (info->invalide && info->invalide == 1)
		ft_room(sale, info);
	else if (info->ants <= 0)
		ft_ants(sale, info);
	else if (!(info->start))
		ft_start(sale, info);
	else if (!(info->end))
		ft_end(sale, info);
	else if (!(info->sales))
		ft_sales(sale, info);
	if (info->start == NULL || info->end == NULL || info->ants <= 0
			|| !(info->sales))
		exit(0);
}

void	ft_free_list(t_e **sale)
{
	t_e *tmp1;
	t_e *tmp2;

	tmp2 = *sale;
	if (!(*sale) || !(sale))
		return ;
	while (tmp2)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		if (tmp1->name)
			free(tmp1->name);
		if (tmp1->x)
			free(tmp1->x);
		if (tmp1->y)
			free(tmp1->y);
		if (tmp1)
			free(tmp1);
	}
	sale = NULL;
}

void	ft_free_path(t_p *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!info->path)
		return ;
	while (info->path[i])
	{
		free(info->path[i]);
		i++;
	}
	free(info->path);
}

void	ft_free(t_e **sale, t_p *info)
{
	int i;

	i = 0;
	ft_free_list(sale);
	if (!(info) || !(info->sales))
		return ;
	while (info->sales[i])
	{
		free(info->sales[i]);
		i++;
	}
	ft_free_path(info);
	if (info->sales)
		free(info->sales);
	if (info->start)
		free(info->start);
	if (info->end)
		free(info->end);
	if (info->new_path)
		free(info->new_path);
	if (info)
		free(info);
	info = NULL;
}
