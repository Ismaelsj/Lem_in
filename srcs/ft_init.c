/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:20:52 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/06 09:39:18 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_listlen(t_e *sale)
{
	int	i;
	t_e *tmp;

	i = 0;
	tmp = sale;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_init_links(t_p *info)
{
	int i;
	int j;

	i = 0;
	info->sales = (int**)malloc(sizeof(int*) * (info->nb_sales + 1));
	while (i < info->nb_sales)
	{
		j = 0;
		info->sales[i] = (int*)malloc(sizeof(int) * (info->nb_sales + 1));
		while (j < info->nb_sales)
		{
			info->sales[i][j] = 0;
			j++;
		}
		i++;
	}
	info->sales[i] = 0;
}

void	ft_links(t_e **sale, t_p *info, char *buff)
{
	t_e		*tmp1;
	t_e		*tmp2;
	char	*tmp;

	tmp1 = *sale;
	tmp2 = *sale;
	if (!(*sale))
		return ;
	if (!(info->sales))
		ft_init_links(info);
	tmp = ft_strcdup(buff, '-');
	while (tmp1 && ft_strcmp(tmp1->name, tmp) != 0)
		tmp1 = tmp1->next;
	free(tmp);
	tmp = ft_strdup(ft_strchr(buff, '-') + 1);
	while (tmp2 && ft_strcmp(tmp2->name, tmp) != 0)
		tmp2 = tmp2->next;
	free(tmp);
	if (tmp1 && tmp2 && ft_strcmp(tmp1->name, tmp2->name) != 0)
	{
		info->sales[tmp1->pos][tmp2->pos] = 1;
		info->sales[tmp2->pos][tmp1->pos] = 1;
	}
}

void	ft_creat(t_e **sale, t_p *info, char *buff, char *prev)
{
	if (buff == NULL || buff[0] == '\0')
		return ;
	if (ft_strchr(buff, '-') != NULL && buff[0] != '#'
			&& (ft_strchr(buff, '-') == ft_strrchr(buff, '-'))
			&& ft_strchr(buff, ' ') == NULL)
		ft_links(sale, info, buff);
	else if (prev && ft_strcmp(prev, "##start") == 0 && !(info->start)
			&& buff[0] != '#')
	{
		if (ft_newsale(sale, buff))
			info->start = ft_strcdup(buff, ' ');
	}
	else if (prev && ft_strcmp(prev, "##end") == 0 && !(info->end)
			&& buff[0] != '#')
	{
		if (ft_newsale(sale, buff))
			info->end = ft_strcdup(buff, ' ');
	}
	else if (buff[0] != '#')
		ft_newsale(sale, buff);
}
