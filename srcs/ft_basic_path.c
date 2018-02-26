/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:12:57 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/08 16:55:36 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			*ft_next_path(char *str)
{
	t_path *path;

	path = (t_path*)malloc(sizeof(t_path));
	path->ants_nb = 0;
	path->name = ft_strcdup(str, ' ');
	path->next = NULL;
	return (path);
}

t_path			*ft_path(t_p *info, int i)
{
	char	*str;
	t_path	*path;
	t_path	*tmp;

	path = NULL;
	str = info->path[i];
	while ((str = ft_strchr(str, ' ')))
	{
		if (str)
			str += 1;
		if (!(path))
			path = ft_next_path(str);
		else
		{
			tmp = ft_next_path(str);
			tmp->next = path;
			path = tmp;
		}
	}
	return (path);
}

static int		ft_fastest_way(t_p *info, int i, int a)
{
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = -1;
	a = 0;
	while (info->path[i])
	{
		j = 0;
		str = info->path[i];
		while ((str = ft_strchr(str, ' ')))
		{
			if (str)
				str += 1;
			j++;
		}
		if (k == -1 || a > j)
		{
			k = i;
			a = j;
		}
		i++;
	}
	return (k);
}

void			ft_free_t_path(t_path *path)
{
	t_path *tmp;

	if (!(path))
		return ;
	while (path)
	{
		tmp = path;
		path = path->next;
		free(tmp->name);
		free(tmp);
	}
}

void			ft_basic_path(t_p *info)
{
	t_path	*path;
	t_path	*tmp;

	path = ft_path(info, ft_fastest_way(info, 0, 0));
	tmp = path;
	while (tmp->ants_nb < info->ants)
	{
		while (tmp)
		{
			if (!tmp->next || (tmp->next && tmp->next->ants_nb > 0))
				tmp->ants_nb++;
			tmp = tmp->next;
		}
		tmp = path;
		ft_write(tmp, info);
		tmp = path;
		ft_printf("\n");
	}
	ft_free_t_path(path);
}
