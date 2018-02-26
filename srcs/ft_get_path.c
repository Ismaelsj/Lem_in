/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:24:04 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/04 16:09:57 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		*ft_strndup(char *str, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int			ft_is_the_same(t_p *info)
{
	int	i;

	i = 0;
	while (info->path && info->path[i])
	{
		if (ft_strcmp(info->path[i], info->new_path) == 0)
			return (0);
		i++;
	}
	return (1);
}

void		ft_new_path(t_p *info)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	while (info->path && info->path[i])
		i++;
	tmp = (char**)malloc(sizeof(char*) * (i + 2));
	while (info->path && info->path[j])
	{
		tmp[j] = ft_strdup(info->path[j]);
		j++;
	}
	tmp[j] = ft_strdup(info->new_path);
	tmp[j + 1] = 0;
	ft_free_path(info);
	info->path = tmp;
}

int			ft_creat_path(t_p *info, t_e *sale)
{
	char	*tmp;

	tmp = ft_strdup(sale->name);
	info->new_path = tmp;
	return (1);
}

int			ft_get_path(t_p *info, t_e *sale)
{
	int		i;
	int		j;
	char	*tmp1;

	i = 0;
	j = 0;
	if (!(info->new_path))
		return (ft_creat_path(info, sale));
	if (ft_strcmp(sale->name, info->end) == 0)
	{
		tmp1 = ft_strjoin_free(ft_strdup(info->new_path), ft_strdup(" "));
		free(info->new_path);
		info->new_path = ft_strjoin_free(tmp1, ft_strdup(sale->name));
		if (info->path && ft_is_the_same(info) == 0)
			return (0);
		ft_new_path(info);
		return (1);
	}
	tmp1 = ft_strjoin_free(ft_strdup(info->new_path), ft_strdup(" "));
	tmp1 = ft_strjoin_free(tmp1, ft_strdup(sale->name));
	if (info->new_path)
		free(info->new_path);
	info->new_path = tmp1;
	return (1);
}
